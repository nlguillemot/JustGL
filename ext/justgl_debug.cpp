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

void DebugGeometry::Reset()
{
    for (auto& v : CPUVertexData)
    {
        v.clear();
    }

    CPUIndirectDrawBuffer.clear();
    DrawPrimitiveTypes.clear();
}

void DebugGeometry::AddLine(const DebugVertex& start, const DebugVertex& end)
{
    if (CPUIndirectDrawBuffer.empty() ||
        DrawPrimitiveTypes[CPUIndirectDrawBuffer.size() - 1] != GL_LINES)
    {
        GLDrawArraysIndirectCommand cmd;
        cmd.count = 2;
        cmd.primCount = 1;
        cmd.first = (GLuint)CPUVertexData[DebugVertexBindingIndex::DebugVerts].size();
        cmd.baseInstance = 0;

        CPUIndirectDrawBuffer.push_back(cmd);
        DrawPrimitiveTypes.push_back(GL_LINES);
    }
    else
    {
        CPUIndirectDrawBuffer.back().count += 2;
    }

    CPUVertexData[DebugVertexBindingIndex::DebugVerts].push_back(start);
    CPUVertexData[DebugVertexBindingIndex::DebugVerts].push_back(end);
}

void DebugGeometry::AddTriangle(const DebugVertex& a, const DebugVertex& b, const DebugVertex& c)
{
    if (CPUIndirectDrawBuffer.empty() ||
        DrawPrimitiveTypes[CPUIndirectDrawBuffer.size() - 1] != GL_TRIANGLES)
    {
        GLDrawArraysIndirectCommand cmd;
        cmd.count = 3;
        cmd.primCount = 1;
        cmd.first = (GLuint)CPUVertexData[DebugVertexBindingIndex::DebugVerts].size();
        cmd.baseInstance = 0;

        CPUIndirectDrawBuffer.push_back(cmd);
        DrawPrimitiveTypes.push_back(GL_TRIANGLES);
    }
    else
    {
        CPUIndirectDrawBuffer.back().count += 3;
    }

    CPUVertexData[DebugVertexBindingIndex::DebugVerts].push_back(a);
    CPUVertexData[DebugVertexBindingIndex::DebugVerts].push_back(b);
    CPUVertexData[DebugVertexBindingIndex::DebugVerts].push_back(c);
}

void DebugGeometry::AddWireTriangle(const DebugVertex& a, const DebugVertex& b, const DebugVertex& c)
{
    AddLine(a, b);
    AddLine(b, c);
    AddLine(c, a);
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

void DebugGeometry::UpdateBuffers()
{
    for (int bufIdx = 0; bufIdx < DebugVertexBindingIndex::Count; bufIdx++)
    {
        if (!VertexBuffers[bufIdx])
        {
            glGenBuffers(1, &VertexBuffers[bufIdx]);
        }

        GLsizei sizeInBytes = (GLsizei)CPUVertexData[bufIdx].size() * sizeof(CPUVertexData[bufIdx][0]);
        if (sizeInBytes > 0)
        {
            glBindBuffer(GL_ARRAY_BUFFER, VertexBuffers[bufIdx]);
            if (VertexBuffersSizeInBytes[bufIdx] < sizeInBytes)
            {
                glBufferData(GL_ARRAY_BUFFER, sizeInBytes, CPUVertexData[bufIdx].data(), GL_STREAM_DRAW);
                VertexBuffersSizeInBytes[bufIdx] = sizeInBytes;
            }
            else
            {
                glBufferSubData(GL_ARRAY_BUFFER, 0, sizeInBytes, CPUVertexData[bufIdx].data());
            }
        }
    }

    if (!IndirectDrawBuffer)
    {
        glGenBuffers(1, &IndirectDrawBuffer);
    }

    if (!CPUIndirectDrawBuffer.empty())
    {
        GLsizei sizeInBytes = (GLsizei)CPUIndirectDrawBuffer.size() * sizeof(CPUIndirectDrawBuffer[0]);
        glBindBuffer(GL_DRAW_INDIRECT_BUFFER, IndirectDrawBuffer);
        if (IndirectDrawBufferSizeInBytes < sizeInBytes)
        {
            glBufferData(GL_DRAW_INDIRECT_BUFFER, sizeInBytes, CPUIndirectDrawBuffer.data(), GL_STREAM_DRAW);
            IndirectDrawBufferSizeInBytes = sizeInBytes;
        }
        else
        {
            glBufferSubData(GL_DRAW_INDIRECT_BUFFER, 0, sizeInBytes, CPUIndirectDrawBuffer.data());
        }
    }

    if (!VertexArray)
    {
        glGenVertexArrays(1, &VertexArray);
        
        glBindVertexArray(VertexArray);

        glBindVertexBuffer(DebugVertexBindingIndex::DebugVerts, VertexBuffers[DebugVertexBindingIndex::DebugVerts], 0, sizeof(DebugVertex));

        glVertexAttribFormat(DebugVertexAttribIndex::Position, (GLint)size(DebugVertex().Position), GL_FLOAT, GL_FALSE, offsetof(DebugVertex, Position));
        glVertexAttribFormat(DebugVertexAttribIndex::Color, (GLint)size(DebugVertex().Color), GL_FLOAT, GL_FALSE, offsetof(DebugVertex, Color));

        glVertexAttribBinding(DebugVertexAttribIndex::Position, DebugVertexBindingIndex::DebugVerts);
        glVertexAttribBinding(DebugVertexAttribIndex::Color, DebugVertexBindingIndex::DebugVerts);

        glEnableVertexAttribArray(DebugVertexAttribIndex::Position);
        glEnableVertexAttribArray(DebugVertexAttribIndex::Color);

        glBindVertexArray(0);
    }
}