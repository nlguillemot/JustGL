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

#ifndef JUSTGL_DEBUG_H
#define JUSTGL_DEBUG_H

#include "justgl.h"
#include "justgl_math.h"

#include <sstream>
#include <string>
#include <vector>
#include <array>

inline const char* DebugSourceToString(GLenum source)
{
    switch (source)
    {
    case GL_DEBUG_SOURCE_API: return "GL_DEBUG_SOURCE_API";
    case GL_DEBUG_SOURCE_WINDOW_SYSTEM: return "GL_DEBUG_SOURCE_WINDOW_SYSTEM";
    case GL_DEBUG_SOURCE_SHADER_COMPILER: return "GL_DEBUG_SOURCE_SHADER_COMPILER";
    case GL_DEBUG_SOURCE_THIRD_PARTY: return "GL_DEBUG_SOURCE_THIRD_PARTY";
    case GL_DEBUG_SOURCE_APPLICATION: return "GL_DEBUG_SOURCE_APPLICATION";
    case GL_DEBUG_SOURCE_OTHER: return "GL_DEBUG_SOURCE_OTHER";
    default: return "(unknown)";
    }
}

inline const char* DebugTypeToString(GLenum type)
{
    switch (type)
    {
    case GL_DEBUG_TYPE_ERROR: return "GL_DEBUG_TYPE_ERROR";
    case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: return "GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR";
    case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR: return "GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR";
    case GL_DEBUG_TYPE_PORTABILITY: return "GL_DEBUG_TYPE_PORTABILITY";
    case GL_DEBUG_TYPE_PERFORMANCE: return "GL_DEBUG_TYPE_PERFORMANCE";
    case GL_DEBUG_TYPE_OTHER: return "GL_DEBUG_TYPE_OTHER";
    default: return "(unknown)";
    }
}

inline const char* DebugSeverityToString(GLenum severity)
{
    switch (severity)
    {
    case GL_DEBUG_SEVERITY_HIGH: return "GL_DEBUG_SEVERITY_HIGH";
    case GL_DEBUG_SEVERITY_MEDIUM: return "GL_DEBUG_SEVERITY_MEDIUM";
    case GL_DEBUG_SEVERITY_LOW: return "GL_DEBUG_SEVERITY_LOW";
    case GL_DEBUG_SEVERITY_NOTIFICATION: return "GL_DEBUG_SEVERITY_NOTIFICATION";
    default: return "(unknown)";
    }
}

inline std::string FormatGLDebugCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message)
{
    std::stringstream ss;
    ss << "OpenGL debug callback: {\n"
       << "\tsource = \"" << DebugSourceToString(source) << "\",\n"
       << "\ttype = \"" << DebugTypeToString(type) << "\",\n"
       << "\tid = " << id << ",\n"
       << "\tseverity = " << DebugSeverityToString(severity) << "\",\n"
       << "\tmessage = " << std::string(message, message + length) << "\n"
       << "}";
    return ss.str();
}

struct DebugVertex
{
    vec3 Position;
    vec4 Color;
};

struct DebugVertexBindingIndex
{
    enum Enum
    {
        DebugVerts,
        Count
    };
};

struct DebugVertexAttribIndex
{
    enum Enum
    {
        Position,
        Color,
        Count
    };
};

class DebugGeometry;
void swap(DebugGeometry& a, DebugGeometry& b);

class DebugGeometry
{
public:
    DebugGeometry()
        : VertexArray(0)
        , VertexBuffers{}
        , VertexBuffersSizeInBytes{}
        , IndirectDrawBuffer(0)
        , IndirectDrawBufferSizeInBytes(0)
    {
    }
    
    ~DebugGeometry()
    {
        glDeleteVertexArrays(1, &VertexArray);
        glDeleteBuffers((GLsizei)VertexBuffers.size(), VertexBuffers.data());
        glDeleteBuffers(1, &IndirectDrawBuffer);
    }

    DebugGeometry(const DebugGeometry&) = delete;
    DebugGeometry& operator=(const DebugGeometry&) = delete;

    DebugGeometry(DebugGeometry&& other)
        : DebugGeometry()
    {
        swap(*this, other);
    }

    DebugGeometry& operator=(DebugGeometry&& other)
    {
        swap(*this, other);
    }

    void Reset();

    void AddLine(const DebugVertex& start, const DebugVertex& end);
    void AddLine(const vec3& start, const vec3& end, const vec4& color)
    {
        AddLine(DebugVertex{ start, color }, DebugVertex{ end, color });
    }

    void AddTriangle(const DebugVertex& a, const DebugVertex& b, const DebugVertex& c);
    void AddTriangle(const vec3& a, const vec3& b, const vec3& c, const vec4& color)
    {
        AddTriangle(DebugVertex{ a, color }, DebugVertex{ b, color }, DebugVertex{ c, color });
    }

    void AddWireTriangle(const DebugVertex& a, const DebugVertex& b, const DebugVertex& c);
    void AddWireTriangle(const vec3& a, const vec3& b, const vec3& c, const vec4& color)
    {
        AddWireTriangle(DebugVertex{ a, color }, DebugVertex{ b, color }, DebugVertex{ c, color });
    }

    void AddWireSphere(const vec3& center, float radius, const vec4& color);
    
    void UpdateBuffers();

    std::array<std::vector<DebugVertex>, DebugVertexBindingIndex::Count> CPUVertexData;
    std::vector<GLDrawArraysIndirectCommand> CPUIndirectDrawBuffer;
    std::vector<GLenum> DrawPrimitiveTypes;

    GLuint VertexArray;
    std::array<GLuint, DebugVertexBindingIndex::Count> VertexBuffers;
    std::array<GLsizei, DebugVertexBindingIndex::Count> VertexBuffersSizeInBytes;
    GLuint IndirectDrawBuffer;
    GLsizei IndirectDrawBufferSizeInBytes;
};

inline void swap(DebugGeometry& a, DebugGeometry& b)
{
    using std::swap;
    
    swap(a.CPUVertexData, b.CPUVertexData);
    swap(a.CPUIndirectDrawBuffer, b.CPUIndirectDrawBuffer);
    swap(a.DrawPrimitiveTypes, b.DrawPrimitiveTypes);

    swap(a.VertexArray, b.VertexArray);
    swap(a.VertexBuffers, b.VertexBuffers);
    swap(a.VertexBuffersSizeInBytes, b.VertexBuffersSizeInBytes);
    swap(a.IndirectDrawBuffer, b.IndirectDrawBuffer);
    swap(a.IndirectDrawBufferSizeInBytes, b.IndirectDrawBufferSizeInBytes);
}

#endif // JUSTGL_DEBUG_H