#include "justgl_fs.h"

#ifdef _WIN32

#include <Windows.h>
#include <cstdio>

uint64_t GetFileTimestamp(const char* filename)
{
    wchar_t* wfilename = (wchar_t*)malloc(sizeof(wchar_t) * (strlen(filename) + 1));
    int i;
    for (i = 0; filename[i] != '\0'; i++)
    {
        wfilename[i] = filename[i];
    }
    wfilename[i] = '\0';

    HANDLE hFile = CreateFileW(wfilename, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
    free(wfilename);

    if (hFile == INVALID_HANDLE_VALUE)
    {
        return 0;
    }

    FILETIME lastWriteTime;
    BOOL getFileTimeOK = GetFileTime(hFile, NULL, NULL, &lastWriteTime);

    if (!CloseHandle(hFile))
    {
        fprintf(stderr, "CloseHandled failed?\n");
    }

    if (getFileTimeOK)
    {
        uint64_t hi64 = uint64_t(lastWriteTime.dwHighDateTime) << 32;
        return hi64 | lastWriteTime.dwLowDateTime;
    }
    else
    {
        return 0;
    }
}

struct Win32FileMapping
{
    HANDLE hFile;
    HANDLE hFileMapping;
};

MappedFile MapFileForRead(const char* filename)
{
    wchar_t* wfilename = (wchar_t*)malloc(sizeof(wchar_t) * (strlen(filename) + 1));
    int i;
    for (i = 0; filename[i] != '\0'; i++)
    {
        wfilename[i] = filename[i];
    }
    wfilename[i] = '\0';

    Win32FileMapping mapping;

    mapping.hFile = CreateFileW(wfilename, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    free(wfilename);

    if (mapping.hFile == INVALID_HANDLE_VALUE)
    {
        return MappedFile();
    }

    LARGE_INTEGER size;
    if (!GetFileSizeEx(mapping.hFile, &size))
    {
        if (!CloseHandle(mapping.hFile))
        {
            fprintf(stderr, "CloseHandle failed?\n");
        }
        return MappedFile();
    }

    mapping.hFileMapping = CreateFileMappingW(mapping.hFile, NULL, PAGE_READONLY, 0, 0, NULL);
    if (mapping.hFileMapping == INVALID_HANDLE_VALUE)
    {
        if (!CloseHandle(mapping.hFile))
        {
            fprintf(stderr, "CloseHandle failed?\n");
        }
        return MappedFile();
    }

    char* data = (char*)MapViewOfFile(mapping.hFileMapping, FILE_MAP_READ, 0, 0, 0);
    if (!data)
    {
        BOOL failed = !CloseHandle(mapping.hFileMapping);
        failed |= !CloseHandle(mapping.hFile);
        if (failed)
        {
            fprintf(stderr, "CloseHandle failed?\n");
        }
        return MappedFile();
    }

    MappedFile result;
    result.Data = data;
    result.Size = size.QuadPart;
    result.pImpl = new Win32FileMapping(mapping);
    return result;
}

MappedFile::~MappedFile()
{
    delete (Win32FileMapping*)pImpl;
}

#endif // _WIN32