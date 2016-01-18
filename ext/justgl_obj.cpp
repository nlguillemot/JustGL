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

#include "justgl_obj.h"
#include "justgl_fs.h"
#include "justgl_image.h"
#include "justgl_dgp.h"

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <cstdio>
#include <cassert>
#include <cerrno>
#include <set>

struct MTLMaterial
{
    // Material name
    std::string mtllib;
    std::string newmtl;

    // Material color and illumination
    std::array<float, 3> Ka{{ 1.0f, 1.0f, 1.0f }}; // ambient color
    std::array<float, 3> Kd{{ 1.0f, 1.0f, 1.0f }}; // diffuse color
    std::array<float, 3> Ks{{ 0.0f, 0.0f, 0.0f }}; // specular color
    std::array<float, 3> Ke{{ 0.0f, 0.0f, 0.0f }}; // emissive color
    std::array<float, 3> Tf{{ 0.0f, 0.0f, 0.0f }}; // transmission factor. The color of the atmosphere. 
    int illum = 2; // illumination model
    float d = 1.0f; // "dissolve factor" - 0.0 = transparent, 1.0 = opaque. opposite of Tr
    float Ns = 10.0f; // specular exponent
    int sharpness = 60; // sharpness of reflections from 0 to 1000 (Default 60). high value = clear reflection.
    float Ni = 1.5f; // optical desntiy aka index of refraction. from 0.001 to 10. 1.0 means light doesn't bend.

    // Texture maps
    std::string map_Ka; // ambient color texture. multiply this by Ka
    std::string map_Kd; // diffuse color texture. multiply this by Kd
    std::string map_Ks; // specular color texture. multiply this by Ks
    std::string map_Ns; // specular exponent texture. multiply this by Ns
    std::string map_d; // dissolve texture. multiply this by d.
    std::string disp; // displacement texture
    std::string decal; // selectively replace material color with texture color
    std::string bump; // bump texture for bump maps

    // Reflection maps
    std::string refl_sphere; // infinitely sized sphere reflected in the material
    std::string refl_cube_right;  // right of cube map
    std::string refl_cube_left;   // left of cube map
    std::string refl_cube_top;    // top of cube map
    std::string refl_cube_bottom; // bottom of cube map
    std::string refl_cube_front;  // front of cube map
    std::string refl_cube_back;   // back of cube map
};

bool ParseMtl(const char* filename, const char* mtlpath, std::map<std::string, MTLMaterial>* pMaterials)
{
    MappedFile mapping = MapFileForRead(filename);
    if (!mapping.Data)
    {
        return false;
    }

    const char* mem = mapping.Data;
    uint64_t size = mapping.Size;
    uint64_t i;

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

    auto isDigit = [](char c)
    {
        return c >= '0' && c <= '9';
    };

    auto isAlpha = [](char c)
    {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    };

    auto acceptId = [&](const char* id)
    {
        size_t j;
        for (j = 0; id[j] != '\0'; j++)
        {
            if (i + j >= size || id[j] != mem[i + j])
            {
                break;
            }
        }

        if (id[j] == '\0')
        {
            i += j;
            return true;
        }
        else
        {
            return false;
        }
    };

    auto parseFloat = [mem, &i, &size, isDigit, isAlpha](float* f)
    {
        uint64_t end = i;
        while (end < size && (isDigit(mem[end]) || isAlpha(mem[end]) || mem[end] == '.' || mem[end] == '-' || mem[end] == '+'))
        {
            end++;
        }

        uint64_t len = end - i;
        char buf[256];
        if (len + 1 >= sizeof(buf))
        {
            fprintf(stderr, "Calm down with your floats\n");
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

    auto parseInt = [mem, &i, &size, isWS, isDigit](int* ii)
    {
        uint64_t end = i;
        while (end < size && (isDigit(mem[end]) || mem[end] == '-' || mem[end] == '+'))
        {
            end++;
        }

        uint64_t len = end - i;
        char buf[256];
        if (len + 1 >= sizeof(buf))
        {
            fprintf(stderr, "Calm down with your ints\n");
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

    auto acceptPath = [&](std::string* s)
    {
        if (acceptString(s))
        {
            std::string basepath = (mtlpath ? mtlpath : "");
            if (!basepath.empty() && (basepath.back() != '\\' && basepath.back() != '/'))
            {
                basepath.push_back('/');
            }

            *s = basepath + *s;
            return true;
        }
        return false;
    };

    auto acceptHS = [&]()
    {
        uint64_t old_i = i;
        while (i < size && (mem[i] == ' ' || mem[i] == '\t'))
        {
            i++;
        }
        if (i != old_i)
        {
            return true;
        }
        else
        {
            i = old_i;
            return false;
        }
    };

    std::map<std::string, MTLMaterial> tempMaterials;
    if (!pMaterials)
    {
        pMaterials = &tempMaterials;
    }

    MTLMaterial currMaterial;
    bool notReadingMaterialYet = true;

    auto emitMaterial = [&]()
    {
        if (currMaterial.newmtl.empty())
        {
            // no material to emit
            return true;
        }

        auto found = pMaterials->find(currMaterial.newmtl);
        if (found != end(*pMaterials))
        {
            return false;
        }
        
        pMaterials->insert(std::make_pair(currMaterial.newmtl, currMaterial));
        return true;
    };

    for (i = 0; i < size; )
    {
        while (i < size && (mem[i] == ' ' || mem[i] == '\t'))
        {
            i++;
        }

        if (i >= size)
        {
            break;
        }

        if (mem[i] == '#')
        {
            // comment line
            while (i < size && mem[i] != '\n' && mem[i] != '\r')
            {
                i++;
            }
        }
        else if (acceptId("newmtl"))
        {
            std::string newmtlname;
            if (!acceptHS() || !acceptString(&newmtlname))
            {
                return false;
            }

            if (notReadingMaterialYet)
            {
                notReadingMaterialYet = false;
            }
            else
            {
                if (!emitMaterial())
                {
                    // duplicate material
                    return false;
                }
            }
            
            currMaterial = MTLMaterial();
            currMaterial.mtllib = filename;
            currMaterial.newmtl = newmtlname;
        }
        else if (acceptId("Ka"))
        {
            for (int j = 0; j < 3; j++)
            {
                if (!acceptHS() || !parseFloat(&currMaterial.Ka[j]))
                {
                    if (j == 1)
                    {
                        for (; j < 3; j++)
                        {
                            currMaterial.Ka[j] = currMaterial.Ka[0];
                        }
                        break;
                    }
                    return false;
                }
            }
        }
        else if (acceptId("Kd"))
        {
            for (int j = 0; j < 3; j++)
            {
                if (!acceptHS() || !parseFloat(&currMaterial.Kd[j]))
                {
                    if (j == 1)
                    {
                        for (; j < 3; j++)
                        {
                            currMaterial.Kd[j] = currMaterial.Kd[0];
                        }
                        break;
                    }
                    return false;
                }
            }
        }
        else if (acceptId("Ks"))
        {
            for (int j = 0; j < 3; j++)
            {
                if (!acceptHS() || !parseFloat(&currMaterial.Ks[j]))
                {
                    if (j == 1)
                    {
                        for (; j < 3; j++)
                        {
                            currMaterial.Ks[j] = currMaterial.Ks[0];
                        }
                        break;
                    }
                    return false;
                }
            }
        }
        else if (acceptId("Ke"))
        {
            for (int j = 0; j < 3; j++)
            {
                if (!acceptHS() || !parseFloat(&currMaterial.Ke[j]))
                {
                    if (j == 1)
                    {
                        for (; j < 3; j++)
                        {
                            currMaterial.Ke[j] = currMaterial.Ke[0];
                        }
                        break;
                    }
                    return false;
                }
            }
        }
        else if (acceptId("Tr"))
        {
            if (!acceptHS() || !parseFloat(&currMaterial.d))
            {
                return false;
            }

            // Tr is the opposite of d
            currMaterial.d = 1.0f - currMaterial.d;
        }
        else if (acceptId("Tf"))
        {
            for (int j = 0; j < 3; j++)
            {
                if (!acceptHS() || !parseFloat(&currMaterial.Tf[j]))
                {
                    if (j == 1)
                    {
                        for (; j < 3; j++)
                        {
                            currMaterial.Tf[j] = currMaterial.Tf[0];
                        }
                        break;
                    }
                    return false;
                }
            }
        }
        else if (acceptId("illum"))
        {
            if (!acceptHS() || !parseInt(&currMaterial.illum))
            {
                return false;
            }
        }
        else if (acceptId("d"))
        {
            if (!acceptHS() || !parseFloat(&currMaterial.d))
            {
                return false;
            }
        }
        else if (acceptId("Ns"))
        {
            if (!acceptHS() || !parseFloat(&currMaterial.Ns))
            {
                return false;
            }
        }
        else if (acceptId("sharpness"))
        {
            if (!acceptHS() || !parseInt(&currMaterial.sharpness))
            {
                return false;
            }
        }
        else if (acceptId("Ni"))
        {
            if (!acceptHS() || !parseFloat(&currMaterial.Ni))
            {
                return false;
            }
        }
        else if (acceptId("map_Ka"))
        {
            if (!acceptHS() || !acceptString(&currMaterial.map_Ka))
            {
                return false;
            }
        }
        else if (acceptId("map_Kd"))
        {
            if (!acceptHS() || !acceptString(&currMaterial.map_Kd))
            {
                return false;
            }
        }
        else if (acceptId("map_Ks"))
        {
            if (!acceptHS() || !acceptString(&currMaterial.map_Ks))
            {
                return false;
            }
        }
        else if (acceptId("map_Ns"))
        {
            if (!acceptHS() || !acceptString(&currMaterial.map_Ns))
            {
                return false;
            }
        }
        else if (acceptId("map_d"))
        {
            if (!acceptHS() || !acceptString(&currMaterial.map_d))
            {
                return false;
            }
        }
        else if (acceptId("disp"))
        {
            if (!acceptHS() || !acceptString(&currMaterial.disp))
            {
                return false;
            }
        }
        else if (acceptId("decal"))
        {
            if (!acceptHS() || !acceptString(&currMaterial.decal))
            {
                return false;
            }
        }
        else if (acceptId("map_bump"))
        {
            if (!acceptHS() || !acceptString(&currMaterial.bump))
            {
                return false;
            }
        }
        else if (acceptId("bump"))
        {
            if (!acceptHS() || !acceptString(&currMaterial.bump))
            {
                return false;
            }
        }
        else if (acceptId("refl"))
        {
            std::string refltype;
            std::string filename;

            if (!acceptHS() || !acceptId("-type") || 
                !acceptHS() || !acceptString(&refltype) ||
                !acceptHS() || !acceptString(&filename))
            {
                return false;
            }

            if (refltype == "sphere")
            {
                currMaterial.refl_sphere = filename;
            }
            else if (refltype == "cube_top")
            {
                currMaterial.refl_cube_top = filename;
            }
            else if (refltype == "cube_bottom")
            {
                currMaterial.refl_cube_bottom = filename;
            }
            else if (refltype == "cube_front")
            {
                currMaterial.refl_cube_front = filename;
            }
            else if (refltype == "cube_back")
            {
                currMaterial.refl_cube_back = filename;
            }
            else if (refltype == "cube_left")
            {
                currMaterial.refl_cube_left = filename;
            }
            else if (refltype == "cube_right")
            {
                currMaterial.refl_cube_right = filename;
            }
            else
            {
                // unknown reflection map type
                return false;
            }
        }

        acceptHS();
        if (i < size && (mem[i] != '\n' && mem[i] != '\r'))
        {
            // expected end of line
            return false;
        }

        while (i < size && (mem[i] == '\n' || mem[i] == '\r'))
        {
            i++;
        }
    }

    if (!emitMaterial())
    {
        // duplicate material
        return false;
    }

    return true;
}

bool LoadObj(const char* filename, const char* mtlpath, MeshObject* pMesh, MaterialPalette* pPaletteToAddTo)
{

    bool parseOK = false;
    std::string errorMessage = "No error";

    struct ParseScope
    {
        bool& parseOK;
        const char*& mem;
        std::string& errorMessage;
        size_t& i;

        ~ParseScope()
        {
            if (!parseOK)
            {
                fprintf(stderr, "Error loading obj: %s\n", errorMessage.c_str());
                DebugBreak();
            }
        }
    };

    const char* mem = NULL;
    uint64_t i = -1;

    ParseScope parseScope{ parseOK, mem, errorMessage, i };

    if (!filename)
    {
        errorMessage = "No filename supplied";
        return false;
    }

    MappedFile mapping = MapFileForRead(filename);
    if (!mapping.Data)
    {
        errorMessage = "MapFileForRead failed";
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

    auto isDigit = [](char c)
    {
        return c >= '0' && c <= '9';
    };

    auto isAlpha = [](char c)
    {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    };

    // original data from obj
    std::vector<float> vs;
    std::vector<float> vts;
    std::vector<float> vns;

    // CPU-side buffers
    std::vector<float> posbuf;
    std::vector<float> tcbuf;
    std::vector<float> nbuf;
    std::vector<GLuint> idxbuf;

    std::map<std::string, MTLMaterial> parsedMaterials;
    std::set<std::string> parsedMaterialFiles;

    int positionCardinality = -1;
    int texCoordCardinality = -1;
    int normalCardinality = -1;

    int firstVertexInThisGroup = -1;

    // this could probably be improved
    std::map<std::tuple<int, int, int>, GLuint> cache;

    auto emitVertex = [&](int vi, int vti, int vni)
    {
        auto found = cache.find(std::make_tuple(vi, vti, vni));
        if (found != end(cache))
        {
            idxbuf.push_back(found->second);
        }
        else
        {
            if (vi != 0)
            {
                for (int vidx = 0; vidx < positionCardinality; vidx++)
                {
                    posbuf.push_back(vs[(vi - 1) * positionCardinality + vidx]);
                }
            }

            if (vti != 0)
            {
                for (int tcidx = 0; tcidx < texCoordCardinality; tcidx++)
                {
                    tcbuf.push_back(vts[(vti - 1) * texCoordCardinality + tcidx]);
                }
            }

            if (vni != 0)
            {
                for (int vnidx = 0; vnidx < normalCardinality; vnidx++)
                {
                    nbuf.push_back(vns[(vni - 1) * normalCardinality + vnidx]);
                }
            }

            if (firstVertexInThisGroup == -1)
            {
                firstVertexInThisGroup = (int)posbuf.size() / positionCardinality - 1;
            }

            idxbuf.push_back((GLuint)posbuf.size() / positionCardinality - 1  - firstVertexInThisGroup);
            
            cache.insert(std::make_pair(std::make_tuple(vi, vti, vni), idxbuf.back()));
        }
    };

    std::vector<GLDrawElementsIndirectCommand> drawbuf;
    std::vector<std::string> groupNames;
    std::vector<std::string> materialNames;

    std::vector<float> bsphereXs;
    std::vector<float> bsphereYs;
    std::vector<float> bsphereZs;
    std::vector<float> bsphereRadii;

    std::string currGroupName;
    std::string currMaterialName;

    auto emitGroup = [&]()
    {
        GLDrawElementsIndirectCommand cmd;
        if (drawbuf.empty())
        {
            cmd.count = (GLuint)idxbuf.size();
            cmd.primCount = 1;
            cmd.firstIndex = 0;
            cmd.baseVertex = 0;
            cmd.baseInstance = 0;
        }
        else
        {
            cmd.count = (GLuint)idxbuf.size() - (drawbuf.back().firstIndex + drawbuf.back().count);
            cmd.primCount = 1;
            cmd.firstIndex = (GLuint)idxbuf.size() - cmd.count;
            cmd.baseVertex = firstVertexInThisGroup;
            cmd.baseInstance = 0;
        }

        if (cmd.count > 0)
        {
            groupNames.push_back(currGroupName);
            materialNames.push_back(currMaterialName);
            drawbuf.push_back(cmd);

            float boundingSphere[4];
            BoundingSphereFromPoints(
                (int)posbuf.size() / positionCardinality - firstVertexInThisGroup,
                posbuf.data() + firstVertexInThisGroup * positionCardinality,
                boundingSphere);

            bsphereXs.push_back(boundingSphere[0]);
            bsphereYs.push_back(boundingSphere[1]);
            bsphereZs.push_back(boundingSphere[2]);
            bsphereRadii.push_back(boundingSphere[3]);
        }

        // don't want different objects to share vertex data
        cache.clear();
        firstVertexInThisGroup = -1;
    };

    mem = mapping.Data;
    uint64_t size = mapping.Size;

    auto parseFloat = [&](float* f)
    {
        uint64_t end = i;
        while (end < size && (isDigit(mem[end]) || isAlpha(mem[end]) || mem[end] == '.' || mem[end] == '-' || mem[end] == '+'))
        {
            end++;
        }

        uint64_t len = end - i;
        char buf[256];
        if (len + 1 >= sizeof(buf))
        {
            errorMessage = "Float too big for buffer";
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
            errorMessage = "strof failed";
            return false;
        }
        else
        {
            *f = parsed;
            i += len;
            return true;
        }
    };

    auto parseInt = [&](int* ii)
    {
        uint64_t end = i;
        while (end < size && (isDigit(mem[end]) || mem[end] == '-' || mem[end] == '+'))
        {
            end++;
        }

        uint64_t len = end - i;
        char buf[256];
        if (len + 1 >= sizeof(buf))
        {
            errorMessage = "Int too big for buffer";
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
            errorMessage = "strtol failed";
            return false;
        }
        else
        {
            *ii = parsed;
            i += len;
            return true;
        }
    };

    auto acceptString = [&](std::string* s)
    {
        uint64_t old_i = i;
        while (i < size && !isWS(mem[i]))
        {
            i++;
        }
        
        if (i - old_i == 0)
        {
            errorMessage = "expected token";
            return false;
        }

        *s = std::string(&mem[old_i], &mem[i]);
        return true;
    };

    auto acceptHS = [&]()
    {
        uint64_t old = i;
        while (i < size && isHS(mem[i]))
        {
            i++;
        }
        if (old != i)
        {
            return true;
        }
        else
        {
            i = old;
            errorMessage = "expected horizontal space";
            return false;
        }
    };
    
    auto optionalHS = [acceptHS]()
    {
        acceptHS();
    };

    auto parse1To4Floats = [&](float* values, int* expectedCardinality, int* cardinality)
    {
        int foundCardinality = 0;
        for (int card = 0; card < 4; card++)
        {
            size_t old_i = i;
            if ((card == 0 || acceptHS()) && parseFloat(&values[card]))
            {
                foundCardinality++;
            }
            else
            {
                i = old_i;
                break;
            }
        }

        if (foundCardinality == 0)
        {
            errorMessage = "Expected 1 to 4 floats, got none";
            return false;
        }

        if (*expectedCardinality == -1)
        {
            *expectedCardinality = foundCardinality;
        }
        else
        {
            if (foundCardinality != *expectedCardinality)
            {
                errorMessage = "Inconsistent cardinality";
                return false;
            }
        }

        *cardinality = foundCardinality;
        return true;
    };

    for (i = 0; i < size; )
    {
        while (i < size && (mem[i] == ' ' || mem[i] == '\t')) 
        {
            i++;
        }

        if (i >= size)
        {
            break;
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
                        float pos[4];
                        int card;
                        if (!parse1To4Floats(pos, &positionCardinality, &card))
                        {
                            return false;
                        }

                        optionalHS();
                        if (!(i >= size || isNL(mem[i])))
                        {
                            errorMessage = "expected end of line";
                            return false;
                        }

                        for (int c = 0; c < card; c++)
                        {
                            vs.push_back(pos[c]);
                        }
                    }
                    else if (mem[i] == 't')
                    {
                        // texcoord
                        i++;
                        if (acceptHS())
                        {
                            float tc[4];
                            int card;
                            if (!parse1To4Floats(tc, &texCoordCardinality, &card))
                            {
                                return false;
                            }

                            optionalHS();
                            if (!(i >= size || isNL(mem[i])))
                            {
                                errorMessage = "expected end of line";
                                return false;
                            }

                            for (int c = 0; c < card; c++)
                            {
                                if (c == 1)
                                {
                                    // OpenGL convention: y is at bottom
                                    tc[c] = 1.0f - tc[c];
                                }
                                vts.push_back(tc[c]);
                            }
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
                            float norm[4];
                            int card;
                            if (!parse1To4Floats(norm, &normalCardinality, &card))
                            {
                                return false;
                            }

                            optionalHS();
                            if (!(i >= size || isNL(mem[i])))
                            {
                                errorMessage = "expected end of line";
                                return false;
                            }

                            for (int c = 0; c < card; c++)
                            {
                                vns.push_back(norm[c]);
                            }
                        }
                        else
                        {
                            // expected space
                            return false;
                        }
                    }
                    else
                    {
                        errorMessage = "unknown start of line";
                        return false;
                    }
                }
                else
                {
                    errorMessage = "unexpected end of file";
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
                                    return false;
                                }
                            }
                        }

                        if (i < size && mem[i] == '/')
                        {
                            i++;
                            if (!parseInt(&vni))
                            {
                                return false;
                            }
                        }

                        if (vi < 0)
                        {
                            vi = (int)vs.size() / positionCardinality + vi + 1;
                        }
                        if (vti < 0)
                        {
                            vti = (int)vts.size() / texCoordCardinality + vti + 1;
                        }
                        if (vni < 0)
                        {
                            vni = (int)vns.size() / normalCardinality + vni + 1;
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
                                errorMessage = "not enough points for a triangle";
                                return false;
                            }
                            else
                            {
                                break;
                            }
                        }
                    }
                }
            }
            else if (mem[i] == 'g')
            {
                i++;

                if (!acceptHS())
                {
                    return false;
                }

                std::string newName;
                if (!acceptString(&newName))
                {
                    return false;
                }
                   
                // emit if this is not the first (and empty) group
                emitGroup();

                currGroupName = std::move(newName);

                optionalHS();
            }
            else if (mem[i] == 's')
            {
                i++;
                if (!acceptHS())
                {
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

                    std::string mtllibname;
                    if (!acceptHS() || !acceptString(&mtllibname))
                    {
                        return false;
                    }
                    else
                    {
                        auto found = parsedMaterialFiles.find(mtllibname);
                        if (found == end(parsedMaterialFiles))
                        {
                            std::string fullpath = (mtlpath ? mtlpath : "");
                            if (!fullpath.empty() && (fullpath.back() != '\\' && fullpath.back() != '/'))
                            {
                                fullpath.push_back('/');
                            }

                            fullpath += mtllibname;
                            MTLMaterial parsedMtl;
                            if (!ParseMtl(fullpath.c_str(), mtlpath, &parsedMaterials))
                            {
                                errorMessage = "failed to parse mtl";
                                return false;
                            }
                            parsedMaterialFiles.insert(mtllibname);
                        }
                    }

                    optionalHS();
                }
                else
                {
                    errorMessage = "unknown start of line";
                    return false;
                }
            }
            else if (mem[i] == 'u')
            {
                if (size - i >= 6 && memcmp(&mem[i], "usemtl", 6) == 0)
                {
                    i += 6;

                    std::string mtlname;
                    if (!acceptHS() || !acceptString(&mtlname))
                    {
                        return false;
                    }
                    else
                    {
                        if (parsedMaterials.find(mtlname) == end(parsedMaterials))
                        {
                            errorMessage = "unknown material name";
                            return false;
                        }

                        emitGroup();
                        currMaterialName = mtlname;
                    }

                    optionalHS();
                }
            }
            else
            {
                errorMessage = "unknown start of line";
                return false;
            }
        }

        while (i < size && isNL(mem[i])) {
            i++;
        }
    }

    // emit the leftover group
    emitGroup();

    if (pMesh)
    {
        pMesh->CPUVertexBuffers[MeshObjectVertexBindingIndex::Position] = std::move(posbuf);
        pMesh->CPUVertexBuffers[MeshObjectVertexBindingIndex::TexCoord] = std::move(tcbuf);
        pMesh->CPUVertexBuffers[MeshObjectVertexBindingIndex::Normal] = std::move(nbuf);
        pMesh->CPUIndexBuffer = std::move(idxbuf);
        pMesh->GroupNames = std::move(groupNames);
        pMesh->CPUIndirectDrawBuffer = std::move(drawbuf);
        pMesh->BSphereXs = std::move(bsphereXs);
        pMesh->BSphereYs = std::move(bsphereYs);
        pMesh->BSphereZs = std::move(bsphereZs);
        pMesh->BSphereRadii = std::move(bsphereRadii);

        glBindVertexArray(0);

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
        glBindVertexBuffer(MeshObjectVertexBindingIndex::Position, pMesh->VertexBuffers[MeshObjectVertexBindingIndex::Position], 0, sizeof(float) * positionCardinality);
        glBindVertexBuffer(MeshObjectVertexBindingIndex::TexCoord, pMesh->VertexBuffers[MeshObjectVertexBindingIndex::TexCoord], 0, sizeof(float) * texCoordCardinality);
        glBindVertexBuffer(MeshObjectVertexBindingIndex::Normal, pMesh->VertexBuffers[MeshObjectVertexBindingIndex::Normal], 0, sizeof(float) * normalCardinality);

        // set up attributes
        glVertexAttribFormat(MeshObjectVertexAttribIndex::Position, positionCardinality, GL_FLOAT, GL_FALSE, 0);
        glVertexAttribFormat(MeshObjectVertexAttribIndex::TexCoord, texCoordCardinality, GL_FLOAT, GL_FALSE, 0);
        glVertexAttribFormat(MeshObjectVertexAttribIndex::Normal, normalCardinality, GL_FLOAT, GL_FALSE, 0);

        // hook up the attributes to the buffer bindings
        glVertexAttribBinding(MeshObjectVertexAttribIndex::Position, MeshObjectVertexBindingIndex::Position);
        glVertexAttribBinding(MeshObjectVertexAttribIndex::TexCoord, MeshObjectVertexBindingIndex::TexCoord);
        glVertexAttribBinding(MeshObjectVertexAttribIndex::Normal, MeshObjectVertexBindingIndex::Normal);

        // enable the attributes
        glEnableVertexAttribArray(MeshObjectVertexAttribIndex::Position);
        glEnableVertexAttribArray(MeshObjectVertexAttribIndex::TexCoord);
        glEnableVertexAttribArray(MeshObjectVertexAttribIndex::Normal);

        pMesh->AttributeSizes[MeshObjectVertexAttribIndex::Position] = positionCardinality;
        pMesh->AttributeSizes[MeshObjectVertexAttribIndex::TexCoord] = texCoordCardinality;
        pMesh->AttributeSizes[MeshObjectVertexAttribIndex::Normal] = normalCardinality;

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, pMesh->IndexBuffer);
        glBindVertexArray(0);
    }

    if (pPaletteToAddTo)
    {
        std::vector<int> groupMaterialIDs;

        for (const std::pair<std::string, MTLMaterial>& parsedMtl: parsedMaterials)
        {
            const MTLMaterial& mtl = parsedMtl.second;

            // check if the material is already present in the palette
            auto found = std::find_if(begin(pPaletteToAddTo->Materials), end(pPaletteToAddTo->Materials),
                [&](const Material& m) {
                return mtl.mtllib == m.LibraryFilename && mtl.newmtl == m.Name;
            });
            
            if (found != end(pPaletteToAddTo->Materials))
            {
                // yup, we already have this one. skip!
                continue;
            }

            Material mat;
            mat.LibraryFilename = mtl.mtllib;
            mat.Name = mtl.newmtl;
            mat.Ka = mtl.Ka;
            mat.Kd = mtl.Kd;
            mat.Ks = mtl.Ks;
            mat.Ke = mtl.Ke;
            mat.Tf = mtl.Tf;
            mat.illum = mtl.illum;
            mat.d = mtl.d;
            mat.Ns = mtl.Ns;
            mat.sharpness = mtl.sharpness;
            mat.Ni = mtl.Ni;

            const int kNumComponentsToFormat[5] = {
                0,
                GL_RED,
                GL_RG,
                GL_RGB,
                GL_RGBA
            };

            const int kNumComponentsToSizedFormat[5] = {
                0,
                GL_R8,
                GL_RG8,
                GL_RGB8,
                GL_RGBA8
            };

            const int kNumComponentsToSizedSRGBFormat[5] = {
                0,
                0,
                0,
                GL_SRGB8,
                GL_SRGB8_ALPHA8,
            };

            bool useSRGB = false;
            
            auto emitTexture = [&](const std::string& filename, int* pTextureIndex)
            {
                if (filename.empty())
                {
                    *pTextureIndex = -1;
                    return true;
                }

                // does this texture already exist?
                auto found = std::find_if(begin(pPaletteToAddTo->TextureFilenames), end(pPaletteToAddTo->TextureFilenames),
                    [&](const std::vector<std::string>& filenames)
                {
                    return filenames.size() == 1 && filenames[0] == filename;
                });

                if (found != end(pPaletteToAddTo->TextureFilenames))
                {
                    *pTextureIndex = (int)std::distance(begin(pPaletteToAddTo->TextureFilenames), found);
                    return true;
                }

                Image img = ReadImageFromFile(filename);
                if (!img.Data)
                {
                    errorMessage = "ReadImageFromFile failed";
                    return false;
                }

#ifndef NDEBUG
                if (img.Width >= 1024 || img.Height >= 1024)
                {
                    printf("Warning: big texture (%dx%d: %s)\n", img.Width, img.Height, filename.c_str());
                }
#endif

                int numLevels = (int)std::floor(std::log2(std::max(img.Width, img.Height))) + 1;

                GLenum sizedFormat;
                if (useSRGB)
                {
                    sizedFormat = kNumComponentsToSizedSRGBFormat[img.BytesPerPixel];
                }
                else
                {
                    sizedFormat = kNumComponentsToSizedFormat[img.BytesPerPixel];
                }

                GLuint tex;
                glGenTextures(1, &tex);
                glBindTexture(GL_TEXTURE_2D, tex);
                glTexStorage2D(GL_TEXTURE_2D, numLevels, sizedFormat, img.Width, img.Height);
                glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, img.Width, img.Height, kNumComponentsToFormat[img.BytesPerPixel], GL_UNSIGNED_BYTE, img.Data.get());
                glGenerateMipmap(GL_TEXTURE_2D);
                pPaletteToAddTo->Textures.push_back(tex);
                pPaletteToAddTo->Images.push_back(std::move(img));
                pPaletteToAddTo->TextureFilenames.push_back({ filename });
                *pTextureIndex = (int)pPaletteToAddTo->Textures.size() - 1;

                return true;
            };

            auto emitTextureCube = [&](
                const std::string& rightname,
                const std::string& leftname,
                const std::string& topname,
                const std::string& bottomname,
                const std::string& frontname,
                const std::string& backname,
                int* pTextureIndex)
            {
                int emptiness = 
                    (int)rightname.empty() + 
                    (int)leftname.empty() + 
                    (int)topname.empty() + 
                    (int)bottomname.empty() + 
                    (int)frontname.empty() + 
                    (int)backname.empty();

                if (emptiness == 6)
                {
                    *pTextureIndex = -1;
                    return true;
                }

                // does this texture already exist?
                auto found = std::find_if(begin(pPaletteToAddTo->TextureFilenames), end(pPaletteToAddTo->TextureFilenames),
                    [&](const std::vector<std::string>& filenames)
                {
                    return filenames.size() == 6 &&
                        filenames[0] == rightname &&
                        filenames[1] == leftname &&
                        filenames[2] == topname &&
                        filenames[3] == bottomname &&
                        filenames[4] == frontname &&
                        filenames[5] == backname;
                });

                if (found != end(pPaletteToAddTo->TextureFilenames))
                {
                    *pTextureIndex = (int)std::distance(begin(pPaletteToAddTo->TextureFilenames), found);
                    return true;
                }

                const std::string* filenames[] = {
                    &rightname, &leftname,
                    &topname, &bottomname,
                    &frontname, &backname
                };

                Image imgs[6];
                int faceWidth = -1, faceHeight = -1, faceBytesPerPixel = -1;
                for (const std::string* filename : filenames)
                {
                    if (filename->empty())
                    {
                        continue;
                    }

                    Image& img = imgs[&filename - filenames];
                    img = ReadImageFromFile(*filename);
                    if (!img.Data)
                    {
                        errorMessage = "ReadImageFromFile failed";
                        return false;
                    }

#ifndef NDEBUG
                    if (img.Width >= 1024 || img.Height >= 1024)
                    {
                        printf("Warning: big texture (%dx%d: %s)\n", img.Width, img.Height, filename->c_str());
                    }
#endif

                    if (faceWidth == -1)
                    {
                        faceWidth = img.Width;
                    }
                    else
                    {
                        if (faceWidth != img.Width)
                        {
                            errorMessage = "Inconsistent cubemap face width";
                            return false;
                        }
                    }

                    if (faceHeight == -1)
                    {
                        faceHeight = img.Height;
                    }
                    else
                    {
                        if (faceHeight != img.Height)
                        {
                            errorMessage = "Inconsistent cubemap face height";
                            return false;
                        }
                    }

                    if (faceBytesPerPixel == -1)
                    {
                        faceBytesPerPixel = img.BytesPerPixel;
                    }
                    else
                    {
                        if (faceBytesPerPixel != img.BytesPerPixel)
                        {
                            errorMessage = "Inconsistent cubemap face bytes per pixel";
                            return false;
                        }
                    }
                }

                if (faceWidth == -1 || faceHeight == -1 || faceBytesPerPixel == -1)
                {
                    errorMessage = "Unknown face width/height/bytesperpixel";
                    return false;
                }

                int numLevels = (int)std::floor(std::log2(std::max(faceWidth, faceHeight))) + 1;

                GLenum sizedFormat;
                if (useSRGB)
                {
                    sizedFormat = kNumComponentsToSizedSRGBFormat[faceBytesPerPixel];
                }
                else
                {
                    sizedFormat = kNumComponentsToSizedFormat[faceBytesPerPixel];
                }

                GLuint tex;
                glGenTextures(1, &tex);
                glBindTexture(GL_TEXTURE_CUBE_MAP, tex);
                glTexStorage2D(GL_TEXTURE_CUBE_MAP, numLevels, sizedFormat, faceWidth, faceHeight);
                for (GLenum target = GL_TEXTURE_CUBE_MAP_POSITIVE_X, faceIdx = 0; target <= GL_TEXTURE_CUBE_MAP_NEGATIVE_Z; target++, faceIdx++)
                {
                    if (!imgs[faceIdx].Data)
                    {
                        continue;
                    }
                    
                    glTexSubImage2D(target, 0, 0, 0, faceWidth, faceHeight, kNumComponentsToFormat[faceBytesPerPixel], GL_UNSIGNED_BYTE, imgs[faceIdx].Data.get());
                }
                glGenerateMipmap(GL_TEXTURE_CUBE_MAP);

                pPaletteToAddTo->Textures.push_back(tex);
                for (Image& img : imgs)
                {
                    pPaletteToAddTo->Images.push_back(std::move(img));
                }
                pPaletteToAddTo->TextureFilenames.push_back({ filename });
                *pTextureIndex = (int)pPaletteToAddTo->Textures.size() - 1;

                return true;
            };

            useSRGB = true;
            if (!emitTexture(mtl.map_Ka, &mat.map_Ka) ||
                !emitTexture(mtl.map_Kd, &mat.map_Kd) ||
                !emitTexture(mtl.map_Ks, &mat.map_Ks))
            {
                return false;
            }
            
            useSRGB = false;
            if (!emitTexture(mtl.map_Ns, &mat.map_Ns) ||
                !emitTexture(mtl.map_d, &mat.map_d) ||
                !emitTexture(mtl.disp, &mat.disp))
            {
                return false;
            }

            useSRGB = true;
            if (!emitTexture(mtl.decal, &mat.decal))
            {
                return false;
            }

            useSRGB = false;
            if (!emitTexture(mtl.bump, &mat.bump))
            {
                return false;
            }

            useSRGB = true;
            if (!emitTexture(mtl.refl_sphere, &mat.refl_sphere) ||
                !emitTextureCube(
                    mtl.refl_cube_right,
                    mtl.refl_cube_left,
                    mtl.refl_cube_top,
                    mtl.refl_cube_bottom,
                    mtl.refl_cube_front,
                    mtl.refl_cube_back,
                    &mat.refl_cube))
            {
                return false;
            }

            pPaletteToAddTo->Materials.push_back(std::move(mat));
        }

        if (pMesh)
        {
            for (const std::string& materialName : materialNames)
            {
                auto found = std::find_if(begin(pPaletteToAddTo->Materials), end(pPaletteToAddTo->Materials),
                    [&](const Material& mtl)
                {
                    // look for this material from one of this mesh's libraries
                    return mtl.Name == materialName && mtl.LibraryFilename == parsedMaterials[mtl.Name].mtllib; 
                });

                if (found == end(pPaletteToAddTo->Materials))
                {
                    errorMessage = "Could not find material";
                    return false;
                }

                groupMaterialIDs.push_back((int)std::distance(begin(pPaletteToAddTo->Materials), found));
            }

            pMesh->GroupMaterialIDs = std::move(groupMaterialIDs);
        }
    }

    parseOK = true;

    return true;
}