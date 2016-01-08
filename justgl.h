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

#ifndef JUSTGL_H_INCLUDED
#define JUSTGL_H_INCLUDED

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

// To customize the creation of the window and context
typedef struct WindowConfig
{
    int ClientWidth;
    int ClientHeight;
    const char* WindowTitle;
} WindowConfig;

// App customization points (you implement these)
void ConfigGL(WindowConfig* pConfig);
void InitGL();
void ResizeGL(int width, int height);
void PaintGL();

// Utility functions
void* GetProcGL(const char* procname);

// A tweaked version of glcorearb.h is pasted inline between __glcorearb_h_.
// The license associated to this chunk of code is also included inline.
// That license applies to that part of the code only.
// The rest of the code in this file is under the license at the top of this file.
// If it wasn't for this bit of code, I'd unlicense this whole thing. :/
// TODO: Generate my own version of this code from the GL XML specs?
#ifndef __glcorearb_h_
#define __glcorearb_h_ 1

/*
** Copyright (c) 2013-2015 The Khronos Group Inc.
**
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and/or associated documentation files (the
** "Materials"), to deal in the Materials without restriction, including
** without limitation the rights to use, copy, modify, merge, publish,
** distribute, sublicense, and/or sell copies of the Materials, and to
** permit persons to whom the Materials are furnished to do so, subject to
** the following conditions:
**
** The above copyright notice and this permission notice shall be included
** in all copies or substantial portions of the Materials.
**
** THE MATERIALS ARE PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
** EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
** MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
** IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
** CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
** TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
** MATERIALS OR THE USE OR OTHER DEALINGS IN THE MATERIALS.
*/
/*
** This header is generated from the Khronos OpenGL / OpenGL ES XML
** API Registry. The current version of the Registry, generator scripts
** used to make the header, and the header can be found at
**   http://www.opengl.org/registry/
**
** Khronos $Revision: 32155 $ on $Date: 2015-10-22 23:25:39 -0400 (Thu, 22 Oct 2015) $
*/

#ifndef GLCALL
#ifdef _WIN32
#define GLCALL __stdcall
#else
#define GLCALL
#endif
#endif
#ifndef GLCALLP
#define GLCALLP GLCALL *
#endif
#ifndef GLAPI
#ifdef JUSTGL_IMPLEMENTATION
#define GLAPI
#else
#define GLAPI extern
#endif
#endif

/* glcorearb.h is for use with OpenGL core profile implementations.
** It should should be placed in the same directory as gl.h and
** included as <GL/glcorearb.h>.
**
** glcorearb.h includes only APIs in the latest OpenGL core profile
** implementation together with APIs in newer ARB extensions which 
** can be supported by the core profile. It does not, and never will
** include functionality removed from the core profile, such as
** fixed-function vertex and fragment processing.
**
** Do not #include both <GL/glcorearb.h> and either of <GL/gl.h> or
** <GL/glext.h> in the same source file.
*/

/* Generated C header for:
 * API: gl
 * Profile: core
 * Versions considered: .*
 * Versions emitted: .*
 * Default extensions included: glcore
 * Additional extensions included: _nomatch_^
 * Extensions removed: _nomatch_^
 */

#ifndef GL_VERSION_1_0
#define GL_VERSION_1_0 1
typedef void GLvoid;
typedef unsigned int GLenum;
typedef float GLfloat;
typedef int GLint;
typedef int GLsizei;
typedef unsigned int GLbitfield;
typedef double GLdouble;
typedef unsigned int GLuint;
typedef unsigned char GLboolean;
typedef unsigned char GLubyte;
GLAPI void (GLCALLP glCullFace)(GLenum mode);
GLAPI void (GLCALLP glFrontFace)(GLenum mode);
GLAPI void (GLCALLP glHint)(GLenum target, GLenum mode);
GLAPI void (GLCALLP glLineWidth)(GLfloat width);
GLAPI void (GLCALLP glPointSize)(GLfloat size);
GLAPI void (GLCALLP glPolygonMode)(GLenum face, GLenum mode);
GLAPI void (GLCALLP glScissor)(GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI void (GLCALLP glTexParameterf)(GLenum target, GLenum pname, GLfloat param);
GLAPI void (GLCALLP glTexParameterfv)(GLenum target, GLenum pname, const GLfloat *params);
GLAPI void (GLCALLP glTexParameteri)(GLenum target, GLenum pname, GLint param);
GLAPI void (GLCALLP glTexParameteriv)(GLenum target, GLenum pname, const GLint *params);
GLAPI void (GLCALLP glTexImage1D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels);
GLAPI void (GLCALLP glTexImage2D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
GLAPI void (GLCALLP glDrawBuffer)(GLenum buf);
GLAPI void (GLCALLP glClear)(GLbitfield mask);
GLAPI void (GLCALLP glClearColor)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
GLAPI void (GLCALLP glClearStencil)(GLint s);
GLAPI void (GLCALLP glClearDepth)(GLdouble depth);
GLAPI void (GLCALLP glStencilMask)(GLuint mask);
GLAPI void (GLCALLP glColorMask)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
GLAPI void (GLCALLP glDepthMask)(GLboolean flag);
GLAPI void (GLCALLP glDisable)(GLenum cap);
GLAPI void (GLCALLP glEnable)(GLenum cap);
GLAPI void (GLCALLP glFinish)(void);
GLAPI void (GLCALLP glFlush)(void);
GLAPI void (GLCALLP glBlendFunc)(GLenum sfactor, GLenum dfactor);
GLAPI void (GLCALLP glLogicOp)(GLenum opcode);
GLAPI void (GLCALLP glStencilFunc)(GLenum func, GLint ref, GLuint mask);
GLAPI void (GLCALLP glStencilOp)(GLenum fail, GLenum zfail, GLenum zpass);
GLAPI void (GLCALLP glDepthFunc)(GLenum func);
GLAPI void (GLCALLP glPixelStoref)(GLenum pname, GLfloat param);
GLAPI void (GLCALLP glPixelStorei)(GLenum pname, GLint param);
GLAPI void (GLCALLP glReadBuffer)(GLenum src);
GLAPI void (GLCALLP glReadPixels)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels);
GLAPI void (GLCALLP glGetBooleanv)(GLenum pname, GLboolean *data);
GLAPI void (GLCALLP glGetDoublev)(GLenum pname, GLdouble *data);
GLAPI GLenum (GLCALLP glGetError)(void);
GLAPI void (GLCALLP glGetFloatv)(GLenum pname, GLfloat *data);
GLAPI void (GLCALLP glGetIntegerv)(GLenum pname, GLint *data);
GLAPI const GLubyte *(GLCALLP glGetString)(GLenum name);
GLAPI void (GLCALLP glGetTexImage)(GLenum target, GLint level, GLenum format, GLenum type, void *pixels);
GLAPI void (GLCALLP glGetTexParameterfv)(GLenum target, GLenum pname, GLfloat *params);
GLAPI void (GLCALLP glGetTexParameteriv)(GLenum target, GLenum pname, GLint *params);
GLAPI void (GLCALLP glGetTexLevelParameterfv)(GLenum target, GLint level, GLenum pname, GLfloat *params);
GLAPI void (GLCALLP glGetTexLevelParameteriv)(GLenum target, GLint level, GLenum pname, GLint *params);
GLAPI GLboolean (GLCALLP glIsEnabled)(GLenum cap);
GLAPI void (GLCALLP glDepthRange)(GLdouble near, GLdouble far);
GLAPI void (GLCALLP glViewport)(GLint x, GLint y, GLsizei width, GLsizei height);
#endif /* GL_VERSION_1_0 */

#ifndef GL_VERSION_1_1
#define GL_VERSION_1_1 1
typedef float GLclampf;
typedef double GLclampd;
#define GL_DEPTH_BUFFER_BIT               0x00000100
#define GL_STENCIL_BUFFER_BIT             0x00000400
#define GL_COLOR_BUFFER_BIT               0x00004000
#define GL_FALSE                          0
#define GL_TRUE                           1
#define GL_POINTS                         0x0000
#define GL_LINES                          0x0001
#define GL_LINE_LOOP                      0x0002
#define GL_LINE_STRIP                     0x0003
#define GL_TRIANGLES                      0x0004
#define GL_TRIANGLE_STRIP                 0x0005
#define GL_TRIANGLE_FAN                   0x0006
#define GL_QUADS                          0x0007
#define GL_NEVER                          0x0200
#define GL_LESS                           0x0201
#define GL_EQUAL                          0x0202
#define GL_LEQUAL                         0x0203
#define GL_GREATER                        0x0204
#define GL_NOTEQUAL                       0x0205
#define GL_GEQUAL                         0x0206
#define GL_ALWAYS                         0x0207
#define GL_ZERO                           0
#define GL_ONE                            1
#define GL_SRC_COLOR                      0x0300
#define GL_ONE_MINUS_SRC_COLOR            0x0301
#define GL_SRC_ALPHA                      0x0302
#define GL_ONE_MINUS_SRC_ALPHA            0x0303
#define GL_DST_ALPHA                      0x0304
#define GL_ONE_MINUS_DST_ALPHA            0x0305
#define GL_DST_COLOR                      0x0306
#define GL_ONE_MINUS_DST_COLOR            0x0307
#define GL_SRC_ALPHA_SATURATE             0x0308
#define GL_NONE                           0
#define GL_FRONT_LEFT                     0x0400
#define GL_FRONT_RIGHT                    0x0401
#define GL_BACK_LEFT                      0x0402
#define GL_BACK_RIGHT                     0x0403
#define GL_FRONT                          0x0404
#define GL_BACK                           0x0405
#define GL_LEFT                           0x0406
#define GL_RIGHT                          0x0407
#define GL_FRONT_AND_BACK                 0x0408
#define GL_NO_ERROR                       0
#define GL_INVALID_ENUM                   0x0500
#define GL_INVALID_VALUE                  0x0501
#define GL_INVALID_OPERATION              0x0502
#define GL_OUT_OF_MEMORY                  0x0505
#define GL_CW                             0x0900
#define GL_CCW                            0x0901
#define GL_POINT_SIZE                     0x0B11
#define GL_POINT_SIZE_RANGE               0x0B12
#define GL_POINT_SIZE_GRANULARITY         0x0B13
#define GL_LINE_SMOOTH                    0x0B20
#define GL_LINE_WIDTH                     0x0B21
#define GL_LINE_WIDTH_RANGE               0x0B22
#define GL_LINE_WIDTH_GRANULARITY         0x0B23
#define GL_POLYGON_MODE                   0x0B40
#define GL_POLYGON_SMOOTH                 0x0B41
#define GL_CULL_FACE                      0x0B44
#define GL_CULL_FACE_MODE                 0x0B45
#define GL_FRONT_FACE                     0x0B46
#define GL_DEPTH_RANGE                    0x0B70
#define GL_DEPTH_TEST                     0x0B71
#define GL_DEPTH_WRITEMASK                0x0B72
#define GL_DEPTH_CLEAR_VALUE              0x0B73
#define GL_DEPTH_FUNC                     0x0B74
#define GL_STENCIL_TEST                   0x0B90
#define GL_STENCIL_CLEAR_VALUE            0x0B91
#define GL_STENCIL_FUNC                   0x0B92
#define GL_STENCIL_VALUE_MASK             0x0B93
#define GL_STENCIL_FAIL                   0x0B94
#define GL_STENCIL_PASS_DEPTH_FAIL        0x0B95
#define GL_STENCIL_PASS_DEPTH_PASS        0x0B96
#define GL_STENCIL_REF                    0x0B97
#define GL_STENCIL_WRITEMASK              0x0B98
#define GL_VIEWPORT                       0x0BA2
#define GL_DITHER                         0x0BD0
#define GL_BLEND_DST                      0x0BE0
#define GL_BLEND_SRC                      0x0BE1
#define GL_BLEND                          0x0BE2
#define GL_LOGIC_OP_MODE                  0x0BF0
#define GL_COLOR_LOGIC_OP                 0x0BF2
#define GL_DRAW_BUFFER                    0x0C01
#define GL_READ_BUFFER                    0x0C02
#define GL_SCISSOR_BOX                    0x0C10
#define GL_SCISSOR_TEST                   0x0C11
#define GL_COLOR_CLEAR_VALUE              0x0C22
#define GL_COLOR_WRITEMASK                0x0C23
#define GL_DOUBLEBUFFER                   0x0C32
#define GL_STEREO                         0x0C33
#define GL_LINE_SMOOTH_HINT               0x0C52
#define GL_POLYGON_SMOOTH_HINT            0x0C53
#define GL_UNPACK_SWAP_BYTES              0x0CF0
#define GL_UNPACK_LSB_FIRST               0x0CF1
#define GL_UNPACK_ROW_LENGTH              0x0CF2
#define GL_UNPACK_SKIP_ROWS               0x0CF3
#define GL_UNPACK_SKIP_PIXELS             0x0CF4
#define GL_UNPACK_ALIGNMENT               0x0CF5
#define GL_PACK_SWAP_BYTES                0x0D00
#define GL_PACK_LSB_FIRST                 0x0D01
#define GL_PACK_ROW_LENGTH                0x0D02
#define GL_PACK_SKIP_ROWS                 0x0D03
#define GL_PACK_SKIP_PIXELS               0x0D04
#define GL_PACK_ALIGNMENT                 0x0D05
#define GL_MAX_TEXTURE_SIZE               0x0D33
#define GL_MAX_VIEWPORT_DIMS              0x0D3A
#define GL_SUBPIXEL_BITS                  0x0D50
#define GL_TEXTURE_1D                     0x0DE0
#define GL_TEXTURE_2D                     0x0DE1
#define GL_POLYGON_OFFSET_UNITS           0x2A00
#define GL_POLYGON_OFFSET_POINT           0x2A01
#define GL_POLYGON_OFFSET_LINE            0x2A02
#define GL_POLYGON_OFFSET_FILL            0x8037
#define GL_POLYGON_OFFSET_FACTOR          0x8038
#define GL_TEXTURE_BINDING_1D             0x8068
#define GL_TEXTURE_BINDING_2D             0x8069
#define GL_TEXTURE_WIDTH                  0x1000
#define GL_TEXTURE_HEIGHT                 0x1001
#define GL_TEXTURE_INTERNAL_FORMAT        0x1003
#define GL_TEXTURE_BORDER_COLOR           0x1004
#define GL_TEXTURE_RED_SIZE               0x805C
#define GL_TEXTURE_GREEN_SIZE             0x805D
#define GL_TEXTURE_BLUE_SIZE              0x805E
#define GL_TEXTURE_ALPHA_SIZE             0x805F
#define GL_DONT_CARE                      0x1100
#define GL_FASTEST                        0x1101
#define GL_NICEST                         0x1102
#define GL_BYTE                           0x1400
#define GL_UNSIGNED_BYTE                  0x1401
#define GL_SHORT                          0x1402
#define GL_UNSIGNED_SHORT                 0x1403
#define GL_INT                            0x1404
#define GL_UNSIGNED_INT                   0x1405
#define GL_FLOAT                          0x1406
#define GL_DOUBLE                         0x140A
#define GL_STACK_OVERFLOW                 0x0503
#define GL_STACK_UNDERFLOW                0x0504
#define GL_CLEAR                          0x1500
#define GL_AND                            0x1501
#define GL_AND_REVERSE                    0x1502
#define GL_COPY                           0x1503
#define GL_AND_INVERTED                   0x1504
#define GL_NOOP                           0x1505
#define GL_XOR                            0x1506
#define GL_OR                             0x1507
#define GL_NOR                            0x1508
#define GL_EQUIV                          0x1509
#define GL_INVERT                         0x150A
#define GL_OR_REVERSE                     0x150B
#define GL_COPY_INVERTED                  0x150C
#define GL_OR_INVERTED                    0x150D
#define GL_NAND                           0x150E
#define GL_SET                            0x150F
#define GL_TEXTURE                        0x1702
#define GL_COLOR                          0x1800
#define GL_DEPTH                          0x1801
#define GL_STENCIL                        0x1802
#define GL_STENCIL_INDEX                  0x1901
#define GL_DEPTH_COMPONENT                0x1902
#define GL_RED                            0x1903
#define GL_GREEN                          0x1904
#define GL_BLUE                           0x1905
#define GL_ALPHA                          0x1906
#define GL_RGB                            0x1907
#define GL_RGBA                           0x1908
#define GL_POINT                          0x1B00
#define GL_LINE                           0x1B01
#define GL_FILL                           0x1B02
#define GL_KEEP                           0x1E00
#define GL_REPLACE                        0x1E01
#define GL_INCR                           0x1E02
#define GL_DECR                           0x1E03
#define GL_VENDOR                         0x1F00
#define GL_RENDERER                       0x1F01
#define GL_VERSION                        0x1F02
#define GL_EXTENSIONS                     0x1F03
#define GL_NEAREST                        0x2600
#define GL_LINEAR                         0x2601
#define GL_NEAREST_MIPMAP_NEAREST         0x2700
#define GL_LINEAR_MIPMAP_NEAREST          0x2701
#define GL_NEAREST_MIPMAP_LINEAR          0x2702
#define GL_LINEAR_MIPMAP_LINEAR           0x2703
#define GL_TEXTURE_MAG_FILTER             0x2800
#define GL_TEXTURE_MIN_FILTER             0x2801
#define GL_TEXTURE_WRAP_S                 0x2802
#define GL_TEXTURE_WRAP_T                 0x2803
#define GL_PROXY_TEXTURE_1D               0x8063
#define GL_PROXY_TEXTURE_2D               0x8064
#define GL_REPEAT                         0x2901
#define GL_R3_G3_B2                       0x2A10
#define GL_RGB4                           0x804F
#define GL_RGB5                           0x8050
#define GL_RGB8                           0x8051
#define GL_RGB10                          0x8052
#define GL_RGB12                          0x8053
#define GL_RGB16                          0x8054
#define GL_RGBA2                          0x8055
#define GL_RGBA4                          0x8056
#define GL_RGB5_A1                        0x8057
#define GL_RGBA8                          0x8058
#define GL_RGB10_A2                       0x8059
#define GL_RGBA12                         0x805A
#define GL_RGBA16                         0x805B
#define GL_VERTEX_ARRAY                   0x8074
GLAPI void (GLCALLP glDrawArrays)(GLenum mode, GLint first, GLsizei count);
GLAPI void (GLCALLP glDrawElements)(GLenum mode, GLsizei count, GLenum type, const void *indices);
GLAPI void (GLCALLP glGetPointerv)(GLenum pname, void **params);
GLAPI void (GLCALLP glPolygonOffset)(GLfloat factor, GLfloat units);
GLAPI void (GLCALLP glCopyTexImage1D)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
GLAPI void (GLCALLP glCopyTexImage2D)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
GLAPI void (GLCALLP glCopyTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
GLAPI void (GLCALLP glCopyTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI void (GLCALLP glTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
GLAPI void (GLCALLP glTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
GLAPI void (GLCALLP glBindTexture)(GLenum target, GLuint texture);
GLAPI void (GLCALLP glDeleteTextures)(GLsizei n, const GLuint *textures);
GLAPI void (GLCALLP glGenTextures)(GLsizei n, GLuint *textures);
GLAPI GLboolean (GLCALLP glIsTexture)(GLuint texture);
#endif /* GL_VERSION_1_1 */

#ifndef GL_VERSION_1_2
#define GL_VERSION_1_2 1
#define GL_UNSIGNED_BYTE_3_3_2            0x8032
#define GL_UNSIGNED_SHORT_4_4_4_4         0x8033
#define GL_UNSIGNED_SHORT_5_5_5_1         0x8034
#define GL_UNSIGNED_INT_8_8_8_8           0x8035
#define GL_UNSIGNED_INT_10_10_10_2        0x8036
#define GL_TEXTURE_BINDING_3D             0x806A
#define GL_PACK_SKIP_IMAGES               0x806B
#define GL_PACK_IMAGE_HEIGHT              0x806C
#define GL_UNPACK_SKIP_IMAGES             0x806D
#define GL_UNPACK_IMAGE_HEIGHT            0x806E
#define GL_TEXTURE_3D                     0x806F
#define GL_PROXY_TEXTURE_3D               0x8070
#define GL_TEXTURE_DEPTH                  0x8071
#define GL_TEXTURE_WRAP_R                 0x8072
#define GL_MAX_3D_TEXTURE_SIZE            0x8073
#define GL_UNSIGNED_BYTE_2_3_3_REV        0x8362
#define GL_UNSIGNED_SHORT_5_6_5           0x8363
#define GL_UNSIGNED_SHORT_5_6_5_REV       0x8364
#define GL_UNSIGNED_SHORT_4_4_4_4_REV     0x8365
#define GL_UNSIGNED_SHORT_1_5_5_5_REV     0x8366
#define GL_UNSIGNED_INT_8_8_8_8_REV       0x8367
#define GL_UNSIGNED_INT_2_10_10_10_REV    0x8368
#define GL_BGR                            0x80E0
#define GL_BGRA                           0x80E1
#define GL_MAX_ELEMENTS_VERTICES          0x80E8
#define GL_MAX_ELEMENTS_INDICES           0x80E9
#define GL_CLAMP_TO_EDGE                  0x812F
#define GL_TEXTURE_MIN_LOD                0x813A
#define GL_TEXTURE_MAX_LOD                0x813B
#define GL_TEXTURE_BASE_LEVEL             0x813C
#define GL_TEXTURE_MAX_LEVEL              0x813D
#define GL_SMOOTH_POINT_SIZE_RANGE        0x0B12
#define GL_SMOOTH_POINT_SIZE_GRANULARITY  0x0B13
#define GL_SMOOTH_LINE_WIDTH_RANGE        0x0B22
#define GL_SMOOTH_LINE_WIDTH_GRANULARITY  0x0B23
#define GL_ALIASED_LINE_WIDTH_RANGE       0x846E
GLAPI void (GLCALLP glDrawRangeElements)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices);
GLAPI void (GLCALLP glTexImage3D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
GLAPI void (GLCALLP glTexSubImage3D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
GLAPI void (GLCALLP glCopyTexSubImage3D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#endif /* GL_VERSION_1_2 */

#ifndef GL_VERSION_1_3
#define GL_VERSION_1_3 1
#define GL_TEXTURE0                       0x84C0
#define GL_TEXTURE1                       0x84C1
#define GL_TEXTURE2                       0x84C2
#define GL_TEXTURE3                       0x84C3
#define GL_TEXTURE4                       0x84C4
#define GL_TEXTURE5                       0x84C5
#define GL_TEXTURE6                       0x84C6
#define GL_TEXTURE7                       0x84C7
#define GL_TEXTURE8                       0x84C8
#define GL_TEXTURE9                       0x84C9
#define GL_TEXTURE10                      0x84CA
#define GL_TEXTURE11                      0x84CB
#define GL_TEXTURE12                      0x84CC
#define GL_TEXTURE13                      0x84CD
#define GL_TEXTURE14                      0x84CE
#define GL_TEXTURE15                      0x84CF
#define GL_TEXTURE16                      0x84D0
#define GL_TEXTURE17                      0x84D1
#define GL_TEXTURE18                      0x84D2
#define GL_TEXTURE19                      0x84D3
#define GL_TEXTURE20                      0x84D4
#define GL_TEXTURE21                      0x84D5
#define GL_TEXTURE22                      0x84D6
#define GL_TEXTURE23                      0x84D7
#define GL_TEXTURE24                      0x84D8
#define GL_TEXTURE25                      0x84D9
#define GL_TEXTURE26                      0x84DA
#define GL_TEXTURE27                      0x84DB
#define GL_TEXTURE28                      0x84DC
#define GL_TEXTURE29                      0x84DD
#define GL_TEXTURE30                      0x84DE
#define GL_TEXTURE31                      0x84DF
#define GL_ACTIVE_TEXTURE                 0x84E0
#define GL_MULTISAMPLE                    0x809D
#define GL_SAMPLE_ALPHA_TO_COVERAGE       0x809E
#define GL_SAMPLE_ALPHA_TO_ONE            0x809F
#define GL_SAMPLE_COVERAGE                0x80A0
#define GL_SAMPLE_BUFFERS                 0x80A8
#define GL_SAMPLES                        0x80A9
#define GL_SAMPLE_COVERAGE_VALUE          0x80AA
#define GL_SAMPLE_COVERAGE_INVERT         0x80AB
#define GL_TEXTURE_CUBE_MAP               0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP       0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X    0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X    0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y    0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y    0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z    0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z    0x851A
#define GL_PROXY_TEXTURE_CUBE_MAP         0x851B
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE      0x851C
#define GL_COMPRESSED_RGB                 0x84ED
#define GL_COMPRESSED_RGBA                0x84EE
#define GL_TEXTURE_COMPRESSION_HINT       0x84EF
#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE  0x86A0
#define GL_TEXTURE_COMPRESSED             0x86A1
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS 0x86A2
#define GL_COMPRESSED_TEXTURE_FORMATS     0x86A3
#define GL_CLAMP_TO_BORDER                0x812D
GLAPI void (GLCALLP glActiveTexture)(GLenum texture);
GLAPI void (GLCALLP glSampleCoverage)(GLfloat value, GLboolean invert);
GLAPI void (GLCALLP glCompressedTexImage3D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data);
GLAPI void (GLCALLP glCompressedTexImage2D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data);
GLAPI void (GLCALLP glCompressedTexImage1D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data);
GLAPI void (GLCALLP glCompressedTexSubImage3D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
GLAPI void (GLCALLP glCompressedTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
GLAPI void (GLCALLP glCompressedTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
GLAPI void (GLCALLP glGetCompressedTexImage)(GLenum target, GLint level, void *img);
#endif /* GL_VERSION_1_3 */

#ifndef GL_VERSION_1_4
#define GL_VERSION_1_4 1
#define GL_BLEND_DST_RGB                  0x80C8
#define GL_BLEND_SRC_RGB                  0x80C9
#define GL_BLEND_DST_ALPHA                0x80CA
#define GL_BLEND_SRC_ALPHA                0x80CB
#define GL_POINT_FADE_THRESHOLD_SIZE      0x8128
#define GL_DEPTH_COMPONENT16              0x81A5
#define GL_DEPTH_COMPONENT24              0x81A6
#define GL_DEPTH_COMPONENT32              0x81A7
#define GL_MIRRORED_REPEAT                0x8370
#define GL_MAX_TEXTURE_LOD_BIAS           0x84FD
#define GL_TEXTURE_LOD_BIAS               0x8501
#define GL_INCR_WRAP                      0x8507
#define GL_DECR_WRAP                      0x8508
#define GL_TEXTURE_DEPTH_SIZE             0x884A
#define GL_TEXTURE_COMPARE_MODE           0x884C
#define GL_TEXTURE_COMPARE_FUNC           0x884D
#define GL_FUNC_ADD                       0x8006
#define GL_FUNC_SUBTRACT                  0x800A
#define GL_FUNC_REVERSE_SUBTRACT          0x800B
#define GL_MIN                            0x8007
#define GL_MAX                            0x8008
#define GL_CONSTANT_COLOR                 0x8001
#define GL_ONE_MINUS_CONSTANT_COLOR       0x8002
#define GL_CONSTANT_ALPHA                 0x8003
#define GL_ONE_MINUS_CONSTANT_ALPHA       0x8004
GLAPI void (GLCALLP glBlendFuncSeparate)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
GLAPI void (GLCALLP glMultiDrawArrays)(GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount);
GLAPI void (GLCALLP glMultiDrawElements)(GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount);
GLAPI void (GLCALLP glPointParameterf)(GLenum pname, GLfloat param);
GLAPI void (GLCALLP glPointParameterfv)(GLenum pname, const GLfloat *params);
GLAPI void (GLCALLP glPointParameteri)(GLenum pname, GLint param);
GLAPI void (GLCALLP glPointParameteriv)(GLenum pname, const GLint *params);
GLAPI void (GLCALLP glBlendColor)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
GLAPI void (GLCALLP glBlendEquation)(GLenum mode);
#endif /* GL_VERSION_1_4 */

#ifndef GL_VERSION_1_5
#define GL_VERSION_1_5 1
#include <stddef.h>
typedef ptrdiff_t GLsizeiptr;
typedef ptrdiff_t GLintptr;
#define GL_BUFFER_SIZE                    0x8764
#define GL_BUFFER_USAGE                   0x8765
#define GL_QUERY_COUNTER_BITS             0x8864
#define GL_CURRENT_QUERY                  0x8865
#define GL_QUERY_RESULT                   0x8866
#define GL_QUERY_RESULT_AVAILABLE         0x8867
#define GL_ARRAY_BUFFER                   0x8892
#define GL_ELEMENT_ARRAY_BUFFER           0x8893
#define GL_ARRAY_BUFFER_BINDING           0x8894
#define GL_ELEMENT_ARRAY_BUFFER_BINDING   0x8895
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING 0x889F
#define GL_READ_ONLY                      0x88B8
#define GL_WRITE_ONLY                     0x88B9
#define GL_READ_WRITE                     0x88BA
#define GL_BUFFER_ACCESS                  0x88BB
#define GL_BUFFER_MAPPED                  0x88BC
#define GL_BUFFER_MAP_POINTER             0x88BD
#define GL_STREAM_DRAW                    0x88E0
#define GL_STREAM_READ                    0x88E1
#define GL_STREAM_COPY                    0x88E2
#define GL_STATIC_DRAW                    0x88E4
#define GL_STATIC_READ                    0x88E5
#define GL_STATIC_COPY                    0x88E6
#define GL_DYNAMIC_DRAW                   0x88E8
#define GL_DYNAMIC_READ                   0x88E9
#define GL_DYNAMIC_COPY                   0x88EA
#define GL_SAMPLES_PASSED                 0x8914
#define GL_SRC1_ALPHA                     0x8589
GLAPI void (GLCALLP glGenQueries)(GLsizei n, GLuint *ids);
GLAPI void (GLCALLP glDeleteQueries)(GLsizei n, const GLuint *ids);
GLAPI GLboolean (GLCALLP glIsQuery)(GLuint id);
GLAPI void (GLCALLP glBeginQuery)(GLenum target, GLuint id);
GLAPI void (GLCALLP glEndQuery)(GLenum target);
GLAPI void (GLCALLP glGetQueryiv)(GLenum target, GLenum pname, GLint *params);
GLAPI void (GLCALLP glGetQueryObjectiv)(GLuint id, GLenum pname, GLint *params);
GLAPI void (GLCALLP glGetQueryObjectuiv)(GLuint id, GLenum pname, GLuint *params);
GLAPI void (GLCALLP glBindBuffer)(GLenum target, GLuint buffer);
GLAPI void (GLCALLP glDeleteBuffers)(GLsizei n, const GLuint *buffers);
GLAPI void (GLCALLP glGenBuffers)(GLsizei n, GLuint *buffers);
GLAPI GLboolean (GLCALLP glIsBuffer)(GLuint buffer);
GLAPI void (GLCALLP glBufferData)(GLenum target, GLsizeiptr size, const void *data, GLenum usage);
GLAPI void (GLCALLP glBufferSubData)(GLenum target, GLintptr offset, GLsizeiptr size, const void *data);
GLAPI void (GLCALLP glGetBufferSubData)(GLenum target, GLintptr offset, GLsizeiptr size, void *data);
GLAPI void *(GLCALLP glMapBuffer)(GLenum target, GLenum access);
GLAPI GLboolean (GLCALLP glUnmapBuffer)(GLenum target);
GLAPI void (GLCALLP glGetBufferParameteriv)(GLenum target, GLenum pname, GLint *params);
GLAPI void (GLCALLP glGetBufferPointerv)(GLenum target, GLenum pname, void **params);
#endif /* GL_VERSION_1_5 */

#ifndef GL_VERSION_2_0
#define GL_VERSION_2_0 1
typedef char GLchar;
typedef short GLshort;
typedef signed char GLbyte;
typedef unsigned short GLushort;
#define GL_BLEND_EQUATION_RGB             0x8009
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED    0x8622
#define GL_VERTEX_ATTRIB_ARRAY_SIZE       0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE     0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE       0x8625
#define GL_CURRENT_VERTEX_ATTRIB          0x8626
#define GL_VERTEX_PROGRAM_POINT_SIZE      0x8642
#define GL_VERTEX_ATTRIB_ARRAY_POINTER    0x8645
#define GL_STENCIL_BACK_FUNC              0x8800
#define GL_STENCIL_BACK_FAIL              0x8801
#define GL_STENCIL_BACK_PASS_DEPTH_FAIL   0x8802
#define GL_STENCIL_BACK_PASS_DEPTH_PASS   0x8803
#define GL_MAX_DRAW_BUFFERS               0x8824
#define GL_DRAW_BUFFER0                   0x8825
#define GL_DRAW_BUFFER1                   0x8826
#define GL_DRAW_BUFFER2                   0x8827
#define GL_DRAW_BUFFER3                   0x8828
#define GL_DRAW_BUFFER4                   0x8829
#define GL_DRAW_BUFFER5                   0x882A
#define GL_DRAW_BUFFER6                   0x882B
#define GL_DRAW_BUFFER7                   0x882C
#define GL_DRAW_BUFFER8                   0x882D
#define GL_DRAW_BUFFER9                   0x882E
#define GL_DRAW_BUFFER10                  0x882F
#define GL_DRAW_BUFFER11                  0x8830
#define GL_DRAW_BUFFER12                  0x8831
#define GL_DRAW_BUFFER13                  0x8832
#define GL_DRAW_BUFFER14                  0x8833
#define GL_DRAW_BUFFER15                  0x8834
#define GL_BLEND_EQUATION_ALPHA           0x883D
#define GL_MAX_VERTEX_ATTRIBS             0x8869
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED 0x886A
#define GL_MAX_TEXTURE_IMAGE_UNITS        0x8872
#define GL_FRAGMENT_SHADER                0x8B30
#define GL_VERTEX_SHADER                  0x8B31
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS 0x8B49
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS  0x8B4A
#define GL_MAX_VARYING_FLOATS             0x8B4B
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS 0x8B4C
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS 0x8B4D
#define GL_SHADER_TYPE                    0x8B4F
#define GL_FLOAT_VEC2                     0x8B50
#define GL_FLOAT_VEC3                     0x8B51
#define GL_FLOAT_VEC4                     0x8B52
#define GL_INT_VEC2                       0x8B53
#define GL_INT_VEC3                       0x8B54
#define GL_INT_VEC4                       0x8B55
#define GL_BOOL                           0x8B56
#define GL_BOOL_VEC2                      0x8B57
#define GL_BOOL_VEC3                      0x8B58
#define GL_BOOL_VEC4                      0x8B59
#define GL_FLOAT_MAT2                     0x8B5A
#define GL_FLOAT_MAT3                     0x8B5B
#define GL_FLOAT_MAT4                     0x8B5C
#define GL_SAMPLER_1D                     0x8B5D
#define GL_SAMPLER_2D                     0x8B5E
#define GL_SAMPLER_3D                     0x8B5F
#define GL_SAMPLER_CUBE                   0x8B60
#define GL_SAMPLER_1D_SHADOW              0x8B61
#define GL_SAMPLER_2D_SHADOW              0x8B62
#define GL_DELETE_STATUS                  0x8B80
#define GL_COMPILE_STATUS                 0x8B81
#define GL_LINK_STATUS                    0x8B82
#define GL_VALIDATE_STATUS                0x8B83
#define GL_INFO_LOG_LENGTH                0x8B84
#define GL_ATTACHED_SHADERS               0x8B85
#define GL_ACTIVE_UNIFORMS                0x8B86
#define GL_ACTIVE_UNIFORM_MAX_LENGTH      0x8B87
#define GL_SHADER_SOURCE_LENGTH           0x8B88
#define GL_ACTIVE_ATTRIBUTES              0x8B89
#define GL_ACTIVE_ATTRIBUTE_MAX_LENGTH    0x8B8A
#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT 0x8B8B
#define GL_SHADING_LANGUAGE_VERSION       0x8B8C
#define GL_CURRENT_PROGRAM                0x8B8D
#define GL_POINT_SPRITE_COORD_ORIGIN      0x8CA0
#define GL_LOWER_LEFT                     0x8CA1
#define GL_UPPER_LEFT                     0x8CA2
#define GL_STENCIL_BACK_REF               0x8CA3
#define GL_STENCIL_BACK_VALUE_MASK        0x8CA4
#define GL_STENCIL_BACK_WRITEMASK         0x8CA5
GLAPI void (GLCALLP glBlendEquationSeparate)(GLenum modeRGB, GLenum modeAlpha);
GLAPI void (GLCALLP glDrawBuffers)(GLsizei n, const GLenum *bufs);
GLAPI void (GLCALLP glStencilOpSeparate)(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
GLAPI void (GLCALLP glStencilFuncSeparate)(GLenum face, GLenum func, GLint ref, GLuint mask);
GLAPI void (GLCALLP glStencilMaskSeparate)(GLenum face, GLuint mask);
GLAPI void (GLCALLP glAttachShader)(GLuint program, GLuint shader);
GLAPI void (GLCALLP glBindAttribLocation)(GLuint program, GLuint index, const GLchar *name);
GLAPI void (GLCALLP glCompileShader)(GLuint shader);
GLAPI GLuint (GLCALLP glCreateProgram)(void);
GLAPI GLuint (GLCALLP glCreateShader)(GLenum type);
GLAPI void (GLCALLP glDeleteProgram)(GLuint program);
GLAPI void (GLCALLP glDeleteShader)(GLuint shader);
GLAPI void (GLCALLP glDetachShader)(GLuint program, GLuint shader);
GLAPI void (GLCALLP glDisableVertexAttribArray)(GLuint index);
GLAPI void (GLCALLP glEnableVertexAttribArray)(GLuint index);
GLAPI void (GLCALLP glGetActiveAttrib)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
GLAPI void (GLCALLP glGetActiveUniform)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
GLAPI void (GLCALLP glGetAttachedShaders)(GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders);
GLAPI GLint (GLCALLP glGetAttribLocation)(GLuint program, const GLchar *name);
GLAPI void (GLCALLP glGetProgramiv)(GLuint program, GLenum pname, GLint *params);
GLAPI void (GLCALLP glGetProgramInfoLog)(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
GLAPI void (GLCALLP glGetShaderiv)(GLuint shader, GLenum pname, GLint *params);
GLAPI void (GLCALLP glGetShaderInfoLog)(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
GLAPI void (GLCALLP glGetShaderSource)(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source);
GLAPI GLint (GLCALLP glGetUniformLocation)(GLuint program, const GLchar *name);
GLAPI void (GLCALLP glGetUniformfv)(GLuint program, GLint location, GLfloat *params);
GLAPI void (GLCALLP glGetUniformiv)(GLuint program, GLint location, GLint *params);
GLAPI void (GLCALLP glGetVertexAttribdv)(GLuint index, GLenum pname, GLdouble *params);
GLAPI void (GLCALLP glGetVertexAttribfv)(GLuint index, GLenum pname, GLfloat *params);
GLAPI void (GLCALLP glGetVertexAttribiv)(GLuint index, GLenum pname, GLint *params);
GLAPI void (GLCALLP glGetVertexAttribPointerv)(GLuint index, GLenum pname, void **pointer);
GLAPI GLboolean (GLCALLP glIsProgram)(GLuint program);
GLAPI GLboolean (GLCALLP glIsShader)(GLuint shader);
GLAPI void (GLCALLP glLinkProgram)(GLuint program);
GLAPI void (GLCALLP glShaderSource)(GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length);
GLAPI void (GLCALLP glUseProgram)(GLuint program);
GLAPI void (GLCALLP glUniform1f)(GLint location, GLfloat v0);
GLAPI void (GLCALLP glUniform2f)(GLint location, GLfloat v0, GLfloat v1);
GLAPI void (GLCALLP glUniform3f)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
GLAPI void (GLCALLP glUniform4f)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
GLAPI void (GLCALLP glUniform1i)(GLint location, GLint v0);
GLAPI void (GLCALLP glUniform2i)(GLint location, GLint v0, GLint v1);
GLAPI void (GLCALLP glUniform3i)(GLint location, GLint v0, GLint v1, GLint v2);
GLAPI void (GLCALLP glUniform4i)(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
GLAPI void (GLCALLP glUniform1fv)(GLint location, GLsizei count, const GLfloat *value);
GLAPI void (GLCALLP glUniform2fv)(GLint location, GLsizei count, const GLfloat *value);
GLAPI void (GLCALLP glUniform3fv)(GLint location, GLsizei count, const GLfloat *value);
GLAPI void (GLCALLP glUniform4fv)(GLint location, GLsizei count, const GLfloat *value);
GLAPI void (GLCALLP glUniform1iv)(GLint location, GLsizei count, const GLint *value);
GLAPI void (GLCALLP glUniform2iv)(GLint location, GLsizei count, const GLint *value);
GLAPI void (GLCALLP glUniform3iv)(GLint location, GLsizei count, const GLint *value);
GLAPI void (GLCALLP glUniform4iv)(GLint location, GLsizei count, const GLint *value);
GLAPI void (GLCALLP glUniformMatrix2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void (GLCALLP glUniformMatrix3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void (GLCALLP glUniformMatrix4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void (GLCALLP glValidateProgram)(GLuint program);
GLAPI void (GLCALLP glVertexAttrib1d)(GLuint index, GLdouble x);
GLAPI void (GLCALLP glVertexAttrib1dv)(GLuint index, const GLdouble *v);
GLAPI void (GLCALLP glVertexAttrib1f)(GLuint index, GLfloat x);
GLAPI void (GLCALLP glVertexAttrib1fv)(GLuint index, const GLfloat *v);
GLAPI void (GLCALLP glVertexAttrib1s)(GLuint index, GLshort x);
GLAPI void (GLCALLP glVertexAttrib1sv)(GLuint index, const GLshort *v);
GLAPI void (GLCALLP glVertexAttrib2d)(GLuint index, GLdouble x, GLdouble y);
GLAPI void (GLCALLP glVertexAttrib2dv)(GLuint index, const GLdouble *v);
GLAPI void (GLCALLP glVertexAttrib2f)(GLuint index, GLfloat x, GLfloat y);
GLAPI void (GLCALLP glVertexAttrib2fv)(GLuint index, const GLfloat *v);
GLAPI void (GLCALLP glVertexAttrib2s)(GLuint index, GLshort x, GLshort y);
GLAPI void (GLCALLP glVertexAttrib2sv)(GLuint index, const GLshort *v);
GLAPI void (GLCALLP glVertexAttrib3d)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
GLAPI void (GLCALLP glVertexAttrib3dv)(GLuint index, const GLdouble *v);
GLAPI void (GLCALLP glVertexAttrib3f)(GLuint index, GLfloat x, GLfloat y, GLfloat z);
GLAPI void (GLCALLP glVertexAttrib3fv)(GLuint index, const GLfloat *v);
GLAPI void (GLCALLP glVertexAttrib3s)(GLuint index, GLshort x, GLshort y, GLshort z);
GLAPI void (GLCALLP glVertexAttrib3sv)(GLuint index, const GLshort *v);
GLAPI void (GLCALLP glVertexAttrib4Nbv)(GLuint index, const GLbyte *v);
GLAPI void (GLCALLP glVertexAttrib4Niv)(GLuint index, const GLint *v);
GLAPI void (GLCALLP glVertexAttrib4Nsv)(GLuint index, const GLshort *v);
GLAPI void (GLCALLP glVertexAttrib4Nub)(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
GLAPI void (GLCALLP glVertexAttrib4Nubv)(GLuint index, const GLubyte *v);
GLAPI void (GLCALLP glVertexAttrib4Nuiv)(GLuint index, const GLuint *v);
GLAPI void (GLCALLP glVertexAttrib4Nusv)(GLuint index, const GLushort *v);
GLAPI void (GLCALLP glVertexAttrib4bv)(GLuint index, const GLbyte *v);
GLAPI void (GLCALLP glVertexAttrib4d)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI void (GLCALLP glVertexAttrib4dv)(GLuint index, const GLdouble *v);
GLAPI void (GLCALLP glVertexAttrib4f)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GLAPI void (GLCALLP glVertexAttrib4fv)(GLuint index, const GLfloat *v);
GLAPI void (GLCALLP glVertexAttrib4iv)(GLuint index, const GLint *v);
GLAPI void (GLCALLP glVertexAttrib4s)(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
GLAPI void (GLCALLP glVertexAttrib4sv)(GLuint index, const GLshort *v);
GLAPI void (GLCALLP glVertexAttrib4ubv)(GLuint index, const GLubyte *v);
GLAPI void (GLCALLP glVertexAttrib4uiv)(GLuint index, const GLuint *v);
GLAPI void (GLCALLP glVertexAttrib4usv)(GLuint index, const GLushort *v);
GLAPI void (GLCALLP glVertexAttribPointer)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);
#endif /* GL_VERSION_2_0 */

#ifndef GL_VERSION_2_1
#define GL_VERSION_2_1 1
#define GL_PIXEL_PACK_BUFFER              0x88EB
#define GL_PIXEL_UNPACK_BUFFER            0x88EC
#define GL_PIXEL_PACK_BUFFER_BINDING      0x88ED
#define GL_PIXEL_UNPACK_BUFFER_BINDING    0x88EF
#define GL_FLOAT_MAT2x3                   0x8B65
#define GL_FLOAT_MAT2x4                   0x8B66
#define GL_FLOAT_MAT3x2                   0x8B67
#define GL_FLOAT_MAT3x4                   0x8B68
#define GL_FLOAT_MAT4x2                   0x8B69
#define GL_FLOAT_MAT4x3                   0x8B6A
#define GL_SRGB                           0x8C40
#define GL_SRGB8                          0x8C41
#define GL_SRGB_ALPHA                     0x8C42
#define GL_SRGB8_ALPHA8                   0x8C43
#define GL_COMPRESSED_SRGB                0x8C48
#define GL_COMPRESSED_SRGB_ALPHA          0x8C49
GLAPI void (GLCALLP glUniformMatrix2x3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void (GLCALLP glUniformMatrix3x2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void (GLCALLP glUniformMatrix2x4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void (GLCALLP glUniformMatrix4x2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void (GLCALLP glUniformMatrix3x4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void (GLCALLP glUniformMatrix4x3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
#endif /* GL_VERSION_2_1 */

#ifndef GL_VERSION_3_0
#define GL_VERSION_3_0 1
typedef unsigned short GLhalf;
#define GL_COMPARE_REF_TO_TEXTURE         0x884E
#define GL_CLIP_DISTANCE0                 0x3000
#define GL_CLIP_DISTANCE1                 0x3001
#define GL_CLIP_DISTANCE2                 0x3002
#define GL_CLIP_DISTANCE3                 0x3003
#define GL_CLIP_DISTANCE4                 0x3004
#define GL_CLIP_DISTANCE5                 0x3005
#define GL_CLIP_DISTANCE6                 0x3006
#define GL_CLIP_DISTANCE7                 0x3007
#define GL_MAX_CLIP_DISTANCES             0x0D32
#define GL_MAJOR_VERSION                  0x821B
#define GL_MINOR_VERSION                  0x821C
#define GL_NUM_EXTENSIONS                 0x821D
#define GL_CONTEXT_FLAGS                  0x821E
#define GL_COMPRESSED_RED                 0x8225
#define GL_COMPRESSED_RG                  0x8226
#define GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT 0x00000001
#define GL_RGBA32F                        0x8814
#define GL_RGB32F                         0x8815
#define GL_RGBA16F                        0x881A
#define GL_RGB16F                         0x881B
#define GL_VERTEX_ATTRIB_ARRAY_INTEGER    0x88FD
#define GL_MAX_ARRAY_TEXTURE_LAYERS       0x88FF
#define GL_MIN_PROGRAM_TEXEL_OFFSET       0x8904
#define GL_MAX_PROGRAM_TEXEL_OFFSET       0x8905
#define GL_CLAMP_READ_COLOR               0x891C
#define GL_FIXED_ONLY                     0x891D
#define GL_MAX_VARYING_COMPONENTS         0x8B4B
#define GL_TEXTURE_1D_ARRAY               0x8C18
#define GL_PROXY_TEXTURE_1D_ARRAY         0x8C19
#define GL_TEXTURE_2D_ARRAY               0x8C1A
#define GL_PROXY_TEXTURE_2D_ARRAY         0x8C1B
#define GL_TEXTURE_BINDING_1D_ARRAY       0x8C1C
#define GL_TEXTURE_BINDING_2D_ARRAY       0x8C1D
#define GL_R11F_G11F_B10F                 0x8C3A
#define GL_UNSIGNED_INT_10F_11F_11F_REV   0x8C3B
#define GL_RGB9_E5                        0x8C3D
#define GL_UNSIGNED_INT_5_9_9_9_REV       0x8C3E
#define GL_TEXTURE_SHARED_SIZE            0x8C3F
#define GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH 0x8C76
#define GL_TRANSFORM_FEEDBACK_BUFFER_MODE 0x8C7F
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS 0x8C80
#define GL_TRANSFORM_FEEDBACK_VARYINGS    0x8C83
#define GL_TRANSFORM_FEEDBACK_BUFFER_START 0x8C84
#define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE 0x8C85
#define GL_PRIMITIVES_GENERATED           0x8C87
#define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN 0x8C88
#define GL_RASTERIZER_DISCARD             0x8C89
#define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS 0x8C8A
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS 0x8C8B
#define GL_INTERLEAVED_ATTRIBS            0x8C8C
#define GL_SEPARATE_ATTRIBS               0x8C8D
#define GL_TRANSFORM_FEEDBACK_BUFFER      0x8C8E
#define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING 0x8C8F
#define GL_RGBA32UI                       0x8D70
#define GL_RGB32UI                        0x8D71
#define GL_RGBA16UI                       0x8D76
#define GL_RGB16UI                        0x8D77
#define GL_RGBA8UI                        0x8D7C
#define GL_RGB8UI                         0x8D7D
#define GL_RGBA32I                        0x8D82
#define GL_RGB32I                         0x8D83
#define GL_RGBA16I                        0x8D88
#define GL_RGB16I                         0x8D89
#define GL_RGBA8I                         0x8D8E
#define GL_RGB8I                          0x8D8F
#define GL_RED_INTEGER                    0x8D94
#define GL_GREEN_INTEGER                  0x8D95
#define GL_BLUE_INTEGER                   0x8D96
#define GL_RGB_INTEGER                    0x8D98
#define GL_RGBA_INTEGER                   0x8D99
#define GL_BGR_INTEGER                    0x8D9A
#define GL_BGRA_INTEGER                   0x8D9B
#define GL_SAMPLER_1D_ARRAY               0x8DC0
#define GL_SAMPLER_2D_ARRAY               0x8DC1
#define GL_SAMPLER_1D_ARRAY_SHADOW        0x8DC3
#define GL_SAMPLER_2D_ARRAY_SHADOW        0x8DC4
#define GL_SAMPLER_CUBE_SHADOW            0x8DC5
#define GL_UNSIGNED_INT_VEC2              0x8DC6
#define GL_UNSIGNED_INT_VEC3              0x8DC7
#define GL_UNSIGNED_INT_VEC4              0x8DC8
#define GL_INT_SAMPLER_1D                 0x8DC9
#define GL_INT_SAMPLER_2D                 0x8DCA
#define GL_INT_SAMPLER_3D                 0x8DCB
#define GL_INT_SAMPLER_CUBE               0x8DCC
#define GL_INT_SAMPLER_1D_ARRAY           0x8DCE
#define GL_INT_SAMPLER_2D_ARRAY           0x8DCF
#define GL_UNSIGNED_INT_SAMPLER_1D        0x8DD1
#define GL_UNSIGNED_INT_SAMPLER_2D        0x8DD2
#define GL_UNSIGNED_INT_SAMPLER_3D        0x8DD3
#define GL_UNSIGNED_INT_SAMPLER_CUBE      0x8DD4
#define GL_UNSIGNED_INT_SAMPLER_1D_ARRAY  0x8DD6
#define GL_UNSIGNED_INT_SAMPLER_2D_ARRAY  0x8DD7
#define GL_QUERY_WAIT                     0x8E13
#define GL_QUERY_NO_WAIT                  0x8E14
#define GL_QUERY_BY_REGION_WAIT           0x8E15
#define GL_QUERY_BY_REGION_NO_WAIT        0x8E16
#define GL_BUFFER_ACCESS_FLAGS            0x911F
#define GL_BUFFER_MAP_LENGTH              0x9120
#define GL_BUFFER_MAP_OFFSET              0x9121
#define GL_DEPTH_COMPONENT32F             0x8CAC
#define GL_DEPTH32F_STENCIL8              0x8CAD
#define GL_FLOAT_32_UNSIGNED_INT_24_8_REV 0x8DAD
#define GL_INVALID_FRAMEBUFFER_OPERATION  0x0506
#define GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING 0x8210
#define GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE 0x8211
#define GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE 0x8212
#define GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE 0x8213
#define GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE 0x8214
#define GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE 0x8215
#define GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE 0x8216
#define GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE 0x8217
#define GL_FRAMEBUFFER_DEFAULT            0x8218
#define GL_FRAMEBUFFER_UNDEFINED          0x8219
#define GL_DEPTH_STENCIL_ATTACHMENT       0x821A
#define GL_MAX_RENDERBUFFER_SIZE          0x84E8
#define GL_DEPTH_STENCIL                  0x84F9
#define GL_UNSIGNED_INT_24_8              0x84FA
#define GL_DEPTH24_STENCIL8               0x88F0
#define GL_TEXTURE_STENCIL_SIZE           0x88F1
#define GL_TEXTURE_RED_TYPE               0x8C10
#define GL_TEXTURE_GREEN_TYPE             0x8C11
#define GL_TEXTURE_BLUE_TYPE              0x8C12
#define GL_TEXTURE_ALPHA_TYPE             0x8C13
#define GL_TEXTURE_DEPTH_TYPE             0x8C16
#define GL_UNSIGNED_NORMALIZED            0x8C17
#define GL_FRAMEBUFFER_BINDING            0x8CA6
#define GL_DRAW_FRAMEBUFFER_BINDING       0x8CA6
#define GL_RENDERBUFFER_BINDING           0x8CA7
#define GL_READ_FRAMEBUFFER               0x8CA8
#define GL_DRAW_FRAMEBUFFER               0x8CA9
#define GL_READ_FRAMEBUFFER_BINDING       0x8CAA
#define GL_RENDERBUFFER_SAMPLES           0x8CAB
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE 0x8CD0
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME 0x8CD1
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL 0x8CD2
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE 0x8CD3
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER 0x8CD4
#define GL_FRAMEBUFFER_COMPLETE           0x8CD5
#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT 0x8CD6
#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT 0x8CD7
#define GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER 0x8CDB
#define GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER 0x8CDC
#define GL_FRAMEBUFFER_UNSUPPORTED        0x8CDD
#define GL_MAX_COLOR_ATTACHMENTS          0x8CDF
#define GL_COLOR_ATTACHMENT0              0x8CE0
#define GL_COLOR_ATTACHMENT1              0x8CE1
#define GL_COLOR_ATTACHMENT2              0x8CE2
#define GL_COLOR_ATTACHMENT3              0x8CE3
#define GL_COLOR_ATTACHMENT4              0x8CE4
#define GL_COLOR_ATTACHMENT5              0x8CE5
#define GL_COLOR_ATTACHMENT6              0x8CE6
#define GL_COLOR_ATTACHMENT7              0x8CE7
#define GL_COLOR_ATTACHMENT8              0x8CE8
#define GL_COLOR_ATTACHMENT9              0x8CE9
#define GL_COLOR_ATTACHMENT10             0x8CEA
#define GL_COLOR_ATTACHMENT11             0x8CEB
#define GL_COLOR_ATTACHMENT12             0x8CEC
#define GL_COLOR_ATTACHMENT13             0x8CED
#define GL_COLOR_ATTACHMENT14             0x8CEE
#define GL_COLOR_ATTACHMENT15             0x8CEF
#define GL_COLOR_ATTACHMENT16             0x8CF0
#define GL_COLOR_ATTACHMENT17             0x8CF1
#define GL_COLOR_ATTACHMENT18             0x8CF2
#define GL_COLOR_ATTACHMENT19             0x8CF3
#define GL_COLOR_ATTACHMENT20             0x8CF4
#define GL_COLOR_ATTACHMENT21             0x8CF5
#define GL_COLOR_ATTACHMENT22             0x8CF6
#define GL_COLOR_ATTACHMENT23             0x8CF7
#define GL_COLOR_ATTACHMENT24             0x8CF8
#define GL_COLOR_ATTACHMENT25             0x8CF9
#define GL_COLOR_ATTACHMENT26             0x8CFA
#define GL_COLOR_ATTACHMENT27             0x8CFB
#define GL_COLOR_ATTACHMENT28             0x8CFC
#define GL_COLOR_ATTACHMENT29             0x8CFD
#define GL_COLOR_ATTACHMENT30             0x8CFE
#define GL_COLOR_ATTACHMENT31             0x8CFF
#define GL_DEPTH_ATTACHMENT               0x8D00
#define GL_STENCIL_ATTACHMENT             0x8D20
#define GL_FRAMEBUFFER                    0x8D40
#define GL_RENDERBUFFER                   0x8D41
#define GL_RENDERBUFFER_WIDTH             0x8D42
#define GL_RENDERBUFFER_HEIGHT            0x8D43
#define GL_RENDERBUFFER_INTERNAL_FORMAT   0x8D44
#define GL_STENCIL_INDEX1                 0x8D46
#define GL_STENCIL_INDEX4                 0x8D47
#define GL_STENCIL_INDEX8                 0x8D48
#define GL_STENCIL_INDEX16                0x8D49
#define GL_RENDERBUFFER_RED_SIZE          0x8D50
#define GL_RENDERBUFFER_GREEN_SIZE        0x8D51
#define GL_RENDERBUFFER_BLUE_SIZE         0x8D52
#define GL_RENDERBUFFER_ALPHA_SIZE        0x8D53
#define GL_RENDERBUFFER_DEPTH_SIZE        0x8D54
#define GL_RENDERBUFFER_STENCIL_SIZE      0x8D55
#define GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE 0x8D56
#define GL_MAX_SAMPLES                    0x8D57
#define GL_FRAMEBUFFER_SRGB               0x8DB9
#define GL_HALF_FLOAT                     0x140B
#define GL_MAP_READ_BIT                   0x0001
#define GL_MAP_WRITE_BIT                  0x0002
#define GL_MAP_INVALIDATE_RANGE_BIT       0x0004
#define GL_MAP_INVALIDATE_BUFFER_BIT      0x0008
#define GL_MAP_FLUSH_EXPLICIT_BIT         0x0010
#define GL_MAP_UNSYNCHRONIZED_BIT         0x0020
#define GL_COMPRESSED_RED_RGTC1           0x8DBB
#define GL_COMPRESSED_SIGNED_RED_RGTC1    0x8DBC
#define GL_COMPRESSED_RG_RGTC2            0x8DBD
#define GL_COMPRESSED_SIGNED_RG_RGTC2     0x8DBE
#define GL_RG                             0x8227
#define GL_RG_INTEGER                     0x8228
#define GL_R8                             0x8229
#define GL_R16                            0x822A
#define GL_RG8                            0x822B
#define GL_RG16                           0x822C
#define GL_R16F                           0x822D
#define GL_R32F                           0x822E
#define GL_RG16F                          0x822F
#define GL_RG32F                          0x8230
#define GL_R8I                            0x8231
#define GL_R8UI                           0x8232
#define GL_R16I                           0x8233
#define GL_R16UI                          0x8234
#define GL_R32I                           0x8235
#define GL_R32UI                          0x8236
#define GL_RG8I                           0x8237
#define GL_RG8UI                          0x8238
#define GL_RG16I                          0x8239
#define GL_RG16UI                         0x823A
#define GL_RG32I                          0x823B
#define GL_RG32UI                         0x823C
#define GL_VERTEX_ARRAY_BINDING           0x85B5
GLAPI void (GLCALLP glColorMaski)(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
GLAPI void (GLCALLP glGetBooleani_v)(GLenum target, GLuint index, GLboolean *data);
GLAPI void (GLCALLP glGetIntegeri_v)(GLenum target, GLuint index, GLint *data);
GLAPI void (GLCALLP glEnablei)(GLenum target, GLuint index);
GLAPI void (GLCALLP glDisablei)(GLenum target, GLuint index);
GLAPI GLboolean (GLCALLP glIsEnabledi)(GLenum target, GLuint index);
GLAPI void (GLCALLP glBeginTransformFeedback)(GLenum primitiveMode);
GLAPI void (GLCALLP glEndTransformFeedback)(void);
GLAPI void (GLCALLP glBindBufferRange)(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
GLAPI void (GLCALLP glBindBufferBase)(GLenum target, GLuint index, GLuint buffer);
GLAPI void (GLCALLP glTransformFeedbackVaryings)(GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode);
GLAPI void (GLCALLP glGetTransformFeedbackVarying)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
GLAPI void (GLCALLP glClampColor)(GLenum target, GLenum clamp);
GLAPI void (GLCALLP glBeginConditionalRender)(GLuint id, GLenum mode);
GLAPI void (GLCALLP glEndConditionalRender)(void);
GLAPI void (GLCALLP glVertexAttribIPointer)(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
GLAPI void (GLCALLP glGetVertexAttribIiv)(GLuint index, GLenum pname, GLint *params);
GLAPI void (GLCALLP glGetVertexAttribIuiv)(GLuint index, GLenum pname, GLuint *params);
GLAPI void (GLCALLP glVertexAttribI1i)(GLuint index, GLint x);
GLAPI void (GLCALLP glVertexAttribI2i)(GLuint index, GLint x, GLint y);
GLAPI void (GLCALLP glVertexAttribI3i)(GLuint index, GLint x, GLint y, GLint z);
GLAPI void (GLCALLP glVertexAttribI4i)(GLuint index, GLint x, GLint y, GLint z, GLint w);
GLAPI void (GLCALLP glVertexAttribI1ui)(GLuint index, GLuint x);
GLAPI void (GLCALLP glVertexAttribI2ui)(GLuint index, GLuint x, GLuint y);
GLAPI void (GLCALLP glVertexAttribI3ui)(GLuint index, GLuint x, GLuint y, GLuint z);
GLAPI void (GLCALLP glVertexAttribI4ui)(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
GLAPI void (GLCALLP glVertexAttribI1iv)(GLuint index, const GLint *v);
GLAPI void (GLCALLP glVertexAttribI2iv)(GLuint index, const GLint *v);
GLAPI void (GLCALLP glVertexAttribI3iv)(GLuint index, const GLint *v);
GLAPI void (GLCALLP glVertexAttribI4iv)(GLuint index, const GLint *v);
GLAPI void (GLCALLP glVertexAttribI1uiv)(GLuint index, const GLuint *v);
GLAPI void (GLCALLP glVertexAttribI2uiv)(GLuint index, const GLuint *v);
GLAPI void (GLCALLP glVertexAttribI3uiv)(GLuint index, const GLuint *v);
GLAPI void (GLCALLP glVertexAttribI4uiv)(GLuint index, const GLuint *v);
GLAPI void (GLCALLP glVertexAttribI4bv)(GLuint index, const GLbyte *v);
GLAPI void (GLCALLP glVertexAttribI4sv)(GLuint index, const GLshort *v);
GLAPI void (GLCALLP glVertexAttribI4ubv)(GLuint index, const GLubyte *v);
GLAPI void (GLCALLP glVertexAttribI4usv)(GLuint index, const GLushort *v);
GLAPI void (GLCALLP glGetUniformuiv)(GLuint program, GLint location, GLuint *params);
GLAPI void (GLCALLP glBindFragDataLocation)(GLuint program, GLuint color, const GLchar *name);
GLAPI GLint (GLCALLP glGetFragDataLocation)(GLuint program, const GLchar *name);
GLAPI void (GLCALLP glUniform1ui)(GLint location, GLuint v0);
GLAPI void (GLCALLP glUniform2ui)(GLint location, GLuint v0, GLuint v1);
GLAPI void (GLCALLP glUniform3ui)(GLint location, GLuint v0, GLuint v1, GLuint v2);
GLAPI void (GLCALLP glUniform4ui)(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
GLAPI void (GLCALLP glUniform1uiv)(GLint location, GLsizei count, const GLuint *value);
GLAPI void (GLCALLP glUniform2uiv)(GLint location, GLsizei count, const GLuint *value);
GLAPI void (GLCALLP glUniform3uiv)(GLint location, GLsizei count, const GLuint *value);
GLAPI void (GLCALLP glUniform4uiv)(GLint location, GLsizei count, const GLuint *value);
GLAPI void (GLCALLP glTexParameterIiv)(GLenum target, GLenum pname, const GLint *params);
GLAPI void (GLCALLP glTexParameterIuiv)(GLenum target, GLenum pname, const GLuint *params);
GLAPI void (GLCALLP glGetTexParameterIiv)(GLenum target, GLenum pname, GLint *params);
GLAPI void (GLCALLP glGetTexParameterIuiv)(GLenum target, GLenum pname, GLuint *params);
GLAPI void (GLCALLP glClearBufferiv)(GLenum buffer, GLint drawbuffer, const GLint *value);
GLAPI void (GLCALLP glClearBufferuiv)(GLenum buffer, GLint drawbuffer, const GLuint *value);
GLAPI void (GLCALLP glClearBufferfv)(GLenum buffer, GLint drawbuffer, const GLfloat *value);
GLAPI void (GLCALLP glClearBufferfi)(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
GLAPI const GLubyte *(GLCALLP glGetStringi)(GLenum name, GLuint index);
GLAPI GLboolean (GLCALLP glIsRenderbuffer)(GLuint renderbuffer);
GLAPI void (GLCALLP glBindRenderbuffer)(GLenum target, GLuint renderbuffer);
GLAPI void (GLCALLP glDeleteRenderbuffers)(GLsizei n, const GLuint *renderbuffers);
GLAPI void (GLCALLP glGenRenderbuffers)(GLsizei n, GLuint *renderbuffers);
GLAPI void (GLCALLP glRenderbufferStorage)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI void (GLCALLP glGetRenderbufferParameteriv)(GLenum target, GLenum pname, GLint *params);
GLAPI GLboolean (GLCALLP glIsFramebuffer)(GLuint framebuffer);
GLAPI void (GLCALLP glBindFramebuffer)(GLenum target, GLuint framebuffer);
GLAPI void (GLCALLP glDeleteFramebuffers)(GLsizei n, const GLuint *framebuffers);
GLAPI void (GLCALLP glGenFramebuffers)(GLsizei n, GLuint *framebuffers);
GLAPI GLenum (GLCALLP glCheckFramebufferStatus)(GLenum target);
GLAPI void (GLCALLP glFramebufferTexture1D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
GLAPI void (GLCALLP glFramebufferTexture2D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
GLAPI void (GLCALLP glFramebufferTexture3D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
GLAPI void (GLCALLP glFramebufferRenderbuffer)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
GLAPI void (GLCALLP glGetFramebufferAttachmentParameteriv)(GLenum target, GLenum attachment, GLenum pname, GLint *params);
GLAPI void (GLCALLP glGenerateMipmap)(GLenum target);
GLAPI void (GLCALLP glBlitFramebuffer)(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
GLAPI void (GLCALLP glRenderbufferStorageMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI void (GLCALLP glFramebufferTextureLayer)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
GLAPI void *(GLCALLP glMapBufferRange)(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
GLAPI void (GLCALLP glFlushMappedBufferRange)(GLenum target, GLintptr offset, GLsizeiptr length);
GLAPI void (GLCALLP glBindVertexArray)(GLuint array);
GLAPI void (GLCALLP glDeleteVertexArrays)(GLsizei n, const GLuint *arrays);
GLAPI void (GLCALLP glGenVertexArrays)(GLsizei n, GLuint *arrays);
GLAPI GLboolean (GLCALLP glIsVertexArray)(GLuint array);
#endif /* GL_VERSION_3_0 */

#ifndef GL_VERSION_3_1
#define GL_VERSION_3_1 1
#define GL_SAMPLER_2D_RECT                0x8B63
#define GL_SAMPLER_2D_RECT_SHADOW         0x8B64
#define GL_SAMPLER_BUFFER                 0x8DC2
#define GL_INT_SAMPLER_2D_RECT            0x8DCD
#define GL_INT_SAMPLER_BUFFER             0x8DD0
#define GL_UNSIGNED_INT_SAMPLER_2D_RECT   0x8DD5
#define GL_UNSIGNED_INT_SAMPLER_BUFFER    0x8DD8
#define GL_TEXTURE_BUFFER                 0x8C2A
#define GL_MAX_TEXTURE_BUFFER_SIZE        0x8C2B
#define GL_TEXTURE_BINDING_BUFFER         0x8C2C
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING 0x8C2D
#define GL_TEXTURE_RECTANGLE              0x84F5
#define GL_TEXTURE_BINDING_RECTANGLE      0x84F6
#define GL_PROXY_TEXTURE_RECTANGLE        0x84F7
#define GL_MAX_RECTANGLE_TEXTURE_SIZE     0x84F8
#define GL_R8_SNORM                       0x8F94
#define GL_RG8_SNORM                      0x8F95
#define GL_RGB8_SNORM                     0x8F96
#define GL_RGBA8_SNORM                    0x8F97
#define GL_R16_SNORM                      0x8F98
#define GL_RG16_SNORM                     0x8F99
#define GL_RGB16_SNORM                    0x8F9A
#define GL_RGBA16_SNORM                   0x8F9B
#define GL_SIGNED_NORMALIZED              0x8F9C
#define GL_PRIMITIVE_RESTART              0x8F9D
#define GL_PRIMITIVE_RESTART_INDEX        0x8F9E
#define GL_COPY_READ_BUFFER               0x8F36
#define GL_COPY_WRITE_BUFFER              0x8F37
#define GL_UNIFORM_BUFFER                 0x8A11
#define GL_UNIFORM_BUFFER_BINDING         0x8A28
#define GL_UNIFORM_BUFFER_START           0x8A29
#define GL_UNIFORM_BUFFER_SIZE            0x8A2A
#define GL_MAX_VERTEX_UNIFORM_BLOCKS      0x8A2B
#define GL_MAX_GEOMETRY_UNIFORM_BLOCKS    0x8A2C
#define GL_MAX_FRAGMENT_UNIFORM_BLOCKS    0x8A2D
#define GL_MAX_COMBINED_UNIFORM_BLOCKS    0x8A2E
#define GL_MAX_UNIFORM_BUFFER_BINDINGS    0x8A2F
#define GL_MAX_UNIFORM_BLOCK_SIZE         0x8A30
#define GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS 0x8A31
#define GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS 0x8A32
#define GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS 0x8A33
#define GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT 0x8A34
#define GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH 0x8A35
#define GL_ACTIVE_UNIFORM_BLOCKS          0x8A36
#define GL_UNIFORM_TYPE                   0x8A37
#define GL_UNIFORM_SIZE                   0x8A38
#define GL_UNIFORM_NAME_LENGTH            0x8A39
#define GL_UNIFORM_BLOCK_INDEX            0x8A3A
#define GL_UNIFORM_OFFSET                 0x8A3B
#define GL_UNIFORM_ARRAY_STRIDE           0x8A3C
#define GL_UNIFORM_MATRIX_STRIDE          0x8A3D
#define GL_UNIFORM_IS_ROW_MAJOR           0x8A3E
#define GL_UNIFORM_BLOCK_BINDING          0x8A3F
#define GL_UNIFORM_BLOCK_DATA_SIZE        0x8A40
#define GL_UNIFORM_BLOCK_NAME_LENGTH      0x8A41
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS  0x8A42
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES 0x8A43
#define GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER 0x8A44
#define GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER 0x8A45
#define GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER 0x8A46
#define GL_INVALID_INDEX                  0xFFFFFFFFu
GLAPI void (GLCALLP glDrawArraysInstanced)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
GLAPI void (GLCALLP glDrawElementsInstanced)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount);
GLAPI void (GLCALLP glTexBuffer)(GLenum target, GLenum internalformat, GLuint buffer);
GLAPI void (GLCALLP glPrimitiveRestartIndex)(GLuint index);
GLAPI void (GLCALLP glCopyBufferSubData)(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
GLAPI void (GLCALLP glGetUniformIndices)(GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices);
GLAPI void (GLCALLP glGetActiveUniformsiv)(GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params);
GLAPI void (GLCALLP glGetActiveUniformName)(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName);
GLAPI GLuint (GLCALLP glGetUniformBlockIndex)(GLuint program, const GLchar *uniformBlockName);
GLAPI void (GLCALLP glGetActiveUniformBlockiv)(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params);
GLAPI void (GLCALLP glGetActiveUniformBlockName)(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName);
GLAPI void (GLCALLP glUniformBlockBinding)(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
#endif /* GL_VERSION_3_1 */

#ifndef GL_VERSION_3_2
#define GL_VERSION_3_2 1
typedef struct __GLsync *GLsync;
#ifndef GLEXT_64_TYPES_DEFINED
/* This code block is duplicated in glxext.h, so must be protected */
#define GLEXT_64_TYPES_DEFINED
/* Define int32_t, int64_t, and uint64_t types for UST/MSC */
/* (as used in the GL_EXT_timer_query extension). */
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
#include <inttypes.h>
#elif defined(__sun__) || defined(__digital__)
#include <inttypes.h>
#if defined(__STDC__)
#if defined(__arch64__) || defined(_LP64)
typedef long int int64_t;
typedef unsigned long int uint64_t;
#else
typedef long long int int64_t;
typedef unsigned long long int uint64_t;
#endif /* __arch64__ */
#endif /* __STDC__ */
#elif defined( __VMS ) || defined(__sgi)
#include <inttypes.h>
#elif defined(__SCO__) || defined(__USLC__)
#include <stdint.h>
#elif defined(__UNIXOS2__) || defined(__SOL64__)
typedef long int int32_t;
typedef long long int int64_t;
typedef unsigned long long int uint64_t;
#elif defined(_WIN32) && defined(__GNUC__)
#include <stdint.h>
#elif defined(_WIN32)
typedef __int32 int32_t;
typedef __int64 int64_t;
typedef unsigned __int64 uint64_t;
#else
/* Fallback if nothing above works */
#include <inttypes.h>
#endif
#endif
typedef uint64_t GLuint64;
typedef int64_t GLint64;
#define GL_CONTEXT_CORE_PROFILE_BIT       0x00000001
#define GL_CONTEXT_COMPATIBILITY_PROFILE_BIT 0x00000002
#define GL_LINES_ADJACENCY                0x000A
#define GL_LINE_STRIP_ADJACENCY           0x000B
#define GL_TRIANGLES_ADJACENCY            0x000C
#define GL_TRIANGLE_STRIP_ADJACENCY       0x000D
#define GL_PROGRAM_POINT_SIZE             0x8642
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS 0x8C29
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED 0x8DA7
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS 0x8DA8
#define GL_GEOMETRY_SHADER                0x8DD9
#define GL_GEOMETRY_VERTICES_OUT          0x8916
#define GL_GEOMETRY_INPUT_TYPE            0x8917
#define GL_GEOMETRY_OUTPUT_TYPE           0x8918
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS 0x8DDF
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES   0x8DE0
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS 0x8DE1
#define GL_MAX_VERTEX_OUTPUT_COMPONENTS   0x9122
#define GL_MAX_GEOMETRY_INPUT_COMPONENTS  0x9123
#define GL_MAX_GEOMETRY_OUTPUT_COMPONENTS 0x9124
#define GL_MAX_FRAGMENT_INPUT_COMPONENTS  0x9125
#define GL_CONTEXT_PROFILE_MASK           0x9126
#define GL_DEPTH_CLAMP                    0x864F
#define GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION 0x8E4C
#define GL_FIRST_VERTEX_CONVENTION        0x8E4D
#define GL_LAST_VERTEX_CONVENTION         0x8E4E
#define GL_PROVOKING_VERTEX               0x8E4F
#define GL_TEXTURE_CUBE_MAP_SEAMLESS      0x884F
#define GL_MAX_SERVER_WAIT_TIMEOUT        0x9111
#define GL_OBJECT_TYPE                    0x9112
#define GL_SYNC_CONDITION                 0x9113
#define GL_SYNC_STATUS                    0x9114
#define GL_SYNC_FLAGS                     0x9115
#define GL_SYNC_FENCE                     0x9116
#define GL_SYNC_GPU_COMMANDS_COMPLETE     0x9117
#define GL_UNSIGNALED                     0x9118
#define GL_SIGNALED                       0x9119
#define GL_ALREADY_SIGNALED               0x911A
#define GL_TIMEOUT_EXPIRED                0x911B
#define GL_CONDITION_SATISFIED            0x911C
#define GL_WAIT_FAILED                    0x911D
#define GL_TIMEOUT_IGNORED                0xFFFFFFFFFFFFFFFFull
#define GL_SYNC_FLUSH_COMMANDS_BIT        0x00000001
#define GL_SAMPLE_POSITION                0x8E50
#define GL_SAMPLE_MASK                    0x8E51
#define GL_SAMPLE_MASK_VALUE              0x8E52
#define GL_MAX_SAMPLE_MASK_WORDS          0x8E59
#define GL_TEXTURE_2D_MULTISAMPLE         0x9100
#define GL_PROXY_TEXTURE_2D_MULTISAMPLE   0x9101
#define GL_TEXTURE_2D_MULTISAMPLE_ARRAY   0x9102
#define GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY 0x9103
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE 0x9104
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY 0x9105
#define GL_TEXTURE_SAMPLES                0x9106
#define GL_TEXTURE_FIXED_SAMPLE_LOCATIONS 0x9107
#define GL_SAMPLER_2D_MULTISAMPLE         0x9108
#define GL_INT_SAMPLER_2D_MULTISAMPLE     0x9109
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE 0x910A
#define GL_SAMPLER_2D_MULTISAMPLE_ARRAY   0x910B
#define GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910C
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910D
#define GL_MAX_COLOR_TEXTURE_SAMPLES      0x910E
#define GL_MAX_DEPTH_TEXTURE_SAMPLES      0x910F
#define GL_MAX_INTEGER_SAMPLES            0x9110
GLAPI void (GLCALLP glDrawElementsBaseVertex)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex);
GLAPI void (GLCALLP glDrawRangeElementsBaseVertex)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex);
GLAPI void (GLCALLP glDrawElementsInstancedBaseVertex)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex);
GLAPI void (GLCALLP glMultiDrawElementsBaseVertex)(GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount, const GLint *basevertex);
GLAPI void (GLCALLP glProvokingVertex)(GLenum mode);
GLAPI GLsync (GLCALLP glFenceSync)(GLenum condition, GLbitfield flags);
GLAPI GLboolean (GLCALLP glIsSync)(GLsync sync);
GLAPI void (GLCALLP glDeleteSync)(GLsync sync);
GLAPI GLenum (GLCALLP glClientWaitSync)(GLsync sync, GLbitfield flags, GLuint64 timeout);
GLAPI void (GLCALLP glWaitSync)(GLsync sync, GLbitfield flags, GLuint64 timeout);
GLAPI void (GLCALLP glGetInteger64v)(GLenum pname, GLint64 *data);
GLAPI void (GLCALLP glGetSynciv)(GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values);
GLAPI void (GLCALLP glGetInteger64i_v)(GLenum target, GLuint index, GLint64 *data);
GLAPI void (GLCALLP glGetBufferParameteri64v)(GLenum target, GLenum pname, GLint64 *params);
GLAPI void (GLCALLP glFramebufferTexture)(GLenum target, GLenum attachment, GLuint texture, GLint level);
GLAPI void (GLCALLP glTexImage2DMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
GLAPI void (GLCALLP glTexImage3DMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
GLAPI void (GLCALLP glGetMultisamplefv)(GLenum pname, GLuint index, GLfloat *val);
GLAPI void (GLCALLP glSampleMaski)(GLuint maskNumber, GLbitfield mask);
#endif /* GL_VERSION_3_2 */

#ifndef GL_VERSION_3_3
#define GL_VERSION_3_3 1
#define GL_VERTEX_ATTRIB_ARRAY_DIVISOR    0x88FE
#define GL_SRC1_COLOR                     0x88F9
#define GL_ONE_MINUS_SRC1_COLOR           0x88FA
#define GL_ONE_MINUS_SRC1_ALPHA           0x88FB
#define GL_MAX_DUAL_SOURCE_DRAW_BUFFERS   0x88FC
#define GL_ANY_SAMPLES_PASSED             0x8C2F
#define GL_SAMPLER_BINDING                0x8919
#define GL_RGB10_A2UI                     0x906F
#define GL_TEXTURE_SWIZZLE_R              0x8E42
#define GL_TEXTURE_SWIZZLE_G              0x8E43
#define GL_TEXTURE_SWIZZLE_B              0x8E44
#define GL_TEXTURE_SWIZZLE_A              0x8E45
#define GL_TEXTURE_SWIZZLE_RGBA           0x8E46
#define GL_TIME_ELAPSED                   0x88BF
#define GL_TIMESTAMP                      0x8E28
#define GL_INT_2_10_10_10_REV             0x8D9F
GLAPI void (GLCALLP glBindFragDataLocationIndexed)(GLuint program, GLuint colorNumber, GLuint index, const GLchar *name);
GLAPI GLint (GLCALLP glGetFragDataIndex)(GLuint program, const GLchar *name);
GLAPI void (GLCALLP glGenSamplers)(GLsizei count, GLuint *samplers);
GLAPI void (GLCALLP glDeleteSamplers)(GLsizei count, const GLuint *samplers);
GLAPI GLboolean (GLCALLP glIsSampler)(GLuint sampler);
GLAPI void (GLCALLP glBindSampler)(GLuint unit, GLuint sampler);
GLAPI void (GLCALLP glSamplerParameteri)(GLuint sampler, GLenum pname, GLint param);
GLAPI void (GLCALLP glSamplerParameteriv)(GLuint sampler, GLenum pname, const GLint *param);
GLAPI void (GLCALLP glSamplerParameterf)(GLuint sampler, GLenum pname, GLfloat param);
GLAPI void (GLCALLP glSamplerParameterfv)(GLuint sampler, GLenum pname, const GLfloat *param);
GLAPI void (GLCALLP glSamplerParameterIiv)(GLuint sampler, GLenum pname, const GLint *param);
GLAPI void (GLCALLP glSamplerParameterIuiv)(GLuint sampler, GLenum pname, const GLuint *param);
GLAPI void (GLCALLP glGetSamplerParameteriv)(GLuint sampler, GLenum pname, GLint *params);
GLAPI void (GLCALLP glGetSamplerParameterIiv)(GLuint sampler, GLenum pname, GLint *params);
GLAPI void (GLCALLP glGetSamplerParameterfv)(GLuint sampler, GLenum pname, GLfloat *params);
GLAPI void (GLCALLP glGetSamplerParameterIuiv)(GLuint sampler, GLenum pname, GLuint *params);
GLAPI void (GLCALLP glQueryCounter)(GLuint id, GLenum target);
GLAPI void (GLCALLP glGetQueryObjecti64v)(GLuint id, GLenum pname, GLint64 *params);
GLAPI void (GLCALLP glGetQueryObjectui64v)(GLuint id, GLenum pname, GLuint64 *params);
GLAPI void (GLCALLP glVertexAttribDivisor)(GLuint index, GLuint divisor);
GLAPI void (GLCALLP glVertexAttribP1ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
GLAPI void (GLCALLP glVertexAttribP1uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
GLAPI void (GLCALLP glVertexAttribP2ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
GLAPI void (GLCALLP glVertexAttribP2uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
GLAPI void (GLCALLP glVertexAttribP3ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
GLAPI void (GLCALLP glVertexAttribP3uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
GLAPI void (GLCALLP glVertexAttribP4ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
GLAPI void (GLCALLP glVertexAttribP4uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
#endif /* GL_VERSION_3_3 */

#ifndef GL_VERSION_4_0
#define GL_VERSION_4_0 1
#define GL_SAMPLE_SHADING                 0x8C36
#define GL_MIN_SAMPLE_SHADING_VALUE       0x8C37
#define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET 0x8E5E
#define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET 0x8E5F
#define GL_TEXTURE_CUBE_MAP_ARRAY         0x9009
#define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY 0x900A
#define GL_PROXY_TEXTURE_CUBE_MAP_ARRAY   0x900B
#define GL_SAMPLER_CUBE_MAP_ARRAY         0x900C
#define GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW  0x900D
#define GL_INT_SAMPLER_CUBE_MAP_ARRAY     0x900E
#define GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY 0x900F
#define GL_DRAW_INDIRECT_BUFFER           0x8F3F
#define GL_DRAW_INDIRECT_BUFFER_BINDING   0x8F43
#define GL_GEOMETRY_SHADER_INVOCATIONS    0x887F
#define GL_MAX_GEOMETRY_SHADER_INVOCATIONS 0x8E5A
#define GL_MIN_FRAGMENT_INTERPOLATION_OFFSET 0x8E5B
#define GL_MAX_FRAGMENT_INTERPOLATION_OFFSET 0x8E5C
#define GL_FRAGMENT_INTERPOLATION_OFFSET_BITS 0x8E5D
#define GL_MAX_VERTEX_STREAMS             0x8E71
#define GL_DOUBLE_VEC2                    0x8FFC
#define GL_DOUBLE_VEC3                    0x8FFD
#define GL_DOUBLE_VEC4                    0x8FFE
#define GL_DOUBLE_MAT2                    0x8F46
#define GL_DOUBLE_MAT3                    0x8F47
#define GL_DOUBLE_MAT4                    0x8F48
#define GL_DOUBLE_MAT2x3                  0x8F49
#define GL_DOUBLE_MAT2x4                  0x8F4A
#define GL_DOUBLE_MAT3x2                  0x8F4B
#define GL_DOUBLE_MAT3x4                  0x8F4C
#define GL_DOUBLE_MAT4x2                  0x8F4D
#define GL_DOUBLE_MAT4x3                  0x8F4E
#define GL_ACTIVE_SUBROUTINES             0x8DE5
#define GL_ACTIVE_SUBROUTINE_UNIFORMS     0x8DE6
#define GL_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS 0x8E47
#define GL_ACTIVE_SUBROUTINE_MAX_LENGTH   0x8E48
#define GL_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH 0x8E49
#define GL_MAX_SUBROUTINES                0x8DE7
#define GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS 0x8DE8
#define GL_NUM_COMPATIBLE_SUBROUTINES     0x8E4A
#define GL_COMPATIBLE_SUBROUTINES         0x8E4B
#define GL_PATCHES                        0x000E
#define GL_PATCH_VERTICES                 0x8E72
#define GL_PATCH_DEFAULT_INNER_LEVEL      0x8E73
#define GL_PATCH_DEFAULT_OUTER_LEVEL      0x8E74
#define GL_TESS_CONTROL_OUTPUT_VERTICES   0x8E75
#define GL_TESS_GEN_MODE                  0x8E76
#define GL_TESS_GEN_SPACING               0x8E77
#define GL_TESS_GEN_VERTEX_ORDER          0x8E78
#define GL_TESS_GEN_POINT_MODE            0x8E79
#define GL_ISOLINES                       0x8E7A
#define GL_FRACTIONAL_ODD                 0x8E7B
#define GL_FRACTIONAL_EVEN                0x8E7C
#define GL_MAX_PATCH_VERTICES             0x8E7D
#define GL_MAX_TESS_GEN_LEVEL             0x8E7E
#define GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS 0x8E7F
#define GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS 0x8E80
#define GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS 0x8E81
#define GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS 0x8E82
#define GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS 0x8E83
#define GL_MAX_TESS_PATCH_COMPONENTS      0x8E84
#define GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS 0x8E85
#define GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS 0x8E86
#define GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS 0x8E89
#define GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS 0x8E8A
#define GL_MAX_TESS_CONTROL_INPUT_COMPONENTS 0x886C
#define GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS 0x886D
#define GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS 0x8E1E
#define GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS 0x8E1F
#define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER 0x84F0
#define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER 0x84F1
#define GL_TESS_EVALUATION_SHADER         0x8E87
#define GL_TESS_CONTROL_SHADER            0x8E88
#define GL_TRANSFORM_FEEDBACK             0x8E22
#define GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED 0x8E23
#define GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE 0x8E24
#define GL_TRANSFORM_FEEDBACK_BINDING     0x8E25
#define GL_MAX_TRANSFORM_FEEDBACK_BUFFERS 0x8E70
GLAPI void (GLCALLP glMinSampleShading)(GLfloat value);
GLAPI void (GLCALLP glBlendEquationi)(GLuint buf, GLenum mode);
GLAPI void (GLCALLP glBlendEquationSeparatei)(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
GLAPI void (GLCALLP glBlendFunci)(GLuint buf, GLenum src, GLenum dst);
GLAPI void (GLCALLP glBlendFuncSeparatei)(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
GLAPI void (GLCALLP glDrawArraysIndirect)(GLenum mode, const void *indirect);
GLAPI void (GLCALLP glDrawElementsIndirect)(GLenum mode, GLenum type, const void *indirect);
GLAPI void (GLCALLP glUniform1d)(GLint location, GLdouble x);
GLAPI void (GLCALLP glUniform2d)(GLint location, GLdouble x, GLdouble y);
GLAPI void (GLCALLP glUniform3d)(GLint location, GLdouble x, GLdouble y, GLdouble z);
GLAPI void (GLCALLP glUniform4d)(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI void (GLCALLP glUniform1dv)(GLint location, GLsizei count, const GLdouble *value);
GLAPI void (GLCALLP glUniform2dv)(GLint location, GLsizei count, const GLdouble *value);
GLAPI void (GLCALLP glUniform3dv)(GLint location, GLsizei count, const GLdouble *value);
GLAPI void (GLCALLP glUniform4dv)(GLint location, GLsizei count, const GLdouble *value);
GLAPI void (GLCALLP glUniformMatrix2dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void (GLCALLP glUniformMatrix3dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void (GLCALLP glUniformMatrix4dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void (GLCALLP glUniformMatrix2x3dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void (GLCALLP glUniformMatrix2x4dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void (GLCALLP glUniformMatrix3x2dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void (GLCALLP glUniformMatrix3x4dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void (GLCALLP glUniformMatrix4x2dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void (GLCALLP glUniformMatrix4x3dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void (GLCALLP glGetUniformdv)(GLuint program, GLint location, GLdouble *params);
GLAPI GLint (GLCALLP glGetSubroutineUniformLocation)(GLuint program, GLenum shadertype, const GLchar *name);
GLAPI GLuint (GLCALLP glGetSubroutineIndex)(GLuint program, GLenum shadertype, const GLchar *name);
GLAPI void (GLCALLP glGetActiveSubroutineUniformiv)(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint *values);
GLAPI void (GLCALLP glGetActiveSubroutineUniformName)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name);
GLAPI void (GLCALLP glGetActiveSubroutineName)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name);
GLAPI void (GLCALLP glUniformSubroutinesuiv)(GLenum shadertype, GLsizei count, const GLuint *indices);
GLAPI void (GLCALLP glGetUniformSubroutineuiv)(GLenum shadertype, GLint location, GLuint *params);
GLAPI void (GLCALLP glGetProgramStageiv)(GLuint program, GLenum shadertype, GLenum pname, GLint *values);
GLAPI void (GLCALLP glPatchParameteri)(GLenum pname, GLint value);
GLAPI void (GLCALLP glPatchParameterfv)(GLenum pname, const GLfloat *values);
GLAPI void (GLCALLP glBindTransformFeedback)(GLenum target, GLuint id);
GLAPI void (GLCALLP glDeleteTransformFeedbacks)(GLsizei n, const GLuint *ids);
GLAPI void (GLCALLP glGenTransformFeedbacks)(GLsizei n, GLuint *ids);
GLAPI GLboolean (GLCALLP glIsTransformFeedback)(GLuint id);
GLAPI void (GLCALLP glPauseTransformFeedback)(void);
GLAPI void (GLCALLP glResumeTransformFeedback)(void);
GLAPI void (GLCALLP glDrawTransformFeedback)(GLenum mode, GLuint id);
GLAPI void (GLCALLP glDrawTransformFeedbackStream)(GLenum mode, GLuint id, GLuint stream);
GLAPI void (GLCALLP glBeginQueryIndexed)(GLenum target, GLuint index, GLuint id);
GLAPI void (GLCALLP glEndQueryIndexed)(GLenum target, GLuint index);
GLAPI void (GLCALLP glGetQueryIndexediv)(GLenum target, GLuint index, GLenum pname, GLint *params);
#endif /* GL_VERSION_4_0 */

#ifndef GL_VERSION_4_1
#define GL_VERSION_4_1 1
#define GL_FIXED                          0x140C
#define GL_IMPLEMENTATION_COLOR_READ_TYPE 0x8B9A
#define GL_IMPLEMENTATION_COLOR_READ_FORMAT 0x8B9B
#define GL_LOW_FLOAT                      0x8DF0
#define GL_MEDIUM_FLOAT                   0x8DF1
#define GL_HIGH_FLOAT                     0x8DF2
#define GL_LOW_INT                        0x8DF3
#define GL_MEDIUM_INT                     0x8DF4
#define GL_HIGH_INT                       0x8DF5
#define GL_SHADER_COMPILER                0x8DFA
#define GL_SHADER_BINARY_FORMATS          0x8DF8
#define GL_NUM_SHADER_BINARY_FORMATS      0x8DF9
#define GL_MAX_VERTEX_UNIFORM_VECTORS     0x8DFB
#define GL_MAX_VARYING_VECTORS            0x8DFC
#define GL_MAX_FRAGMENT_UNIFORM_VECTORS   0x8DFD
#define GL_RGB565                         0x8D62
#define GL_PROGRAM_BINARY_RETRIEVABLE_HINT 0x8257
#define GL_PROGRAM_BINARY_LENGTH          0x8741
#define GL_NUM_PROGRAM_BINARY_FORMATS     0x87FE
#define GL_PROGRAM_BINARY_FORMATS         0x87FF
#define GL_VERTEX_SHADER_BIT              0x00000001
#define GL_FRAGMENT_SHADER_BIT            0x00000002
#define GL_GEOMETRY_SHADER_BIT            0x00000004
#define GL_TESS_CONTROL_SHADER_BIT        0x00000008
#define GL_TESS_EVALUATION_SHADER_BIT     0x00000010
#define GL_ALL_SHADER_BITS                0xFFFFFFFF
#define GL_PROGRAM_SEPARABLE              0x8258
#define GL_ACTIVE_PROGRAM                 0x8259
#define GL_PROGRAM_PIPELINE_BINDING       0x825A
#define GL_MAX_VIEWPORTS                  0x825B
#define GL_VIEWPORT_SUBPIXEL_BITS         0x825C
#define GL_VIEWPORT_BOUNDS_RANGE          0x825D
#define GL_LAYER_PROVOKING_VERTEX         0x825E
#define GL_VIEWPORT_INDEX_PROVOKING_VERTEX 0x825F
#define GL_UNDEFINED_VERTEX               0x8260
GLAPI void (GLCALLP glReleaseShaderCompiler)(void);
GLAPI void (GLCALLP glShaderBinary)(GLsizei count, const GLuint *shaders, GLenum binaryformat, const void *binary, GLsizei length);
GLAPI void (GLCALLP glGetShaderPrecisionFormat)(GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision);
GLAPI void (GLCALLP glDepthRangef)(GLfloat n, GLfloat f);
GLAPI void (GLCALLP glClearDepthf)(GLfloat d);
GLAPI void (GLCALLP glGetProgramBinary)(GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary);
GLAPI void (GLCALLP glProgramBinary)(GLuint program, GLenum binaryFormat, const void *binary, GLsizei length);
GLAPI void (GLCALLP glProgramParameteri)(GLuint program, GLenum pname, GLint value);
GLAPI void (GLCALLP glUseProgramStages)(GLuint pipeline, GLbitfield stages, GLuint program);
GLAPI void (GLCALLP glActiveShaderProgram)(GLuint pipeline, GLuint program);
GLAPI GLuint (GLCALLP glCreateShaderProgramv)(GLenum type, GLsizei count, const GLchar *const*strings);
GLAPI void (GLCALLP glBindProgramPipeline)(GLuint pipeline);
GLAPI void (GLCALLP glDeleteProgramPipelines)(GLsizei n, const GLuint *pipelines);
GLAPI void (GLCALLP glGenProgramPipelines)(GLsizei n, GLuint *pipelines);
GLAPI GLboolean (GLCALLP glIsProgramPipeline)(GLuint pipeline);
GLAPI void (GLCALLP glGetProgramPipelineiv)(GLuint pipeline, GLenum pname, GLint *params);
GLAPI void (GLCALLP glProgramUniform1i)(GLuint program, GLint location, GLint v0);
GLAPI void (GLCALLP glProgramUniform1iv)(GLuint program, GLint location, GLsizei count, const GLint *value);
GLAPI void (GLCALLP glProgramUniform1f)(GLuint program, GLint location, GLfloat v0);
GLAPI void (GLCALLP glProgramUniform1fv)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
GLAPI void (GLCALLP glProgramUniform1d)(GLuint program, GLint location, GLdouble v0);
GLAPI void (GLCALLP glProgramUniform1dv)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
GLAPI void (GLCALLP glProgramUniform1ui)(GLuint program, GLint location, GLuint v0);
GLAPI void (GLCALLP glProgramUniform1uiv)(GLuint program, GLint location, GLsizei count, const GLuint *value);
GLAPI void (GLCALLP glProgramUniform2i)(GLuint program, GLint location, GLint v0, GLint v1);
GLAPI void (GLCALLP glProgramUniform2iv)(GLuint program, GLint location, GLsizei count, const GLint *value);
GLAPI void (GLCALLP glProgramUniform2f)(GLuint program, GLint location, GLfloat v0, GLfloat v1);
GLAPI void (GLCALLP glProgramUniform2fv)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
GLAPI void (GLCALLP glProgramUniform2d)(GLuint program, GLint location, GLdouble v0, GLdouble v1);
GLAPI void (GLCALLP glProgramUniform2dv)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
GLAPI void (GLCALLP glProgramUniform2ui)(GLuint program, GLint location, GLuint v0, GLuint v1);
GLAPI void (GLCALLP glProgramUniform2uiv)(GLuint program, GLint location, GLsizei count, const GLuint *value);
GLAPI void (GLCALLP glProgramUniform3i)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
GLAPI void (GLCALLP glProgramUniform3iv)(GLuint program, GLint location, GLsizei count, const GLint *value);
GLAPI void (GLCALLP glProgramUniform3f)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
GLAPI void (GLCALLP glProgramUniform3fv)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
GLAPI void (GLCALLP glProgramUniform3d)(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2);
GLAPI void (GLCALLP glProgramUniform3dv)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
GLAPI void (GLCALLP glProgramUniform3ui)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
GLAPI void (GLCALLP glProgramUniform3uiv)(GLuint program, GLint location, GLsizei count, const GLuint *value);
GLAPI void (GLCALLP glProgramUniform4i)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
GLAPI void (GLCALLP glProgramUniform4iv)(GLuint program, GLint location, GLsizei count, const GLint *value);
GLAPI void (GLCALLP glProgramUniform4f)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
GLAPI void (GLCALLP glProgramUniform4fv)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
GLAPI void (GLCALLP glProgramUniform4d)(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
GLAPI void (GLCALLP glProgramUniform4dv)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
GLAPI void (GLCALLP glProgramUniform4ui)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
GLAPI void (GLCALLP glProgramUniform4uiv)(GLuint program, GLint location, GLsizei count, const GLuint *value);
GLAPI void (GLCALLP glProgramUniformMatrix2fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void (GLCALLP glProgramUniformMatrix3fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void (GLCALLP glProgramUniformMatrix4fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void (GLCALLP glProgramUniformMatrix2dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void (GLCALLP glProgramUniformMatrix3dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void (GLCALLP glProgramUniformMatrix4dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void (GLCALLP glProgramUniformMatrix2x3fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void (GLCALLP glProgramUniformMatrix3x2fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void (GLCALLP glProgramUniformMatrix2x4fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void (GLCALLP glProgramUniformMatrix4x2fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void (GLCALLP glProgramUniformMatrix3x4fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void (GLCALLP glProgramUniformMatrix4x3fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void (GLCALLP glProgramUniformMatrix2x3dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void (GLCALLP glProgramUniformMatrix3x2dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void (GLCALLP glProgramUniformMatrix2x4dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void (GLCALLP glProgramUniformMatrix4x2dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void (GLCALLP glProgramUniformMatrix3x4dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void (GLCALLP glProgramUniformMatrix4x3dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void (GLCALLP glValidateProgramPipeline)(GLuint pipeline);
GLAPI void (GLCALLP glGetProgramPipelineInfoLog)(GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
GLAPI void (GLCALLP glVertexAttribL1d)(GLuint index, GLdouble x);
GLAPI void (GLCALLP glVertexAttribL2d)(GLuint index, GLdouble x, GLdouble y);
GLAPI void (GLCALLP glVertexAttribL3d)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
GLAPI void (GLCALLP glVertexAttribL4d)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI void (GLCALLP glVertexAttribL1dv)(GLuint index, const GLdouble *v);
GLAPI void (GLCALLP glVertexAttribL2dv)(GLuint index, const GLdouble *v);
GLAPI void (GLCALLP glVertexAttribL3dv)(GLuint index, const GLdouble *v);
GLAPI void (GLCALLP glVertexAttribL4dv)(GLuint index, const GLdouble *v);
GLAPI void (GLCALLP glVertexAttribLPointer)(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
GLAPI void (GLCALLP glGetVertexAttribLdv)(GLuint index, GLenum pname, GLdouble *params);
GLAPI void (GLCALLP glViewportArrayv)(GLuint first, GLsizei count, const GLfloat *v);
GLAPI void (GLCALLP glViewportIndexedf)(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
GLAPI void (GLCALLP glViewportIndexedfv)(GLuint index, const GLfloat *v);
GLAPI void (GLCALLP glScissorArrayv)(GLuint first, GLsizei count, const GLint *v);
GLAPI void (GLCALLP glScissorIndexed)(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
GLAPI void (GLCALLP glScissorIndexedv)(GLuint index, const GLint *v);
GLAPI void (GLCALLP glDepthRangeArrayv)(GLuint first, GLsizei count, const GLdouble *v);
GLAPI void (GLCALLP glDepthRangeIndexed)(GLuint index, GLdouble n, GLdouble f);
GLAPI void (GLCALLP glGetFloati_v)(GLenum target, GLuint index, GLfloat *data);
GLAPI void (GLCALLP glGetDoublei_v)(GLenum target, GLuint index, GLdouble *data);
#endif /* GL_VERSION_4_1 */

#ifndef GL_VERSION_4_2
#define GL_VERSION_4_2 1
#define GL_COPY_READ_BUFFER_BINDING       0x8F36
#define GL_COPY_WRITE_BUFFER_BINDING      0x8F37
#define GL_TRANSFORM_FEEDBACK_ACTIVE      0x8E24
#define GL_TRANSFORM_FEEDBACK_PAUSED      0x8E23
#define GL_UNPACK_COMPRESSED_BLOCK_WIDTH  0x9127
#define GL_UNPACK_COMPRESSED_BLOCK_HEIGHT 0x9128
#define GL_UNPACK_COMPRESSED_BLOCK_DEPTH  0x9129
#define GL_UNPACK_COMPRESSED_BLOCK_SIZE   0x912A
#define GL_PACK_COMPRESSED_BLOCK_WIDTH    0x912B
#define GL_PACK_COMPRESSED_BLOCK_HEIGHT   0x912C
#define GL_PACK_COMPRESSED_BLOCK_DEPTH    0x912D
#define GL_PACK_COMPRESSED_BLOCK_SIZE     0x912E
#define GL_NUM_SAMPLE_COUNTS              0x9380
#define GL_MIN_MAP_BUFFER_ALIGNMENT       0x90BC
#define GL_ATOMIC_COUNTER_BUFFER          0x92C0
#define GL_ATOMIC_COUNTER_BUFFER_BINDING  0x92C1
#define GL_ATOMIC_COUNTER_BUFFER_START    0x92C2
#define GL_ATOMIC_COUNTER_BUFFER_SIZE     0x92C3
#define GL_ATOMIC_COUNTER_BUFFER_DATA_SIZE 0x92C4
#define GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTERS 0x92C5
#define GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTER_INDICES 0x92C6
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_VERTEX_SHADER 0x92C7
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_CONTROL_SHADER 0x92C8
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_EVALUATION_SHADER 0x92C9
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_GEOMETRY_SHADER 0x92CA
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_FRAGMENT_SHADER 0x92CB
#define GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS 0x92CC
#define GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS 0x92CD
#define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS 0x92CE
#define GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS 0x92CF
#define GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS 0x92D0
#define GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS 0x92D1
#define GL_MAX_VERTEX_ATOMIC_COUNTERS     0x92D2
#define GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS 0x92D3
#define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS 0x92D4
#define GL_MAX_GEOMETRY_ATOMIC_COUNTERS   0x92D5
#define GL_MAX_FRAGMENT_ATOMIC_COUNTERS   0x92D6
#define GL_MAX_COMBINED_ATOMIC_COUNTERS   0x92D7
#define GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE 0x92D8
#define GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS 0x92DC
#define GL_ACTIVE_ATOMIC_COUNTER_BUFFERS  0x92D9
#define GL_UNIFORM_ATOMIC_COUNTER_BUFFER_INDEX 0x92DA
#define GL_UNSIGNED_INT_ATOMIC_COUNTER    0x92DB
#define GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT 0x00000001
#define GL_ELEMENT_ARRAY_BARRIER_BIT      0x00000002
#define GL_UNIFORM_BARRIER_BIT            0x00000004
#define GL_TEXTURE_FETCH_BARRIER_BIT      0x00000008
#define GL_SHADER_IMAGE_ACCESS_BARRIER_BIT 0x00000020
#define GL_COMMAND_BARRIER_BIT            0x00000040
#define GL_PIXEL_BUFFER_BARRIER_BIT       0x00000080
#define GL_TEXTURE_UPDATE_BARRIER_BIT     0x00000100
#define GL_BUFFER_UPDATE_BARRIER_BIT      0x00000200
#define GL_FRAMEBUFFER_BARRIER_BIT        0x00000400
#define GL_TRANSFORM_FEEDBACK_BARRIER_BIT 0x00000800
#define GL_ATOMIC_COUNTER_BARRIER_BIT     0x00001000
#define GL_ALL_BARRIER_BITS               0xFFFFFFFF
#define GL_MAX_IMAGE_UNITS                0x8F38
#define GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS 0x8F39
#define GL_IMAGE_BINDING_NAME             0x8F3A
#define GL_IMAGE_BINDING_LEVEL            0x8F3B
#define GL_IMAGE_BINDING_LAYERED          0x8F3C
#define GL_IMAGE_BINDING_LAYER            0x8F3D
#define GL_IMAGE_BINDING_ACCESS           0x8F3E
#define GL_IMAGE_1D                       0x904C
#define GL_IMAGE_2D                       0x904D
#define GL_IMAGE_3D                       0x904E
#define GL_IMAGE_2D_RECT                  0x904F
#define GL_IMAGE_CUBE                     0x9050
#define GL_IMAGE_BUFFER                   0x9051
#define GL_IMAGE_1D_ARRAY                 0x9052
#define GL_IMAGE_2D_ARRAY                 0x9053
#define GL_IMAGE_CUBE_MAP_ARRAY           0x9054
#define GL_IMAGE_2D_MULTISAMPLE           0x9055
#define GL_IMAGE_2D_MULTISAMPLE_ARRAY     0x9056
#define GL_INT_IMAGE_1D                   0x9057
#define GL_INT_IMAGE_2D                   0x9058
#define GL_INT_IMAGE_3D                   0x9059
#define GL_INT_IMAGE_2D_RECT              0x905A
#define GL_INT_IMAGE_CUBE                 0x905B
#define GL_INT_IMAGE_BUFFER               0x905C
#define GL_INT_IMAGE_1D_ARRAY             0x905D
#define GL_INT_IMAGE_2D_ARRAY             0x905E
#define GL_INT_IMAGE_CUBE_MAP_ARRAY       0x905F
#define GL_INT_IMAGE_2D_MULTISAMPLE       0x9060
#define GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY 0x9061
#define GL_UNSIGNED_INT_IMAGE_1D          0x9062
#define GL_UNSIGNED_INT_IMAGE_2D          0x9063
#define GL_UNSIGNED_INT_IMAGE_3D          0x9064
#define GL_UNSIGNED_INT_IMAGE_2D_RECT     0x9065
#define GL_UNSIGNED_INT_IMAGE_CUBE        0x9066
#define GL_UNSIGNED_INT_IMAGE_BUFFER      0x9067
#define GL_UNSIGNED_INT_IMAGE_1D_ARRAY    0x9068
#define GL_UNSIGNED_INT_IMAGE_2D_ARRAY    0x9069
#define GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY 0x906A
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE 0x906B
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY 0x906C
#define GL_MAX_IMAGE_SAMPLES              0x906D
#define GL_IMAGE_BINDING_FORMAT           0x906E
#define GL_IMAGE_FORMAT_COMPATIBILITY_TYPE 0x90C7
#define GL_IMAGE_FORMAT_COMPATIBILITY_BY_SIZE 0x90C8
#define GL_IMAGE_FORMAT_COMPATIBILITY_BY_CLASS 0x90C9
#define GL_MAX_VERTEX_IMAGE_UNIFORMS      0x90CA
#define GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS 0x90CB
#define GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS 0x90CC
#define GL_MAX_GEOMETRY_IMAGE_UNIFORMS    0x90CD
#define GL_MAX_FRAGMENT_IMAGE_UNIFORMS    0x90CE
#define GL_MAX_COMBINED_IMAGE_UNIFORMS    0x90CF
#define GL_COMPRESSED_RGBA_BPTC_UNORM     0x8E8C
#define GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM 0x8E8D
#define GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT 0x8E8E
#define GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT 0x8E8F
#define GL_TEXTURE_IMMUTABLE_FORMAT       0x912F
GLAPI void (GLCALLP glDrawArraysInstancedBaseInstance)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
GLAPI void (GLCALLP glDrawElementsInstancedBaseInstance)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLuint baseinstance);
GLAPI void (GLCALLP glDrawElementsInstancedBaseVertexBaseInstance)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
GLAPI void (GLCALLP glGetInternalformativ)(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint *params);
GLAPI void (GLCALLP glGetActiveAtomicCounterBufferiv)(GLuint program, GLuint bufferIndex, GLenum pname, GLint *params);
GLAPI void (GLCALLP glBindImageTexture)(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
GLAPI void (GLCALLP glMemoryBarrier)(GLbitfield barriers);
GLAPI void (GLCALLP glTexStorage1D)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
GLAPI void (GLCALLP glTexStorage2D)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI void (GLCALLP glTexStorage3D)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
GLAPI void (GLCALLP glDrawTransformFeedbackInstanced)(GLenum mode, GLuint id, GLsizei instancecount);
GLAPI void (GLCALLP glDrawTransformFeedbackStreamInstanced)(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount);
#endif /* GL_VERSION_4_2 */

#ifndef GL_VERSION_4_3
#define GL_VERSION_4_3 1
typedef void (GLCALL  *GLDEBUGPROC)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,const void *userParam);
#define GL_NUM_SHADING_LANGUAGE_VERSIONS  0x82E9
#define GL_VERTEX_ATTRIB_ARRAY_LONG       0x874E
#define GL_COMPRESSED_RGB8_ETC2           0x9274
#define GL_COMPRESSED_SRGB8_ETC2          0x9275
#define GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2 0x9276
#define GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2 0x9277
#define GL_COMPRESSED_RGBA8_ETC2_EAC      0x9278
#define GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC 0x9279
#define GL_COMPRESSED_R11_EAC             0x9270
#define GL_COMPRESSED_SIGNED_R11_EAC      0x9271
#define GL_COMPRESSED_RG11_EAC            0x9272
#define GL_COMPRESSED_SIGNED_RG11_EAC     0x9273
#define GL_PRIMITIVE_RESTART_FIXED_INDEX  0x8D69
#define GL_ANY_SAMPLES_PASSED_CONSERVATIVE 0x8D6A
#define GL_MAX_ELEMENT_INDEX              0x8D6B
#define GL_COMPUTE_SHADER                 0x91B9
#define GL_MAX_COMPUTE_UNIFORM_BLOCKS     0x91BB
#define GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS 0x91BC
#define GL_MAX_COMPUTE_IMAGE_UNIFORMS     0x91BD
#define GL_MAX_COMPUTE_SHARED_MEMORY_SIZE 0x8262
#define GL_MAX_COMPUTE_UNIFORM_COMPONENTS 0x8263
#define GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS 0x8264
#define GL_MAX_COMPUTE_ATOMIC_COUNTERS    0x8265
#define GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS 0x8266
#define GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS 0x90EB
#define GL_MAX_COMPUTE_WORK_GROUP_COUNT   0x91BE
#define GL_MAX_COMPUTE_WORK_GROUP_SIZE    0x91BF
#define GL_COMPUTE_WORK_GROUP_SIZE        0x8267
#define GL_UNIFORM_BLOCK_REFERENCED_BY_COMPUTE_SHADER 0x90EC
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_COMPUTE_SHADER 0x90ED
#define GL_DISPATCH_INDIRECT_BUFFER       0x90EE
#define GL_DISPATCH_INDIRECT_BUFFER_BINDING 0x90EF
#define GL_COMPUTE_SHADER_BIT             0x00000020
#define GL_DEBUG_OUTPUT_SYNCHRONOUS       0x8242
#define GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH 0x8243
#define GL_DEBUG_CALLBACK_FUNCTION        0x8244
#define GL_DEBUG_CALLBACK_USER_PARAM      0x8245
#define GL_DEBUG_SOURCE_API               0x8246
#define GL_DEBUG_SOURCE_WINDOW_SYSTEM     0x8247
#define GL_DEBUG_SOURCE_SHADER_COMPILER   0x8248
#define GL_DEBUG_SOURCE_THIRD_PARTY       0x8249
#define GL_DEBUG_SOURCE_APPLICATION       0x824A
#define GL_DEBUG_SOURCE_OTHER             0x824B
#define GL_DEBUG_TYPE_ERROR               0x824C
#define GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR 0x824D
#define GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR  0x824E
#define GL_DEBUG_TYPE_PORTABILITY         0x824F
#define GL_DEBUG_TYPE_PERFORMANCE         0x8250
#define GL_DEBUG_TYPE_OTHER               0x8251
#define GL_MAX_DEBUG_MESSAGE_LENGTH       0x9143
#define GL_MAX_DEBUG_LOGGED_MESSAGES      0x9144
#define GL_DEBUG_LOGGED_MESSAGES          0x9145
#define GL_DEBUG_SEVERITY_HIGH            0x9146
#define GL_DEBUG_SEVERITY_MEDIUM          0x9147
#define GL_DEBUG_SEVERITY_LOW             0x9148
#define GL_DEBUG_TYPE_MARKER              0x8268
#define GL_DEBUG_TYPE_PUSH_GROUP          0x8269
#define GL_DEBUG_TYPE_POP_GROUP           0x826A
#define GL_DEBUG_SEVERITY_NOTIFICATION    0x826B
#define GL_MAX_DEBUG_GROUP_STACK_DEPTH    0x826C
#define GL_DEBUG_GROUP_STACK_DEPTH        0x826D
#define GL_BUFFER                         0x82E0
#define GL_SHADER                         0x82E1
#define GL_PROGRAM                        0x82E2
#define GL_QUERY                          0x82E3
#define GL_PROGRAM_PIPELINE               0x82E4
#define GL_SAMPLER                        0x82E6
#define GL_MAX_LABEL_LENGTH               0x82E8
#define GL_DEBUG_OUTPUT                   0x92E0
#define GL_CONTEXT_FLAG_DEBUG_BIT         0x00000002
#define GL_MAX_UNIFORM_LOCATIONS          0x826E
#define GL_FRAMEBUFFER_DEFAULT_WIDTH      0x9310
#define GL_FRAMEBUFFER_DEFAULT_HEIGHT     0x9311
#define GL_FRAMEBUFFER_DEFAULT_LAYERS     0x9312
#define GL_FRAMEBUFFER_DEFAULT_SAMPLES    0x9313
#define GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS 0x9314
#define GL_MAX_FRAMEBUFFER_WIDTH          0x9315
#define GL_MAX_FRAMEBUFFER_HEIGHT         0x9316
#define GL_MAX_FRAMEBUFFER_LAYERS         0x9317
#define GL_MAX_FRAMEBUFFER_SAMPLES        0x9318
#define GL_INTERNALFORMAT_SUPPORTED       0x826F
#define GL_INTERNALFORMAT_PREFERRED       0x8270
#define GL_INTERNALFORMAT_RED_SIZE        0x8271
#define GL_INTERNALFORMAT_GREEN_SIZE      0x8272
#define GL_INTERNALFORMAT_BLUE_SIZE       0x8273
#define GL_INTERNALFORMAT_ALPHA_SIZE      0x8274
#define GL_INTERNALFORMAT_DEPTH_SIZE      0x8275
#define GL_INTERNALFORMAT_STENCIL_SIZE    0x8276
#define GL_INTERNALFORMAT_SHARED_SIZE     0x8277
#define GL_INTERNALFORMAT_RED_TYPE        0x8278
#define GL_INTERNALFORMAT_GREEN_TYPE      0x8279
#define GL_INTERNALFORMAT_BLUE_TYPE       0x827A
#define GL_INTERNALFORMAT_ALPHA_TYPE      0x827B
#define GL_INTERNALFORMAT_DEPTH_TYPE      0x827C
#define GL_INTERNALFORMAT_STENCIL_TYPE    0x827D
#define GL_MAX_WIDTH                      0x827E
#define GL_MAX_HEIGHT                     0x827F
#define GL_MAX_DEPTH                      0x8280
#define GL_MAX_LAYERS                     0x8281
#define GL_MAX_COMBINED_DIMENSIONS        0x8282
#define GL_COLOR_COMPONENTS               0x8283
#define GL_DEPTH_COMPONENTS               0x8284
#define GL_STENCIL_COMPONENTS             0x8285
#define GL_COLOR_RENDERABLE               0x8286
#define GL_DEPTH_RENDERABLE               0x8287
#define GL_STENCIL_RENDERABLE             0x8288
#define GL_FRAMEBUFFER_RENDERABLE         0x8289
#define GL_FRAMEBUFFER_RENDERABLE_LAYERED 0x828A
#define GL_FRAMEBUFFER_BLEND              0x828B
#define GL_READ_PIXELS                    0x828C
#define GL_READ_PIXELS_FORMAT             0x828D
#define GL_READ_PIXELS_TYPE               0x828E
#define GL_TEXTURE_IMAGE_FORMAT           0x828F
#define GL_TEXTURE_IMAGE_TYPE             0x8290
#define GL_GET_TEXTURE_IMAGE_FORMAT       0x8291
#define GL_GET_TEXTURE_IMAGE_TYPE         0x8292
#define GL_MIPMAP                         0x8293
#define GL_MANUAL_GENERATE_MIPMAP         0x8294
#define GL_AUTO_GENERATE_MIPMAP           0x8295
#define GL_COLOR_ENCODING                 0x8296
#define GL_SRGB_READ                      0x8297
#define GL_SRGB_WRITE                     0x8298
#define GL_FILTER                         0x829A
#define GL_VERTEX_TEXTURE                 0x829B
#define GL_TESS_CONTROL_TEXTURE           0x829C
#define GL_TESS_EVALUATION_TEXTURE        0x829D
#define GL_GEOMETRY_TEXTURE               0x829E
#define GL_FRAGMENT_TEXTURE               0x829F
#define GL_COMPUTE_TEXTURE                0x82A0
#define GL_TEXTURE_SHADOW                 0x82A1
#define GL_TEXTURE_GATHER                 0x82A2
#define GL_TEXTURE_GATHER_SHADOW          0x82A3
#define GL_SHADER_IMAGE_LOAD              0x82A4
#define GL_SHADER_IMAGE_STORE             0x82A5
#define GL_SHADER_IMAGE_ATOMIC            0x82A6
#define GL_IMAGE_TEXEL_SIZE               0x82A7
#define GL_IMAGE_COMPATIBILITY_CLASS      0x82A8
#define GL_IMAGE_PIXEL_FORMAT             0x82A9
#define GL_IMAGE_PIXEL_TYPE               0x82AA
#define GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST 0x82AC
#define GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST 0x82AD
#define GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE 0x82AE
#define GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE 0x82AF
#define GL_TEXTURE_COMPRESSED_BLOCK_WIDTH 0x82B1
#define GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT 0x82B2
#define GL_TEXTURE_COMPRESSED_BLOCK_SIZE  0x82B3
#define GL_CLEAR_BUFFER                   0x82B4
#define GL_TEXTURE_VIEW                   0x82B5
#define GL_VIEW_COMPATIBILITY_CLASS       0x82B6
#define GL_FULL_SUPPORT                   0x82B7
#define GL_CAVEAT_SUPPORT                 0x82B8
#define GL_IMAGE_CLASS_4_X_32             0x82B9
#define GL_IMAGE_CLASS_2_X_32             0x82BA
#define GL_IMAGE_CLASS_1_X_32             0x82BB
#define GL_IMAGE_CLASS_4_X_16             0x82BC
#define GL_IMAGE_CLASS_2_X_16             0x82BD
#define GL_IMAGE_CLASS_1_X_16             0x82BE
#define GL_IMAGE_CLASS_4_X_8              0x82BF
#define GL_IMAGE_CLASS_2_X_8              0x82C0
#define GL_IMAGE_CLASS_1_X_8              0x82C1
#define GL_IMAGE_CLASS_11_11_10           0x82C2
#define GL_IMAGE_CLASS_10_10_10_2         0x82C3
#define GL_VIEW_CLASS_128_BITS            0x82C4
#define GL_VIEW_CLASS_96_BITS             0x82C5
#define GL_VIEW_CLASS_64_BITS             0x82C6
#define GL_VIEW_CLASS_48_BITS             0x82C7
#define GL_VIEW_CLASS_32_BITS             0x82C8
#define GL_VIEW_CLASS_24_BITS             0x82C9
#define GL_VIEW_CLASS_16_BITS             0x82CA
#define GL_VIEW_CLASS_8_BITS              0x82CB
#define GL_VIEW_CLASS_S3TC_DXT1_RGB       0x82CC
#define GL_VIEW_CLASS_S3TC_DXT1_RGBA      0x82CD
#define GL_VIEW_CLASS_S3TC_DXT3_RGBA      0x82CE
#define GL_VIEW_CLASS_S3TC_DXT5_RGBA      0x82CF
#define GL_VIEW_CLASS_RGTC1_RED           0x82D0
#define GL_VIEW_CLASS_RGTC2_RG            0x82D1
#define GL_VIEW_CLASS_BPTC_UNORM          0x82D2
#define GL_VIEW_CLASS_BPTC_FLOAT          0x82D3
#define GL_UNIFORM                        0x92E1
#define GL_UNIFORM_BLOCK                  0x92E2
#define GL_PROGRAM_INPUT                  0x92E3
#define GL_PROGRAM_OUTPUT                 0x92E4
#define GL_BUFFER_VARIABLE                0x92E5
#define GL_SHADER_STORAGE_BLOCK           0x92E6
#define GL_VERTEX_SUBROUTINE              0x92E8
#define GL_TESS_CONTROL_SUBROUTINE        0x92E9
#define GL_TESS_EVALUATION_SUBROUTINE     0x92EA
#define GL_GEOMETRY_SUBROUTINE            0x92EB
#define GL_FRAGMENT_SUBROUTINE            0x92EC
#define GL_COMPUTE_SUBROUTINE             0x92ED
#define GL_VERTEX_SUBROUTINE_UNIFORM      0x92EE
#define GL_TESS_CONTROL_SUBROUTINE_UNIFORM 0x92EF
#define GL_TESS_EVALUATION_SUBROUTINE_UNIFORM 0x92F0
#define GL_GEOMETRY_SUBROUTINE_UNIFORM    0x92F1
#define GL_FRAGMENT_SUBROUTINE_UNIFORM    0x92F2
#define GL_COMPUTE_SUBROUTINE_UNIFORM     0x92F3
#define GL_TRANSFORM_FEEDBACK_VARYING     0x92F4
#define GL_ACTIVE_RESOURCES               0x92F5
#define GL_MAX_NAME_LENGTH                0x92F6
#define GL_MAX_NUM_ACTIVE_VARIABLES       0x92F7
#define GL_MAX_NUM_COMPATIBLE_SUBROUTINES 0x92F8
#define GL_NAME_LENGTH                    0x92F9
#define GL_TYPE                           0x92FA
#define GL_ARRAY_SIZE                     0x92FB
#define GL_OFFSET                         0x92FC
#define GL_BLOCK_INDEX                    0x92FD
#define GL_ARRAY_STRIDE                   0x92FE
#define GL_MATRIX_STRIDE                  0x92FF
#define GL_IS_ROW_MAJOR                   0x9300
#define GL_ATOMIC_COUNTER_BUFFER_INDEX    0x9301
#define GL_BUFFER_BINDING                 0x9302
#define GL_BUFFER_DATA_SIZE               0x9303
#define GL_NUM_ACTIVE_VARIABLES           0x9304
#define GL_ACTIVE_VARIABLES               0x9305
#define GL_REFERENCED_BY_VERTEX_SHADER    0x9306
#define GL_REFERENCED_BY_TESS_CONTROL_SHADER 0x9307
#define GL_REFERENCED_BY_TESS_EVALUATION_SHADER 0x9308
#define GL_REFERENCED_BY_GEOMETRY_SHADER  0x9309
#define GL_REFERENCED_BY_FRAGMENT_SHADER  0x930A
#define GL_REFERENCED_BY_COMPUTE_SHADER   0x930B
#define GL_TOP_LEVEL_ARRAY_SIZE           0x930C
#define GL_TOP_LEVEL_ARRAY_STRIDE         0x930D
#define GL_LOCATION                       0x930E
#define GL_LOCATION_INDEX                 0x930F
#define GL_IS_PER_PATCH                   0x92E7
#define GL_SHADER_STORAGE_BUFFER          0x90D2
#define GL_SHADER_STORAGE_BUFFER_BINDING  0x90D3
#define GL_SHADER_STORAGE_BUFFER_START    0x90D4
#define GL_SHADER_STORAGE_BUFFER_SIZE     0x90D5
#define GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS 0x90D6
#define GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS 0x90D7
#define GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS 0x90D8
#define GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS 0x90D9
#define GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS 0x90DA
#define GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS 0x90DB
#define GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS 0x90DC
#define GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS 0x90DD
#define GL_MAX_SHADER_STORAGE_BLOCK_SIZE  0x90DE
#define GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT 0x90DF
#define GL_SHADER_STORAGE_BARRIER_BIT     0x00002000
#define GL_MAX_COMBINED_SHADER_OUTPUT_RESOURCES 0x8F39
#define GL_DEPTH_STENCIL_TEXTURE_MODE     0x90EA
#define GL_TEXTURE_BUFFER_OFFSET          0x919D
#define GL_TEXTURE_BUFFER_SIZE            0x919E
#define GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT 0x919F
#define GL_TEXTURE_VIEW_MIN_LEVEL         0x82DB
#define GL_TEXTURE_VIEW_NUM_LEVELS        0x82DC
#define GL_TEXTURE_VIEW_MIN_LAYER         0x82DD
#define GL_TEXTURE_VIEW_NUM_LAYERS        0x82DE
#define GL_TEXTURE_IMMUTABLE_LEVELS       0x82DF
#define GL_VERTEX_ATTRIB_BINDING          0x82D4
#define GL_VERTEX_ATTRIB_RELATIVE_OFFSET  0x82D5
#define GL_VERTEX_BINDING_DIVISOR         0x82D6
#define GL_VERTEX_BINDING_OFFSET          0x82D7
#define GL_VERTEX_BINDING_STRIDE          0x82D8
#define GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET 0x82D9
#define GL_MAX_VERTEX_ATTRIB_BINDINGS     0x82DA
#define GL_VERTEX_BINDING_BUFFER          0x8F4F
GLAPI void (GLCALLP glClearBufferData)(GLenum target, GLenum internalformat, GLenum format, GLenum type, const void *data);
GLAPI void (GLCALLP glClearBufferSubData)(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
GLAPI void (GLCALLP glDispatchCompute)(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
GLAPI void (GLCALLP glDispatchComputeIndirect)(GLintptr indirect);
GLAPI void (GLCALLP glCopyImageSubData)(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
GLAPI void (GLCALLP glFramebufferParameteri)(GLenum target, GLenum pname, GLint param);
GLAPI void (GLCALLP glGetFramebufferParameteriv)(GLenum target, GLenum pname, GLint *params);
GLAPI void (GLCALLP glGetInternalformati64v)(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64 *params);
GLAPI void (GLCALLP glInvalidateTexSubImage)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth);
GLAPI void (GLCALLP glInvalidateTexImage)(GLuint texture, GLint level);
GLAPI void (GLCALLP glInvalidateBufferSubData)(GLuint buffer, GLintptr offset, GLsizeiptr length);
GLAPI void (GLCALLP glInvalidateBufferData)(GLuint buffer);
GLAPI void (GLCALLP glInvalidateFramebuffer)(GLenum target, GLsizei numAttachments, const GLenum *attachments);
GLAPI void (GLCALLP glInvalidateSubFramebuffer)(GLenum target, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI void (GLCALLP glMultiDrawArraysIndirect)(GLenum mode, const void *indirect, GLsizei drawcount, GLsizei stride);
GLAPI void (GLCALLP glMultiDrawElementsIndirect)(GLenum mode, GLenum type, const void *indirect, GLsizei drawcount, GLsizei stride);
GLAPI void (GLCALLP glGetProgramInterfaceiv)(GLuint program, GLenum programInterface, GLenum pname, GLint *params);
GLAPI GLuint (GLCALLP glGetProgramResourceIndex)(GLuint program, GLenum programInterface, const GLchar *name);
GLAPI void (GLCALLP glGetProgramResourceName)(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name);
GLAPI void (GLCALLP glGetProgramResourceiv)(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei bufSize, GLsizei *length, GLint *params);
GLAPI GLint (GLCALLP glGetProgramResourceLocation)(GLuint program, GLenum programInterface, const GLchar *name);
GLAPI GLint (GLCALLP glGetProgramResourceLocationIndex)(GLuint program, GLenum programInterface, const GLchar *name);
GLAPI void (GLCALLP glShaderStorageBlockBinding)(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
GLAPI void (GLCALLP glTexBufferRange)(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
GLAPI void (GLCALLP glTexStorage2DMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
GLAPI void (GLCALLP glTexStorage3DMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
GLAPI void (GLCALLP glTextureView)(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
GLAPI void (GLCALLP glBindVertexBuffer)(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
GLAPI void (GLCALLP glVertexAttribFormat)(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
GLAPI void (GLCALLP glVertexAttribIFormat)(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
GLAPI void (GLCALLP glVertexAttribLFormat)(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
GLAPI void (GLCALLP glVertexAttribBinding)(GLuint attribindex, GLuint bindingindex);
GLAPI void (GLCALLP glVertexBindingDivisor)(GLuint bindingindex, GLuint divisor);
GLAPI void (GLCALLP glDebugMessageControl)(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
GLAPI void (GLCALLP glDebugMessageInsert)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf);
GLAPI void (GLCALLP glDebugMessageCallback)(GLDEBUGPROC callback, const void *userParam);
GLAPI GLuint (GLCALLP glGetDebugMessageLog)(GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog);
GLAPI void (GLCALLP glPushDebugGroup)(GLenum source, GLuint id, GLsizei length, const GLchar *message);
GLAPI void (GLCALLP glPopDebugGroup)(void);
GLAPI void (GLCALLP glObjectLabel)(GLenum identifier, GLuint name, GLsizei length, const GLchar *label);
GLAPI void (GLCALLP glGetObjectLabel)(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei *length, GLchar *label);
GLAPI void (GLCALLP glObjectPtrLabel)(const void *ptr, GLsizei length, const GLchar *label);
GLAPI void (GLCALLP glGetObjectPtrLabel)(const void *ptr, GLsizei bufSize, GLsizei *length, GLchar *label);
#endif /* GL_VERSION_4_3 */

#ifndef GL_VERSION_4_4
#define GL_VERSION_4_4 1
#define GL_MAX_VERTEX_ATTRIB_STRIDE       0x82E5
#define GL_PRIMITIVE_RESTART_FOR_PATCHES_SUPPORTED 0x8221
#define GL_TEXTURE_BUFFER_BINDING         0x8C2A
#define GL_MAP_PERSISTENT_BIT             0x0040
#define GL_MAP_COHERENT_BIT               0x0080
#define GL_DYNAMIC_STORAGE_BIT            0x0100
#define GL_CLIENT_STORAGE_BIT             0x0200
#define GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT 0x00004000
#define GL_BUFFER_IMMUTABLE_STORAGE       0x821F
#define GL_BUFFER_STORAGE_FLAGS           0x8220
#define GL_CLEAR_TEXTURE                  0x9365
#define GL_LOCATION_COMPONENT             0x934A
#define GL_TRANSFORM_FEEDBACK_BUFFER_INDEX 0x934B
#define GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE 0x934C
#define GL_QUERY_BUFFER                   0x9192
#define GL_QUERY_BUFFER_BARRIER_BIT       0x00008000
#define GL_QUERY_BUFFER_BINDING           0x9193
#define GL_QUERY_RESULT_NO_WAIT           0x9194
#define GL_MIRROR_CLAMP_TO_EDGE           0x8743
GLAPI void (GLCALLP glBufferStorage)(GLenum target, GLsizeiptr size, const void *data, GLbitfield flags);
GLAPI void (GLCALLP glClearTexImage)(GLuint texture, GLint level, GLenum format, GLenum type, const void *data);
GLAPI void (GLCALLP glClearTexSubImage)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *data);
GLAPI void (GLCALLP glBindBuffersBase)(GLenum target, GLuint first, GLsizei count, const GLuint *buffers);
GLAPI void (GLCALLP glBindBuffersRange)(GLenum target, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizeiptr *sizes);
GLAPI void (GLCALLP glBindTextures)(GLuint first, GLsizei count, const GLuint *textures);
GLAPI void (GLCALLP glBindSamplers)(GLuint first, GLsizei count, const GLuint *samplers);
GLAPI void (GLCALLP glBindImageTextures)(GLuint first, GLsizei count, const GLuint *textures);
GLAPI void (GLCALLP glBindVertexBuffers)(GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);
#endif /* GL_VERSION_4_4 */

#ifndef GL_VERSION_4_5
#define GL_VERSION_4_5 1
#define GL_CONTEXT_LOST                   0x0507
#define GL_NEGATIVE_ONE_TO_ONE            0x935E
#define GL_ZERO_TO_ONE                    0x935F
#define GL_CLIP_ORIGIN                    0x935C
#define GL_CLIP_DEPTH_MODE                0x935D
#define GL_QUERY_WAIT_INVERTED            0x8E17
#define GL_QUERY_NO_WAIT_INVERTED         0x8E18
#define GL_QUERY_BY_REGION_WAIT_INVERTED  0x8E19
#define GL_QUERY_BY_REGION_NO_WAIT_INVERTED 0x8E1A
#define GL_MAX_CULL_DISTANCES             0x82F9
#define GL_MAX_COMBINED_CLIP_AND_CULL_DISTANCES 0x82FA
#define GL_TEXTURE_TARGET                 0x1006
#define GL_QUERY_TARGET                   0x82EA
#define GL_GUILTY_CONTEXT_RESET           0x8253
#define GL_INNOCENT_CONTEXT_RESET         0x8254
#define GL_UNKNOWN_CONTEXT_RESET          0x8255
#define GL_RESET_NOTIFICATION_STRATEGY    0x8256
#define GL_LOSE_CONTEXT_ON_RESET          0x8252
#define GL_NO_RESET_NOTIFICATION          0x8261
#define GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT 0x00000004
#define GL_CONTEXT_RELEASE_BEHAVIOR       0x82FB
#define GL_CONTEXT_RELEASE_BEHAVIOR_FLUSH 0x82FC
GLAPI void (GLCALLP glClipControl)(GLenum origin, GLenum depth);
GLAPI void (GLCALLP glCreateTransformFeedbacks)(GLsizei n, GLuint *ids);
GLAPI void (GLCALLP glTransformFeedbackBufferBase)(GLuint xfb, GLuint index, GLuint buffer);
GLAPI void (GLCALLP glTransformFeedbackBufferRange)(GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
GLAPI void (GLCALLP glGetTransformFeedbackiv)(GLuint xfb, GLenum pname, GLint *param);
GLAPI void (GLCALLP glGetTransformFeedbacki_v)(GLuint xfb, GLenum pname, GLuint index, GLint *param);
GLAPI void (GLCALLP glGetTransformFeedbacki64_v)(GLuint xfb, GLenum pname, GLuint index, GLint64 *param);
GLAPI void (GLCALLP glCreateBuffers)(GLsizei n, GLuint *buffers);
GLAPI void (GLCALLP glNamedBufferStorage)(GLuint buffer, GLsizeiptr size, const void *data, GLbitfield flags);
GLAPI void (GLCALLP glNamedBufferData)(GLuint buffer, GLsizeiptr size, const void *data, GLenum usage);
GLAPI void (GLCALLP glNamedBufferSubData)(GLuint buffer, GLintptr offset, GLsizeiptr size, const void *data);
GLAPI void (GLCALLP glCopyNamedBufferSubData)(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
GLAPI void (GLCALLP glClearNamedBufferData)(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void *data);
GLAPI void (GLCALLP glClearNamedBufferSubData)(GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
GLAPI void *(GLCALLP glMapNamedBuffer)(GLuint buffer, GLenum access);
GLAPI void *(GLCALLP glMapNamedBufferRange)(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
GLAPI GLboolean (GLCALLP glUnmapNamedBuffer)(GLuint buffer);
GLAPI void (GLCALLP glFlushMappedNamedBufferRange)(GLuint buffer, GLintptr offset, GLsizeiptr length);
GLAPI void (GLCALLP glGetNamedBufferParameteriv)(GLuint buffer, GLenum pname, GLint *params);
GLAPI void (GLCALLP glGetNamedBufferParameteri64v)(GLuint buffer, GLenum pname, GLint64 *params);
GLAPI void (GLCALLP glGetNamedBufferPointerv)(GLuint buffer, GLenum pname, void **params);
GLAPI void (GLCALLP glGetNamedBufferSubData)(GLuint buffer, GLintptr offset, GLsizeiptr size, void *data);
GLAPI void (GLCALLP glCreateFramebuffers)(GLsizei n, GLuint *framebuffers);
GLAPI void (GLCALLP glNamedFramebufferRenderbuffer)(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
GLAPI void (GLCALLP glNamedFramebufferParameteri)(GLuint framebuffer, GLenum pname, GLint param);
GLAPI void (GLCALLP glNamedFramebufferTexture)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
GLAPI void (GLCALLP glNamedFramebufferTextureLayer)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
GLAPI void (GLCALLP glNamedFramebufferDrawBuffer)(GLuint framebuffer, GLenum buf);
GLAPI void (GLCALLP glNamedFramebufferDrawBuffers)(GLuint framebuffer, GLsizei n, const GLenum *bufs);
GLAPI void (GLCALLP glNamedFramebufferReadBuffer)(GLuint framebuffer, GLenum src);
GLAPI void (GLCALLP glInvalidateNamedFramebufferData)(GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments);
GLAPI void (GLCALLP glInvalidateNamedFramebufferSubData)(GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI void (GLCALLP glClearNamedFramebufferiv)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint *value);
GLAPI void (GLCALLP glClearNamedFramebufferuiv)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint *value);
GLAPI void (GLCALLP glClearNamedFramebufferfv)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat *value);
GLAPI void (GLCALLP glClearNamedFramebufferfi)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
GLAPI void (GLCALLP glBlitNamedFramebuffer)(GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
GLAPI GLenum (GLCALLP glCheckNamedFramebufferStatus)(GLuint framebuffer, GLenum target);
GLAPI void (GLCALLP glGetNamedFramebufferParameteriv)(GLuint framebuffer, GLenum pname, GLint *param);
GLAPI void (GLCALLP glGetNamedFramebufferAttachmentParameteriv)(GLuint framebuffer, GLenum attachment, GLenum pname, GLint *params);
GLAPI void (GLCALLP glCreateRenderbuffers)(GLsizei n, GLuint *renderbuffers);
GLAPI void (GLCALLP glNamedRenderbufferStorage)(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI void (GLCALLP glNamedRenderbufferStorageMultisample)(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI void (GLCALLP glGetNamedRenderbufferParameteriv)(GLuint renderbuffer, GLenum pname, GLint *params);
GLAPI void (GLCALLP glCreateTextures)(GLenum target, GLsizei n, GLuint *textures);
GLAPI void (GLCALLP glTextureBuffer)(GLuint texture, GLenum internalformat, GLuint buffer);
GLAPI void (GLCALLP glTextureBufferRange)(GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
GLAPI void (GLCALLP glTextureStorage1D)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width);
GLAPI void (GLCALLP glTextureStorage2D)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI void (GLCALLP glTextureStorage3D)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
GLAPI void (GLCALLP glTextureStorage2DMultisample)(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
GLAPI void (GLCALLP glTextureStorage3DMultisample)(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
GLAPI void (GLCALLP glTextureSubImage1D)(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
GLAPI void (GLCALLP glTextureSubImage2D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
GLAPI void (GLCALLP glTextureSubImage3D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
GLAPI void (GLCALLP glCompressedTextureSubImage1D)(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
GLAPI void (GLCALLP glCompressedTextureSubImage2D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
GLAPI void (GLCALLP glCompressedTextureSubImage3D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
GLAPI void (GLCALLP glCopyTextureSubImage1D)(GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
GLAPI void (GLCALLP glCopyTextureSubImage2D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI void (GLCALLP glCopyTextureSubImage3D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI void (GLCALLP glTextureParameterf)(GLuint texture, GLenum pname, GLfloat param);
GLAPI void (GLCALLP glTextureParameterfv)(GLuint texture, GLenum pname, const GLfloat *param);
GLAPI void (GLCALLP glTextureParameteri)(GLuint texture, GLenum pname, GLint param);
GLAPI void (GLCALLP glTextureParameterIiv)(GLuint texture, GLenum pname, const GLint *params);
GLAPI void (GLCALLP glTextureParameterIuiv)(GLuint texture, GLenum pname, const GLuint *params);
GLAPI void (GLCALLP glTextureParameteriv)(GLuint texture, GLenum pname, const GLint *param);
GLAPI void (GLCALLP glGenerateTextureMipmap)(GLuint texture);
GLAPI void (GLCALLP glBindTextureUnit)(GLuint unit, GLuint texture);
GLAPI void (GLCALLP glGetTextureImage)(GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
GLAPI void (GLCALLP glGetCompressedTextureImage)(GLuint texture, GLint level, GLsizei bufSize, void *pixels);
GLAPI void (GLCALLP glGetTextureLevelParameterfv)(GLuint texture, GLint level, GLenum pname, GLfloat *params);
GLAPI void (GLCALLP glGetTextureLevelParameteriv)(GLuint texture, GLint level, GLenum pname, GLint *params);
GLAPI void (GLCALLP glGetTextureParameterfv)(GLuint texture, GLenum pname, GLfloat *params);
GLAPI void (GLCALLP glGetTextureParameterIiv)(GLuint texture, GLenum pname, GLint *params);
GLAPI void (GLCALLP glGetTextureParameterIuiv)(GLuint texture, GLenum pname, GLuint *params);
GLAPI void (GLCALLP glGetTextureParameteriv)(GLuint texture, GLenum pname, GLint *params);
GLAPI void (GLCALLP glCreateVertexArrays)(GLsizei n, GLuint *arrays);
GLAPI void (GLCALLP glDisableVertexArrayAttrib)(GLuint vaobj, GLuint index);
GLAPI void (GLCALLP glEnableVertexArrayAttrib)(GLuint vaobj, GLuint index);
GLAPI void (GLCALLP glVertexArrayElementBuffer)(GLuint vaobj, GLuint buffer);
GLAPI void (GLCALLP glVertexArrayVertexBuffer)(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
GLAPI void (GLCALLP glVertexArrayVertexBuffers)(GLuint vaobj, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);
GLAPI void (GLCALLP glVertexArrayAttribBinding)(GLuint vaobj, GLuint attribindex, GLuint bindingindex);
GLAPI void (GLCALLP glVertexArrayAttribFormat)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
GLAPI void (GLCALLP glVertexArrayAttribIFormat)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
GLAPI void (GLCALLP glVertexArrayAttribLFormat)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
GLAPI void (GLCALLP glVertexArrayBindingDivisor)(GLuint vaobj, GLuint bindingindex, GLuint divisor);
GLAPI void (GLCALLP glGetVertexArrayiv)(GLuint vaobj, GLenum pname, GLint *param);
GLAPI void (GLCALLP glGetVertexArrayIndexediv)(GLuint vaobj, GLuint index, GLenum pname, GLint *param);
GLAPI void (GLCALLP glGetVertexArrayIndexed64iv)(GLuint vaobj, GLuint index, GLenum pname, GLint64 *param);
GLAPI void (GLCALLP glCreateSamplers)(GLsizei n, GLuint *samplers);
GLAPI void (GLCALLP glCreateProgramPipelines)(GLsizei n, GLuint *pipelines);
GLAPI void (GLCALLP glCreateQueries)(GLenum target, GLsizei n, GLuint *ids);
GLAPI void (GLCALLP glGetQueryBufferObjecti64v)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
GLAPI void (GLCALLP glGetQueryBufferObjectiv)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
GLAPI void (GLCALLP glGetQueryBufferObjectui64v)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
GLAPI void (GLCALLP glGetQueryBufferObjectuiv)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
GLAPI void (GLCALLP glMemoryBarrierByRegion)(GLbitfield barriers);
GLAPI void (GLCALLP glGetTextureSubImage)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
GLAPI void (GLCALLP glGetCompressedTextureSubImage)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void *pixels);
GLAPI GLenum (GLCALLP glGetGraphicsResetStatus)(void);
GLAPI void (GLCALLP glGetnCompressedTexImage)(GLenum target, GLint lod, GLsizei bufSize, void *pixels);
GLAPI void (GLCALLP glGetnTexImage)(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
GLAPI void (GLCALLP glGetnUniformdv)(GLuint program, GLint location, GLsizei bufSize, GLdouble *params);
GLAPI void (GLCALLP glGetnUniformfv)(GLuint program, GLint location, GLsizei bufSize, GLfloat *params);
GLAPI void (GLCALLP glGetnUniformiv)(GLuint program, GLint location, GLsizei bufSize, GLint *params);
GLAPI void (GLCALLP glGetnUniformuiv)(GLuint program, GLint location, GLsizei bufSize, GLuint *params);
GLAPI void (GLCALLP glReadnPixels)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data);
GLAPI void (GLCALLP glTextureBarrier)(void);
#endif /* GL_VERSION_4_5 */

#ifndef GL_ARB_ES2_compatibility
#define GL_ARB_ES2_compatibility 1
#endif /* GL_ARB_ES2_compatibility */

#ifndef GL_ARB_ES3_1_compatibility
#define GL_ARB_ES3_1_compatibility 1
#endif /* GL_ARB_ES3_1_compatibility */

#ifndef GL_ARB_ES3_compatibility
#define GL_ARB_ES3_compatibility 1
#endif /* GL_ARB_ES3_compatibility */

#ifndef GL_ARB_arrays_of_arrays
#define GL_ARB_arrays_of_arrays 1
#endif /* GL_ARB_arrays_of_arrays */

#ifndef GL_ARB_base_instance
#define GL_ARB_base_instance 1
#endif /* GL_ARB_base_instance */

#ifndef GL_ARB_bindless_texture
#define GL_ARB_bindless_texture 1
typedef uint64_t GLuint64EXT;
#define GL_UNSIGNED_INT64_ARB             0x140F
GLAPI GLuint64 (GLCALLP glGetTextureHandleARB)(GLuint texture);
GLAPI GLuint64 (GLCALLP glGetTextureSamplerHandleARB)(GLuint texture, GLuint sampler);
GLAPI void (GLCALLP glMakeTextureHandleResidentARB)(GLuint64 handle);
GLAPI void (GLCALLP glMakeTextureHandleNonResidentARB)(GLuint64 handle);
GLAPI GLuint64 (GLCALLP glGetImageHandleARB)(GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format);
GLAPI void (GLCALLP glMakeImageHandleResidentARB)(GLuint64 handle, GLenum access);
GLAPI void (GLCALLP glMakeImageHandleNonResidentARB)(GLuint64 handle);
GLAPI void (GLCALLP glUniformHandleui64ARB)(GLint location, GLuint64 value);
GLAPI void (GLCALLP glUniformHandleui64vARB)(GLint location, GLsizei count, const GLuint64 *value);
GLAPI void (GLCALLP glProgramUniformHandleui64ARB)(GLuint program, GLint location, GLuint64 value);
GLAPI void (GLCALLP glProgramUniformHandleui64vARB)(GLuint program, GLint location, GLsizei count, const GLuint64 *values);
GLAPI GLboolean (GLCALLP glIsTextureHandleResidentARB)(GLuint64 handle);
GLAPI GLboolean (GLCALLP glIsImageHandleResidentARB)(GLuint64 handle);
GLAPI void (GLCALLP glVertexAttribL1ui64ARB)(GLuint index, GLuint64EXT x);
GLAPI void (GLCALLP glVertexAttribL1ui64vARB)(GLuint index, const GLuint64EXT *v);
GLAPI void (GLCALLP glGetVertexAttribLui64vARB)(GLuint index, GLenum pname, GLuint64EXT *params);
#endif /* GL_ARB_bindless_texture */

#ifndef GL_ARB_blend_func_extended
#define GL_ARB_blend_func_extended 1
#endif /* GL_ARB_blend_func_extended */

#ifndef GL_ARB_buffer_storage
#define GL_ARB_buffer_storage 1
#endif /* GL_ARB_buffer_storage */

#ifndef GL_ARB_cl_event
#define GL_ARB_cl_event 1
struct _cl_context;
struct _cl_event;
#define GL_SYNC_CL_EVENT_ARB              0x8240
#define GL_SYNC_CL_EVENT_COMPLETE_ARB     0x8241
GLAPI GLsync (GLCALLP glCreateSyncFromCLeventARB)(struct _cl_context *context, struct _cl_event *event, GLbitfield flags);
#endif /* GL_ARB_cl_event */

#ifndef GL_ARB_clear_buffer_object
#define GL_ARB_clear_buffer_object 1
#endif /* GL_ARB_clear_buffer_object */

#ifndef GL_ARB_clear_texture
#define GL_ARB_clear_texture 1
#endif /* GL_ARB_clear_texture */

#ifndef GL_ARB_clip_control
#define GL_ARB_clip_control 1
#endif /* GL_ARB_clip_control */

#ifndef GL_ARB_compressed_texture_pixel_storage
#define GL_ARB_compressed_texture_pixel_storage 1
#endif /* GL_ARB_compressed_texture_pixel_storage */

#ifndef GL_ARB_compute_shader
#define GL_ARB_compute_shader 1
#endif /* GL_ARB_compute_shader */

#ifndef GL_ARB_compute_variable_group_size
#define GL_ARB_compute_variable_group_size 1
#define GL_MAX_COMPUTE_VARIABLE_GROUP_INVOCATIONS_ARB 0x9344
#define GL_MAX_COMPUTE_FIXED_GROUP_INVOCATIONS_ARB 0x90EB
#define GL_MAX_COMPUTE_VARIABLE_GROUP_SIZE_ARB 0x9345
#define GL_MAX_COMPUTE_FIXED_GROUP_SIZE_ARB 0x91BF
GLAPI void (GLCALLP glDispatchComputeGroupSizeARB)(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z, GLuint group_size_x, GLuint group_size_y, GLuint group_size_z);
#endif /* GL_ARB_compute_variable_group_size */

#ifndef GL_ARB_conditional_render_inverted
#define GL_ARB_conditional_render_inverted 1
#endif /* GL_ARB_conditional_render_inverted */

#ifndef GL_ARB_conservative_depth
#define GL_ARB_conservative_depth 1
#endif /* GL_ARB_conservative_depth */

#ifndef GL_ARB_copy_buffer
#define GL_ARB_copy_buffer 1
#endif /* GL_ARB_copy_buffer */

#ifndef GL_ARB_copy_image
#define GL_ARB_copy_image 1
#endif /* GL_ARB_copy_image */

#ifndef GL_ARB_cull_distance
#define GL_ARB_cull_distance 1
#endif /* GL_ARB_cull_distance */

#ifndef GL_ARB_debug_output
#define GL_ARB_debug_output 1
typedef void (GLCALL  *GLDEBUGPROCARB)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,const void *userParam);
#define GL_DEBUG_OUTPUT_SYNCHRONOUS_ARB   0x8242
#define GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH_ARB 0x8243
#define GL_DEBUG_CALLBACK_FUNCTION_ARB    0x8244
#define GL_DEBUG_CALLBACK_USER_PARAM_ARB  0x8245
#define GL_DEBUG_SOURCE_API_ARB           0x8246
#define GL_DEBUG_SOURCE_WINDOW_SYSTEM_ARB 0x8247
#define GL_DEBUG_SOURCE_SHADER_COMPILER_ARB 0x8248
#define GL_DEBUG_SOURCE_THIRD_PARTY_ARB   0x8249
#define GL_DEBUG_SOURCE_APPLICATION_ARB   0x824A
#define GL_DEBUG_SOURCE_OTHER_ARB         0x824B
#define GL_DEBUG_TYPE_ERROR_ARB           0x824C
#define GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR_ARB 0x824D
#define GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR_ARB 0x824E
#define GL_DEBUG_TYPE_PORTABILITY_ARB     0x824F
#define GL_DEBUG_TYPE_PERFORMANCE_ARB     0x8250
#define GL_DEBUG_TYPE_OTHER_ARB           0x8251
#define GL_MAX_DEBUG_MESSAGE_LENGTH_ARB   0x9143
#define GL_MAX_DEBUG_LOGGED_MESSAGES_ARB  0x9144
#define GL_DEBUG_LOGGED_MESSAGES_ARB      0x9145
#define GL_DEBUG_SEVERITY_HIGH_ARB        0x9146
#define GL_DEBUG_SEVERITY_MEDIUM_ARB      0x9147
#define GL_DEBUG_SEVERITY_LOW_ARB         0x9148
GLAPI void (GLCALLP glDebugMessageControlARB)(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
GLAPI void (GLCALLP glDebugMessageInsertARB)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf);
GLAPI void (GLCALLP glDebugMessageCallbackARB)(GLDEBUGPROCARB callback, const void *userParam);
GLAPI GLuint (GLCALLP glGetDebugMessageLogARB)(GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog);
#endif /* GL_ARB_debug_output */

#ifndef GL_ARB_depth_buffer_float
#define GL_ARB_depth_buffer_float 1
#endif /* GL_ARB_depth_buffer_float */

#ifndef GL_ARB_depth_clamp
#define GL_ARB_depth_clamp 1
#endif /* GL_ARB_depth_clamp */

#ifndef GL_ARB_derivative_control
#define GL_ARB_derivative_control 1
#endif /* GL_ARB_derivative_control */

#ifndef GL_ARB_direct_state_access
#define GL_ARB_direct_state_access 1
#endif /* GL_ARB_direct_state_access */

#ifndef GL_ARB_draw_buffers_blend
#define GL_ARB_draw_buffers_blend 1
GLAPI void (GLCALLP glBlendEquationiARB)(GLuint buf, GLenum mode);
GLAPI void (GLCALLP glBlendEquationSeparateiARB)(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
GLAPI void (GLCALLP glBlendFunciARB)(GLuint buf, GLenum src, GLenum dst);
GLAPI void (GLCALLP glBlendFuncSeparateiARB)(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
#endif /* GL_ARB_draw_buffers_blend */

#ifndef GL_ARB_draw_elements_base_vertex
#define GL_ARB_draw_elements_base_vertex 1
#endif /* GL_ARB_draw_elements_base_vertex */

#ifndef GL_ARB_draw_indirect
#define GL_ARB_draw_indirect 1
#endif /* GL_ARB_draw_indirect */

#ifndef GL_ARB_enhanced_layouts
#define GL_ARB_enhanced_layouts 1
#endif /* GL_ARB_enhanced_layouts */

#ifndef GL_ARB_explicit_attrib_location
#define GL_ARB_explicit_attrib_location 1
#endif /* GL_ARB_explicit_attrib_location */

#ifndef GL_ARB_explicit_uniform_location
#define GL_ARB_explicit_uniform_location 1
#endif /* GL_ARB_explicit_uniform_location */

#ifndef GL_ARB_fragment_coord_conventions
#define GL_ARB_fragment_coord_conventions 1
#endif /* GL_ARB_fragment_coord_conventions */

#ifndef GL_ARB_fragment_layer_viewport
#define GL_ARB_fragment_layer_viewport 1
#endif /* GL_ARB_fragment_layer_viewport */

#ifndef GL_ARB_framebuffer_no_attachments
#define GL_ARB_framebuffer_no_attachments 1
#endif /* GL_ARB_framebuffer_no_attachments */

#ifndef GL_ARB_framebuffer_object
#define GL_ARB_framebuffer_object 1
#endif /* GL_ARB_framebuffer_object */

#ifndef GL_ARB_framebuffer_sRGB
#define GL_ARB_framebuffer_sRGB 1
#endif /* GL_ARB_framebuffer_sRGB */

#ifndef GL_ARB_get_program_binary
#define GL_ARB_get_program_binary 1
#endif /* GL_ARB_get_program_binary */

#ifndef GL_ARB_get_texture_sub_image
#define GL_ARB_get_texture_sub_image 1
#endif /* GL_ARB_get_texture_sub_image */

#ifndef GL_ARB_gpu_shader5
#define GL_ARB_gpu_shader5 1
#endif /* GL_ARB_gpu_shader5 */

#ifndef GL_ARB_gpu_shader_fp64
#define GL_ARB_gpu_shader_fp64 1
#endif /* GL_ARB_gpu_shader_fp64 */

#ifndef GL_ARB_half_float_vertex
#define GL_ARB_half_float_vertex 1
#endif /* GL_ARB_half_float_vertex */

#ifndef GL_ARB_imaging
#define GL_ARB_imaging 1
#define GL_BLEND_COLOR                    0x8005
#define GL_BLEND_EQUATION                 0x8009
#endif /* GL_ARB_imaging */

#ifndef GL_ARB_indirect_parameters
#define GL_ARB_indirect_parameters 1
#define GL_PARAMETER_BUFFER_ARB           0x80EE
#define GL_PARAMETER_BUFFER_BINDING_ARB   0x80EF
GLAPI void (GLCALLP glMultiDrawArraysIndirectCountARB)(GLenum mode, GLintptr indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
GLAPI void (GLCALLP glMultiDrawElementsIndirectCountARB)(GLenum mode, GLenum type, GLintptr indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
#endif /* GL_ARB_indirect_parameters */

#ifndef GL_ARB_internalformat_query
#define GL_ARB_internalformat_query 1
#endif /* GL_ARB_internalformat_query */

#ifndef GL_ARB_internalformat_query2
#define GL_ARB_internalformat_query2 1
#define GL_SRGB_DECODE_ARB                0x8299
#endif /* GL_ARB_internalformat_query2 */

#ifndef GL_ARB_invalidate_subdata
#define GL_ARB_invalidate_subdata 1
#endif /* GL_ARB_invalidate_subdata */

#ifndef GL_ARB_map_buffer_alignment
#define GL_ARB_map_buffer_alignment 1
#endif /* GL_ARB_map_buffer_alignment */

#ifndef GL_ARB_map_buffer_range
#define GL_ARB_map_buffer_range 1
#endif /* GL_ARB_map_buffer_range */

#ifndef GL_ARB_multi_bind
#define GL_ARB_multi_bind 1
#endif /* GL_ARB_multi_bind */

#ifndef GL_ARB_multi_draw_indirect
#define GL_ARB_multi_draw_indirect 1
#endif /* GL_ARB_multi_draw_indirect */

#ifndef GL_ARB_occlusion_query2
#define GL_ARB_occlusion_query2 1
#endif /* GL_ARB_occlusion_query2 */

#ifndef GL_ARB_pipeline_statistics_query
#define GL_ARB_pipeline_statistics_query 1
#define GL_VERTICES_SUBMITTED_ARB         0x82EE
#define GL_PRIMITIVES_SUBMITTED_ARB       0x82EF
#define GL_VERTEX_SHADER_INVOCATIONS_ARB  0x82F0
#define GL_TESS_CONTROL_SHADER_PATCHES_ARB 0x82F1
#define GL_TESS_EVALUATION_SHADER_INVOCATIONS_ARB 0x82F2
#define GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED_ARB 0x82F3
#define GL_FRAGMENT_SHADER_INVOCATIONS_ARB 0x82F4
#define GL_COMPUTE_SHADER_INVOCATIONS_ARB 0x82F5
#define GL_CLIPPING_INPUT_PRIMITIVES_ARB  0x82F6
#define GL_CLIPPING_OUTPUT_PRIMITIVES_ARB 0x82F7
#endif /* GL_ARB_pipeline_statistics_query */

#ifndef GL_ARB_program_interface_query
#define GL_ARB_program_interface_query 1
#endif /* GL_ARB_program_interface_query */

#ifndef GL_ARB_provoking_vertex
#define GL_ARB_provoking_vertex 1
#endif /* GL_ARB_provoking_vertex */

#ifndef GL_ARB_query_buffer_object
#define GL_ARB_query_buffer_object 1
#endif /* GL_ARB_query_buffer_object */

#ifndef GL_ARB_robust_buffer_access_behavior
#define GL_ARB_robust_buffer_access_behavior 1
#endif /* GL_ARB_robust_buffer_access_behavior */

#ifndef GL_ARB_robustness
#define GL_ARB_robustness 1
#define GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT_ARB 0x00000004
#define GL_LOSE_CONTEXT_ON_RESET_ARB      0x8252
#define GL_GUILTY_CONTEXT_RESET_ARB       0x8253
#define GL_INNOCENT_CONTEXT_RESET_ARB     0x8254
#define GL_UNKNOWN_CONTEXT_RESET_ARB      0x8255
#define GL_RESET_NOTIFICATION_STRATEGY_ARB 0x8256
#define GL_NO_RESET_NOTIFICATION_ARB      0x8261
GLAPI GLenum (GLCALLP glGetGraphicsResetStatusARB)(void);
GLAPI void (GLCALLP glGetnTexImageARB)(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *img);
GLAPI void (GLCALLP glReadnPixelsARB)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data);
GLAPI void (GLCALLP glGetnCompressedTexImageARB)(GLenum target, GLint lod, GLsizei bufSize, void *img);
GLAPI void (GLCALLP glGetnUniformfvARB)(GLuint program, GLint location, GLsizei bufSize, GLfloat *params);
GLAPI void (GLCALLP glGetnUniformivARB)(GLuint program, GLint location, GLsizei bufSize, GLint *params);
GLAPI void (GLCALLP glGetnUniformuivARB)(GLuint program, GLint location, GLsizei bufSize, GLuint *params);
GLAPI void (GLCALLP glGetnUniformdvARB)(GLuint program, GLint location, GLsizei bufSize, GLdouble *params);
#endif /* GL_ARB_robustness */

#ifndef GL_ARB_robustness_isolation
#define GL_ARB_robustness_isolation 1
#endif /* GL_ARB_robustness_isolation */

#ifndef GL_ARB_sample_shading
#define GL_ARB_sample_shading 1
#define GL_SAMPLE_SHADING_ARB             0x8C36
#define GL_MIN_SAMPLE_SHADING_VALUE_ARB   0x8C37
GLAPI void (GLCALLP glMinSampleShadingARB)(GLfloat value);
#endif /* GL_ARB_sample_shading */

#ifndef GL_ARB_sampler_objects
#define GL_ARB_sampler_objects 1
#endif /* GL_ARB_sampler_objects */

#ifndef GL_ARB_seamless_cube_map
#define GL_ARB_seamless_cube_map 1
#endif /* GL_ARB_seamless_cube_map */

#ifndef GL_ARB_seamless_cubemap_per_texture
#define GL_ARB_seamless_cubemap_per_texture 1
#endif /* GL_ARB_seamless_cubemap_per_texture */

#ifndef GL_ARB_separate_shader_objects
#define GL_ARB_separate_shader_objects 1
#endif /* GL_ARB_separate_shader_objects */

#ifndef GL_ARB_shader_atomic_counters
#define GL_ARB_shader_atomic_counters 1
#endif /* GL_ARB_shader_atomic_counters */

#ifndef GL_ARB_shader_bit_encoding
#define GL_ARB_shader_bit_encoding 1
#endif /* GL_ARB_shader_bit_encoding */

#ifndef GL_ARB_shader_draw_parameters
#define GL_ARB_shader_draw_parameters 1
#endif /* GL_ARB_shader_draw_parameters */

#ifndef GL_ARB_shader_group_vote
#define GL_ARB_shader_group_vote 1
#endif /* GL_ARB_shader_group_vote */

#ifndef GL_ARB_shader_image_load_store
#define GL_ARB_shader_image_load_store 1
#endif /* GL_ARB_shader_image_load_store */

#ifndef GL_ARB_shader_image_size
#define GL_ARB_shader_image_size 1
#endif /* GL_ARB_shader_image_size */

#ifndef GL_ARB_shader_precision
#define GL_ARB_shader_precision 1
#endif /* GL_ARB_shader_precision */

#ifndef GL_ARB_shader_stencil_export
#define GL_ARB_shader_stencil_export 1
#endif /* GL_ARB_shader_stencil_export */

#ifndef GL_ARB_shader_storage_buffer_object
#define GL_ARB_shader_storage_buffer_object 1
#endif /* GL_ARB_shader_storage_buffer_object */

#ifndef GL_ARB_shader_subroutine
#define GL_ARB_shader_subroutine 1
#endif /* GL_ARB_shader_subroutine */

#ifndef GL_ARB_shader_texture_image_samples
#define GL_ARB_shader_texture_image_samples 1
#endif /* GL_ARB_shader_texture_image_samples */

#ifndef GL_ARB_shading_language_420pack
#define GL_ARB_shading_language_420pack 1
#endif /* GL_ARB_shading_language_420pack */

#ifndef GL_ARB_shading_language_include
#define GL_ARB_shading_language_include 1
#define GL_SHADER_INCLUDE_ARB             0x8DAE
#define GL_NAMED_STRING_LENGTH_ARB        0x8DE9
#define GL_NAMED_STRING_TYPE_ARB          0x8DEA
GLAPI void (GLCALLP glNamedStringARB)(GLenum type, GLint namelen, const GLchar *name, GLint stringlen, const GLchar *string);
GLAPI void (GLCALLP glDeleteNamedStringARB)(GLint namelen, const GLchar *name);
GLAPI void (GLCALLP glCompileShaderIncludeARB)(GLuint shader, GLsizei count, const GLchar *const*path, const GLint *length);
GLAPI GLboolean (GLCALLP glIsNamedStringARB)(GLint namelen, const GLchar *name);
GLAPI void (GLCALLP glGetNamedStringARB)(GLint namelen, const GLchar *name, GLsizei bufSize, GLint *stringlen, GLchar *string);
GLAPI void (GLCALLP glGetNamedStringivARB)(GLint namelen, const GLchar *name, GLenum pname, GLint *params);
#endif /* GL_ARB_shading_language_include */

#ifndef GL_ARB_shading_language_packing
#define GL_ARB_shading_language_packing 1
#endif /* GL_ARB_shading_language_packing */

#ifndef GL_ARB_sparse_buffer
#define GL_ARB_sparse_buffer 1
#define GL_SPARSE_STORAGE_BIT_ARB         0x0400
#define GL_SPARSE_BUFFER_PAGE_SIZE_ARB    0x82F8
GLAPI void (GLCALLP glBufferPageCommitmentARB)(GLenum target, GLintptr offset, GLsizeiptr size, GLboolean commit);
GLAPI void (GLCALLP glNamedBufferPageCommitmentEXT)(GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit);
GLAPI void (GLCALLP glNamedBufferPageCommitmentARB)(GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit);
#endif /* GL_ARB_sparse_buffer */

#ifndef GL_ARB_sparse_texture
#define GL_ARB_sparse_texture 1
#define GL_TEXTURE_SPARSE_ARB             0x91A6
#define GL_VIRTUAL_PAGE_SIZE_INDEX_ARB    0x91A7
#define GL_NUM_SPARSE_LEVELS_ARB          0x91AA
#define GL_NUM_VIRTUAL_PAGE_SIZES_ARB     0x91A8
#define GL_VIRTUAL_PAGE_SIZE_X_ARB        0x9195
#define GL_VIRTUAL_PAGE_SIZE_Y_ARB        0x9196
#define GL_VIRTUAL_PAGE_SIZE_Z_ARB        0x9197
#define GL_MAX_SPARSE_TEXTURE_SIZE_ARB    0x9198
#define GL_MAX_SPARSE_3D_TEXTURE_SIZE_ARB 0x9199
#define GL_MAX_SPARSE_ARRAY_TEXTURE_LAYERS_ARB 0x919A
#define GL_SPARSE_TEXTURE_FULL_ARRAY_CUBE_MIPMAPS_ARB 0x91A9
GLAPI void (GLCALLP glTexPageCommitmentARB)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit);
#endif /* GL_ARB_sparse_texture */

#ifndef GL_ARB_stencil_texturing
#define GL_ARB_stencil_texturing 1
#endif /* GL_ARB_stencil_texturing */

#ifndef GL_ARB_sync
#define GL_ARB_sync 1
#endif /* GL_ARB_sync */

#ifndef GL_ARB_tessellation_shader
#define GL_ARB_tessellation_shader 1
#endif /* GL_ARB_tessellation_shader */

#ifndef GL_ARB_texture_barrier
#define GL_ARB_texture_barrier 1
#endif /* GL_ARB_texture_barrier */

#ifndef GL_ARB_texture_buffer_object_rgb32
#define GL_ARB_texture_buffer_object_rgb32 1
#endif /* GL_ARB_texture_buffer_object_rgb32 */

#ifndef GL_ARB_texture_buffer_range
#define GL_ARB_texture_buffer_range 1
#endif /* GL_ARB_texture_buffer_range */

#ifndef GL_ARB_texture_compression_bptc
#define GL_ARB_texture_compression_bptc 1
#define GL_COMPRESSED_RGBA_BPTC_UNORM_ARB 0x8E8C
#define GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM_ARB 0x8E8D
#define GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT_ARB 0x8E8E
#define GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT_ARB 0x8E8F
#endif /* GL_ARB_texture_compression_bptc */

#ifndef GL_ARB_texture_compression_rgtc
#define GL_ARB_texture_compression_rgtc 1
#endif /* GL_ARB_texture_compression_rgtc */

#ifndef GL_ARB_texture_cube_map_array
#define GL_ARB_texture_cube_map_array 1
#define GL_TEXTURE_CUBE_MAP_ARRAY_ARB     0x9009
#define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY_ARB 0x900A
#define GL_PROXY_TEXTURE_CUBE_MAP_ARRAY_ARB 0x900B
#define GL_SAMPLER_CUBE_MAP_ARRAY_ARB     0x900C
#define GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW_ARB 0x900D
#define GL_INT_SAMPLER_CUBE_MAP_ARRAY_ARB 0x900E
#define GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY_ARB 0x900F
#endif /* GL_ARB_texture_cube_map_array */

#ifndef GL_ARB_texture_gather
#define GL_ARB_texture_gather 1
#define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET_ARB 0x8E5E
#define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET_ARB 0x8E5F
#define GL_MAX_PROGRAM_TEXTURE_GATHER_COMPONENTS_ARB 0x8F9F
#endif /* GL_ARB_texture_gather */

#ifndef GL_ARB_texture_mirror_clamp_to_edge
#define GL_ARB_texture_mirror_clamp_to_edge 1
#endif /* GL_ARB_texture_mirror_clamp_to_edge */

#ifndef GL_ARB_texture_multisample
#define GL_ARB_texture_multisample 1
#endif /* GL_ARB_texture_multisample */

#ifndef GL_ARB_texture_query_levels
#define GL_ARB_texture_query_levels 1
#endif /* GL_ARB_texture_query_levels */

#ifndef GL_ARB_texture_query_lod
#define GL_ARB_texture_query_lod 1
#endif /* GL_ARB_texture_query_lod */

#ifndef GL_ARB_texture_rg
#define GL_ARB_texture_rg 1
#endif /* GL_ARB_texture_rg */

#ifndef GL_ARB_texture_rgb10_a2ui
#define GL_ARB_texture_rgb10_a2ui 1
#endif /* GL_ARB_texture_rgb10_a2ui */

#ifndef GL_ARB_texture_stencil8
#define GL_ARB_texture_stencil8 1
#endif /* GL_ARB_texture_stencil8 */

#ifndef GL_ARB_texture_storage
#define GL_ARB_texture_storage 1
#endif /* GL_ARB_texture_storage */

#ifndef GL_ARB_texture_storage_multisample
#define GL_ARB_texture_storage_multisample 1
#endif /* GL_ARB_texture_storage_multisample */

#ifndef GL_ARB_texture_swizzle
#define GL_ARB_texture_swizzle 1
#endif /* GL_ARB_texture_swizzle */

#ifndef GL_ARB_texture_view
#define GL_ARB_texture_view 1
#endif /* GL_ARB_texture_view */

#ifndef GL_ARB_timer_query
#define GL_ARB_timer_query 1
#endif /* GL_ARB_timer_query */

#ifndef GL_ARB_transform_feedback2
#define GL_ARB_transform_feedback2 1
#endif /* GL_ARB_transform_feedback2 */

#ifndef GL_ARB_transform_feedback3
#define GL_ARB_transform_feedback3 1
#endif /* GL_ARB_transform_feedback3 */

#ifndef GL_ARB_transform_feedback_instanced
#define GL_ARB_transform_feedback_instanced 1
#endif /* GL_ARB_transform_feedback_instanced */

#ifndef GL_ARB_transform_feedback_overflow_query
#define GL_ARB_transform_feedback_overflow_query 1
#define GL_TRANSFORM_FEEDBACK_OVERFLOW_ARB 0x82EC
#define GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW_ARB 0x82ED
#endif /* GL_ARB_transform_feedback_overflow_query */

#ifndef GL_ARB_uniform_buffer_object
#define GL_ARB_uniform_buffer_object 1
#endif /* GL_ARB_uniform_buffer_object */

#ifndef GL_ARB_vertex_array_bgra
#define GL_ARB_vertex_array_bgra 1
#endif /* GL_ARB_vertex_array_bgra */

#ifndef GL_ARB_vertex_array_object
#define GL_ARB_vertex_array_object 1
#endif /* GL_ARB_vertex_array_object */

#ifndef GL_ARB_vertex_attrib_64bit
#define GL_ARB_vertex_attrib_64bit 1
#endif /* GL_ARB_vertex_attrib_64bit */

#ifndef GL_ARB_vertex_attrib_binding
#define GL_ARB_vertex_attrib_binding 1
#endif /* GL_ARB_vertex_attrib_binding */

#ifndef GL_ARB_vertex_type_10f_11f_11f_rev
#define GL_ARB_vertex_type_10f_11f_11f_rev 1
#endif /* GL_ARB_vertex_type_10f_11f_11f_rev */

#ifndef GL_ARB_vertex_type_2_10_10_10_rev
#define GL_ARB_vertex_type_2_10_10_10_rev 1
#endif /* GL_ARB_vertex_type_2_10_10_10_rev */

#ifndef GL_ARB_viewport_array
#define GL_ARB_viewport_array 1
#endif /* GL_ARB_viewport_array */

#ifndef GL_KHR_context_flush_control
#define GL_KHR_context_flush_control 1
#endif /* GL_KHR_context_flush_control */

#ifndef GL_KHR_debug
#define GL_KHR_debug 1
#endif /* GL_KHR_debug */

#ifndef GL_KHR_no_error
#define GL_KHR_no_error 1
#define GL_CONTEXT_FLAG_NO_ERROR_BIT_KHR  0x00000008
#endif /* GL_KHR_no_error */

#ifndef GL_KHR_robust_buffer_access_behavior
#define GL_KHR_robust_buffer_access_behavior 1
#endif /* GL_KHR_robust_buffer_access_behavior */

#ifndef GL_KHR_robustness
#define GL_KHR_robustness 1
#define GL_CONTEXT_ROBUST_ACCESS          0x90F3
#endif /* GL_KHR_robustness */

#ifndef GL_KHR_texture_compression_astc_hdr
#define GL_KHR_texture_compression_astc_hdr 1
#define GL_COMPRESSED_RGBA_ASTC_4x4_KHR   0x93B0
#define GL_COMPRESSED_RGBA_ASTC_5x4_KHR   0x93B1
#define GL_COMPRESSED_RGBA_ASTC_5x5_KHR   0x93B2
#define GL_COMPRESSED_RGBA_ASTC_6x5_KHR   0x93B3
#define GL_COMPRESSED_RGBA_ASTC_6x6_KHR   0x93B4
#define GL_COMPRESSED_RGBA_ASTC_8x5_KHR   0x93B5
#define GL_COMPRESSED_RGBA_ASTC_8x6_KHR   0x93B6
#define GL_COMPRESSED_RGBA_ASTC_8x8_KHR   0x93B7
#define GL_COMPRESSED_RGBA_ASTC_10x5_KHR  0x93B8
#define GL_COMPRESSED_RGBA_ASTC_10x6_KHR  0x93B9
#define GL_COMPRESSED_RGBA_ASTC_10x8_KHR  0x93BA
#define GL_COMPRESSED_RGBA_ASTC_10x10_KHR 0x93BB
#define GL_COMPRESSED_RGBA_ASTC_12x10_KHR 0x93BC
#define GL_COMPRESSED_RGBA_ASTC_12x12_KHR 0x93BD
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_4x4_KHR 0x93D0
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x4_KHR 0x93D1
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x5_KHR 0x93D2
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x5_KHR 0x93D3
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x6_KHR 0x93D4
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x5_KHR 0x93D5
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x6_KHR 0x93D6
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x8_KHR 0x93D7
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x5_KHR 0x93D8
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x6_KHR 0x93D9
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x8_KHR 0x93DA
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x10_KHR 0x93DB
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x10_KHR 0x93DC
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x12_KHR 0x93DD
#endif /* GL_KHR_texture_compression_astc_hdr */

#ifndef GL_KHR_texture_compression_astc_ldr
#define GL_KHR_texture_compression_astc_ldr 1
#endif /* GL_KHR_texture_compression_astc_ldr */

#ifndef GL_KHR_texture_compression_astc_sliced_3d
#define GL_KHR_texture_compression_astc_sliced_3d 1
#endif /* GL_KHR_texture_compression_astc_sliced_3d */

#endif // __glcorearb_h_

// Indirect draw stuff
typedef struct GLDrawArraysIndirectCommand
{
    GLuint count;
    GLuint primCount;
    GLuint first;
    GLuint baseInstance;
} GLDrawArraysIndirectCommand;

typedef struct GLDrawElementsIndirectCommand
{
    GLuint count;
    GLuint primCount;
    GLuint firstIndex;
    GLint  baseVertex;
    GLuint baseInstance;
} GLDrawElementsIndirectCommand;

#endif // JUSTGL_H_INCLUDED

#ifdef JUSTGL_IMPLEMENTATION

// internal forward declarations
void InitProcsGL();

// argh C++
#ifdef __cplusplus
#define PROC_CAST *(void**)&
#else
#define PROC_CAST
#endif

// Windows implementation
#ifdef _WIN32

#ifndef UNICODE
#define UNICODE 1
#endif
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN 1
#endif
#ifndef NOMINMAX
#define NOMINMAX 1
#endif
#include <Windows.h>

HMODULE g_hModuleOpenGL32;
HWND g_hWnd;

HGLRC(APIENTRY *pfnwglCreateContext)(HDC hdc);
PROC(APIENTRY *pfnwglGetProcAddress)(LPCSTR lpszProc);
BOOL(APIENTRY *pfnwglMakeCurrent)(HDC hdc, HGLRC hglrc);

void* GetProcGL(const char* procname)
{
    PROC proc = pfnwglGetProcAddress(procname);
    if (proc == NULL)
    {
        proc = GetProcAddress(g_hModuleOpenGL32, procname);
    }
    return proc;
}

void AssertWin32(BOOL b)
{
    if (b == TRUE)
    {
        return;
    }

    DWORD errorCode = GetLastError();

    LPWSTR buffPtr;
    DWORD bufferLength = FormatMessageW(
        FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL, errorCode, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPWSTR)&buffPtr, 0, NULL);
    AssertWin32(bufferLength != 0);

    OutputDebugStringW(buffPtr);

    int choice = MessageBoxW(g_hWnd, buffPtr, NULL, MB_ABORTRETRYIGNORE);
    AssertWin32(choice != 0);

    if (choice == IDABORT)
    {
        ExitProcess(-1);
    }
    else if (choice == IDRETRY)
    {
        DebugBreak();
    }
    else if (choice == IDIGNORE)
    {
        // do nothing
    }

    AssertWin32(LocalFree(buffPtr) == NULL);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CLOSE:
        ExitProcess(0);
    case WM_SIZE:
    {
        int width = LOWORD(lParam);
        int height = HIWORD(lParam);
        ResizeGL(width, height);
        return 0;
    }
    default:
        return DefWindowProcW(hWnd, message, wParam, lParam);
    }
}

int main()
{
    g_hModuleOpenGL32 = LoadLibraryW(L"opengl32.dll");

    PROC_CAST pfnwglCreateContext = GetProcAddress(g_hModuleOpenGL32, "wglCreateContext");
    AssertWin32(pfnwglCreateContext != NULL);
    PROC_CAST pfnwglGetProcAddress = GetProcAddress(g_hModuleOpenGL32, "wglGetProcAddress");
    AssertWin32(pfnwglGetProcAddress != NULL);
    PROC_CAST pfnwglMakeCurrent = GetProcAddress(g_hModuleOpenGL32, "wglMakeCurrent");
    AssertWin32(pfnwglMakeCurrent != NULL);

    HMODULE hInstance = GetModuleHandle(NULL);
    AssertWin32(hInstance != NULL);

    WNDCLASSEXW wc;
    ZeroMemory(&wc, sizeof(wc));
    wc.cbSize = sizeof(wc);
    wc.style = CS_OWNDC;
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursorW(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)COLOR_BACKGROUND;
    wc.lpszClassName = L"WindowClass";
    AssertWin32(RegisterClassExW(&wc) != 0);

    WindowConfig config;
    ZeroMemory(&config, sizeof(config));
    ConfigGL(&config);

    wchar_t* wtitle = (wchar_t*)malloc(sizeof(wchar_t) * (strlen(config.WindowTitle) + 1));
    int i;
    for (i = 0; config.WindowTitle[i] != '\0'; i++)
    {
        wtitle[i] = config.WindowTitle[i];
    }
    wtitle[i] = '\0';

    DWORD dwStyle = WS_OVERLAPPEDWINDOW;
    RECT wr = { 0, 0, config.ClientWidth, config.ClientHeight };
    AssertWin32(AdjustWindowRect(&wr, dwStyle, FALSE) != 0);
    g_hWnd = CreateWindowExW(
        0, L"WindowClass",
        wtitle,
        dwStyle,
        0, 0, wr.right - wr.left, wr.bottom - wr.top,
        0, 0, hInstance, 0);
    AssertWin32(g_hWnd != NULL);

    free(wtitle);

    PIXELFORMATDESCRIPTOR pfd;
    ZeroMemory(&pfd, sizeof(pfd));
    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 32;
    pfd.cDepthBits = 24;
    pfd.cStencilBits = 8;
    pfd.iLayerType = PFD_MAIN_PLANE;

    HDC hDC = GetDC(g_hWnd);
    AssertWin32(hDC != NULL);

    int chosenPixelFormat = ChoosePixelFormat(hDC, &pfd);
    AssertWin32(chosenPixelFormat != 0);

    AssertWin32(SetPixelFormat(hDC, chosenPixelFormat, &pfd) != FALSE);

    HGLRC hGLRC = pfnwglCreateContext(hDC);
    AssertWin32(hGLRC != NULL);

    AssertWin32(pfnwglMakeCurrent(hDC, hGLRC) != FALSE);

    InitProcsGL();

    InitGL();

    ShowWindow(g_hWnd, SW_SHOWNORMAL);

    for (;;)
    {
        MSG msg;
        while (PeekMessageW(&msg, NULL, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessageW(&msg);
        }

        PaintGL();

        AssertWin32(SwapBuffers(hDC) != FALSE);
    }

    return 0;
}
#endif // _WIN32

// cross-platform OpenGL proc setup
void InitProcsGL()
{
    PROC_CAST glCullFace = GetProcGL("glCullFace");
    PROC_CAST glFrontFace = GetProcGL("glFrontFace");
    PROC_CAST glHint = GetProcGL("glHint");
    PROC_CAST glLineWidth = GetProcGL("glLineWidth");
    PROC_CAST glPointSize = GetProcGL("glPointSize");
    PROC_CAST glPolygonMode = GetProcGL("glPolygonMode");
    PROC_CAST glScissor = GetProcGL("glScissor");
    PROC_CAST glTexParameterf = GetProcGL("glTexParameterf");
    PROC_CAST glTexParameterfv = GetProcGL("glTexParameterfv");
    PROC_CAST glTexParameteri = GetProcGL("glTexParameteri");
    PROC_CAST glTexParameteriv = GetProcGL("glTexParameteriv");
    PROC_CAST glTexImage1D = GetProcGL("glTexImage1D");
    PROC_CAST glTexImage2D = GetProcGL("glTexImage2D");
    PROC_CAST glDrawBuffer = GetProcGL("glDrawBuffer");
    PROC_CAST glClear = GetProcGL("glClear");
    PROC_CAST glClearColor = GetProcGL("glClearColor");
    PROC_CAST glClearStencil = GetProcGL("glClearStencil");
    PROC_CAST glClearDepth = GetProcGL("glClearDepth");
    PROC_CAST glStencilMask = GetProcGL("glStencilMask");
    PROC_CAST glColorMask = GetProcGL("glColorMask");
    PROC_CAST glDepthMask = GetProcGL("glDepthMask");
    PROC_CAST glDisable = GetProcGL("glDisable");
    PROC_CAST glEnable = GetProcGL("glEnable");
    PROC_CAST glFinish = GetProcGL("glFinish");
    PROC_CAST glFlush = GetProcGL("glFlush");
    PROC_CAST glBlendFunc = GetProcGL("glBlendFunc");
    PROC_CAST glLogicOp = GetProcGL("glLogicOp");
    PROC_CAST glStencilFunc = GetProcGL("glStencilFunc");
    PROC_CAST glStencilOp = GetProcGL("glStencilOp");
    PROC_CAST glDepthFunc = GetProcGL("glDepthFunc");
    PROC_CAST glPixelStoref = GetProcGL("glPixelStoref");
    PROC_CAST glPixelStorei = GetProcGL("glPixelStorei");
    PROC_CAST glReadBuffer = GetProcGL("glReadBuffer");
    PROC_CAST glReadPixels = GetProcGL("glReadPixels");
    PROC_CAST glGetBooleanv = GetProcGL("glGetBooleanv");
    PROC_CAST glGetDoublev = GetProcGL("glGetDoublev");
    PROC_CAST glGetError = GetProcGL("glGetError");
    PROC_CAST glGetFloatv = GetProcGL("glGetFloatv");
    PROC_CAST glGetIntegerv = GetProcGL("glGetIntegerv");
    PROC_CAST glGetString = GetProcGL("glGetString");
    PROC_CAST glGetTexImage = GetProcGL("glGetTexImage");
    PROC_CAST glGetTexParameterfv = GetProcGL("glGetTexParameterfv");
    PROC_CAST glGetTexParameteriv = GetProcGL("glGetTexParameteriv");
    PROC_CAST glGetTexLevelParameterfv = GetProcGL("glGetTexLevelParameterfv");
    PROC_CAST glGetTexLevelParameteriv = GetProcGL("glGetTexLevelParameteriv");
    PROC_CAST glIsEnabled = GetProcGL("glIsEnabled");
    PROC_CAST glDepthRange = GetProcGL("glDepthRange");
    PROC_CAST glViewport = GetProcGL("glViewport");
    PROC_CAST glDrawArrays = GetProcGL("glDrawArrays");
    PROC_CAST glDrawElements = GetProcGL("glDrawElements");
    PROC_CAST glGetPointerv = GetProcGL("glGetPointerv");
    PROC_CAST glPolygonOffset = GetProcGL("glPolygonOffset");
    PROC_CAST glCopyTexImage1D = GetProcGL("glCopyTexImage1D");
    PROC_CAST glCopyTexImage2D = GetProcGL("glCopyTexImage2D");
    PROC_CAST glCopyTexSubImage1D = GetProcGL("glCopyTexSubImage1D");
    PROC_CAST glCopyTexSubImage2D = GetProcGL("glCopyTexSubImage2D");
    PROC_CAST glTexSubImage1D = GetProcGL("glTexSubImage1D");
    PROC_CAST glTexSubImage2D = GetProcGL("glTexSubImage2D");
    PROC_CAST glBindTexture = GetProcGL("glBindTexture");
    PROC_CAST glDeleteTextures = GetProcGL("glDeleteTextures");
    PROC_CAST glGenTextures = GetProcGL("glGenTextures");
    PROC_CAST glIsTexture = GetProcGL("glIsTexture");
    PROC_CAST glDrawRangeElements = GetProcGL("glDrawRangeElements");
    PROC_CAST glTexImage3D = GetProcGL("glTexImage3D");
    PROC_CAST glTexSubImage3D = GetProcGL("glTexSubImage3D");
    PROC_CAST glCopyTexSubImage3D = GetProcGL("glCopyTexSubImage3D");
    PROC_CAST glActiveTexture = GetProcGL("glActiveTexture");
    PROC_CAST glSampleCoverage = GetProcGL("glSampleCoverage");
    PROC_CAST glCompressedTexImage3D = GetProcGL("glCompressedTexImage3D");
    PROC_CAST glCompressedTexImage2D = GetProcGL("glCompressedTexImage2D");
    PROC_CAST glCompressedTexImage1D = GetProcGL("glCompressedTexImage1D");
    PROC_CAST glCompressedTexSubImage3D = GetProcGL("glCompressedTexSubImage3D");
    PROC_CAST glCompressedTexSubImage2D = GetProcGL("glCompressedTexSubImage2D");
    PROC_CAST glCompressedTexSubImage1D = GetProcGL("glCompressedTexSubImage1D");
    PROC_CAST glGetCompressedTexImage = GetProcGL("glGetCompressedTexImage");
    PROC_CAST glBlendFuncSeparate = GetProcGL("glBlendFuncSeparate");
    PROC_CAST glMultiDrawArrays = GetProcGL("glMultiDrawArrays");
    PROC_CAST glMultiDrawElements = GetProcGL("glMultiDrawElements");
    PROC_CAST glPointParameterf = GetProcGL("glPointParameterf");
    PROC_CAST glPointParameterfv = GetProcGL("glPointParameterfv");
    PROC_CAST glPointParameteri = GetProcGL("glPointParameteri");
    PROC_CAST glPointParameteriv = GetProcGL("glPointParameteriv");
    PROC_CAST glBlendColor = GetProcGL("glBlendColor");
    PROC_CAST glBlendEquation = GetProcGL("glBlendEquation");
    PROC_CAST glGenQueries = GetProcGL("glGenQueries");
    PROC_CAST glDeleteQueries = GetProcGL("glDeleteQueries");
    PROC_CAST glIsQuery = GetProcGL("glIsQuery");
    PROC_CAST glBeginQuery = GetProcGL("glBeginQuery");
    PROC_CAST glEndQuery = GetProcGL("glEndQuery");
    PROC_CAST glGetQueryiv = GetProcGL("glGetQueryiv");
    PROC_CAST glGetQueryObjectiv = GetProcGL("glGetQueryObjectiv");
    PROC_CAST glGetQueryObjectuiv = GetProcGL("glGetQueryObjectuiv");
    PROC_CAST glBindBuffer = GetProcGL("glBindBuffer");
    PROC_CAST glDeleteBuffers = GetProcGL("glDeleteBuffers");
    PROC_CAST glGenBuffers = GetProcGL("glGenBuffers");
    PROC_CAST glIsBuffer = GetProcGL("glIsBuffer");
    PROC_CAST glBufferData = GetProcGL("glBufferData");
    PROC_CAST glBufferSubData = GetProcGL("glBufferSubData");
    PROC_CAST glGetBufferSubData = GetProcGL("glGetBufferSubData");
    PROC_CAST glMapBuffer = GetProcGL("glMapBuffer");
    PROC_CAST glUnmapBuffer = GetProcGL("glUnmapBuffer");
    PROC_CAST glGetBufferParameteriv = GetProcGL("glGetBufferParameteriv");
    PROC_CAST glGetBufferPointerv = GetProcGL("glGetBufferPointerv");
    PROC_CAST glBlendEquationSeparate = GetProcGL("glBlendEquationSeparate");
    PROC_CAST glDrawBuffers = GetProcGL("glDrawBuffers");
    PROC_CAST glStencilOpSeparate = GetProcGL("glStencilOpSeparate");
    PROC_CAST glStencilFuncSeparate = GetProcGL("glStencilFuncSeparate");
    PROC_CAST glStencilMaskSeparate = GetProcGL("glStencilMaskSeparate");
    PROC_CAST glAttachShader = GetProcGL("glAttachShader");
    PROC_CAST glBindAttribLocation = GetProcGL("glBindAttribLocation");
    PROC_CAST glCompileShader = GetProcGL("glCompileShader");
    PROC_CAST glCreateProgram = GetProcGL("glCreateProgram");
    PROC_CAST glCreateShader = GetProcGL("glCreateShader");
    PROC_CAST glDeleteProgram = GetProcGL("glDeleteProgram");
    PROC_CAST glDeleteShader = GetProcGL("glDeleteShader");
    PROC_CAST glDetachShader = GetProcGL("glDetachShader");
    PROC_CAST glDisableVertexAttribArray = GetProcGL("glDisableVertexAttribArray");
    PROC_CAST glEnableVertexAttribArray = GetProcGL("glEnableVertexAttribArray");
    PROC_CAST glGetActiveAttrib = GetProcGL("glGetActiveAttrib");
    PROC_CAST glGetActiveUniform = GetProcGL("glGetActiveUniform");
    PROC_CAST glGetAttachedShaders = GetProcGL("glGetAttachedShaders");
    PROC_CAST glGetAttribLocation = GetProcGL("glGetAttribLocation");
    PROC_CAST glGetProgramiv = GetProcGL("glGetProgramiv");
    PROC_CAST glGetProgramInfoLog = GetProcGL("glGetProgramInfoLog");
    PROC_CAST glGetShaderiv = GetProcGL("glGetShaderiv");
    PROC_CAST glGetShaderInfoLog = GetProcGL("glGetShaderInfoLog");
    PROC_CAST glGetShaderSource = GetProcGL("glGetShaderSource");
    PROC_CAST glGetUniformLocation = GetProcGL("glGetUniformLocation");
    PROC_CAST glGetUniformfv = GetProcGL("glGetUniformfv");
    PROC_CAST glGetUniformiv = GetProcGL("glGetUniformiv");
    PROC_CAST glGetVertexAttribdv = GetProcGL("glGetVertexAttribdv");
    PROC_CAST glGetVertexAttribfv = GetProcGL("glGetVertexAttribfv");
    PROC_CAST glGetVertexAttribiv = GetProcGL("glGetVertexAttribiv");
    PROC_CAST glGetVertexAttribPointerv = GetProcGL("glGetVertexAttribPointerv");
    PROC_CAST glIsProgram = GetProcGL("glIsProgram");
    PROC_CAST glIsShader = GetProcGL("glIsShader");
    PROC_CAST glLinkProgram = GetProcGL("glLinkProgram");
    PROC_CAST glShaderSource = GetProcGL("glShaderSource");
    PROC_CAST glUseProgram = GetProcGL("glUseProgram");
    PROC_CAST glUniform1f = GetProcGL("glUniform1f");
    PROC_CAST glUniform2f = GetProcGL("glUniform2f");
    PROC_CAST glUniform3f = GetProcGL("glUniform3f");
    PROC_CAST glUniform4f = GetProcGL("glUniform4f");
    PROC_CAST glUniform1i = GetProcGL("glUniform1i");
    PROC_CAST glUniform2i = GetProcGL("glUniform2i");
    PROC_CAST glUniform3i = GetProcGL("glUniform3i");
    PROC_CAST glUniform4i = GetProcGL("glUniform4i");
    PROC_CAST glUniform1fv = GetProcGL("glUniform1fv");
    PROC_CAST glUniform2fv = GetProcGL("glUniform2fv");
    PROC_CAST glUniform3fv = GetProcGL("glUniform3fv");
    PROC_CAST glUniform4fv = GetProcGL("glUniform4fv");
    PROC_CAST glUniform1iv = GetProcGL("glUniform1iv");
    PROC_CAST glUniform2iv = GetProcGL("glUniform2iv");
    PROC_CAST glUniform3iv = GetProcGL("glUniform3iv");
    PROC_CAST glUniform4iv = GetProcGL("glUniform4iv");
    PROC_CAST glUniformMatrix2fv = GetProcGL("glUniformMatrix2fv");
    PROC_CAST glUniformMatrix3fv = GetProcGL("glUniformMatrix3fv");
    PROC_CAST glUniformMatrix4fv = GetProcGL("glUniformMatrix4fv");
    PROC_CAST glValidateProgram = GetProcGL("glValidateProgram");
    PROC_CAST glVertexAttrib1d = GetProcGL("glVertexAttrib1d");
    PROC_CAST glVertexAttrib1dv = GetProcGL("glVertexAttrib1dv");
    PROC_CAST glVertexAttrib1f = GetProcGL("glVertexAttrib1f");
    PROC_CAST glVertexAttrib1fv = GetProcGL("glVertexAttrib1fv");
    PROC_CAST glVertexAttrib1s = GetProcGL("glVertexAttrib1s");
    PROC_CAST glVertexAttrib1sv = GetProcGL("glVertexAttrib1sv");
    PROC_CAST glVertexAttrib2d = GetProcGL("glVertexAttrib2d");
    PROC_CAST glVertexAttrib2dv = GetProcGL("glVertexAttrib2dv");
    PROC_CAST glVertexAttrib2f = GetProcGL("glVertexAttrib2f");
    PROC_CAST glVertexAttrib2fv = GetProcGL("glVertexAttrib2fv");
    PROC_CAST glVertexAttrib2s = GetProcGL("glVertexAttrib2s");
    PROC_CAST glVertexAttrib2sv = GetProcGL("glVertexAttrib2sv");
    PROC_CAST glVertexAttrib3d = GetProcGL("glVertexAttrib3d");
    PROC_CAST glVertexAttrib3dv = GetProcGL("glVertexAttrib3dv");
    PROC_CAST glVertexAttrib3f = GetProcGL("glVertexAttrib3f");
    PROC_CAST glVertexAttrib3fv = GetProcGL("glVertexAttrib3fv");
    PROC_CAST glVertexAttrib3s = GetProcGL("glVertexAttrib3s");
    PROC_CAST glVertexAttrib3sv = GetProcGL("glVertexAttrib3sv");
    PROC_CAST glVertexAttrib4Nbv = GetProcGL("glVertexAttrib4Nbv");
    PROC_CAST glVertexAttrib4Niv = GetProcGL("glVertexAttrib4Niv");
    PROC_CAST glVertexAttrib4Nsv = GetProcGL("glVertexAttrib4Nsv");
    PROC_CAST glVertexAttrib4Nub = GetProcGL("glVertexAttrib4Nub");
    PROC_CAST glVertexAttrib4Nubv = GetProcGL("glVertexAttrib4Nubv");
    PROC_CAST glVertexAttrib4Nuiv = GetProcGL("glVertexAttrib4Nuiv");
    PROC_CAST glVertexAttrib4Nusv = GetProcGL("glVertexAttrib4Nusv");
    PROC_CAST glVertexAttrib4bv = GetProcGL("glVertexAttrib4bv");
    PROC_CAST glVertexAttrib4d = GetProcGL("glVertexAttrib4d");
    PROC_CAST glVertexAttrib4dv = GetProcGL("glVertexAttrib4dv");
    PROC_CAST glVertexAttrib4f = GetProcGL("glVertexAttrib4f");
    PROC_CAST glVertexAttrib4fv = GetProcGL("glVertexAttrib4fv");
    PROC_CAST glVertexAttrib4iv = GetProcGL("glVertexAttrib4iv");
    PROC_CAST glVertexAttrib4s = GetProcGL("glVertexAttrib4s");
    PROC_CAST glVertexAttrib4sv = GetProcGL("glVertexAttrib4sv");
    PROC_CAST glVertexAttrib4ubv = GetProcGL("glVertexAttrib4ubv");
    PROC_CAST glVertexAttrib4uiv = GetProcGL("glVertexAttrib4uiv");
    PROC_CAST glVertexAttrib4usv = GetProcGL("glVertexAttrib4usv");
    PROC_CAST glVertexAttribPointer = GetProcGL("glVertexAttribPointer");
    PROC_CAST glUniformMatrix2x3fv = GetProcGL("glUniformMatrix2x3fv");
    PROC_CAST glUniformMatrix3x2fv = GetProcGL("glUniformMatrix3x2fv");
    PROC_CAST glUniformMatrix2x4fv = GetProcGL("glUniformMatrix2x4fv");
    PROC_CAST glUniformMatrix4x2fv = GetProcGL("glUniformMatrix4x2fv");
    PROC_CAST glUniformMatrix3x4fv = GetProcGL("glUniformMatrix3x4fv");
    PROC_CAST glUniformMatrix4x3fv = GetProcGL("glUniformMatrix4x3fv");
    PROC_CAST glColorMaski = GetProcGL("glColorMaski");
    PROC_CAST glGetBooleani_v = GetProcGL("glGetBooleani_v");
    PROC_CAST glGetIntegeri_v = GetProcGL("glGetIntegeri_v");
    PROC_CAST glEnablei = GetProcGL("glEnablei");
    PROC_CAST glDisablei = GetProcGL("glDisablei");
    PROC_CAST glIsEnabledi = GetProcGL("glIsEnabledi");
    PROC_CAST glBeginTransformFeedback = GetProcGL("glBeginTransformFeedback");
    PROC_CAST glEndTransformFeedback = GetProcGL("glEndTransformFeedback");
    PROC_CAST glBindBufferRange = GetProcGL("glBindBufferRange");
    PROC_CAST glBindBufferBase = GetProcGL("glBindBufferBase");
    PROC_CAST glTransformFeedbackVaryings = GetProcGL("glTransformFeedbackVaryings");
    PROC_CAST glGetTransformFeedbackVarying = GetProcGL("glGetTransformFeedbackVarying");
    PROC_CAST glClampColor = GetProcGL("glClampColor");
    PROC_CAST glBeginConditionalRender = GetProcGL("glBeginConditionalRender");
    PROC_CAST glEndConditionalRender = GetProcGL("glEndConditionalRender");
    PROC_CAST glVertexAttribIPointer = GetProcGL("glVertexAttribIPointer");
    PROC_CAST glGetVertexAttribIiv = GetProcGL("glGetVertexAttribIiv");
    PROC_CAST glGetVertexAttribIuiv = GetProcGL("glGetVertexAttribIuiv");
    PROC_CAST glVertexAttribI1i = GetProcGL("glVertexAttribI1i");
    PROC_CAST glVertexAttribI2i = GetProcGL("glVertexAttribI2i");
    PROC_CAST glVertexAttribI3i = GetProcGL("glVertexAttribI3i");
    PROC_CAST glVertexAttribI4i = GetProcGL("glVertexAttribI4i");
    PROC_CAST glVertexAttribI1ui = GetProcGL("glVertexAttribI1ui");
    PROC_CAST glVertexAttribI2ui = GetProcGL("glVertexAttribI2ui");
    PROC_CAST glVertexAttribI3ui = GetProcGL("glVertexAttribI3ui");
    PROC_CAST glVertexAttribI4ui = GetProcGL("glVertexAttribI4ui");
    PROC_CAST glVertexAttribI1iv = GetProcGL("glVertexAttribI1iv");
    PROC_CAST glVertexAttribI2iv = GetProcGL("glVertexAttribI2iv");
    PROC_CAST glVertexAttribI3iv = GetProcGL("glVertexAttribI3iv");
    PROC_CAST glVertexAttribI4iv = GetProcGL("glVertexAttribI4iv");
    PROC_CAST glVertexAttribI1uiv = GetProcGL("glVertexAttribI1uiv");
    PROC_CAST glVertexAttribI2uiv = GetProcGL("glVertexAttribI2uiv");
    PROC_CAST glVertexAttribI3uiv = GetProcGL("glVertexAttribI3uiv");
    PROC_CAST glVertexAttribI4uiv = GetProcGL("glVertexAttribI4uiv");
    PROC_CAST glVertexAttribI4bv = GetProcGL("glVertexAttribI4bv");
    PROC_CAST glVertexAttribI4sv = GetProcGL("glVertexAttribI4sv");
    PROC_CAST glVertexAttribI4ubv = GetProcGL("glVertexAttribI4ubv");
    PROC_CAST glVertexAttribI4usv = GetProcGL("glVertexAttribI4usv");
    PROC_CAST glGetUniformuiv = GetProcGL("glGetUniformuiv");
    PROC_CAST glBindFragDataLocation = GetProcGL("glBindFragDataLocation");
    PROC_CAST glGetFragDataLocation = GetProcGL("glGetFragDataLocation");
    PROC_CAST glUniform1ui = GetProcGL("glUniform1ui");
    PROC_CAST glUniform2ui = GetProcGL("glUniform2ui");
    PROC_CAST glUniform3ui = GetProcGL("glUniform3ui");
    PROC_CAST glUniform4ui = GetProcGL("glUniform4ui");
    PROC_CAST glUniform1uiv = GetProcGL("glUniform1uiv");
    PROC_CAST glUniform2uiv = GetProcGL("glUniform2uiv");
    PROC_CAST glUniform3uiv = GetProcGL("glUniform3uiv");
    PROC_CAST glUniform4uiv = GetProcGL("glUniform4uiv");
    PROC_CAST glTexParameterIiv = GetProcGL("glTexParameterIiv");
    PROC_CAST glTexParameterIuiv = GetProcGL("glTexParameterIuiv");
    PROC_CAST glGetTexParameterIiv = GetProcGL("glGetTexParameterIiv");
    PROC_CAST glGetTexParameterIuiv = GetProcGL("glGetTexParameterIuiv");
    PROC_CAST glClearBufferiv = GetProcGL("glClearBufferiv");
    PROC_CAST glClearBufferuiv = GetProcGL("glClearBufferuiv");
    PROC_CAST glClearBufferfv = GetProcGL("glClearBufferfv");
    PROC_CAST glClearBufferfi = GetProcGL("glClearBufferfi");
    PROC_CAST glGetStringi = GetProcGL("glGetStringi");
    PROC_CAST glIsRenderbuffer = GetProcGL("glIsRenderbuffer");
    PROC_CAST glBindRenderbuffer = GetProcGL("glBindRenderbuffer");
    PROC_CAST glDeleteRenderbuffers = GetProcGL("glDeleteRenderbuffers");
    PROC_CAST glGenRenderbuffers = GetProcGL("glGenRenderbuffers");
    PROC_CAST glRenderbufferStorage = GetProcGL("glRenderbufferStorage");
    PROC_CAST glGetRenderbufferParameteriv = GetProcGL("glGetRenderbufferParameteriv");
    PROC_CAST glIsFramebuffer = GetProcGL("glIsFramebuffer");
    PROC_CAST glBindFramebuffer = GetProcGL("glBindFramebuffer");
    PROC_CAST glDeleteFramebuffers = GetProcGL("glDeleteFramebuffers");
    PROC_CAST glGenFramebuffers = GetProcGL("glGenFramebuffers");
    PROC_CAST glCheckFramebufferStatus = GetProcGL("glCheckFramebufferStatus");
    PROC_CAST glFramebufferTexture1D = GetProcGL("glFramebufferTexture1D");
    PROC_CAST glFramebufferTexture2D = GetProcGL("glFramebufferTexture2D");
    PROC_CAST glFramebufferTexture3D = GetProcGL("glFramebufferTexture3D");
    PROC_CAST glFramebufferRenderbuffer = GetProcGL("glFramebufferRenderbuffer");
    PROC_CAST glGetFramebufferAttachmentParameteriv = GetProcGL("glGetFramebufferAttachmentParameteriv");
    PROC_CAST glGenerateMipmap = GetProcGL("glGenerateMipmap");
    PROC_CAST glBlitFramebuffer = GetProcGL("glBlitFramebuffer");
    PROC_CAST glRenderbufferStorageMultisample = GetProcGL("glRenderbufferStorageMultisample");
    PROC_CAST glFramebufferTextureLayer = GetProcGL("glFramebufferTextureLayer");
    PROC_CAST glMapBufferRange = GetProcGL("glMapBufferRange");
    PROC_CAST glFlushMappedBufferRange = GetProcGL("glFlushMappedBufferRange");
    PROC_CAST glBindVertexArray = GetProcGL("glBindVertexArray");
    PROC_CAST glDeleteVertexArrays = GetProcGL("glDeleteVertexArrays");
    PROC_CAST glGenVertexArrays = GetProcGL("glGenVertexArrays");
    PROC_CAST glIsVertexArray = GetProcGL("glIsVertexArray");
    PROC_CAST glDrawArraysInstanced = GetProcGL("glDrawArraysInstanced");
    PROC_CAST glDrawElementsInstanced = GetProcGL("glDrawElementsInstanced");
    PROC_CAST glTexBuffer = GetProcGL("glTexBuffer");
    PROC_CAST glPrimitiveRestartIndex = GetProcGL("glPrimitiveRestartIndex");
    PROC_CAST glCopyBufferSubData = GetProcGL("glCopyBufferSubData");
    PROC_CAST glGetUniformIndices = GetProcGL("glGetUniformIndices");
    PROC_CAST glGetActiveUniformsiv = GetProcGL("glGetActiveUniformsiv");
    PROC_CAST glGetActiveUniformName = GetProcGL("glGetActiveUniformName");
    PROC_CAST glGetUniformBlockIndex = GetProcGL("glGetUniformBlockIndex");
    PROC_CAST glGetActiveUniformBlockiv = GetProcGL("glGetActiveUniformBlockiv");
    PROC_CAST glGetActiveUniformBlockName = GetProcGL("glGetActiveUniformBlockName");
    PROC_CAST glUniformBlockBinding = GetProcGL("glUniformBlockBinding");
    PROC_CAST glDrawElementsBaseVertex = GetProcGL("glDrawElementsBaseVertex");
    PROC_CAST glDrawRangeElementsBaseVertex = GetProcGL("glDrawRangeElementsBaseVertex");
    PROC_CAST glDrawElementsInstancedBaseVertex = GetProcGL("glDrawElementsInstancedBaseVertex");
    PROC_CAST glMultiDrawElementsBaseVertex = GetProcGL("glMultiDrawElementsBaseVertex");
    PROC_CAST glProvokingVertex = GetProcGL("glProvokingVertex");
    PROC_CAST glFenceSync = GetProcGL("glFenceSync");
    PROC_CAST glIsSync = GetProcGL("glIsSync");
    PROC_CAST glDeleteSync = GetProcGL("glDeleteSync");
    PROC_CAST glClientWaitSync = GetProcGL("glClientWaitSync");
    PROC_CAST glWaitSync = GetProcGL("glWaitSync");
    PROC_CAST glGetInteger64v = GetProcGL("glGetInteger64v");
    PROC_CAST glGetSynciv = GetProcGL("glGetSynciv");
    PROC_CAST glGetInteger64i_v = GetProcGL("glGetInteger64i_v");
    PROC_CAST glGetBufferParameteri64v = GetProcGL("glGetBufferParameteri64v");
    PROC_CAST glFramebufferTexture = GetProcGL("glFramebufferTexture");
    PROC_CAST glTexImage2DMultisample = GetProcGL("glTexImage2DMultisample");
    PROC_CAST glTexImage3DMultisample = GetProcGL("glTexImage3DMultisample");
    PROC_CAST glGetMultisamplefv = GetProcGL("glGetMultisamplefv");
    PROC_CAST glSampleMaski = GetProcGL("glSampleMaski");
    PROC_CAST glBindFragDataLocationIndexed = GetProcGL("glBindFragDataLocationIndexed");
    PROC_CAST glGetFragDataIndex = GetProcGL("glGetFragDataIndex");
    PROC_CAST glGenSamplers = GetProcGL("glGenSamplers");
    PROC_CAST glDeleteSamplers = GetProcGL("glDeleteSamplers");
    PROC_CAST glIsSampler = GetProcGL("glIsSampler");
    PROC_CAST glBindSampler = GetProcGL("glBindSampler");
    PROC_CAST glSamplerParameteri = GetProcGL("glSamplerParameteri");
    PROC_CAST glSamplerParameteriv = GetProcGL("glSamplerParameteriv");
    PROC_CAST glSamplerParameterf = GetProcGL("glSamplerParameterf");
    PROC_CAST glSamplerParameterfv = GetProcGL("glSamplerParameterfv");
    PROC_CAST glSamplerParameterIiv = GetProcGL("glSamplerParameterIiv");
    PROC_CAST glSamplerParameterIuiv = GetProcGL("glSamplerParameterIuiv");
    PROC_CAST glGetSamplerParameteriv = GetProcGL("glGetSamplerParameteriv");
    PROC_CAST glGetSamplerParameterIiv = GetProcGL("glGetSamplerParameterIiv");
    PROC_CAST glGetSamplerParameterfv = GetProcGL("glGetSamplerParameterfv");
    PROC_CAST glGetSamplerParameterIuiv = GetProcGL("glGetSamplerParameterIuiv");
    PROC_CAST glQueryCounter = GetProcGL("glQueryCounter");
    PROC_CAST glGetQueryObjecti64v = GetProcGL("glGetQueryObjecti64v");
    PROC_CAST glGetQueryObjectui64v = GetProcGL("glGetQueryObjectui64v");
    PROC_CAST glVertexAttribDivisor = GetProcGL("glVertexAttribDivisor");
    PROC_CAST glVertexAttribP1ui = GetProcGL("glVertexAttribP1ui");
    PROC_CAST glVertexAttribP1uiv = GetProcGL("glVertexAttribP1uiv");
    PROC_CAST glVertexAttribP2ui = GetProcGL("glVertexAttribP2ui");
    PROC_CAST glVertexAttribP2uiv = GetProcGL("glVertexAttribP2uiv");
    PROC_CAST glVertexAttribP3ui = GetProcGL("glVertexAttribP3ui");
    PROC_CAST glVertexAttribP3uiv = GetProcGL("glVertexAttribP3uiv");
    PROC_CAST glVertexAttribP4ui = GetProcGL("glVertexAttribP4ui");
    PROC_CAST glVertexAttribP4uiv = GetProcGL("glVertexAttribP4uiv");
    PROC_CAST glMinSampleShading = GetProcGL("glMinSampleShading");
    PROC_CAST glBlendEquationi = GetProcGL("glBlendEquationi");
    PROC_CAST glBlendEquationSeparatei = GetProcGL("glBlendEquationSeparatei");
    PROC_CAST glBlendFunci = GetProcGL("glBlendFunci");
    PROC_CAST glBlendFuncSeparatei = GetProcGL("glBlendFuncSeparatei");
    PROC_CAST glDrawArraysIndirect = GetProcGL("glDrawArraysIndirect");
    PROC_CAST glDrawElementsIndirect = GetProcGL("glDrawElementsIndirect");
    PROC_CAST glUniform1d = GetProcGL("glUniform1d");
    PROC_CAST glUniform2d = GetProcGL("glUniform2d");
    PROC_CAST glUniform3d = GetProcGL("glUniform3d");
    PROC_CAST glUniform4d = GetProcGL("glUniform4d");
    PROC_CAST glUniform1dv = GetProcGL("glUniform1dv");
    PROC_CAST glUniform2dv = GetProcGL("glUniform2dv");
    PROC_CAST glUniform3dv = GetProcGL("glUniform3dv");
    PROC_CAST glUniform4dv = GetProcGL("glUniform4dv");
    PROC_CAST glUniformMatrix2dv = GetProcGL("glUniformMatrix2dv");
    PROC_CAST glUniformMatrix3dv = GetProcGL("glUniformMatrix3dv");
    PROC_CAST glUniformMatrix4dv = GetProcGL("glUniformMatrix4dv");
    PROC_CAST glUniformMatrix2x3dv = GetProcGL("glUniformMatrix2x3dv");
    PROC_CAST glUniformMatrix2x4dv = GetProcGL("glUniformMatrix2x4dv");
    PROC_CAST glUniformMatrix3x2dv = GetProcGL("glUniformMatrix3x2dv");
    PROC_CAST glUniformMatrix3x4dv = GetProcGL("glUniformMatrix3x4dv");
    PROC_CAST glUniformMatrix4x2dv = GetProcGL("glUniformMatrix4x2dv");
    PROC_CAST glUniformMatrix4x3dv = GetProcGL("glUniformMatrix4x3dv");
    PROC_CAST glGetUniformdv = GetProcGL("glGetUniformdv");
    PROC_CAST glGetSubroutineUniformLocation = GetProcGL("glGetSubroutineUniformLocation");
    PROC_CAST glGetSubroutineIndex = GetProcGL("glGetSubroutineIndex");
    PROC_CAST glGetActiveSubroutineUniformiv = GetProcGL("glGetActiveSubroutineUniformiv");
    PROC_CAST glGetActiveSubroutineUniformName = GetProcGL("glGetActiveSubroutineUniformName");
    PROC_CAST glGetActiveSubroutineName = GetProcGL("glGetActiveSubroutineName");
    PROC_CAST glUniformSubroutinesuiv = GetProcGL("glUniformSubroutinesuiv");
    PROC_CAST glGetUniformSubroutineuiv = GetProcGL("glGetUniformSubroutineuiv");
    PROC_CAST glGetProgramStageiv = GetProcGL("glGetProgramStageiv");
    PROC_CAST glPatchParameteri = GetProcGL("glPatchParameteri");
    PROC_CAST glPatchParameterfv = GetProcGL("glPatchParameterfv");
    PROC_CAST glBindTransformFeedback = GetProcGL("glBindTransformFeedback");
    PROC_CAST glDeleteTransformFeedbacks = GetProcGL("glDeleteTransformFeedbacks");
    PROC_CAST glGenTransformFeedbacks = GetProcGL("glGenTransformFeedbacks");
    PROC_CAST glIsTransformFeedback = GetProcGL("glIsTransformFeedback");
    PROC_CAST glPauseTransformFeedback = GetProcGL("glPauseTransformFeedback");
    PROC_CAST glResumeTransformFeedback = GetProcGL("glResumeTransformFeedback");
    PROC_CAST glDrawTransformFeedback = GetProcGL("glDrawTransformFeedback");
    PROC_CAST glDrawTransformFeedbackStream = GetProcGL("glDrawTransformFeedbackStream");
    PROC_CAST glBeginQueryIndexed = GetProcGL("glBeginQueryIndexed");
    PROC_CAST glEndQueryIndexed = GetProcGL("glEndQueryIndexed");
    PROC_CAST glGetQueryIndexediv = GetProcGL("glGetQueryIndexediv");
    PROC_CAST glReleaseShaderCompiler = GetProcGL("glReleaseShaderCompiler");
    PROC_CAST glShaderBinary = GetProcGL("glShaderBinary");
    PROC_CAST glGetShaderPrecisionFormat = GetProcGL("glGetShaderPrecisionFormat");
    PROC_CAST glDepthRangef = GetProcGL("glDepthRangef");
    PROC_CAST glClearDepthf = GetProcGL("glClearDepthf");
    PROC_CAST glGetProgramBinary = GetProcGL("glGetProgramBinary");
    PROC_CAST glProgramBinary = GetProcGL("glProgramBinary");
    PROC_CAST glProgramParameteri = GetProcGL("glProgramParameteri");
    PROC_CAST glUseProgramStages = GetProcGL("glUseProgramStages");
    PROC_CAST glActiveShaderProgram = GetProcGL("glActiveShaderProgram");
    PROC_CAST glCreateShaderProgramv = GetProcGL("glCreateShaderProgramv");
    PROC_CAST glBindProgramPipeline = GetProcGL("glBindProgramPipeline");
    PROC_CAST glDeleteProgramPipelines = GetProcGL("glDeleteProgramPipelines");
    PROC_CAST glGenProgramPipelines = GetProcGL("glGenProgramPipelines");
    PROC_CAST glIsProgramPipeline = GetProcGL("glIsProgramPipeline");
    PROC_CAST glGetProgramPipelineiv = GetProcGL("glGetProgramPipelineiv");
    PROC_CAST glProgramUniform1i = GetProcGL("glProgramUniform1i");
    PROC_CAST glProgramUniform1iv = GetProcGL("glProgramUniform1iv");
    PROC_CAST glProgramUniform1f = GetProcGL("glProgramUniform1f");
    PROC_CAST glProgramUniform1fv = GetProcGL("glProgramUniform1fv");
    PROC_CAST glProgramUniform1d = GetProcGL("glProgramUniform1d");
    PROC_CAST glProgramUniform1dv = GetProcGL("glProgramUniform1dv");
    PROC_CAST glProgramUniform1ui = GetProcGL("glProgramUniform1ui");
    PROC_CAST glProgramUniform1uiv = GetProcGL("glProgramUniform1uiv");
    PROC_CAST glProgramUniform2i = GetProcGL("glProgramUniform2i");
    PROC_CAST glProgramUniform2iv = GetProcGL("glProgramUniform2iv");
    PROC_CAST glProgramUniform2f = GetProcGL("glProgramUniform2f");
    PROC_CAST glProgramUniform2fv = GetProcGL("glProgramUniform2fv");
    PROC_CAST glProgramUniform2d = GetProcGL("glProgramUniform2d");
    PROC_CAST glProgramUniform2dv = GetProcGL("glProgramUniform2dv");
    PROC_CAST glProgramUniform2ui = GetProcGL("glProgramUniform2ui");
    PROC_CAST glProgramUniform2uiv = GetProcGL("glProgramUniform2uiv");
    PROC_CAST glProgramUniform3i = GetProcGL("glProgramUniform3i");
    PROC_CAST glProgramUniform3iv = GetProcGL("glProgramUniform3iv");
    PROC_CAST glProgramUniform3f = GetProcGL("glProgramUniform3f");
    PROC_CAST glProgramUniform3fv = GetProcGL("glProgramUniform3fv");
    PROC_CAST glProgramUniform3d = GetProcGL("glProgramUniform3d");
    PROC_CAST glProgramUniform3dv = GetProcGL("glProgramUniform3dv");
    PROC_CAST glProgramUniform3ui = GetProcGL("glProgramUniform3ui");
    PROC_CAST glProgramUniform3uiv = GetProcGL("glProgramUniform3uiv");
    PROC_CAST glProgramUniform4i = GetProcGL("glProgramUniform4i");
    PROC_CAST glProgramUniform4iv = GetProcGL("glProgramUniform4iv");
    PROC_CAST glProgramUniform4f = GetProcGL("glProgramUniform4f");
    PROC_CAST glProgramUniform4fv = GetProcGL("glProgramUniform4fv");
    PROC_CAST glProgramUniform4d = GetProcGL("glProgramUniform4d");
    PROC_CAST glProgramUniform4dv = GetProcGL("glProgramUniform4dv");
    PROC_CAST glProgramUniform4ui = GetProcGL("glProgramUniform4ui");
    PROC_CAST glProgramUniform4uiv = GetProcGL("glProgramUniform4uiv");
    PROC_CAST glProgramUniformMatrix2fv = GetProcGL("glProgramUniformMatrix2fv");
    PROC_CAST glProgramUniformMatrix3fv = GetProcGL("glProgramUniformMatrix3fv");
    PROC_CAST glProgramUniformMatrix4fv = GetProcGL("glProgramUniformMatrix4fv");
    PROC_CAST glProgramUniformMatrix2dv = GetProcGL("glProgramUniformMatrix2dv");
    PROC_CAST glProgramUniformMatrix3dv = GetProcGL("glProgramUniformMatrix3dv");
    PROC_CAST glProgramUniformMatrix4dv = GetProcGL("glProgramUniformMatrix4dv");
    PROC_CAST glProgramUniformMatrix2x3fv = GetProcGL("glProgramUniformMatrix2x3fv");
    PROC_CAST glProgramUniformMatrix3x2fv = GetProcGL("glProgramUniformMatrix3x2fv");
    PROC_CAST glProgramUniformMatrix2x4fv = GetProcGL("glProgramUniformMatrix2x4fv");
    PROC_CAST glProgramUniformMatrix4x2fv = GetProcGL("glProgramUniformMatrix4x2fv");
    PROC_CAST glProgramUniformMatrix3x4fv = GetProcGL("glProgramUniformMatrix3x4fv");
    PROC_CAST glProgramUniformMatrix4x3fv = GetProcGL("glProgramUniformMatrix4x3fv");
    PROC_CAST glProgramUniformMatrix2x3dv = GetProcGL("glProgramUniformMatrix2x3dv");
    PROC_CAST glProgramUniformMatrix3x2dv = GetProcGL("glProgramUniformMatrix3x2dv");
    PROC_CAST glProgramUniformMatrix2x4dv = GetProcGL("glProgramUniformMatrix2x4dv");
    PROC_CAST glProgramUniformMatrix4x2dv = GetProcGL("glProgramUniformMatrix4x2dv");
    PROC_CAST glProgramUniformMatrix3x4dv = GetProcGL("glProgramUniformMatrix3x4dv");
    PROC_CAST glProgramUniformMatrix4x3dv = GetProcGL("glProgramUniformMatrix4x3dv");
    PROC_CAST glValidateProgramPipeline = GetProcGL("glValidateProgramPipeline");
    PROC_CAST glGetProgramPipelineInfoLog = GetProcGL("glGetProgramPipelineInfoLog");
    PROC_CAST glVertexAttribL1d = GetProcGL("glVertexAttribL1d");
    PROC_CAST glVertexAttribL2d = GetProcGL("glVertexAttribL2d");
    PROC_CAST glVertexAttribL3d = GetProcGL("glVertexAttribL3d");
    PROC_CAST glVertexAttribL4d = GetProcGL("glVertexAttribL4d");
    PROC_CAST glVertexAttribL1dv = GetProcGL("glVertexAttribL1dv");
    PROC_CAST glVertexAttribL2dv = GetProcGL("glVertexAttribL2dv");
    PROC_CAST glVertexAttribL3dv = GetProcGL("glVertexAttribL3dv");
    PROC_CAST glVertexAttribL4dv = GetProcGL("glVertexAttribL4dv");
    PROC_CAST glVertexAttribLPointer = GetProcGL("glVertexAttribLPointer");
    PROC_CAST glGetVertexAttribLdv = GetProcGL("glGetVertexAttribLdv");
    PROC_CAST glViewportArrayv = GetProcGL("glViewportArrayv");
    PROC_CAST glViewportIndexedf = GetProcGL("glViewportIndexedf");
    PROC_CAST glViewportIndexedfv = GetProcGL("glViewportIndexedfv");
    PROC_CAST glScissorArrayv = GetProcGL("glScissorArrayv");
    PROC_CAST glScissorIndexed = GetProcGL("glScissorIndexed");
    PROC_CAST glScissorIndexedv = GetProcGL("glScissorIndexedv");
    PROC_CAST glDepthRangeArrayv = GetProcGL("glDepthRangeArrayv");
    PROC_CAST glDepthRangeIndexed = GetProcGL("glDepthRangeIndexed");
    PROC_CAST glGetFloati_v = GetProcGL("glGetFloati_v");
    PROC_CAST glGetDoublei_v = GetProcGL("glGetDoublei_v");
    PROC_CAST glDrawArraysInstancedBaseInstance = GetProcGL("glDrawArraysInstancedBaseInstance");
    PROC_CAST glDrawElementsInstancedBaseInstance = GetProcGL("glDrawElementsInstancedBaseInstance");
    PROC_CAST glDrawElementsInstancedBaseVertexBaseInstance = GetProcGL("glDrawElementsInstancedBaseVertexBaseInstance");
    PROC_CAST glGetInternalformativ = GetProcGL("glGetInternalformativ");
    PROC_CAST glGetActiveAtomicCounterBufferiv = GetProcGL("glGetActiveAtomicCounterBufferiv");
    PROC_CAST glBindImageTexture = GetProcGL("glBindImageTexture");
    PROC_CAST glMemoryBarrier = GetProcGL("glMemoryBarrier");
    PROC_CAST glTexStorage1D = GetProcGL("glTexStorage1D");
    PROC_CAST glTexStorage2D = GetProcGL("glTexStorage2D");
    PROC_CAST glTexStorage3D = GetProcGL("glTexStorage3D");
    PROC_CAST glDrawTransformFeedbackInstanced = GetProcGL("glDrawTransformFeedbackInstanced");
    PROC_CAST glDrawTransformFeedbackStreamInstanced = GetProcGL("glDrawTransformFeedbackStreamInstanced");
    PROC_CAST glClearBufferData = GetProcGL("glClearBufferData");
    PROC_CAST glClearBufferSubData = GetProcGL("glClearBufferSubData");
    PROC_CAST glDispatchCompute = GetProcGL("glDispatchCompute");
    PROC_CAST glDispatchComputeIndirect = GetProcGL("glDispatchComputeIndirect");
    PROC_CAST glCopyImageSubData = GetProcGL("glCopyImageSubData");
    PROC_CAST glFramebufferParameteri = GetProcGL("glFramebufferParameteri");
    PROC_CAST glGetFramebufferParameteriv = GetProcGL("glGetFramebufferParameteriv");
    PROC_CAST glGetInternalformati64v = GetProcGL("glGetInternalformati64v");
    PROC_CAST glInvalidateTexSubImage = GetProcGL("glInvalidateTexSubImage");
    PROC_CAST glInvalidateTexImage = GetProcGL("glInvalidateTexImage");
    PROC_CAST glInvalidateBufferSubData = GetProcGL("glInvalidateBufferSubData");
    PROC_CAST glInvalidateBufferData = GetProcGL("glInvalidateBufferData");
    PROC_CAST glInvalidateFramebuffer = GetProcGL("glInvalidateFramebuffer");
    PROC_CAST glInvalidateSubFramebuffer = GetProcGL("glInvalidateSubFramebuffer");
    PROC_CAST glMultiDrawArraysIndirect = GetProcGL("glMultiDrawArraysIndirect");
    PROC_CAST glMultiDrawElementsIndirect = GetProcGL("glMultiDrawElementsIndirect");
    PROC_CAST glGetProgramInterfaceiv = GetProcGL("glGetProgramInterfaceiv");
    PROC_CAST glGetProgramResourceIndex = GetProcGL("glGetProgramResourceIndex");
    PROC_CAST glGetProgramResourceName = GetProcGL("glGetProgramResourceName");
    PROC_CAST glGetProgramResourceiv = GetProcGL("glGetProgramResourceiv");
    PROC_CAST glGetProgramResourceLocation = GetProcGL("glGetProgramResourceLocation");
    PROC_CAST glGetProgramResourceLocationIndex = GetProcGL("glGetProgramResourceLocationIndex");
    PROC_CAST glShaderStorageBlockBinding = GetProcGL("glShaderStorageBlockBinding");
    PROC_CAST glTexBufferRange = GetProcGL("glTexBufferRange");
    PROC_CAST glTexStorage2DMultisample = GetProcGL("glTexStorage2DMultisample");
    PROC_CAST glTexStorage3DMultisample = GetProcGL("glTexStorage3DMultisample");
    PROC_CAST glTextureView = GetProcGL("glTextureView");
    PROC_CAST glBindVertexBuffer = GetProcGL("glBindVertexBuffer");
    PROC_CAST glVertexAttribFormat = GetProcGL("glVertexAttribFormat");
    PROC_CAST glVertexAttribIFormat = GetProcGL("glVertexAttribIFormat");
    PROC_CAST glVertexAttribLFormat = GetProcGL("glVertexAttribLFormat");
    PROC_CAST glVertexAttribBinding = GetProcGL("glVertexAttribBinding");
    PROC_CAST glVertexBindingDivisor = GetProcGL("glVertexBindingDivisor");
    PROC_CAST glDebugMessageControl = GetProcGL("glDebugMessageControl");
    PROC_CAST glDebugMessageInsert = GetProcGL("glDebugMessageInsert");
    PROC_CAST glDebugMessageCallback = GetProcGL("glDebugMessageCallback");
    PROC_CAST glGetDebugMessageLog = GetProcGL("glGetDebugMessageLog");
    PROC_CAST glPushDebugGroup = GetProcGL("glPushDebugGroup");
    PROC_CAST glPopDebugGroup = GetProcGL("glPopDebugGroup");
    PROC_CAST glObjectLabel = GetProcGL("glObjectLabel");
    PROC_CAST glGetObjectLabel = GetProcGL("glGetObjectLabel");
    PROC_CAST glObjectPtrLabel = GetProcGL("glObjectPtrLabel");
    PROC_CAST glGetObjectPtrLabel = GetProcGL("glGetObjectPtrLabel");
    PROC_CAST glBufferStorage = GetProcGL("glBufferStorage");
    PROC_CAST glClearTexImage = GetProcGL("glClearTexImage");
    PROC_CAST glClearTexSubImage = GetProcGL("glClearTexSubImage");
    PROC_CAST glBindBuffersBase = GetProcGL("glBindBuffersBase");
    PROC_CAST glBindBuffersRange = GetProcGL("glBindBuffersRange");
    PROC_CAST glBindTextures = GetProcGL("glBindTextures");
    PROC_CAST glBindSamplers = GetProcGL("glBindSamplers");
    PROC_CAST glBindImageTextures = GetProcGL("glBindImageTextures");
    PROC_CAST glBindVertexBuffers = GetProcGL("glBindVertexBuffers");
    PROC_CAST glClipControl = GetProcGL("glClipControl");
    PROC_CAST glCreateTransformFeedbacks = GetProcGL("glCreateTransformFeedbacks");
    PROC_CAST glTransformFeedbackBufferBase = GetProcGL("glTransformFeedbackBufferBase");
    PROC_CAST glTransformFeedbackBufferRange = GetProcGL("glTransformFeedbackBufferRange");
    PROC_CAST glGetTransformFeedbackiv = GetProcGL("glGetTransformFeedbackiv");
    PROC_CAST glGetTransformFeedbacki_v = GetProcGL("glGetTransformFeedbacki_v");
    PROC_CAST glGetTransformFeedbacki64_v = GetProcGL("glGetTransformFeedbacki64_v");
    PROC_CAST glCreateBuffers = GetProcGL("glCreateBuffers");
    PROC_CAST glNamedBufferStorage = GetProcGL("glNamedBufferStorage");
    PROC_CAST glNamedBufferData = GetProcGL("glNamedBufferData");
    PROC_CAST glNamedBufferSubData = GetProcGL("glNamedBufferSubData");
    PROC_CAST glCopyNamedBufferSubData = GetProcGL("glCopyNamedBufferSubData");
    PROC_CAST glClearNamedBufferData = GetProcGL("glClearNamedBufferData");
    PROC_CAST glClearNamedBufferSubData = GetProcGL("glClearNamedBufferSubData");
    PROC_CAST glMapNamedBuffer = GetProcGL("glMapNamedBuffer");
    PROC_CAST glMapNamedBufferRange = GetProcGL("glMapNamedBufferRange");
    PROC_CAST glUnmapNamedBuffer = GetProcGL("glUnmapNamedBuffer");
    PROC_CAST glFlushMappedNamedBufferRange = GetProcGL("glFlushMappedNamedBufferRange");
    PROC_CAST glGetNamedBufferParameteriv = GetProcGL("glGetNamedBufferParameteriv");
    PROC_CAST glGetNamedBufferParameteri64v = GetProcGL("glGetNamedBufferParameteri64v");
    PROC_CAST glGetNamedBufferPointerv = GetProcGL("glGetNamedBufferPointerv");
    PROC_CAST glGetNamedBufferSubData = GetProcGL("glGetNamedBufferSubData");
    PROC_CAST glCreateFramebuffers = GetProcGL("glCreateFramebuffers");
    PROC_CAST glNamedFramebufferRenderbuffer = GetProcGL("glNamedFramebufferRenderbuffer");
    PROC_CAST glNamedFramebufferParameteri = GetProcGL("glNamedFramebufferParameteri");
    PROC_CAST glNamedFramebufferTexture = GetProcGL("glNamedFramebufferTexture");
    PROC_CAST glNamedFramebufferTextureLayer = GetProcGL("glNamedFramebufferTextureLayer");
    PROC_CAST glNamedFramebufferDrawBuffer = GetProcGL("glNamedFramebufferDrawBuffer");
    PROC_CAST glNamedFramebufferDrawBuffers = GetProcGL("glNamedFramebufferDrawBuffers");
    PROC_CAST glNamedFramebufferReadBuffer = GetProcGL("glNamedFramebufferReadBuffer");
    PROC_CAST glInvalidateNamedFramebufferData = GetProcGL("glInvalidateNamedFramebufferData");
    PROC_CAST glInvalidateNamedFramebufferSubData = GetProcGL("glInvalidateNamedFramebufferSubData");
    PROC_CAST glClearNamedFramebufferiv = GetProcGL("glClearNamedFramebufferiv");
    PROC_CAST glClearNamedFramebufferuiv = GetProcGL("glClearNamedFramebufferuiv");
    PROC_CAST glClearNamedFramebufferfv = GetProcGL("glClearNamedFramebufferfv");
    PROC_CAST glClearNamedFramebufferfi = GetProcGL("glClearNamedFramebufferfi");
    PROC_CAST glBlitNamedFramebuffer = GetProcGL("glBlitNamedFramebuffer");
    PROC_CAST glCheckNamedFramebufferStatus = GetProcGL("glCheckNamedFramebufferStatus");
    PROC_CAST glGetNamedFramebufferParameteriv = GetProcGL("glGetNamedFramebufferParameteriv");
    PROC_CAST glGetNamedFramebufferAttachmentParameteriv = GetProcGL("glGetNamedFramebufferAttachmentParameteriv");
    PROC_CAST glCreateRenderbuffers = GetProcGL("glCreateRenderbuffers");
    PROC_CAST glNamedRenderbufferStorage = GetProcGL("glNamedRenderbufferStorage");
    PROC_CAST glNamedRenderbufferStorageMultisample = GetProcGL("glNamedRenderbufferStorageMultisample");
    PROC_CAST glGetNamedRenderbufferParameteriv = GetProcGL("glGetNamedRenderbufferParameteriv");
    PROC_CAST glCreateTextures = GetProcGL("glCreateTextures");
    PROC_CAST glTextureBuffer = GetProcGL("glTextureBuffer");
    PROC_CAST glTextureBufferRange = GetProcGL("glTextureBufferRange");
    PROC_CAST glTextureStorage1D = GetProcGL("glTextureStorage1D");
    PROC_CAST glTextureStorage2D = GetProcGL("glTextureStorage2D");
    PROC_CAST glTextureStorage3D = GetProcGL("glTextureStorage3D");
    PROC_CAST glTextureStorage2DMultisample = GetProcGL("glTextureStorage2DMultisample");
    PROC_CAST glTextureStorage3DMultisample = GetProcGL("glTextureStorage3DMultisample");
    PROC_CAST glTextureSubImage1D = GetProcGL("glTextureSubImage1D");
    PROC_CAST glTextureSubImage2D = GetProcGL("glTextureSubImage2D");
    PROC_CAST glTextureSubImage3D = GetProcGL("glTextureSubImage3D");
    PROC_CAST glCompressedTextureSubImage1D = GetProcGL("glCompressedTextureSubImage1D");
    PROC_CAST glCompressedTextureSubImage2D = GetProcGL("glCompressedTextureSubImage2D");
    PROC_CAST glCompressedTextureSubImage3D = GetProcGL("glCompressedTextureSubImage3D");
    PROC_CAST glCopyTextureSubImage1D = GetProcGL("glCopyTextureSubImage1D");
    PROC_CAST glCopyTextureSubImage2D = GetProcGL("glCopyTextureSubImage2D");
    PROC_CAST glCopyTextureSubImage3D = GetProcGL("glCopyTextureSubImage3D");
    PROC_CAST glTextureParameterf = GetProcGL("glTextureParameterf");
    PROC_CAST glTextureParameterfv = GetProcGL("glTextureParameterfv");
    PROC_CAST glTextureParameteri = GetProcGL("glTextureParameteri");
    PROC_CAST glTextureParameterIiv = GetProcGL("glTextureParameterIiv");
    PROC_CAST glTextureParameterIuiv = GetProcGL("glTextureParameterIuiv");
    PROC_CAST glTextureParameteriv = GetProcGL("glTextureParameteriv");
    PROC_CAST glGenerateTextureMipmap = GetProcGL("glGenerateTextureMipmap");
    PROC_CAST glBindTextureUnit = GetProcGL("glBindTextureUnit");
    PROC_CAST glGetTextureImage = GetProcGL("glGetTextureImage");
    PROC_CAST glGetCompressedTextureImage = GetProcGL("glGetCompressedTextureImage");
    PROC_CAST glGetTextureLevelParameterfv = GetProcGL("glGetTextureLevelParameterfv");
    PROC_CAST glGetTextureLevelParameteriv = GetProcGL("glGetTextureLevelParameteriv");
    PROC_CAST glGetTextureParameterfv = GetProcGL("glGetTextureParameterfv");
    PROC_CAST glGetTextureParameterIiv = GetProcGL("glGetTextureParameterIiv");
    PROC_CAST glGetTextureParameterIuiv = GetProcGL("glGetTextureParameterIuiv");
    PROC_CAST glGetTextureParameteriv = GetProcGL("glGetTextureParameteriv");
    PROC_CAST glCreateVertexArrays = GetProcGL("glCreateVertexArrays");
    PROC_CAST glDisableVertexArrayAttrib = GetProcGL("glDisableVertexArrayAttrib");
    PROC_CAST glEnableVertexArrayAttrib = GetProcGL("glEnableVertexArrayAttrib");
    PROC_CAST glVertexArrayElementBuffer = GetProcGL("glVertexArrayElementBuffer");
    PROC_CAST glVertexArrayVertexBuffer = GetProcGL("glVertexArrayVertexBuffer");
    PROC_CAST glVertexArrayVertexBuffers = GetProcGL("glVertexArrayVertexBuffers");
    PROC_CAST glVertexArrayAttribBinding = GetProcGL("glVertexArrayAttribBinding");
    PROC_CAST glVertexArrayAttribFormat = GetProcGL("glVertexArrayAttribFormat");
    PROC_CAST glVertexArrayAttribIFormat = GetProcGL("glVertexArrayAttribIFormat");
    PROC_CAST glVertexArrayAttribLFormat = GetProcGL("glVertexArrayAttribLFormat");
    PROC_CAST glVertexArrayBindingDivisor = GetProcGL("glVertexArrayBindingDivisor");
    PROC_CAST glGetVertexArrayiv = GetProcGL("glGetVertexArrayiv");
    PROC_CAST glGetVertexArrayIndexediv = GetProcGL("glGetVertexArrayIndexediv");
    PROC_CAST glGetVertexArrayIndexed64iv = GetProcGL("glGetVertexArrayIndexed64iv");
    PROC_CAST glCreateSamplers = GetProcGL("glCreateSamplers");
    PROC_CAST glCreateProgramPipelines = GetProcGL("glCreateProgramPipelines");
    PROC_CAST glCreateQueries = GetProcGL("glCreateQueries");
    PROC_CAST glGetQueryBufferObjecti64v = GetProcGL("glGetQueryBufferObjecti64v");
    PROC_CAST glGetQueryBufferObjectiv = GetProcGL("glGetQueryBufferObjectiv");
    PROC_CAST glGetQueryBufferObjectui64v = GetProcGL("glGetQueryBufferObjectui64v");
    PROC_CAST glGetQueryBufferObjectuiv = GetProcGL("glGetQueryBufferObjectuiv");
    PROC_CAST glMemoryBarrierByRegion = GetProcGL("glMemoryBarrierByRegion");
    PROC_CAST glGetTextureSubImage = GetProcGL("glGetTextureSubImage");
    PROC_CAST glGetCompressedTextureSubImage = GetProcGL("glGetCompressedTextureSubImage");
    PROC_CAST glGetGraphicsResetStatus = GetProcGL("glGetGraphicsResetStatus");
    PROC_CAST glGetnCompressedTexImage = GetProcGL("glGetnCompressedTexImage");
    PROC_CAST glGetnTexImage = GetProcGL("glGetnTexImage");
    PROC_CAST glGetnUniformdv = GetProcGL("glGetnUniformdv");
    PROC_CAST glGetnUniformfv = GetProcGL("glGetnUniformfv");
    PROC_CAST glGetnUniformiv = GetProcGL("glGetnUniformiv");
    PROC_CAST glGetnUniformuiv = GetProcGL("glGetnUniformuiv");
    PROC_CAST glReadnPixels = GetProcGL("glReadnPixels");
    PROC_CAST glTextureBarrier = GetProcGL("glTextureBarrier");
    PROC_CAST glGetTextureHandleARB = GetProcGL("glGetTextureHandleARB");
    PROC_CAST glGetTextureSamplerHandleARB = GetProcGL("glGetTextureSamplerHandleARB");
    PROC_CAST glMakeTextureHandleResidentARB = GetProcGL("glMakeTextureHandleResidentARB");
    PROC_CAST glMakeTextureHandleNonResidentARB = GetProcGL("glMakeTextureHandleNonResidentARB");
    PROC_CAST glGetImageHandleARB = GetProcGL("glGetImageHandleARB");
    PROC_CAST glMakeImageHandleResidentARB = GetProcGL("glMakeImageHandleResidentARB");
    PROC_CAST glMakeImageHandleNonResidentARB = GetProcGL("glMakeImageHandleNonResidentARB");
    PROC_CAST glUniformHandleui64ARB = GetProcGL("glUniformHandleui64ARB");
    PROC_CAST glUniformHandleui64vARB = GetProcGL("glUniformHandleui64vARB");
    PROC_CAST glProgramUniformHandleui64ARB = GetProcGL("glProgramUniformHandleui64ARB");
    PROC_CAST glProgramUniformHandleui64vARB = GetProcGL("glProgramUniformHandleui64vARB");
    PROC_CAST glIsTextureHandleResidentARB = GetProcGL("glIsTextureHandleResidentARB");
    PROC_CAST glIsImageHandleResidentARB = GetProcGL("glIsImageHandleResidentARB");
    PROC_CAST glVertexAttribL1ui64ARB = GetProcGL("glVertexAttribL1ui64ARB");
    PROC_CAST glVertexAttribL1ui64vARB = GetProcGL("glVertexAttribL1ui64vARB");
    PROC_CAST glGetVertexAttribLui64vARB = GetProcGL("glGetVertexAttribLui64vARB");
    PROC_CAST glCreateSyncFromCLeventARB = GetProcGL("glCreateSyncFromCLeventARB");
    PROC_CAST glDispatchComputeGroupSizeARB = GetProcGL("glDispatchComputeGroupSizeARB");
    PROC_CAST glDebugMessageControlARB = GetProcGL("glDebugMessageControlARB");
    PROC_CAST glDebugMessageInsertARB = GetProcGL("glDebugMessageInsertARB");
    PROC_CAST glDebugMessageCallbackARB = GetProcGL("glDebugMessageCallbackARB");
    PROC_CAST glGetDebugMessageLogARB = GetProcGL("glGetDebugMessageLogARB");
    PROC_CAST glBlendEquationiARB = GetProcGL("glBlendEquationiARB");
    PROC_CAST glBlendEquationSeparateiARB = GetProcGL("glBlendEquationSeparateiARB");
    PROC_CAST glBlendFunciARB = GetProcGL("glBlendFunciARB");
    PROC_CAST glBlendFuncSeparateiARB = GetProcGL("glBlendFuncSeparateiARB");
    PROC_CAST glMultiDrawArraysIndirectCountARB = GetProcGL("glMultiDrawArraysIndirectCountARB");
    PROC_CAST glMultiDrawElementsIndirectCountARB = GetProcGL("glMultiDrawElementsIndirectCountARB");
    PROC_CAST glGetGraphicsResetStatusARB = GetProcGL("glGetGraphicsResetStatusARB");
    PROC_CAST glGetnTexImageARB = GetProcGL("glGetnTexImageARB");
    PROC_CAST glReadnPixelsARB = GetProcGL("glReadnPixelsARB");
    PROC_CAST glGetnCompressedTexImageARB = GetProcGL("glGetnCompressedTexImageARB");
    PROC_CAST glGetnUniformfvARB = GetProcGL("glGetnUniformfvARB");
    PROC_CAST glGetnUniformivARB = GetProcGL("glGetnUniformivARB");
    PROC_CAST glGetnUniformuivARB = GetProcGL("glGetnUniformuivARB");
    PROC_CAST glGetnUniformdvARB = GetProcGL("glGetnUniformdvARB");
    PROC_CAST glMinSampleShadingARB = GetProcGL("glMinSampleShadingARB");
    PROC_CAST glNamedStringARB = GetProcGL("glNamedStringARB");
    PROC_CAST glDeleteNamedStringARB = GetProcGL("glDeleteNamedStringARB");
    PROC_CAST glCompileShaderIncludeARB = GetProcGL("glCompileShaderIncludeARB");
    PROC_CAST glIsNamedStringARB = GetProcGL("glIsNamedStringARB");
    PROC_CAST glGetNamedStringARB = GetProcGL("glGetNamedStringARB");
    PROC_CAST glGetNamedStringivARB = GetProcGL("glGetNamedStringivARB");
    PROC_CAST glBufferPageCommitmentARB = GetProcGL("glBufferPageCommitmentARB");
    PROC_CAST glNamedBufferPageCommitmentEXT = GetProcGL("glNamedBufferPageCommitmentEXT");
    PROC_CAST glNamedBufferPageCommitmentARB = GetProcGL("glNamedBufferPageCommitmentARB");
    PROC_CAST glTexPageCommitmentARB = GetProcGL("glTexPageCommitmentARB");
}

#endif // JUSTGL_IMPLEMENTATION