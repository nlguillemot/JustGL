#include "justgl_obj.h"
#include "justgl_fs.h"

#include <cstdio>
#include <cassert>
#include <cerrno>

bool LoadObj(const char* filename, CPUMeshObject* pCPUObject, GPUMeshObject* pGPUObject)
{
    MappedFile mapping = MapFileForRead(filename);
    if (!mapping.Data)
    {
        return false;
    }

    auto isWS = [](char c)
    {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t';
    };
    
    auto isHS = [](char c)
    {
        return c == ' ' || c == '\t';
    };

    auto isNL = [](char c)
    {
        return c == '\n' || c == '\r';
    };

    std::vector<float> vs;
    std::vector<float> vts;
    std::vector<float> vns;

    // CPU-side buffers
    std::vector<float> posbuf;
    std::vector<float> tcbuf;
    std::vector<float> nbuf;
    std::vector<GLuint> idxbuf;

    struct VertexCacheEntry
    {
        int v, vt, vn;
        GLuint idx;
    };

    static const unsigned int kCacheSize = 1024;
    static_assert((kCacheSize & (kCacheSize - 1)) == 0, "assuming pow2");
    VertexCacheEntry cache[kCacheSize];

    auto emitVertex = [&vs, &vts, &vns, &posbuf, &tcbuf, &nbuf, &idxbuf, &cache]
        (int vi, int vti, int vni)
    {
        int hashed =
            (vi & (kCacheSize - 1)) ^
            (vti & (kCacheSize - 1)) ^
            (vni & (kCacheSize - 1));

        if (cache[hashed].v == vi &&
            cache[hashed].vt == vti &&
            cache[hashed].vn == vni)
        {
            idxbuf.push_back(cache[hashed].idx);
        }
        else
        {
            posbuf.push_back(vs[(vi - 1) * 3 + 0]);
            posbuf.push_back(vs[(vi - 1) * 3 + 1]);
            posbuf.push_back(vs[(vi - 1) * 3 + 2]);

            if (vti != 0)
            {
                tcbuf.push_back(vts[(vti - 1) * 3 + 0]);
                tcbuf.push_back(vts[(vti - 1) * 3 + 1]);
                tcbuf.push_back(vts[(vti - 1) * 3 + 2]);
            }

            if (vni != 0)
            {
                nbuf.push_back(vns[(vni - 1) * 3 + 0]);
                nbuf.push_back(vns[(vni - 1) * 3 + 1]);
                nbuf.push_back(vns[(vni - 1) * 3 + 2]);
            }

            idxbuf.push_back((GLuint)posbuf.size() - 1);
            
            cache[hashed].v = vi;
            cache[hashed].vt = vti;
            cache[hashed].vn = vni;
            cache[hashed].idx = idxbuf.back();
        }
    };

    std::vector<GLDrawElementsIndirectCommand> drawbuf;
    std::vector<std::string> groupNames;

    std::string currGroupName;

    auto emitGroup = [&drawbuf, &posbuf, &idxbuf, &groupNames, &currGroupName]()
    {
        GLDrawElementsIndirectCommand cmd;
        if (drawbuf.empty())
        {
            cmd.count = 0;
            cmd.primCount = 1;
            cmd.firstIndex = 0;
            cmd.baseVertex = 0;
            cmd.baseInstance = 0;
        }
        else
        {
            cmd.count = (GLuint)idxbuf.size() - drawbuf.back().firstIndex + drawbuf.back().count;
            cmd.primCount = 1;
            cmd.firstIndex = (GLuint)idxbuf.size() - cmd.count;
            cmd.baseVertex = 0;
            cmd.baseInstance = 0;
        }

        groupNames.push_back(currGroupName);
        drawbuf.push_back(cmd);
    };

    const char* mem = mapping.Data;
    uint64_t size = mapping.Size;

    size_t i;

    auto parseFloat = [mem, &i, &size, isWS](float* f)
    {
        uint64_t end = i;
        while (i < size && !isWS(mem[i]))
        {
            end++;
        }

        uint64_t len = end - i;
        char buf[256];
        if (len + 1 >= sizeof(buf))
        {
            fprintf(stderr, "Calm down with your floats");
            return false;
        }

        uint64_t j;
        for (j = 0; j < len; j++)
        {
            buf[j] = mem[i + j];
        }
        buf[j] = '\0';

        errno = 0;
        float parsed = strtof(buf, nullptr);
        if (errno)
        {
            return false;
        }
        else
        {
            *f = parsed;
            i += len;
            return true;
        }
    };

    auto parseInt = [mem, &i, &size, isWS](int* ii)
    {
        uint64_t end = i;
        while (i < size && !isWS(mem[i]))
        {
            end++;
        }

        uint64_t len = end - i;
        char buf[256];
        if (len + 1 >= sizeof(buf))
        {
            fprintf(stderr, "Calm down with your floats");
            return false;
        }

        uint64_t j;
        for (j = 0; j < len; j++)
        {
            buf[j] = mem[i + j];
        }
        buf[j] = '\0';

        errno = 0;
        int parsed = strtol(buf, nullptr, 10);
        if (errno)
        {
            return false;
        }
        else
        {
            *ii = parsed;
            i += len;
            return true;
        }
    };

    auto acceptHS = [mem, &i, &size, isHS]()
    {
        uint64_t old = i;
        while (i < size && isHS(mem[i]))
        {
            i++;
        }
        return old != i;
    };
    
    auto optionalHS = [acceptHS]()
    {
        acceptHS();
    };

    for (i = 0; i < size; i++)
    {
        while (i < size && isWS(mem[i])) {
            i++;
        }

        if (mem[i] == '#')
        {
            while (i < size && !isNL(mem[i])) {
                i++;
            }
        }
        else
        {
            if (mem[i] == 'v')
            {
                i++;
                if (i < size)
                {
                    if (acceptHS())
                    {
                        // position
                        float x, y, z;
                        if (!parseFloat(&x) ||
                            !acceptHS() ||
                            !parseFloat(&y) ||
                            !acceptHS() ||
                            !parseFloat(&z))
                        {
                            // failed to parse x y z
                            return false;
                        }

                        optionalHS();
                        if (!(i >= size || isNL(mem[i])))
                        {
                            // expected end of line
                            return false;
                        }

                        vs.push_back(x);
                        vs.push_back(y);
                        vs.push_back(z);
                    }
                    else if (mem[i] == 't')
                    {
                        // texcoord
                        i++;
                        if (acceptHS())
                        {
                            float u, v;
                            if (!parseFloat(&u) ||
                                !acceptHS() ||
                                !parseFloat(&v))
                            {
                                // failed to parse u v
                                return false;
                            }

                            optionalHS();
                            if (!(i >= size || isNL(mem[i])))
                            {
                                // expected end of line
                                return false;
                            }
                            
                            vts.push_back(u);
                            vts.push_back(v);
                        }
                        else
                        {
                            // expected space
                            return false;
                        }
                    }
                    else if (mem[i] == 'n')
                    {
                        // normal
                        i++;
                        if (acceptHS())
                        {
                            float x, y, z;
                            if (!parseFloat(&x) ||
                                !acceptHS() ||
                                !parseFloat(&y) ||
                                !acceptHS() ||
                                !parseFloat(&z))
                            {
                                // failed to parse x y z
                                return false;
                            }

                            optionalHS();
                            if (!(i >= size || isNL(mem[i])))
                            {
                                // expected end of line
                                return false;
                            }

                            vns.push_back(x);
                            vns.push_back(y);
                            vns.push_back(z);
                        }
                        else
                        {
                            // expected space
                            return false;
                        }
                    }
                    else
                    {
                        // unknown start of line
                        return false;
                    }
                }
                else
                {
                    // unexpected end
                    return false;
                }
            }
            else if (mem[i] == 'f')
            {
                i++;
                if (acceptHS())
                {
                    int pivot_vi, pivot_vti, pivot_vni;
                    int last_vi, last_vti, last_vni;

                    for (int j = 0; ; j++)
                    {
                        int vi = 0, vti = 0, vni = 0;

                        if (!parseInt(&vi))
                        {
                            // expected index
                            return false;
                        }

                        if (i < size && mem[i] == '/')
                        {
                            i++;
                            if (i < size && mem[i] == '/')
                            {
                                // no texcoord
                            }
                            else
                            {
                                if (!parseInt(&vti))
                                {
                                    // expected index
                                    return false;
                                }
                            }
                        }

                        if (i < size && mem[i] == '/')
                        {
                            i++;
                            if (!parseInt(&vni))
                            {
                                // expected index
                                return false;
                            }
                        }

                        if (vi < 0)
                        {
                            vi = (int)vs.size() + vi;
                        }
                        if (vti < 0)
                        {
                            vti = (int)vts.size() + vti;
                        }
                        if (vni < 0)
                        {
                            vni = (int)vns.size() + vni;
                        }

                        if (j == 0)
                        {
                            pivot_vi = vi;
                            pivot_vti = vti;
                            pivot_vni = vni;
                        }
                        else if (j > 1)
                        {
                            emitVertex(pivot_vi, pivot_vti, pivot_vni);
                            emitVertex(last_vi, last_vti, last_vni);
                            emitVertex(vi, vti, vni);
                        }
                        
                        last_vi = vi;
                        last_vti = vti;
                        last_vni = vni;

                        optionalHS();

                        if (i >= size || isNL(mem[i]))
                        {
                            if (j < 2)
                            {
                                // not enough points for a triangle
                                return false;
                            }
                            else
                            {
                                break;
                            }
                        }
                    }
                }
                else if (mem[i] == 'g')
                {
                    i++;

                    if (!acceptHS())
                    {
                        // unknown start of line
                        return false;
                    }

                    // grab the group name
                    uint64_t old_i = i;
                    while (i < size && !isWS(mem[i]))
                    {
                        i++;
                    }
                    uint64_t namelen = i - old_i;

                    std::string newName(&mem[old_i], &mem[i]);
                   
                    if (drawbuf.empty() && idxbuf.empty())
                    {
                        // first (and empty) group, don't emit anything
                    }
                    else
                    {
                        emitGroup();
                    }

                    currGroupName = newName;

                    optionalHS();
                }
                else if (mem[i] == 's')
                {
                    i++;
                    if (!acceptHS())
                    {
                        // unknown start of line
                        return false;
                    }

                    // smoothing groups are ignored
                    while (i < size && !isNL(mem[i]))
                    {
                        i++;
                    }
                }
                else
                {
                    // unknown start of line
                    return false;
                }
            }
            else
            {
                // unknown start of line
                return false;
            }
        }

        while (i < size && isNL(mem[i])) {
            i++;
        }
    }

    CPUMeshObject tmpCPUMeshObject;
    if (!pCPUObject)
    {
        pCPUObject = &tmpCPUMeshObject;
    }

    pCPUObject->VertexBuffers[MeshObjectVertexBindingIndex::Position] = std::move(posbuf);
    pCPUObject->VertexBuffers[MeshObjectVertexBindingIndex::TexCoord] = std::move(tcbuf);
    pCPUObject->VertexBuffers[MeshObjectVertexBindingIndex::Normal] = std::move(nbuf);
    pCPUObject->IndexBuffer = std::move(idxbuf);
    pCPUObject->GroupNames = std::move(groupNames);
    pCPUObject->IndirectDrawBuffer = std::move(drawbuf);

    if (pGPUObject)
    {
        glGenBuffers(MeshObjectVertexBindingIndex::Count, pGPUObject->VertexBuffers);
        for (int bindingidx = 0; bindingidx < MeshObjectVertexBindingIndex::Count; bindingidx++)
        {
            glBindBuffer(GL_ARRAY_BUFFER, pGPUObject->VertexBuffers[bindingidx]);
            glBufferData(GL_ARRAY_BUFFER,
                pCPUObject->VertexBuffers[bindingidx].size() * sizeof(float),
                pCPUObject->VertexBuffers[bindingidx].data(),
                GL_STATIC_DRAW);
        }

        glGenBuffers(1, &pGPUObject->IndexBuffer);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, pGPUObject->IndexBuffer);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, pCPUObject->IndexBuffer.size() * sizeof(GLuint), pCPUObject->IndexBuffer.data(), GL_STATIC_DRAW);

        glGenBuffers(1, &pGPUObject->IndirectDrawBuffer);
        glBindBuffer(GL_DRAW_INDIRECT_BUFFER, pGPUObject->IndirectDrawBuffer);
        glBufferData(GL_DRAW_INDIRECT_BUFFER, pCPUObject->IndirectDrawBuffer.size() * sizeof(GLDrawElementsIndirectCommand), pCPUObject->IndirectDrawBuffer.data(), GL_STATIC_DRAW);
    }

    return true;
}