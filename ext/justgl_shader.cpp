#include "justgl_shader.h"
#include "justgl_fs.h"

#include <vector>
#include <cstdio>

std::set<Shader*> Shader::AllShaders;
std::set<ShaderProgram*> ShaderProgram::AllPrograms;

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

            MappedFile shaderFile = MapFileForRead(shader->Filename.c_str());
            if (!shaderFile.Data)
            {
                anyBroken = true;
                continue;
            }

            const char* data = shaderFile.Data;
            GLint size = (GLint)shaderFile.Size;

            shader->Handle = glCreateShader(shader->Type);
            glShaderSource(shader->Handle, 1, &data, &size);
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
            }
            else
            {
                printf("Compiled %s successfully.\n", shader->Filename.c_str());
                pUpdatedShaders->insert(shader);
            }
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