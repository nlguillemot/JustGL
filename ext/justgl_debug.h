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

class DebugGeometry
{
public:
    DebugGeometry() = default;
    ~DebugGeometry()
    {
        glDeleteShader(VS);
        glDeleteShader(FS);
        glDeleteProgram(SP);
        glDeleteBuffers(1, &VBO);
        glDeleteVertexArrays(1, &VAO);
    }

    DebugGeometry(const DebugGeometry&) = delete;
    DebugGeometry& operator=(const DebugGeometry&) = delete;
    DebugGeometry(DebugGeometry&& other) = delete;
    DebugGeometry& operator=(DebugGeometry&& other) = delete;

    void Init();
    
    void NewFrame(const mat4& mvp);

    void AddLine(const vec3& start, const vec3& end, const vec4& color);
    void AddTriangle(const vec3& a, const vec3& b, const vec3& c, const vec4& color);
    void AddWireTriangle(const vec3& a, const vec3& b, const vec3& c, const vec4& color);
    void AddCircle(const vec3& center, float radius, const vec3& normal, const vec4& color);
    void AddWireSphere(const vec3& center, float radius, const vec4& color);
    void AddWireAABB(const vec3& minCorner, const vec3& maxCorner, const vec4& color);
    void AddWireArrow(const vec3& start, const vec3& end, const vec4& color);
    void AddFrustumFromMVP(const mat4& mvp, const vec4& color);
    void AddWireFrustumFromMVP(const mat4& mvp, const vec4& color);
    
    void Render();

    struct DebugVertex
    {
        vec4 Position;
        vec4 Color;
    };
    std::vector<DebugVertex> CPUVertexData;
    std::vector<GLDrawArraysIndirectCommand> CPUIndirectDrawBuffer;
    std::vector<GLenum> DrawPrimitiveTypes;

    mat4 MVP;

    GLuint VS = 0;
    GLuint FS = 0;
    GLuint SP = 0;
    GLuint VAO = 0;
    GLuint VBO = 0;
    GLsizei VBOSizeInBytes = 0;
};

#endif // JUSTGL_DEBUG_H