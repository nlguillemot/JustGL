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

#include "justgl_fs.h"

#ifdef _WIN32

#include <Windows.h>
#include <cstdio>

static bool CheckWin32(BOOL b, const WCHAR* info)
{
    if (b)
    {
        return true;
    }

    DWORD errorCode = GetLastError();

    LPWSTR buffPtr;
    DWORD bufferLength = FormatMessageW(
        FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL, errorCode, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPWSTR)&buffPtr, 0, NULL);
    CheckWin32(bufferLength != 0, L"FormatMessageW");

    fwprintf(stderr, L"Error (%s): %s\n", info, buffPtr);

    DebugBreak();

    CheckWin32(LocalFree(buffPtr) == NULL, L"AssertWin32");
    return false;
}

uint64_t GetFileTimestamp(const char* filename)
{
    int fileBufferSize = MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, filename, -1, NULL, 0);
    if (!CheckWin32(fileBufferSize != 0, L"MultiByteToWideChar"))
    {
        return 0;
    }

    WCHAR* wfilename = (WCHAR*)malloc(sizeof(WCHAR) * fileBufferSize);
    if (!CheckWin32(MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, filename, -1, wfilename, fileBufferSize), L"MultiByteToWideChar"))
    {
        free(wfilename);
        return 0;
    }

    HANDLE hFile = CreateFileW(wfilename, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);

    free(wfilename);

    if (hFile == INVALID_HANDLE_VALUE)
    {
        return 0;
    }

    FILETIME lastWriteTime;
    BOOL getFileTimeOK = GetFileTime(hFile, NULL, NULL, &lastWriteTime);

    CheckWin32(CloseHandle(hFile), L"CloseHandle");

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
    MappedFile result;
    Win32FileMapping mapping{ INVALID_HANDLE_VALUE, NULL };
    char* data = NULL;
    WCHAR* wfilename = NULL;

    int fileBufferSize = MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, filename, -1, NULL, 0);
    if (!CheckWin32(fileBufferSize != 0, L"MultiByteToWideChar"))
    {
        goto fail;
    }

    wfilename = (WCHAR*)malloc(sizeof(WCHAR) * fileBufferSize);
    if (!CheckWin32(MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, filename, -1, wfilename, fileBufferSize), L"MultiByteToWideChar"))
    {
        goto fail;
    }

    mapping.hFile = CreateFileW(wfilename, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    CheckWin32(mapping.hFile != INVALID_HANDLE_VALUE, L"CreateFileW");

    free(wfilename);
    wfilename = NULL;

    if (mapping.hFile == INVALID_HANDLE_VALUE)
    {
        goto fail;
    }

    LARGE_INTEGER size;
    if (!CheckWin32(GetFileSizeEx(mapping.hFile, &size), L"GetFileSizeEx"))
    {
        goto fail;
    }

    mapping.hFileMapping = CreateFileMappingW(mapping.hFile, NULL, PAGE_READONLY, 0, 0, NULL);
    if (!CheckWin32(mapping.hFileMapping != NULL, L"CreateFileMappingW"))
    {
        goto fail;
    }

    data = (char*)MapViewOfFile(mapping.hFileMapping, FILE_MAP_READ, 0, 0, 0);
    if (!data)
    {
        goto fail;
    }

    result.Data = data;
    result.Size = size.QuadPart;
    result.pImpl = new Win32FileMapping(mapping);
    if (!result.pImpl)
    {
        goto fail;
    }

    return result;

fail:
    if (wfilename)
    {
        free(wfilename);
    }
    if (data)
    {
        CheckWin32(UnmapViewOfFile(data), L"UnmapViewOfFile");
    }
    if (mapping.hFileMapping != NULL)
    {
        CheckWin32(CloseHandle(mapping.hFileMapping), L"CloseHandle");
    }
    if (mapping.hFile != INVALID_HANDLE_VALUE)
    {
        CheckWin32(CloseHandle(mapping.hFile), L"CloseHandle");
    }
    if (wfilename)
    {
        free(wfilename);
    }
    return MappedFile();
}

MappedFile::~MappedFile()
{
    if (Data)
    {
        if (!UnmapViewOfFile(Data))
        {
            fprintf(stderr, "UnmapViewOfFile failed?\n");
        }
    }

    if (pImpl)
    {
        Win32FileMapping* impl = (Win32FileMapping*)pImpl;

        if (!CloseHandle(impl->hFileMapping))
        {
            fprintf(stderr, "CloseHandle failed?\n");
        }
        if (!CloseHandle(impl->hFile))
        {
            fprintf(stderr, "CloseHandle failed?\n");
        }
        delete (Win32FileMapping*)pImpl;
    }
}

#endif // _WIN32