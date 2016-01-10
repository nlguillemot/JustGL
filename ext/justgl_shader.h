#ifndef JUSTGL_SHADER_H
#define JUSTGL_SHADER_H

#include "justgl.h"

#include <set>
#include <map>
#include <string>
#include <utility>
#include <cstring>
#include <cassert>

class Shader;
void swap(Shader& a, Shader& b);

class Shader
{
public:
    static std::set<Shader*> AllShaders;

    Shader()
        : Type(0)
        , Timestamp(0)
        , Handle(0)
    {
        AllShaders.insert(this);
    }

    Shader(std::string filename, GLenum type)
        : Shader()
    {
        Filename = std::move(filename);
        Type = type;
    }

    // Guesses shader type from the extension
    explicit Shader(std::string filename)
        : Shader()
    {
        Filename = std::move(filename);
        size_t extLoc = Filename.find_last_of('.');
        if (extLoc != std::string::npos)
        {
            struct ShaderExt {
                const char* Name;
                GLenum Type;
            };
            ShaderExt exts[] = {
                { "vert", GL_VERTEX_SHADER },
                { "frag", GL_FRAGMENT_SHADER },
                { "geom", GL_GEOMETRY_SHADER },
                { "tesc", GL_TESS_CONTROL_SHADER },
                { "tese", GL_TESS_EVALUATION_SHADER },
                { "comp", GL_COMPUTE_SHADER }
            };

            for (ShaderExt& ext : exts)
            {
                if (strcmp(Filename.c_str() + extLoc + 1, ext.Name) == 0)
                {
                    Type = ext.Type;
                    break;
                }
            }

            assert(Type != 0);
        }
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

    std::string Filename;
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

    explicit ShaderProgram(Shader* vs_or_cs, Shader* fs = nullptr, Shader* gs = nullptr, Shader* tcs = nullptr, Shader* tes = nullptr)
        : ShaderProgram()
    {
        if (vs_or_cs)
        {
            if (vs_or_cs->Type == GL_VERTEX_SHADER)
            {
                VS = vs_or_cs;
                FS = fs;
                GS = gs;
                TCS = tcs;
                TES = tes;
            }
            else if (vs_or_cs->Type == GL_COMPUTE_SHADER)
            {
                CS = vs_or_cs;
                assert(fs == nullptr);
                assert(gs == nullptr);
                assert(tcs == nullptr);
                assert(tes == nullptr);
            }
        }
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
    Shader* CS;
    GLuint Handle;

    // Used with glProgramParameteri before linking
    std::map<GLenum, GLint> PreLinkParametersi;
};

inline void swap(ShaderProgram& a, ShaderProgram& b)
{
    std::swap(a.VS, b.VS);
    std::swap(a.FS, b.FS);
    std::swap(a.GS, b.GS);
    std::swap(a.TCS, b.TCS);
    std::swap(a.TES, b.TES);
    std::swap(a.CS, b.CS);
    std::swap(a.Handle, b.Handle);
    std::swap(a.PreLinkParametersi, b.PreLinkParametersi);
}

// Returns false if any shaders failed to compile/link.
// Intended use: void PaintGL() { if (!UpdateShaders()){ return; } }
// No matter the return value, it optionally reports shaders and programs that were updated.
bool UpdateShaders(std::set<Shader*>* pUpdatedShaders = nullptr, std::set<ShaderProgram*>* pUpdatedPrograms = nullptr);

#endif // JUSTGL_SHADER_H