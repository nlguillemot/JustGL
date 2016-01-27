/*
    The MIT License (MIT)

    Copyright (c) 2016 Nicolas Guillemot

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/

#include "justgl_shader.h"
#include "justgl_fs.h"

#include <vector>
#include <cstdio>
#include <utility>
#include <cctype>

std::set<Shader*> Shader::AllShaders;
std::set<ShaderProgram*> ShaderProgram::AllPrograms;

static uint16_t ShaderNameHash(const char *str)
{
    uint16_t hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

static bool ReadAndExpandIncludes(const char* filename, 
    std::vector<std::string>& result, 
    std::vector<std::string>& resultFiles)
{
    MappedFile shaderFile = MapFileForRead(filename);
    if (!shaderFile.Data)
    {
        return false;
    }

    std::vector<std::pair<uint64_t, uint64_t>> includeSpans;
    std::vector<std::pair<uint64_t, uint64_t>> includeFilenameSpans;
    std::vector<int> spanLineNumbers;

    const char* mem = shaderFile.Data;
    uint64_t size = shaderFile.Size;
    int lineNumber = 1;
    
    std::string versionPrefix = "#version";
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

                    spanLineNumbers.push_back(lineNumber);
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
                    if (mem[i] == '\n')
                    {
                        lineNumber++;
                    }
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
    
    // add initial source span
    if (includeSpans.empty())
    {
        result.emplace_back(mem, (std::string::size_type)size);
    }
    else
    {
        result.emplace_back(mem, (std::string::size_type)includeSpans[0].first);
    }
    resultFiles.push_back(filename);

    for (size_t i = 0; i < includeSpans.size(); i++)
    {
        std::pair<uint64_t, uint64_t> span = includeSpans[i];
        std::pair<uint64_t, uint64_t> filenameSpan = includeFilenameSpans[i];

        std::string includedFilename(&mem[filenameSpan.first], &mem[filenameSpan.second]);
        std::vector<std::string> includedFileBody, includedFilenames;
        if (!ReadAndExpandIncludes(includedFilename.c_str(), includedFileBody, includedFilenames))
        {
            return false;
        }

        // indicate start of the new file
        result.push_back("#line 1 " + std::to_string(ShaderNameHash(includedFilename.c_str())) + "\n");
        resultFiles.push_back(includedFilename);

        for (size_t j = 0; j < includedFileBody.size(); j++)
        {
            result.push_back(std::move(includedFileBody[j]));
            resultFiles.push_back(std::move(includedFilenames[j]));
        }

        // indicate starting this file again
        result.push_back(
            "\n#line " + 
            std::to_string(spanLineNumbers[i] + 1) + 
            " " + 
            std::to_string(ShaderNameHash(filename)));
        resultFiles.push_back(filename);

        // add what comes after the include up until the next span
        uint64_t nextSpan = size;
        if (i + 1 < includeSpans.size())
        {
            nextSpan = includeSpans[i + 1].first;
        }
        result.emplace_back(&mem[span.second], (std::string::size_type)(nextSpan - span.second));
        resultFiles.push_back(filename);
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
        if (timestamp != 0)
        {
            for (const std::string& dep : shader->IncludeDependencies)
            {
                uint64_t depTimestamp = GetFileTimestamp(dep.c_str());
                if (depTimestamp == 0)
                {
                    timestamp = 0;
                    break;
                }
                else if (depTimestamp > timestamp)
                {
                    timestamp = depTimestamp;
                }
            }
        }

        if (timestamp == 0)
        {
            anyBroken = true;
            continue;
        }

        if (timestamp > shader->Timestamp)
        {
            glDeleteShader(shader->Handle);
            shader->Timestamp = timestamp;
            shader->Handle = 0;

            std::vector<std::string> sources, sourceFiles;
            if (!ReadAndExpandIncludes(shader->Filename.c_str(), sources, sourceFiles))
            {
                fprintf(stderr, "Failed to read and expand includes in %s\n", shader->Filename.c_str());
                anyBroken = true;
                continue;
            }

            shader->IncludeDependencies.clear();
            for (const std::string& dep : sourceFiles)
            {
                if (dep != shader->Filename)
                {
                    shader->IncludeDependencies.insert(dep);
                }
            }

            std::vector<const char*> datas;
            std::vector<GLint> lengths;
            for (size_t i = 0; i < sources.size(); i++)
            {
                datas.push_back(sources[i].c_str());
                lengths.push_back((GLint)sources[i].length());
            }

            shader->Handle = glCreateShader(shader->Type);
            glShaderSource(shader->Handle, (GLsizei)sources.size(), datas.data(), lengths.data());
            glCompileShader(shader->Handle);

            GLint status;
            glGetShaderiv(shader->Handle, GL_COMPILE_STATUS, &status);
            if (!status)
            {
                GLint logLength;
                glGetShaderiv(shader->Handle, GL_INFO_LOG_LENGTH, &logLength);
                std::vector<char> log(logLength);
                glGetShaderInfoLog(shader->Handle, logLength, NULL, log.data());
                
                std::string logStr(log.data());
                for (size_t i = 0; i < sources.size(); i++)
                {
                    std::string hashedName = std::to_string(ShaderNameHash(sourceFiles[i].c_str()));
                    size_t loc;
                    for (;;)
                    {
                        loc = logStr.find(hashedName);
                        if (loc == std::string::npos)
                        {
                            break;
                        }
                        else
                        {
                            logStr.replace(loc, hashedName.length(), sourceFiles[i]);
                        }
                    }
                }

                fprintf(stderr, "Error compiling %s: %s\n", shader->Filename.c_str(), logStr.c_str());
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