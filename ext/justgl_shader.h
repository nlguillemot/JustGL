#ifndef JUSTGL_SHADER_H
#define JUSTGL_SHADER_H

#include "justgl.h"

#include <cstdio>
#include <set>
#include <vector>
#include <fstream>
#include <sstream>

class Shader;
void swap(Shader& a, Shader& b);

class Shader
{
public:
    static std::set<Shader*> AllShaders;

    Shader()
        : Filename(nullptr)
        , Type(0)
        , Timestamp(0)
        , Handle(0)
    {
        AllShaders.insert(this);
    }

    Shader(const char* filename, GLenum type)
        : Shader()
    {
        Filename = filename;
        Type = type;
    }

    ~Shader()
    {
        glDeleteShader(Handle);
        AllShaders.erase(this);
    }

    Shader(const Shader&) = delete;
    Shader& operator=(const Shader&) = delete;

    Shader(Shader&& other)
        : Shader()
    {
        swap(*this, other);
    }

    Shader& operator=(Shader&& other)
    {
        swap(*this, other);
    }

    const char* Filename;
    GLenum Type;
    uint64_t Timestamp;
    GLuint Handle;
};

inline void swap(Shader& a, Shader& b)
{
    std::swap(a.Filename, b.Filename);
    std::swap(a.Type, b.Type);
    std::swap(a.Timestamp, b.Timestamp);
    std::swap(a.Handle, b.Handle);
}

class ShaderProgram;
void swap(ShaderProgram& a, ShaderProgram& b);

class ShaderProgram
{
public:
    static std::set<ShaderProgram*> AllPrograms;

    ShaderProgram()
        : VS(nullptr)
        , FS(nullptr)
        , GS(nullptr)
        , TCS(nullptr)
        , TES(nullptr)
        , Handle(0)
    {
        AllPrograms.insert(this);
    }

    explicit ShaderProgram(Shader* vs, Shader* fs = nullptr, Shader* gs = nullptr, Shader* tcs = nullptr, Shader* tes = nullptr)
        : ShaderProgram()
    {
        VS = vs;
        FS = fs;
        GS = gs;
        TCS = tcs;
        TES = tes;
    }

    ~ShaderProgram()
    {
        glDeleteProgram(Handle);
        AllPrograms.erase(this);
    }

    ShaderProgram(const ShaderProgram&) = delete;
    ShaderProgram& operator=(const ShaderProgram&) = delete;
    
    ShaderProgram(ShaderProgram&& other)
        : ShaderProgram()
    {
        swap(*this, other);
    }

    ShaderProgram& operator=(ShaderProgram&& other)
    {
        swap(*this, other);
    }

    Shader* VS;
    Shader* FS;
    Shader* GS;
    Shader* TCS;
    Shader* TES;
    GLuint Handle;
};

inline void swap(ShaderProgram& a, ShaderProgram& b)
{
    std::swap(a.VS, b.VS);
    std::swap(a.FS, b.FS);
    std::swap(a.GS, b.GS);
    std::swap(a.TCS, b.TCS);
    std::swap(a.TES, b.TES);
    std::swap(a.Handle, b.Handle);
}

bool UpdateShaders();

#endif // JUSTGL_SHADER_H