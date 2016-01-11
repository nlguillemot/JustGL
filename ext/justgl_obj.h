#ifndef JUSTGL_SCENEOBJECTS_H
#define JUSTGL_OBJ_H

#include "justgl.h"

#include <vector>
#include <array>
#include <string>

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

class MaterialPalette
{
public:
};

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

    GLuint VertexArray;
    std::array<GLuint, MeshObjectVertexBindingIndex::Count> VertexBuffers;
    GLuint IndexBuffer;
    GLuint IndirectDrawBuffer;

    // CPU data so you wanna do some other manipulations
    int PositionSize;
    int TexCoordSize;
    int NormalSize;

    std::array<std::vector<float>, MeshObjectVertexBindingIndex::Count> CPUVertexBuffers;
    std::array<int, MeshObjectVertexAttribIndex::Count> AttributeSizes;
    std::vector<GLuint> CPUIndexBuffer;
    std::vector<GLDrawElementsIndirectCommand> CPUIndirectDrawBuffer;

    // The group name of each draw call
    std::vector<std::string> GroupNames;
};

inline void swap(MeshObject& a, MeshObject& b)
{
    std::swap(a.VertexArray, b.VertexArray);
    std::swap(a.VertexBuffers, b.VertexBuffers);
    std::swap(a.IndexBuffer, b.IndexBuffer);
    std::swap(a.IndirectDrawBuffer, b.IndirectDrawBuffer);

    std::swap(a.CPUVertexBuffers, b.CPUVertexBuffers);
    std::swap(a.CPUIndexBuffer, b.CPUIndexBuffer);
    std::swap(a.CPUIndirectDrawBuffer, b.CPUIndirectDrawBuffer);
    
    std::swap(a.GroupNames, b.GroupNames);
}

bool LoadObj(const char* filename, const char* mtlpath, MeshObject* pMesh, MaterialPalette* pPaletteToAddTo);

#endif // JUSTGL_OBJ_H