#ifndef JUSTGL_SHADER_H
#define JUSTGL_SHADER_H

#include "justgl.h"

#include <cstdio>
#include <set>
#include <vector>
#include <fstream>
#include <sstream>

class Shader
{
public:
    static std::set<Shader*> AllShaders;

    Shader(const char* filename, GLenum type)
        : Filename(filename)
        , Type(type)
        , Timestamp(0)
        , Handle(0)
    {
        AllShaders.insert(this);
    }

    ~Shader()
    {
        AllShaders.erase(this);
    }

    const char* Filename;
    GLenum Type;
    uint64_t Timestamp;
    GLuint Handle;
};

class ShaderProgram
{
public:
    static std::set<ShaderProgram*> AllPrograms;

    ShaderProgram(Shader* vs, Shader* fs)
        : VS(vs)
        , FS(fs)
        , Handle(0)
    {
        AllPrograms.insert(this);
    }

    ~ShaderProgram()
    {
        AllPrograms.erase(this);
    }

    Shader* VS;
    Shader* FS;
    GLuint Handle;
};

bool UpdateShaders();

#ifdef JUSTGL_SHADER_IMPLEMENTATION

std::set<Shader*> Shader::AllShaders;
std::set<ShaderProgram*> ShaderProgram::AllPrograms;

bool UpdateShaders()
{
    std::set<Shader*> updatedShaders;
    bool anyBroken = false;

    for (Shader* shader : Shader::AllShaders)
    {
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
            updatedShaders.find(program->FS) != updatedShaders.end())
        {
            glDeleteProgram(program->Handle);
            program->Handle = 0;

            program->Handle = glCreateProgram();
            glAttachShader(program->Handle, program->VS->Handle);
            glAttachShader(program->Handle, program->FS->Handle);
            glLinkProgram(program->Handle);

            GLint status;
            glGetProgramiv(program->Handle, GL_LINK_STATUS, &status);
            if (!status)
            {
                GLint logLength;
                glGetProgramiv(program->Handle, GL_INFO_LOG_LENGTH, &logLength);
                std::vector<char> log(logLength);
                glGetProgramInfoLog(program->Handle, logLength, NULL, log.data());
                fprintf(stderr, "Error linking program (VS: %s, FS: %s): %s\n",
                    program->VS->Filename, program->FS->Filename, log.data());
                anyBroken = true;
            }
        }
    }

    return !anyBroken;
}

#endif // JUSTGL_SHADER_IMPLEMENTATION

#endif // JUSTGL_SHADER_H