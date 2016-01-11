#include "justgl_shader.h"
#include "justgl_fs.h"

#include <vector>
#include <cstdio>
#include <utility>
#include <cctype>

std::set<Shader*> Shader::AllShaders;
std::set<ShaderProgram*> ShaderProgram::AllPrograms;

static bool ReadAndExpandIncludes(const char* filename, std::string& result)
{
    MappedFile shaderFile = MapFileForRead(filename);
    if (!shaderFile.Data)
    {
        return false;
    }

    std::vector<std::pair<uint64_t, uint64_t>> includeSpans;
    std::vector<std::pair<uint64_t, uint64_t>> includeFilenameSpans;

    const char* mem = shaderFile.Data;
    uint64_t size = shaderFile.Size;
    
    std::string includePrefix = "#include";

    for (uint64_t i = 0; i < size; )
    {
        while (i < size && (mem[i] == ' ' || mem[i] == '\t'))
        {
            i++;
        }

        if (size - i >= includePrefix.size() && memcmp(&mem[i], includePrefix.data(), includePrefix.length()) == 0)
        {
            // found an include line
            std::pair<uint64_t, uint64_t> includeSpan;
            includeSpan.first = i;
            
            i += includePrefix.length();
            while (i < size && (mem[i] == ' ' || mem[i] == '\t'))
            {
                i++;
            }

            if (i < size && mem[i] == '\"')
            {
                i++;

                std::pair<uint64_t, uint64_t> includeFilenameSpan;
                includeFilenameSpan.first = i;

                while (i < size && (mem[i] != '\"' && mem[i] != '\n' && mem[i] != '\r'))
                {
                    i++;
                }

                if (i < size && mem[i] == '\"')
                {
                    includeFilenameSpan.second = i;
                    includeFilenameSpans.push_back(includeFilenameSpan);

                    i++;
                    includeSpan.second = i;
                    includeSpans.push_back(includeSpan);
                }
                else
                {
                    // expected ending quote
                    return false;
                }
            }
            else
            {
                // expected opening quote
                return false;
            }
        }
        else
        {
            // not an include line
            while (i < size && (mem[i] != '\n' && mem[i] != '\r'))
            {
                i++;
            }
        }

        if (i < size)
        {
            if (mem[i] == '\n' || mem[i] == '\r')
            {
                while (i < size && (mem[i] == '\n' || mem[i] == '\r'))
                {
                    i++;
                }
            }
            else
            {
                // expected newline at the end of the line (or after the include)
                return false;
            }
        }
    }

    // insert the includes in reverse order to not screw up the spans' locations
    result.clear();
    result.append(mem, size);
    for (size_t i = 0; i < includeSpans.size(); i++)
    {
        std::pair<uint64_t, uint64_t> span = includeSpans[includeSpans.size() - i - 1];
        std::pair<uint64_t, uint64_t> filenameSpan = includeFilenameSpans[includeFilenameSpans.size() - i - 1];

        std::string includedFilename(&mem[filenameSpan.first], &mem[filenameSpan.second]);
        std::string includedFileBody;
        if (!ReadAndExpandIncludes(includedFilename.c_str(), includedFileBody))
        {
            return false;
        }

        result.replace(span.first, span.second - span.first, includedFileBody);
    }

    return true;
}

bool UpdateShaders(std::set<Shader*>* pUpdatedShaders, std::set<ShaderProgram*>* pUpdatedPrograms)
{
    std::set<Shader*> tempUpdatedShaders;
    std::set<ShaderProgram*> tempUpdatedPrograms;

    if (!pUpdatedShaders) {
        pUpdatedShaders = &tempUpdatedShaders;
    }
    if (!pUpdatedPrograms) {
        pUpdatedPrograms = &tempUpdatedPrograms;
    }

    bool anyBroken = false;

    for (Shader* shader : Shader::AllShaders)
    {
        uint64_t timestamp = GetFileTimestamp(shader->Filename.c_str());
        if (timestamp == 0)
        {
            anyBroken = true;
        }
        else if (timestamp > shader->Timestamp)
        {
            glDeleteShader(shader->Handle);
            shader->Timestamp = timestamp;
            shader->Handle = 0;

            std::string source;
            if (!ReadAndExpandIncludes(shader->Filename.c_str(), source))
            {
                fprintf(stderr, "Failed to read and expand includes in %s\n", shader->Filename.c_str());
                anyBroken = true;
                continue;
            }

            const char* data = source.c_str();
            GLint length = (GLint)source.length();

            shader->Handle = glCreateShader(shader->Type);
            glShaderSource(shader->Handle, 1, &data, &length);
            glCompileShader(shader->Handle);

            GLint status;
            glGetShaderiv(shader->Handle, GL_COMPILE_STATUS, &status);
            if (!status)
            {
                GLint logLength;
                glGetShaderiv(shader->Handle, GL_INFO_LOG_LENGTH, &logLength);
                std::vector<char> log(logLength);
                glGetShaderInfoLog(shader->Handle, logLength, NULL, log.data());
                fprintf(stderr, "Error compiling %s: %s\n", shader->Filename.c_str(), log.data());
                anyBroken = true;

                glDeleteShader(shader->Handle);
                shader->Handle = 0;
            }
            else
            {
                printf("Compiled %s successfully.\n", shader->Filename.c_str());
                pUpdatedShaders->insert(shader);
            }
        }
        else if (shader->Handle == 0)
        {
            anyBroken = true;
        }
    }

    for (ShaderProgram* program : ShaderProgram::AllPrograms)
    {
        std::set<Shader*>::iterator end = pUpdatedShaders->end();
        if (pUpdatedShaders->find(program->VS)  != end ||
            pUpdatedShaders->find(program->FS)  != end || 
            pUpdatedShaders->find(program->GS)  != end ||
            pUpdatedShaders->find(program->TCS) != end ||
            pUpdatedShaders->find(program->TES) != end ||
            pUpdatedShaders->find(program->CS)  != end)
        {
            glDeleteProgram(program->Handle);
            program->Handle = 0;

            program->Handle = glCreateProgram();
            
            Shader* shaderStages[] = {
                program->VS,
                program->FS,
                program->GS,
                program->TCS,
                program->TES,
                program->CS
            };
            const char* shaderStageNames[] = {
                "VS", "FS", "GS", "TCS", "TES", "CS"
            };

            for (Shader* stage : shaderStages)
            {
                if (stage && stage->Handle)
                {
                    glAttachShader(program->Handle, stage->Handle);
                }
            }

            for (const std::pair<GLenum, GLint>& preLinkParam : program->PreLinkParametersi)
            {
                glProgramParameteri(program->Handle, preLinkParam.first, preLinkParam.second);
            }
            
            glLinkProgram(program->Handle);

            auto printShaders = [&shaderStages, &shaderStageNames](FILE* f)
            {
                fprintf(f, "{ ");
                bool anyLinked = false;
                for (Shader*& stage : shaderStages)
                {
                    if (!stage)
                    {
                        continue;
                    }

                    anyLinked = true;

                    fprintf(f, "%s%s: \"%s\"",
                        stage == shaderStages[0] ? "" : ", ",
                        shaderStageNames[&stage - shaderStages],
                        stage->Filename.c_str());
                }
                if (anyLinked)
                {
                    fprintf(f, " ");
                }
                fprintf(f, "}");
            };

            GLint status;
            glGetProgramiv(program->Handle, GL_LINK_STATUS, &status);
            if (!status)
            {
                GLint logLength;
                glGetProgramiv(program->Handle, GL_INFO_LOG_LENGTH, &logLength);
                std::vector<char> log(logLength);
                glGetProgramInfoLog(program->Handle, logLength, NULL, log.data());

                fprintf(stderr, "Error linking shaders ");
                printShaders(stderr);
                fprintf(stderr, "\n%s\n", log.data());
                anyBroken = true;

                glDeleteProgram(program->Handle);
                program->Handle = 0;
            }
            else
            {
                fprintf(stdout, "Linked program successfully: ");
                printShaders(stdout);
                fprintf(stdout, "\n");

                pUpdatedPrograms->insert(program);
            }
        }
    }

    return !anyBroken;
}