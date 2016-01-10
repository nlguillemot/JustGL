#ifndef JUSTGL_DEBUG_H
#define JUSTGL_DEBUG_H

#include "justgl.h"

#include <sstream>
#include <string>

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

std::string FormatGLError(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message)
{
    std::stringstream ss;
    ss << "OpenGL error: {\n"
       << "\tsource = \"" << DebugSourceToString(source) << "\",\n"
       << "\ttype = \"" << DebugTypeToString(type) << "\",\n"
       << "\tid = " << id << ",\n"
       << "\tseverity = " << DebugSeverityToString(severity) << "\",\n"
       << "\tmessage = " << std::string(message, message + length) << "\n"
       << "}";
    return ss.str();
}

#endif // JUSTGL_DEBUG_H