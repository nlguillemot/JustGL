#include "justgl_shader.h"
#include "justgl_fs.h"

std::set<Shader*> Shader::AllShaders;
std::set<ShaderProgram*> ShaderProgram::AllPrograms;

bool UpdateShaders()
{
    std::set<Shader*> updatedShaders;
    bool anyBroken = false;

    for (Shader* shader : Shader::AllShaders)
    {
        if (!shader->Filename)
        {
            continue;
        }

        uint64_t timestamp = GetFileTimestamp(shader->Filename);
        if (timestamp == 0)
        {
            fprintf(stderr, "Couldn't find file: %s\n", shader->Filename);
            anyBroken = true;
        }
        else if (timestamp > shader->Timestamp)
        {
            glDeleteShader(shader->Handle);
            shader->Timestamp = timestamp;
            shader->Handle = 0;

            std::ifstream ifs(shader->Filename);
            if (!ifs)
            {
                anyBroken = true;
                continue;
            }

            std::stringstream ss;
            ss << ifs.rdbuf();
            std::string s = ss.str();
            const char* cs = s.c_str();

            shader->Handle = glCreateShader(shader->Type);
            glShaderSource(shader->Handle, 1, &cs, NULL);
            glCompileShader(shader->Handle);

            GLint status;
            glGetShaderiv(shader->Handle, GL_COMPILE_STATUS, &status);
            if (!status)
            {
                GLint logLength;
                glGetShaderiv(shader->Handle, GL_INFO_LOG_LENGTH, &logLength);
                std::vector<char> log(logLength);
                glGetShaderInfoLog(shader->Handle, logLength, NULL, log.data());
                fprintf(stderr, "Error compiling %s: %s\n", shader->Filename, log.data());
                anyBroken = true;
            }
            else
            {
                updatedShaders.insert(shader);
            }
        }
    }

    for (ShaderProgram* program : ShaderProgram::AllPrograms)
    {
        if (updatedShaders.find(program->VS) != updatedShaders.end() ||
            updatedShaders.find(program->FS) != updatedShaders.end() || 
            updatedShaders.find(program->GS) != updatedShaders.end() ||
            updatedShaders.find(program->TCS) != updatedShaders.end() ||
            updatedShaders.find(program->TES) != updatedShaders.end())
        {
            glDeleteProgram(program->Handle);
            program->Handle = 0;

            program->Handle = glCreateProgram();
            
            Shader* shaderStages[] = {
                program->VS,
                program->FS,
                program->GS,
                program->TCS,
                program->TES
            };
            const char* shaderStageNames[] = {
                "VS", "FS", "GS", "TCS", "TES"
            };

            for (Shader* stage : shaderStages)
            {
                if (stage && stage->Handle)
                {
                    glAttachShader(program->Handle, stage->Handle);
                }
            }
            
            glLinkProgram(program->Handle);

            GLint status;
            glGetProgramiv(program->Handle, GL_LINK_STATUS, &status);
            if (!status)
            {
                GLint logLength;
                glGetProgramiv(program->Handle, GL_INFO_LOG_LENGTH, &logLength);
                std::vector<char> log(logLength);
                glGetProgramInfoLog(program->Handle, logLength, NULL, log.data());
                fprintf(stderr, "Error linking program (");
                for (Shader* stage : shaderStages)
                {
                    fprintf(stderr, "%s%s: %s", 
                        stage == shaderStages[0] ? "" : ", ",
                        shaderStageNames[&stage - shaderStages], 
                        stage->Filename ? stage->Filename : "(no filename)");
                }
                fprintf(stderr, "): %s\n", log.data());
                anyBroken = true;
            }
        }
    }

    return !anyBroken;
}