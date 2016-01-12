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

#ifndef JUSTGL_FS_H
#define JUSTGL_FS_H

#include <cstdint>
#include <utility>

uint64_t GetFileTimestamp(const char* filename);

class MappedFile;
void swap(MappedFile& a, MappedFile& b);

class MappedFile
{
public:
    MappedFile()
        : Data(nullptr)
        , Size(0)
    {
    }

    // Unmaps
    ~MappedFile();

    MappedFile(const MappedFile&) = delete;
    MappedFile& operator=(const MappedFile&) = delete;

    MappedFile(MappedFile&& other)
        : MappedFile()
    {
        swap(*this, other);
    }

    MappedFile& operator=(MappedFile&& other)
    {
        swap(*this, other);
    }

    char* Data;
    uint64_t Size;
    void* pImpl;
};

inline void swap(MappedFile& a, MappedFile& b)
{
    using std::swap;

    swap(a.Data, b.Data);
    swap(a.Size, b.Size);
    swap(a.pImpl, b.pImpl);
}

MappedFile MapFileForRead(const char* filename);

#endif // JUSTGL_FS_H