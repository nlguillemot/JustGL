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
    std::swap(a.Data, b.Data);
    std::swap(a.Size, b.Size);
    std::swap(a.pImpl, b.pImpl);
}

MappedFile MapFileForRead(const char* filename);

#endif // JUSTGL_FS_H