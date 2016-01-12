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

#ifndef JUSTGL_SHADER_H
#define JUSTGL_SHADER_H

#include "justgl.h"

#include <set>
#include <map>
#include <vector>
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
    
    std::vector<std::string> IncludeDependencies;
};

inline void swap(Shader& a, Shader& b)
{
    using std::swap;

    swap(a.Filename, b.Filename);
    swap(a.Type, b.Type);
    swap(a.Timestamp, b.Timestamp);
    swap(a.Handle, b.Handle);
    swap(a.IncludeDependencies, b.IncludeDependencies);
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
    using std::swap;

    swap(a.VS, b.VS);
    swap(a.FS, b.FS);
    swap(a.GS, b.GS);
    swap(a.TCS, b.TCS);
    swap(a.TES, b.TES);
    swap(a.CS, b.CS);
    swap(a.Handle, b.Handle);

    swap(a.PreLinkParametersi, b.PreLinkParametersi);
}

// Returns false if any shaders failed to compile/link.
// Intended use: void PaintGL() { if (!UpdateShaders()){ return; } }
// No matter the return value, it optionally reports shaders and programs that were updated.
bool UpdateShaders(std::set<Shader*>* pUpdatedShaders = nullptr, std::set<ShaderProgram*>* pUpdatedPrograms = nullptr);

#endif // JUSTGL_SHADER_H