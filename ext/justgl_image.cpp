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

#include "justgl_image.h"
#include "justgl_fs.h"

std::function<Image(const std::string&)>* Image::CustomImageLoader = nullptr;

Image ReadTGAImage(const unsigned char* data, uint64_t size)
{
    uint64_t i = 0;

    static const size_t kHeaderSize = 18;
    if (i + kHeaderSize >= size)
    {
        // not enough room for header
        return Image();
    }

    const unsigned char* header = &data[i];
    i += kHeaderSize;

    uint8_t idlength = header[0];
    uint8_t colorMapType = header[1];
    uint8_t imageType = header[2];
    uint16_t imageWidth = (header[13] << 8) | header[12];
    uint16_t imageHeight = (header[15] << 8) | header[14];
    uint8_t pixelDepth = header[16];
    uint8_t imageDescriptor = header[17];

    if (colorMapType != 0)
    {
        // tga color mapped images not supported
        return Image();
    }

    enum
    {
        TGA_IMAGE_TYPE_UNCOMPRESSED_TRUECOLOR = 2,
        TGA_IMAGE_TYPE_RLE_TRUECOLOR = 10
    };

    if (imageType != TGA_IMAGE_TYPE_UNCOMPRESSED_TRUECOLOR &&
        imageType != TGA_IMAGE_TYPE_RLE_TRUECOLOR)
    {
        // Only tga true color images are supported
        return Image();
    }

    if (pixelDepth != 24 &&
        pixelDepth != 32)
    {
        // Only pixel depths 24 and 32 are supported
        return Image();
    }

    if ((imageDescriptor & 0x10) != 0)
    {
        // Image needs to be left to right
        return Image();
    }

    // Seek past the ID field
    if (i + idlength >= size)
    {
        // not enough room for the ID field
        return Image();
    }

    i += idlength;

    int bytesPerPixel = pixelDepth / 8;
    size_t dataSize = imageWidth * imageHeight * 4;
    std::unique_ptr<uint8_t[]> imageData(new uint8_t[dataSize]);

    if (imageType == TGA_IMAGE_TYPE_UNCOMPRESSED_TRUECOLOR)
    {
        if (i + imageWidth * imageHeight * bytesPerPixel >= size)
        {
            // not enough room for all the pixels to exist
            return Image();
        }

        for (int pxi = 0; pxi < imageWidth * imageHeight; pxi++)
        {
            uint8_t srcPixel[4];
            for (int byteIdx = 0; byteIdx < bytesPerPixel; byteIdx++)
            {
                srcPixel[byteIdx] = data[i];
                i++;
            }

            uint8_t *destPixel = &imageData[pxi * 4];

            // note: srcPixel bytes are ordered as BGRA. destPixel as RGBA
            if (bytesPerPixel == 4)
            {
                destPixel[0] = srcPixel[2];
                destPixel[1] = srcPixel[1];
                destPixel[2] = srcPixel[0];
                destPixel[3] = srcPixel[3];
            }
            else if (bytesPerPixel == 3)
            {
                destPixel[0] = srcPixel[2];
                destPixel[1] = srcPixel[1];
                destPixel[2] = srcPixel[0];
                destPixel[3] = 255;
            }
        }
    }
    else if (imageType == TGA_IMAGE_TYPE_RLE_TRUECOLOR)
    {
        int pxi = 0;

        while (pxi < imageWidth * imageHeight)
        {
            uint8_t rleHeader;
            if (i + sizeof(rleHeader) >= size)
            {
                // not enough room for RLE header
                return Image();
            }

            rleHeader = data[i];
            i++;

            uint8_t pixelCount = (rleHeader & 0x7F) + 1;

            if (rleHeader & 0x80)
            {
                // Run-Length Packet
                uint8_t srcPixel[4];
                if (i + bytesPerPixel >= size)
                {
                    // not enough room for RLE body
                    return Image();
                }

                for (int byteIdx = 0; byteIdx < bytesPerPixel; byteIdx++)
                {
                    srcPixel[byteIdx] = data[i];
                    i++;
                }

                for (int p = 0; p < pixelCount; p++, pxi++)
                {
                    uint8_t *destPixel = &imageData[pxi * 4];
                    if (bytesPerPixel == 4)
                    {
                        destPixel[0] = srcPixel[2];
                        destPixel[1] = srcPixel[1];
                        destPixel[2] = srcPixel[0];
                        destPixel[3] = srcPixel[3];
                    }
                    else if (bytesPerPixel == 3)
                    {
                        destPixel[0] = srcPixel[2];
                        destPixel[1] = srcPixel[1];
                        destPixel[2] = srcPixel[0];
                        destPixel[3] = 255;
                    }
                }
            }
            else
            {
                // Raw Packet
                for (int p = 0; p < pixelCount; p++, pxi++)
                {
                    uint8_t srcPixel[4];
                    if (i + bytesPerPixel >= size)
                    {
                        // not enough room for RLE body
                        return Image();
                    }

                    for (int byteIdx = 0; byteIdx < bytesPerPixel; byteIdx++)
                    {
                        srcPixel[byteIdx] = data[i];
                        i++;
                    }

                    uint8_t *destPixel = &imageData[pxi * 4];
                    if (bytesPerPixel == 4)
                    {
                        destPixel[0] = srcPixel[2];
                        destPixel[1] = srcPixel[1];
                        destPixel[2] = srcPixel[0];
                        destPixel[3] = srcPixel[3];
                    }
                    else
                    {
                        destPixel[0] = srcPixel[2];
                        destPixel[1] = srcPixel[1];
                        destPixel[2] = srcPixel[0];
                        destPixel[3] = 255;
                    }
                }
            }
        }
    }
    else
    {
        // Unhandled TGA Image Type
        return Image();
    }

    Image img;
    img.Data = std::move(imageData);
    img.BytesPerPixel = 4;
    img.Width = imageWidth;
    img.Height = imageHeight;
    img.Depth = 1;
    return std::move(img);
}

Image ReadImageFromFile(const std::string& filename)
{
    size_t extLoc = filename.find_last_of('.');
    if (extLoc == std::string::npos)
    {
        return Image();
    }

    MappedFile mapped = MapFileForRead(filename.c_str());
    if (!mapped.Data)
    {
        return Image();
    }

    std::string ext = filename.substr(extLoc + 1);

    // try using the custom image loader if it's available
    if (Image::CustomImageLoader != nullptr)
    {
        Image customLoaded = (*Image::CustomImageLoader)(filename);
        if (customLoaded.Data)
        {
            return std::move(customLoaded);
        }
    }

    // fall back to built-in loader
    if (ext == "tga")
    {
        return ReadTGAImage((const unsigned char*)mapped.Data, mapped.Size);
    }
    else
    {
        return Image();
    }
}