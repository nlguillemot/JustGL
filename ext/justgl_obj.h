#ifndef JUSTGL_SCENEOBJECTS_H
#define JUSTGL_OBJ_H

#include "justgl.h"

#include <vector>
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
        glDeleteBuffers(MeshObjectVertexBindingIndex::Count, VertexBuffers);
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
    GLuint VertexBuffers[MeshObjectVertexBindingIndex::Count];
    GLuint IndexBuffer;
    GLuint IndirectDrawBuffer;

    // CPU data so you wanna do some other manipulations
    std::vector<float> CPUVertexBuffers[MeshObjectVertexBindingIndex::Count];
    std::vector<GLuint> CPUIndexBuffer;
    std::vector<std::string> GroupNames;
    std::vector<GLDrawElementsIndirectCommand> CPUIndirectDrawBuffer;
};

inline void swap(MeshObject& a, MeshObject& b)
{
    std::swap(a.VertexArray, b.VertexArray);
    for (int i = 0; i < sizeof(a.VertexBuffers) / sizeof(*a.VertexBuffers); i++)
    {
        std::swap(a.VertexBuffers[i], b.VertexBuffers[i]);
        std::swap(a.CPUVertexBuffers[i], b.CPUVertexBuffers[i]);
    }
    std::swap(a.IndexBuffer, b.IndexBuffer);
    std::swap(a.CPUIndexBuffer, b.CPUIndexBuffer);
    std::swap(a.IndirectDrawBuffer, b.IndirectDrawBuffer);
    std::swap(a.CPUIndirectDrawBuffer, b.CPUIndirectDrawBuffer);
    std::swap(a.GroupNames, b.GroupNames);
}

bool LoadObj(const char* filename, const char* mtlpath, MeshObject* pMesh, MaterialPalette* pPalette);

#endif // JUSTGL_OBJ_H