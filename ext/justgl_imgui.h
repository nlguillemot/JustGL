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

#ifndef JUSTGL_IMGUI_H
#define JUSTGL_IMGUI_H

#include "justgl.h"

#include <utility>

// Include imgui.h before including this
class ImGuiBinding
{
public:
    ImGuiBinding() = default;
    ~ImGuiBinding()
    {
        glDeleteTextures(1, &FontTexture);
        glDeleteShader(ImGuiVS);
        glDeleteShader(ImGuiFS);
        glDeleteProgram(ImGuiSP);
        glDeleteBuffers(1, &ImGuiVBO);
        glDeleteBuffers(1, &ImGuiEBO);
        glDeleteVertexArrays(1, &ImGuiVAO);
    }

    ImGuiBinding(const ImGuiBinding&) = delete;
    ImGuiBinding& operator=(const ImGuiBinding&) = delete;
    ImGuiBinding(ImGuiBinding&& other) = delete;
    ImGuiBinding& operator=(ImGuiBinding&& other) = delete;

    void Init();
    void HandleEvent(const Event* ev);
    void NewFrame();
    void Render();

    GLuint FontTexture = 0;
    GLuint ImGuiVS = 0;
    GLuint ImGuiFS = 0;
    GLuint ImGuiSP = 0;
    GLuint ImGuiVBO = 0;
    GLuint ImGuiEBO = 0;
    GLuint ImGuiVAO = 0;

    uint64_t LastTicks = 0;

    int VBOSizeInBytes = 0;
    int EBOSizeInBytes = 0;
};

inline void ImGuiBinding::Init()
{
    GLint lastTexture, lastArrayBuffer, lastVertexArray;
    glGetIntegerv(GL_TEXTURE_BINDING_2D, &lastTexture);
    glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &lastArrayBuffer);
    glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &lastVertexArray);

    ImGuiIO& io = ImGui::GetIO();

    io.KeyMap[ImGuiKey_Tab] = KC_Tab;
    io.KeyMap[ImGuiKey_LeftArrow] = KC_Left;
    io.KeyMap[ImGuiKey_RightArrow] = KC_Right;
    io.KeyMap[ImGuiKey_UpArrow] = KC_Up;
    io.KeyMap[ImGuiKey_DownArrow] = KC_Down;
    io.KeyMap[ImGuiKey_PageUp] = KC_PageUp;
    io.KeyMap[ImGuiKey_PageDown] = KC_PageDown;
    io.KeyMap[ImGuiKey_Home] = KC_Home;
    io.KeyMap[ImGuiKey_End] = KC_End;
    io.KeyMap[ImGuiKey_Delete] = KC_Delete;
    io.KeyMap[ImGuiKey_Backspace] = KC_Backspace;
    io.KeyMap[ImGuiKey_Enter] = KC_Return;
    io.KeyMap[ImGuiKey_Escape] = KC_Escape;
    io.KeyMap[ImGuiKey_A] = KC_A;
    io.KeyMap[ImGuiKey_C] = KC_C;
    io.KeyMap[ImGuiKey_V] = KC_V;
    io.KeyMap[ImGuiKey_X] = KC_X;
    io.KeyMap[ImGuiKey_Y] = KC_Y;
    io.KeyMap[ImGuiKey_Z] = KC_Z;

    unsigned char* fontPixels;
    int fontWidth, fontHeight;
    io.Fonts->GetTexDataAsAlpha8(&fontPixels, &fontWidth, &fontHeight);

    glGenTextures(1, &FontTexture);
    glBindTexture(GL_TEXTURE_2D, FontTexture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexStorage2D(GL_TEXTURE_2D, 1, GL_R8, fontWidth, fontHeight);
    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, fontWidth, fontHeight, GL_RED, GL_UNSIGNED_BYTE, fontPixels);

    io.Fonts->TexID = (void*)(intptr_t)FontTexture;

    const GLchar *vs_src =
        "#version 430\n"
        "layout(location = 0) uniform vec2 Size;\n"
        "layout(location = 0) in vec2 Position;\n"
        "layout(location = 1) in vec2 TexCoord;\n"
        "layout(location = 2) in vec4 Color;\n"
        "out vec2 fTexCoord;\n"
        "out vec4 fColor;\n"
        "void main()\n"
        "{\n"
        "    fTexCoord = TexCoord;\n"
        "    fColor = Color;\n"
        "    gl_Position = vec4(2.0 * Position.x / Size.x - 1.0, 1.0 - 2.0 * Position.y / Size.y, 0.0, 1.0);\n"
        "}\n";

    const GLchar* fs_src =
        "#version 430\n"
        "layout(binding = 0) uniform sampler2D Texture;\n"
        "in vec2 fTexCoord;\n"
        "in vec4 fColor;\n"
        "out vec4 FragColor;\n"
        "void main()\n"
        "{\n"
        "    FragColor = fColor * texture(Texture, fTexCoord.st).rrrr;\n"
        "}\n";

    ImGuiSP = glCreateProgram();
    ImGuiVS = glCreateShader(GL_VERTEX_SHADER);
    ImGuiFS = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(ImGuiVS, 1, &vs_src, 0);
    glShaderSource(ImGuiFS, 1, &fs_src, 0);
    glCompileShader(ImGuiVS);
    glCompileShader(ImGuiFS);
    glAttachShader(ImGuiSP, ImGuiVS);
    glAttachShader(ImGuiSP, ImGuiFS);
    glLinkProgram(ImGuiSP);

    glGenBuffers(1, &ImGuiVBO);
    glGenBuffers(1, &ImGuiEBO);

    glGenVertexArrays(1, &ImGuiVAO);
    glBindVertexArray(ImGuiVAO);
    glBindBuffer(GL_ARRAY_BUFFER, ImGuiVBO);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(ImDrawVert), (GLvoid*)offsetof(ImDrawVert, pos));
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(ImDrawVert), (GLvoid*)offsetof(ImDrawVert, uv));
    glVertexAttribPointer(2, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(ImDrawVert), (GLvoid*)offsetof(ImDrawVert, col));
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ImGuiEBO);
    glBindVertexArray(0);

    // Restore modified GL state
    glBindTexture(GL_TEXTURE_2D, lastTexture);
    glBindBuffer(GL_ARRAY_BUFFER, lastArrayBuffer);
    glBindVertexArray(lastVertexArray);
}

inline void ImGuiBinding::HandleEvent(const Event* ev)
{
    ImGuiIO& io = ImGui::GetIO();

    if (ev->Type == ET_MouseButton)
    {
        if (ev->Button.Button == MB_Left)
        {
            io.MouseDown[0] = ev->Button.Pressed != 0;
        }
        else if (ev->Button.Button == MB_Right)
        {
            io.MouseDown[1] = ev->Button.Pressed != 0;
        }
        else if (ev->Button.Button == MB_Middle)
        {
            io.MouseDown[2] = ev->Button.Pressed != 0;
        }
    }
    else if (ev->Type == ET_MouseScroll)
    {
        io.MouseWheel += ev->Scroll.ScrollDelta > 0 ? +1.0f : -1.0f;
    }
    else if (ev->Type == ET_MouseMove)
    {
        int dpi = GetCurrentMonitorDPI();
        int dpiScale = dpi / 96;

        io.MousePos.x = (float)(ev->Move.X / dpiScale);
        io.MousePos.y = (float)(ev->Move.Y / dpiScale);
    }
    else if (ev->Type == ET_Key)
    {
        if (ev->Key.Key < 256)
        {
            io.KeysDown[ev->Key.Key] = ev->Key.Pressed != 0;
        }
    }
    else if (ev->Type == ET_Char)
    {
        if (ev->Char.CharCode > 0 && ev->Char.CharCode < 0x10000)
        {
            io.AddInputCharacter(ev->Char.CharCode);
        }
    }
}

inline void ImGuiBinding::NewFrame()
{
    ImGuiIO& io = ImGui::GetIO();

    int w, h;
    GetWindowClientAreaSize(&w, &h);
    io.DisplaySize = ImVec2((float)w, (float)h);

    uint64_t ticks = GetCurrentTicks();
    uint64_t deltaTicks = LastTicks == 0 ? 0 : ticks - LastTicks;
    io.DeltaTime = (float)deltaTicks / GetTicksPerSecond();
    LastTicks = ticks;

    ImGui::NewFrame();
}

inline void ImGuiBinding::Render()
{
    ImGui::Render();

    // Backup GL state
    GLint lastProgram; glGetIntegerv(GL_CURRENT_PROGRAM, &lastProgram);
    GLint lastActiveTexture; glGetIntegerv(GL_ACTIVE_TEXTURE, &lastActiveTexture);
    GLint lastTexture; glGetIntegerv(GL_TEXTURE_BINDING_2D, &lastTexture);
    GLint lastArrayBuffer; glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &lastArrayBuffer);
    GLint lastElementArrayBuffer; glGetIntegerv(GL_ELEMENT_ARRAY_BUFFER_BINDING, &lastElementArrayBuffer);
    GLint lastVertexArray; glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &lastVertexArray);
    GLint lastBlendSrc; glGetIntegerv(GL_BLEND_SRC, &lastBlendSrc);
    GLint lastBlendDst; glGetIntegerv(GL_BLEND_DST, &lastBlendDst);
    GLint lastBlendEquationRGB; glGetIntegerv(GL_BLEND_EQUATION_RGB, &lastBlendEquationRGB);
    GLint lastBlendEquationAlpha; glGetIntegerv(GL_BLEND_EQUATION_ALPHA, &lastBlendEquationAlpha);
    GLint lastViewport[4]; glGetIntegerv(GL_VIEWPORT, lastViewport);
    GLint lastScissor[4]; glGetIntegerv(GL_SCISSOR_BOX, lastScissor);
    GLboolean lastEnableBlend = glIsEnabled(GL_BLEND);
    GLboolean lastEnableCullFace = glIsEnabled(GL_CULL_FACE);
    GLboolean lastEnableDepthTest = glIsEnabled(GL_DEPTH_TEST);
    GLboolean lastEnableScissorTest = glIsEnabled(GL_SCISSOR_TEST);

    // Setup render state: alpha-blending enabled, no face culling, no depth testing, scissor enabled
    glEnable(GL_BLEND);
    glBlendEquation(GL_FUNC_ADD);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDisable(GL_CULL_FACE);
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_SCISSOR_TEST);
    glActiveTexture(GL_TEXTURE0);

    ImDrawData* drawData = ImGui::GetDrawData();

    ImGuiIO& io = ImGui::GetIO();
    
    int dpi = GetCurrentMonitorDPI();
    int dpiScale = dpi / 96;

    // Setup viewport, orthographic projection matrix
    glViewport(0, 0, (GLsizei)io.DisplaySize.x, (GLsizei)io.DisplaySize.y);
    glUseProgram(ImGuiSP);
    glProgramUniform2f(ImGuiSP, 0, io.DisplaySize.x / dpiScale, io.DisplaySize.y / dpiScale);
    glBindVertexArray(ImGuiVAO);

    int requiredVBOSize = 0, requiredEBOSize = 0;
    for (int n = 0; n < drawData->CmdListsCount; n++)
    {
        requiredVBOSize += drawData->CmdLists[n]->VtxBuffer.size() * sizeof(ImDrawVert);
        requiredEBOSize += drawData->CmdLists[n]->IdxBuffer.size() * sizeof(ImDrawIdx);
    }

    if (requiredVBOSize > VBOSizeInBytes)
    {
        glBindBuffer(GL_ARRAY_BUFFER, ImGuiVBO);
        glBufferData(GL_ARRAY_BUFFER, requiredVBOSize, NULL, GL_DYNAMIC_DRAW);
        VBOSizeInBytes = requiredVBOSize;
    }

    if (requiredEBOSize > EBOSizeInBytes)
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ImGuiEBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, requiredEBOSize, NULL, GL_DYNAMIC_DRAW);
        EBOSizeInBytes = requiredEBOSize;
    }

    int vboOffset = 0;
    int eboOffset = 0;

    glBindBuffer(GL_ARRAY_BUFFER, ImGuiVBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ImGuiEBO);

    for (int n = 0; n < drawData->CmdListsCount; n++)
    {
        const ImDrawList* cmdList = drawData->CmdLists[n];

        glBufferSubData(GL_ARRAY_BUFFER, vboOffset, cmdList->VtxBuffer.size() * sizeof(ImDrawVert), &cmdList->VtxBuffer.front());
        glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, eboOffset, cmdList->IdxBuffer.size() * sizeof(ImDrawIdx), &cmdList->IdxBuffer.front());

        int cmdIdxBufferOffset = 0;
        for (const ImDrawCmd* pcmd = cmdList->CmdBuffer.begin(); pcmd != cmdList->CmdBuffer.end(); pcmd++)
        {
            if (pcmd->UserCallback)
            {
                pcmd->UserCallback(cmdList, pcmd);
            }
            else
            {
                glBindTexture(GL_TEXTURE_2D, (GLuint)(intptr_t)pcmd->TextureId);
                glScissor(
                    (int)pcmd->ClipRect.x * dpiScale,
                    (int)(io.DisplaySize.y - pcmd->ClipRect.w * dpiScale),
                    (int)(pcmd->ClipRect.z - pcmd->ClipRect.x) * dpiScale, 
                    (int)(pcmd->ClipRect.w - pcmd->ClipRect.y) * dpiScale);
                glDrawElementsBaseVertex(GL_TRIANGLES, (GLsizei)pcmd->ElemCount, GL_UNSIGNED_SHORT, (GLvoid*)(intptr_t)eboOffset, vboOffset / sizeof(ImDrawVert));
            }
            eboOffset += pcmd->ElemCount * sizeof(ImDrawIdx);
        }

        vboOffset += cmdList->VtxBuffer.size() * sizeof(ImDrawVert);
    }

    // Restore modified GL state
    glUseProgram(lastProgram);
    glBindTexture(GL_TEXTURE_2D, lastTexture);
    glActiveTexture(lastActiveTexture);
    glBindBuffer(GL_ARRAY_BUFFER, lastArrayBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, lastElementArrayBuffer);
    glBindVertexArray(lastVertexArray);
    glBlendEquationSeparate(lastBlendEquationRGB, lastBlendEquationAlpha);
    glBlendFunc(lastBlendSrc, lastBlendDst);
    if (lastEnableBlend) glEnable(GL_BLEND); else glDisable(GL_BLEND);
    if (lastEnableCullFace) glEnable(GL_CULL_FACE); else glDisable(GL_CULL_FACE);
    if (lastEnableDepthTest) glEnable(GL_DEPTH_TEST); else glDisable(GL_DEPTH_TEST);
    if (lastEnableScissorTest) glEnable(GL_SCISSOR_TEST); else glDisable(GL_SCISSOR_TEST);
    glViewport(lastViewport[0], lastViewport[1], lastViewport[2], lastViewport[3]);
    glScissor(lastScissor[0], lastScissor[1], lastScissor[2], lastScissor[3]);
}

#endif // JUSTGL_IMGUI_H