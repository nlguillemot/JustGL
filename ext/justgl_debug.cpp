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

#include "justgl_debug.h"

void DebugGeometry::Init()
{
    GLint lastArrayBuffer, lastVertexArray;
    glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &lastArrayBuffer);
    glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &lastVertexArray);

    const GLchar *vs_src =
        "#version 430\n"
        "layout(location = 0) in vec4 Position;\n"
        "layout(location = 1) in vec4 Color;\n"
        "out vec4 fColor;\n"
        "void main()\n"
        "{\n"
        "    fColor = Color;\n"
        "    gl_Position = Position;\n"
        "}\n";

    const GLchar* fs_src =
        "#version 430\n"
        "in vec4 fColor;\n"
        "out vec4 FragColor;\n"
        "void main()\n"
        "{\n"
        "    FragColor = fColor;\n"
        "}\n";

    SP = glCreateProgram();
    VS = glCreateShader(GL_VERTEX_SHADER);
    FS = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(VS, 1, &vs_src, 0);
    glShaderSource(FS, 1, &fs_src, 0);
    glCompileShader(VS);
    glCompileShader(FS);
    glAttachShader(SP, VS);
    glAttachShader(SP, FS);
    glLinkProgram(SP);

    glGenBuffers(1, &VBO);

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 8 * sizeof(float), 0);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (GLvoid*)(4 * sizeof(float)));
    glBindVertexArray(0);

    // Restore modified GL state
    glBindBuffer(GL_ARRAY_BUFFER, lastArrayBuffer);
    glBindVertexArray(lastVertexArray);
}

void DebugGeometry::NewFrame(const mat4& mvp)
{
    CPUVertexData.clear();
    CPUIndirectDrawBuffer.clear();
    DrawPrimitiveTypes.clear();
    MVP = mvp;
}

void DebugGeometry::AddLine(const vec3& start, const vec3& end, const vec4& color)
{
    if (CPUIndirectDrawBuffer.empty() ||
        DrawPrimitiveTypes[CPUIndirectDrawBuffer.size() - 1] != GL_LINES)
    {
        GLDrawArraysIndirectCommand cmd;
        cmd.count = 2;
        cmd.primCount = 1;
        cmd.first = (GLuint)CPUVertexData.size();
        cmd.baseInstance = 0;

        CPUIndirectDrawBuffer.push_back(cmd);
        DrawPrimitiveTypes.push_back(GL_LINES);
    }
    else
    {
        CPUIndirectDrawBuffer.back().count += 2;
    }

    CPUVertexData.push_back({ MVP * vec4(start, 1.0f), color });
    CPUVertexData.push_back({ MVP * vec4(end, 1.0f), color });
}

void DebugGeometry::AddTriangle(const vec3& a, const vec3& b, const vec3& c, const vec4& color)
{
    if (CPUIndirectDrawBuffer.empty() ||
        DrawPrimitiveTypes[CPUIndirectDrawBuffer.size() - 1] != GL_TRIANGLES)
    {
        GLDrawArraysIndirectCommand cmd;
        cmd.count = 3;
        cmd.primCount = 1;
        cmd.first = (GLuint)CPUVertexData.size();
        cmd.baseInstance = 0;

        CPUIndirectDrawBuffer.push_back(cmd);
        DrawPrimitiveTypes.push_back(GL_TRIANGLES);
    }
    else
    {
        CPUIndirectDrawBuffer.back().count += 3;
    }

    CPUVertexData.push_back({MVP * vec4(a, 1.0f), color });
    CPUVertexData.push_back({MVP * vec4(b, 1.0f), color });
    CPUVertexData.push_back({MVP * vec4(c, 1.0f), color });
}

void DebugGeometry::AddWireTriangle(const vec3& a, const vec3& b, const vec3& c, const vec4& color)
{
    AddLine(a, b, color);
    AddLine(b, c, color);
    AddLine(c, a, color);
}

void DebugGeometry::AddCircle(const vec3& center, float radius, const vec3& normal, const vec4& color)
{
    int nSlices = 10;

    vec3 t, b;
    coordinateSystem(normalize(normal), t, b);

    vec3 lastDir;
    for (int slice = 0; slice <= nSlices; slice++)
    {
        float c = cos(6.28318530718f * slice / nSlices);
        float s = sin(6.28318530718f * slice / nSlices);

        vec3 dir = radius * (t * c + b * s);
        if (slice != 0)
        {
            AddLine(center + lastDir, center + dir, color);
        }

        lastDir = dir;
    }
}

void DebugGeometry::AddWireSphere(const vec3& center, float radius, const vec4& color)
{
    int nRings = 10; // space separations
    int nSlices = 10; // angle separations

    float lastRingY, lastRingRadius;
    for (int r = 0; r <= nRings; r++)
    {
        float ringY = -radius + 2.0f * radius * r / nRings;
        float ringRadius = sqrt(radius * radius - ringY * ringY);
        float lastSliceX, lastSliceZ;
        for (int s = 0; s <= nSlices; s++)
        {
            float sliceX = ringRadius * cos(6.28318530718f * s / nSlices);
            float sliceZ = ringRadius * sin(6.28318530718f * s / nSlices);

            if (r != 0)
            {
                float lastRingSliceX = lastRingRadius * cos(6.28318530718f * s / nSlices);
                float lastRingSliceZ = lastRingRadius * sin(6.28318530718f * s / nSlices);

                AddLine(
                    center + vec3(lastRingSliceX, lastRingY, lastRingSliceZ),
                    center + vec3(sliceX, ringY, sliceZ),
                    color);
            }

            if (s != 0)
            {
                AddLine(
                    center + vec3(lastSliceX, ringY, lastSliceZ), 
                    center + vec3(sliceX, ringY, sliceZ),
                    color);
            }

            lastSliceX = sliceX;
            lastSliceZ = sliceZ;
        }
        lastRingY = ringY;
        lastRingRadius = ringRadius;
    }
}

void DebugGeometry::AddWireAABB(const vec3& minCorner, const vec3& maxCorner, const vec4& color)
{
    vec3 bottom[] = {
        minCorner,
        vec3(minCorner.x, minCorner.y, maxCorner.z),
        vec3(maxCorner.x, minCorner.y, minCorner.z),
        vec3(maxCorner.x, minCorner.y, maxCorner.z)
    };

    vec3 top[] = {
        maxCorner,
        vec3(maxCorner.x, maxCorner.y, minCorner.z),
        vec3(minCorner.x, maxCorner.y, maxCorner.z),
        vec3(minCorner.x, maxCorner.y, minCorner.z)
    };

    AddLine(bottom[0], bottom[1], color);
    AddLine(bottom[0], bottom[2], color);
    AddLine(bottom[1], bottom[3], color);
    AddLine(bottom[2], bottom[3], color);

    AddLine(top[0], top[1], color);
    AddLine(top[0], top[2], color);
    AddLine(top[1], top[3], color);
    AddLine(top[2], top[3], color);

    AddLine(bottom[0], top[3], color);
    AddLine(bottom[1], top[2], color);
    AddLine(bottom[2], top[1], color);
    AddLine(bottom[3], top[0], color);
}

void DebugGeometry::AddWireArrow(const vec3& start, const vec3& end, const vec4& color)
{
    vec3 t, b;
    coordinateSystem(normalize(start - end), t, b);
    t = normalize(t + start - end);
    b = normalize(b + start - end);
    float arrowheadLen = length(start - end) * 0.1f;
    AddLine(start, end, color);
    AddLine(end, end + t * arrowheadLen, color);
    AddLine(end, end + b * arrowheadLen, color);
}

void DebugGeometry::AddFrustumFromMVP(const mat4& mvp, const vec4& color)
{
    mat4 inv = inverse(mvp);
    vec4 cs[] = {
        inv * vec4(-1, +1, -1, +1), // left up near
        inv * vec4(+1, +1, -1, +1), // right up near
        inv * vec4(-1, -1, -1, +1), // left down near
        inv * vec4(+1, -1, -1, +1), // right down near
        inv * vec4(-1, +1, +1, +1), // left up far
        inv * vec4(+1, +1, +1, +1), // right up far
        inv * vec4(-1, -1, +1, +1), // left down far
        inv * vec4(+1, -1, +1, +1), // right down far
    };

    for (vec4& c : cs)
    {
        c.xyz() /= c.w;
    }

    AddTriangle(cs[0].xyz(), cs[2].xyz(), cs[1].xyz(), color);
    AddTriangle(cs[2].xyz(), cs[3].xyz(), cs[1].xyz(), color);
    AddTriangle(cs[0].xyz(), cs[5].xyz(), cs[4].xyz(), color);
    AddTriangle(cs[0].xyz(), cs[1].xyz(), cs[5].xyz(), color);
    AddTriangle(cs[1].xyz(), cs[7].xyz(), cs[5].xyz(), color);
    AddTriangle(cs[1].xyz(), cs[3].xyz(), cs[7].xyz(), color);
    AddTriangle(cs[3].xyz(), cs[6].xyz(), cs[7].xyz(), color);
    AddTriangle(cs[3].xyz(), cs[2].xyz(), cs[6].xyz(), color);
    AddTriangle(cs[0].xyz(), cs[4].xyz(), cs[6].xyz(), color);
    AddTriangle(cs[0].xyz(), cs[6].xyz(), cs[2].xyz(), color);
    AddTriangle(cs[5].xyz(), cs[7].xyz(), cs[4].xyz(), color);
    AddTriangle(cs[7].xyz(), cs[6].xyz(), cs[4].xyz(), color);
}

void DebugGeometry::AddWireFrustumFromMVP(const mat4& mvp, const vec4& color)
{
    mat4 inv = inverse(mvp);
    vec4 cs[] = {
        inv * vec4(-1, +1, -1, +1), // left up near
        inv * vec4(+1, +1, -1, +1), // right up near
        inv * vec4(-1, -1, -1, +1), // left down near
        inv * vec4(+1, -1, -1, +1), // right down near
        inv * vec4(-1, +1, +1, +1), // left up far
        inv * vec4(+1, +1, +1, +1), // right up far
        inv * vec4(-1, -1, +1, +1), // left down far
        inv * vec4(+1, -1, +1, +1), // right down far
    };

    for (vec4& c : cs)
    {
        c.xyz() /= c.w;
    }

    AddLine(cs[0].xyz(), cs[1].xyz(), color);
    AddLine(cs[1].xyz(), cs[3].xyz(), color);
    AddLine(cs[3].xyz(), cs[2].xyz(), color);
    AddLine(cs[2].xyz(), cs[0].xyz(), color);
    AddLine(cs[0].xyz(), cs[4].xyz(), color);
    AddLine(cs[1].xyz(), cs[5].xyz(), color);
    AddLine(cs[3].xyz(), cs[7].xyz(), color);
    AddLine(cs[2].xyz(), cs[6].xyz(), color);
    AddLine(cs[4].xyz(), cs[5].xyz(), color);
    AddLine(cs[5].xyz(), cs[7].xyz(), color);
    AddLine(cs[7].xyz(), cs[6].xyz(), color);
    AddLine(cs[6].xyz(), cs[4].xyz(), color);
}

void DebugGeometry::Render()
{
    GLint lastProgram; glGetIntegerv(GL_CURRENT_PROGRAM, &lastProgram);
    GLint lastArrayBuffer; glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &lastArrayBuffer);
    GLint lastVertexArray; glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &lastVertexArray);
    GLint lastDepthMask; glGetIntegerv(GL_DEPTH_WRITEMASK, &lastDepthMask);
    GLint lastBlendSrc; glGetIntegerv(GL_BLEND_SRC, &lastBlendSrc);
    GLint lastBlendDst; glGetIntegerv(GL_BLEND_DST, &lastBlendDst);
    GLint lastBlendEquationRGB; glGetIntegerv(GL_BLEND_EQUATION_RGB, &lastBlendEquationRGB);
    GLint lastBlendEquationAlpha; glGetIntegerv(GL_BLEND_EQUATION_ALPHA, &lastBlendEquationAlpha);
    GLboolean lastEnableBlend = glIsEnabled(GL_BLEND);
    GLboolean lastEnableDepthTest = glIsEnabled(GL_DEPTH_TEST);

    GLsizei sizeInBytes = (GLsizei)CPUVertexData.size() * sizeof(CPUVertexData[0]);
    if (sizeInBytes > 0)
    {
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        if (VBOSizeInBytes < sizeInBytes)
        {
            glBufferData(GL_ARRAY_BUFFER, sizeInBytes, CPUVertexData.data(), GL_STREAM_DRAW);
            VBOSizeInBytes = sizeInBytes;
        }
        else
        {
            glBufferSubData(GL_ARRAY_BUFFER, 0, sizeInBytes, CPUVertexData.data());
        }
    }

    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_FALSE);
    glEnable(GL_BLEND);
    glBlendEquation(GL_FUNC_ADD);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glBindVertexArray(VAO);
    glUseProgram(SP);
    
    for (size_t drawIdx = 0; drawIdx < CPUIndirectDrawBuffer.size(); drawIdx++)
    {
        const GLDrawArraysIndirectCommand& draw = CPUIndirectDrawBuffer[drawIdx];
        glDrawArraysInstancedBaseInstance(
            DrawPrimitiveTypes[drawIdx],
            draw.first,
            draw.count,
            draw.primCount,
            draw.baseInstance);
    }

    glUseProgram(lastProgram);
    glBindBuffer(GL_ARRAY_BUFFER, lastArrayBuffer);
    glBindVertexArray(lastVertexArray);
    glBlendEquationSeparate(lastBlendEquationRGB, lastBlendEquationAlpha);
    glBlendFunc(lastBlendSrc, lastBlendDst);
    glDepthMask(lastDepthMask);
    if (lastEnableBlend) glEnable(GL_BLEND); else glDisable(GL_BLEND);
    if (lastEnableDepthTest) glEnable(GL_DEPTH_TEST); else glDisable(GL_DEPTH_TEST);
}