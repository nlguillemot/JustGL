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

// CPU-side data so you can do extra manipulations
class CPUMeshObject
{
public:
    std::vector<float> VertexBuffers[MeshObjectVertexBindingIndex::Count];
    std::vector<GLuint> IndexBuffer;
    
    std::vector<std::string> GroupNames;
    std::vector<GLDrawElementsIndirectCommand> IndirectDrawBuffer;
};

class GPUMeshObject;
void swap(GPUMeshObject& a, GPUMeshObject& b);

// All wrapped up and good to go for rendering
class GPUMeshObject
{
public:
    GPUMeshObject()
        : VertexArray(0)
        , VertexBuffers{}
        , IndexBuffer(0)
        , IndirectDrawBuffer(0)
    {
    }

    ~GPUMeshObject()
    {
        glDeleteVertexArrays(1, &VertexArray);
        glDeleteBuffers(MeshObjectVertexBindingIndex::Count, VertexBuffers);
        glDeleteBuffers(1, &IndexBuffer);
        glDeleteBuffers(1, &IndirectDrawBuffer);
    }

    GPUMeshObject(const GPUMeshObject&) = delete;
    GPUMeshObject& operator=(const GPUMeshObject&) = delete;

    GPUMeshObject(GPUMeshObject&& other)
        : GPUMeshObject()
    {
        swap(*this, other);
    }

    GPUMeshObject& operator=(GPUMeshObject&& other)
    {
        swap(*this, other);
    }

    GLuint VertexArray;
    GLuint VertexBuffers[MeshObjectVertexBindingIndex::Count];
    GLuint IndexBuffer;
    GLuint IndirectDrawBuffer;
};

inline void swap(GPUMeshObject& a, GPUMeshObject& b)
{
    std::swap(a.VertexArray, b.VertexArray);
    for (int i = 0; i < sizeof(a.VertexBuffers) / sizeof(*a.VertexBuffers); i++)
    {
        std::swap(a.VertexBuffers[i], b.VertexBuffers[i]);
    }
    std::swap(a.IndexBuffer, b.IndexBuffer);
    std::swap(a.IndirectDrawBuffer, b.IndirectDrawBuffer);
}

bool LoadObj(const char* filename, CPUMeshObject* pCPUObject, GPUMeshObject* pGPUObject);

#endif // JUSTGL_OBJ_H