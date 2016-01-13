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

#ifndef JUSTGL_OBJ_H
#define JUSTGL_OBJ_H

#include "justgl.h"
#include "justgl_image.h"

#include <vector>
#include <array>
#include <string>
#include <map>

struct MeshObjectVertexBindingIndex
{
    enum Enum
    {
        Position,
        TexCoord,
        Normal,
        Count
    };
};

struct MeshObjectVertexAttribIndex
{
    enum Enum
    {
        Position,
        TexCoord,
        Normal,
        Count
    };
};

class MaterialPalette;
void swap(MaterialPalette& a, MaterialPalette& b);

class Material
{
public:
    std::string LibraryFilename;
    std::string Name;

    // Material color and illumination
    std::array<float, 3> Ka; // ambient color
    std::array<float, 3> Kd; // diffuse color
    std::array<float, 3> Ks; // specular color
    std::array<float, 3> Ke; // emissive color
    std::array<float, 3> Tf; // transmission factor. The color of the atmosphere. 
    int illum; // illumination model
    float d; // "dissolve factor" - 0.0 = transparent, 1.0 = opaque. opposite of Tr
    float Ns; // specular exponent
    int sharpness; // sharpness of reflections from 0 to 1000 (Default 60). high value = clear reflection.
    float Ni; // optical desntiy aka index of refraction. from 0.001 to 10. 1.0 means light doesn't bend.

    // Texture maps. Use this to index into the material palette's textures.
    // the index is -1 if the texture is not present
    int map_Ka; // ambient color texture. multiply this by Ka
    int map_Kd; // diffuse color texture. multiply this by Kd
    int map_Ks; // specular color texture. multiply this by Ks
    int map_Ns; // specular exponent texture. multiply this by Ns
    int map_d; // dissolve texture. multiply this by d.
    int disp; // displacement texture
    int decal; // selectively replace material color with texture color
    int bump; // bump texture for bump maps

    // Reflection maps. Use this to index into the material palette's textures.
    // the index is -1 if the texture is not present
    int refl_sphere; // sphere reflection map
    int refl_cube; // cube reflection map
};

class MaterialPalette
{
public:
    MaterialPalette()
    {
    }

    ~MaterialPalette()
    {
        glDeleteTextures((GLsizei)Textures.size(), Textures.data());
    }

    MaterialPalette(const MaterialPalette&) = delete;
    MaterialPalette& operator=(const MaterialPalette&) = delete;

    MaterialPalette(MaterialPalette&& other)
        : MaterialPalette()
    {
        swap(*this, other);
    }

    MaterialPalette& operator=(MaterialPalette&& other)
    {
        swap(*this, other);
    }

    std::vector<GLuint> Textures;
    std::vector<Image> Images;
    std::vector<std::vector<std::string>> TextureFilenames; // One texture can have >1 filename eg. if it's a cubemap

    std::vector<Material> Materials;
};

inline void swap(MaterialPalette& a, MaterialPalette& b)
{
    using std::swap;

    swap(a.Textures, b.Textures);
    swap(a.Images, b.Images);
    swap(a.TextureFilenames, b.TextureFilenames);

    swap(a.Materials, b.Materials);
}

class MeshObject;
void swap(MeshObject& a, MeshObject& b);

// All wrapped up and good to go for rendering
class MeshObject
{
public:
    MeshObject()
        : VertexArray(0)
        , VertexBuffers{}
        , IndexBuffer(0)
        , IndirectDrawBuffer(0)
        , AttributeSizes{}
    {
    }

    ~MeshObject()
    {
        glDeleteVertexArrays(1, &VertexArray);
        glDeleteBuffers(MeshObjectVertexBindingIndex::Count, VertexBuffers.data());
        glDeleteBuffers(1, &IndexBuffer);
        glDeleteBuffers(1, &IndirectDrawBuffer);
    }

    MeshObject(const MeshObject&) = delete;
    MeshObject& operator=(const MeshObject&) = delete;

    MeshObject(MeshObject&& other)
        : MeshObject()
    {
        swap(*this, other);
    }

    MeshObject& operator=(MeshObject&& other)
    {
        swap(*this, other);
    }

    // GPU data for rendering
    GLuint VertexArray;
    std::array<GLuint, MeshObjectVertexBindingIndex::Count> VertexBuffers;
    GLuint IndexBuffer;
    GLuint IndirectDrawBuffer;

    // CPU data so you wanna do some other manipulations
    std::array<std::vector<float>, MeshObjectVertexBindingIndex::Count> CPUVertexBuffers;
    std::array<int, MeshObjectVertexAttribIndex::Count> AttributeSizes;
    std::vector<GLuint> CPUIndexBuffer;
    std::vector<GLDrawElementsIndirectCommand> CPUIndirectDrawBuffer;

    // These vectors are associated 1-1 with the draw calls
    std::vector<std::string> GroupNames;
    std::vector<int> GroupMaterialIDs;
};

inline void swap(MeshObject& a, MeshObject& b)
{
    using std::swap;

    swap(a.VertexArray, b.VertexArray);
    swap(a.VertexBuffers, b.VertexBuffers);
    swap(a.IndexBuffer, b.IndexBuffer);
    swap(a.IndirectDrawBuffer, b.IndirectDrawBuffer);

    swap(a.CPUVertexBuffers, b.CPUVertexBuffers);
    swap(a.AttributeSizes, b.AttributeSizes);
    swap(a.CPUIndexBuffer, b.CPUIndexBuffer);
    swap(a.CPUIndirectDrawBuffer, b.CPUIndirectDrawBuffer);
    
    swap(a.GroupNames, b.GroupNames);
    swap(a.GroupMaterialIDs, b.GroupMaterialIDs);
}

bool LoadObj(const char* filename, const char* mtlpath, MeshObject* pMesh, MaterialPalette* pPaletteToAddTo);

#endif // JUSTGL_OBJ_H