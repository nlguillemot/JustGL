#include "justgl_obj.h"
#include "justgl_fs.h"

#include <cstdio>
#include <cassert>
#include <cerrno>

bool LoadObj(const char* filename, const char* mtlpath, MeshObject* pMesh, MaterialPalette* pPaletteToAddTo)
{
    if (!filename)
    {
        return false;
    }

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

    auto acceptString = [mem, &i, &size, isWS](std::string* s)
    {
        uint64_t old_i = i;
        while (i < size && !isWS(mem[i]))
        {
            i++;
        }
        
        if (i - old_i == 0)
        {
            return false;
        }

        *s = std::string(&mem[old_i], &mem[i]);
        return true;
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

                    std::string newName;
                    if (!acceptString(&newName))
                    {
                        // expected group name
                        return false;
                    }
                   
                    if (drawbuf.empty() && idxbuf.empty())
                    {
                        // first (and empty) group, don't emit anything
                    }
                    else
                    {
                        emitGroup();
                    }

                    currGroupName = std::move(newName);

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
                else if (mem[i] == 'm')
                {
                    if (size - i >= 6 && memcmp(&mem[i], "mtllib", 6) == 0)
                    {
                        i += 6;
                        acceptHS();

                        std::string mtllibname;
                        if (!acceptString(&mtllibname))
                        {
                            // expected material library name
                            return false;
                        }
                        else
                        {
                            // static_assert(false, "TODO: Read and parse material file");
                        }

                        optionalHS();
                    }
                    else
                    {
                        // unknown start of line
                        return false;
                    }
                }
                else if (mem[i] == 'u')
                {
                    if (size - i >= 6 && memcmp(&mem[i], "usemtl", 6) == 0)
                    {
                        i += 6;
                        acceptHS();

                        std::string mtlname;
                        if (!acceptString(&mtlname))
                        {
                            // expected material name
                            return false;
                        }
                        else
                        {
                            // static_assert(false, "TODO: Check for existence of material");
                            // static_assert(false, "TODO: Call emitMaterial() or something?");
                        }

                        optionalHS();
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

    if (!pMesh)
    {
        // nothing to do
        return true;
    }

    pMesh->CPUVertexBuffers[MeshObjectVertexBindingIndex::Position] = std::move(posbuf);
    pMesh->CPUVertexBuffers[MeshObjectVertexBindingIndex::TexCoord] = std::move(tcbuf);
    pMesh->CPUVertexBuffers[MeshObjectVertexBindingIndex::Normal] = std::move(nbuf);
    pMesh->CPUIndexBuffer = std::move(idxbuf);
    pMesh->GroupNames = std::move(groupNames);
    pMesh->CPUIndirectDrawBuffer = std::move(drawbuf);

    glDeleteBuffers(MeshObjectVertexBindingIndex::Count, &pMesh->VertexBuffers[0]);
    glGenBuffers(MeshObjectVertexBindingIndex::Count, &pMesh->VertexBuffers[0]);
    for (int bindingidx = 0; bindingidx < MeshObjectVertexBindingIndex::Count; bindingidx++)
    {
        glBindBuffer(GL_ARRAY_BUFFER, pMesh->VertexBuffers[bindingidx]);
        glBufferStorage(GL_ARRAY_BUFFER,
            pMesh->CPUVertexBuffers[bindingidx].size() * sizeof(float),
            pMesh->CPUVertexBuffers[bindingidx].data(),
            0);
    }

    glDeleteBuffers(1, &pMesh->IndexBuffer);
    glGenBuffers(1, &pMesh->IndexBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, pMesh->IndexBuffer);
    glBufferStorage(GL_ELEMENT_ARRAY_BUFFER, pMesh->CPUIndexBuffer.size() * sizeof(GLuint), pMesh->CPUIndexBuffer.data(), 0);

    glDeleteBuffers(1, &pMesh->IndirectDrawBuffer);
    glGenBuffers(1, &pMesh->IndirectDrawBuffer);
    glBindBuffer(GL_DRAW_INDIRECT_BUFFER, pMesh->IndirectDrawBuffer);
    glBufferStorage(GL_DRAW_INDIRECT_BUFFER, pMesh->CPUIndirectDrawBuffer.size() * sizeof(GLDrawElementsIndirectCommand), pMesh->CPUIndirectDrawBuffer.data(), 0);

    glDeleteVertexArrays(1, &pMesh->VertexArray);
    glGenVertexArrays(1, &pMesh->VertexArray);
    glBindVertexArray(pMesh->VertexArray);
    
    // set up buffer bindings
    glBindVertexBuffer(MeshObjectVertexBindingIndex::Position, pMesh->VertexBuffers[MeshObjectVertexBindingIndex::Position], 0, sizeof(float) * 3);
    glBindVertexBuffer(MeshObjectVertexBindingIndex::TexCoord, pMesh->VertexBuffers[MeshObjectVertexBindingIndex::TexCoord], 0, sizeof(float) * 2);
    glBindVertexBuffer(MeshObjectVertexBindingIndex::Normal, pMesh->VertexBuffers[MeshObjectVertexBindingIndex::Normal], 0, sizeof(float) * 3);
    
    // set up attributes
    glVertexAttribFormat(MeshObjectVertexAttribIndex::Position, 3, GL_FLOAT, GL_FALSE, 0);
    glVertexAttribFormat(MeshObjectVertexAttribIndex::TexCoord, 2, GL_FLOAT, GL_FALSE, 0);
    glVertexAttribFormat(MeshObjectVertexAttribIndex::Normal, 3, GL_FLOAT, GL_FALSE, 0);

    // hook up the attributes to the buffer bindings
    glVertexAttribBinding(MeshObjectVertexAttribIndex::Position, MeshObjectVertexBindingIndex::Position);
    glVertexAttribBinding(MeshObjectVertexAttribIndex::TexCoord, MeshObjectVertexBindingIndex::TexCoord);
    glVertexAttribBinding(MeshObjectVertexAttribIndex::Normal,   MeshObjectVertexBindingIndex::Normal);

    // enable the attributes
    glEnableVertexAttribArray(MeshObjectVertexAttribIndex::Position);
    glEnableVertexAttribArray(MeshObjectVertexAttribIndex::TexCoord);
    glEnableVertexAttribArray(MeshObjectVertexAttribIndex::Normal);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, pMesh->IndexBuffer);
    glBindVertexArray(0);

    return true;
}