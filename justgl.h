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

    // advanced stuff (they have sensible defaults if you don't care)
    int MajorGLVersion;
    int MinorGLVersion;
    
    int DebugContext;
    int ForwardCompatibleContext;
    int CompatibilityProfileContext;

    int EnableFramebufferDepth;
    int EnableFramebufferStencil;
    int MultisampleCount;
    int FramebufferSRGBCapable;
} WindowConfig;

// App customization points (you implement these)
void ConfigGL(WindowConfig* pConfig);
void InitGL();
void ResizeGL(int width, int height);
void PaintGL();

// Utility functions
void* GetProcGL(const char* procname);

// Windows implementation
#ifdef _WIN32

// Include Windows.h prior to contents of glcorearb
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN 1
#endif
#ifndef NOMINMAX
#define NOMINMAX 1
#endif
#include <Windows.h>

#endif // _WIN32

// A tweaked version of glcorearb.h is pasted inline between __glcorearb_h_.
// The license associated to this chunk of code is also included inline.
// That license applies to that part of the code only.
// The rest of the code in this file is under the license at the top of this file.
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

#ifndef APIENTRY
#define APIENTRY
#endif
#ifndef APIENTRYP
#define APIENTRYP APIENTRY *
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
typedef void (APIENTRYP PFNGLCULLFACEPROC) (GLenum mode);
typedef void (APIENTRYP PFNGLFRONTFACEPROC) (GLenum mode);
typedef void (APIENTRYP PFNGLHINTPROC) (GLenum target, GLenum mode);
typedef void (APIENTRYP PFNGLLINEWIDTHPROC) (GLfloat width);
typedef void (APIENTRYP PFNGLPOINTSIZEPROC) (GLfloat size);
typedef void (APIENTRYP PFNGLPOLYGONMODEPROC) (GLenum face, GLenum mode);
typedef void (APIENTRYP PFNGLSCISSORPROC) (GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLTEXPARAMETERFPROC) (GLenum target, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLTEXPARAMETERFVPROC) (GLenum target, GLenum pname, const GLfloat *params);
typedef void (APIENTRYP PFNGLTEXPARAMETERIPROC) (GLenum target, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLTEXPARAMETERIVPROC) (GLenum target, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLTEXIMAGE1DPROC) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLTEXIMAGE2DPROC) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLDRAWBUFFERPROC) (GLenum buf);
typedef void (APIENTRYP PFNGLCLEARPROC) (GLbitfield mask);
typedef void (APIENTRYP PFNGLCLEARCOLORPROC) (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
typedef void (APIENTRYP PFNGLCLEARSTENCILPROC) (GLint s);
typedef void (APIENTRYP PFNGLCLEARDEPTHPROC) (GLdouble depth);
typedef void (APIENTRYP PFNGLSTENCILMASKPROC) (GLuint mask);
typedef void (APIENTRYP PFNGLCOLORMASKPROC) (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
typedef void (APIENTRYP PFNGLDEPTHMASKPROC) (GLboolean flag);
typedef void (APIENTRYP PFNGLDISABLEPROC) (GLenum cap);
typedef void (APIENTRYP PFNGLENABLEPROC) (GLenum cap);
typedef void (APIENTRYP PFNGLFINISHPROC) (void);
typedef void (APIENTRYP PFNGLFLUSHPROC) (void);
typedef void (APIENTRYP PFNGLBLENDFUNCPROC) (GLenum sfactor, GLenum dfactor);
typedef void (APIENTRYP PFNGLLOGICOPPROC) (GLenum opcode);
typedef void (APIENTRYP PFNGLSTENCILFUNCPROC) (GLenum func, GLint ref, GLuint mask);
typedef void (APIENTRYP PFNGLSTENCILOPPROC) (GLenum fail, GLenum zfail, GLenum zpass);
typedef void (APIENTRYP PFNGLDEPTHFUNCPROC) (GLenum func);
typedef void (APIENTRYP PFNGLPIXELSTOREFPROC) (GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLPIXELSTOREIPROC) (GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLREADBUFFERPROC) (GLenum src);
typedef void (APIENTRYP PFNGLREADPIXELSPROC) (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels);
typedef void (APIENTRYP PFNGLGETBOOLEANVPROC) (GLenum pname, GLboolean *data);
typedef void (APIENTRYP PFNGLGETDOUBLEVPROC) (GLenum pname, GLdouble *data);
typedef GLenum(APIENTRYP PFNGLGETERRORPROC) (void);
typedef void (APIENTRYP PFNGLGETFLOATVPROC) (GLenum pname, GLfloat *data);
typedef void (APIENTRYP PFNGLGETINTEGERVPROC) (GLenum pname, GLint *data);
typedef const GLubyte *(APIENTRYP PFNGLGETSTRINGPROC) (GLenum name);
typedef void (APIENTRYP PFNGLGETTEXIMAGEPROC) (GLenum target, GLint level, GLenum format, GLenum type, void *pixels);
typedef void (APIENTRYP PFNGLGETTEXPARAMETERFVPROC) (GLenum target, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETTEXPARAMETERIVPROC) (GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETTEXLEVELPARAMETERFVPROC) (GLenum target, GLint level, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETTEXLEVELPARAMETERIVPROC) (GLenum target, GLint level, GLenum pname, GLint *params);
typedef GLboolean(APIENTRYP PFNGLISENABLEDPROC) (GLenum cap);
typedef void (APIENTRYP PFNGLDEPTHRANGEPROC) (GLdouble near, GLdouble far);
typedef void (APIENTRYP PFNGLVIEWPORTPROC) (GLint x, GLint y, GLsizei width, GLsizei height);
extern void (APIENTRYP glCullFace)(GLenum mode);
extern void (APIENTRYP glFrontFace)(GLenum mode);
extern void (APIENTRYP glHint)(GLenum target, GLenum mode);
extern void (APIENTRYP glLineWidth)(GLfloat width);
extern void (APIENTRYP glPointSize)(GLfloat size);
extern void (APIENTRYP glPolygonMode)(GLenum face, GLenum mode);
extern void (APIENTRYP glScissor)(GLint x, GLint y, GLsizei width, GLsizei height);
extern void (APIENTRYP glTexParameterf)(GLenum target, GLenum pname, GLfloat param);
extern void (APIENTRYP glTexParameterfv)(GLenum target, GLenum pname, const GLfloat *params);
extern void (APIENTRYP glTexParameteri)(GLenum target, GLenum pname, GLint param);
extern void (APIENTRYP glTexParameteriv)(GLenum target, GLenum pname, const GLint *params);
extern void (APIENTRYP glTexImage1D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels);
extern void (APIENTRYP glTexImage2D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
extern void (APIENTRYP glDrawBuffer)(GLenum buf);
extern void (APIENTRYP glClear)(GLbitfield mask);
extern void (APIENTRYP glClearColor)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
extern void (APIENTRYP glClearStencil)(GLint s);
extern void (APIENTRYP glClearDepth)(GLdouble depth);
extern void (APIENTRYP glStencilMask)(GLuint mask);
extern void (APIENTRYP glColorMask)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
extern void (APIENTRYP glDepthMask)(GLboolean flag);
extern void (APIENTRYP glDisable)(GLenum cap);
extern void (APIENTRYP glEnable)(GLenum cap);
extern void (APIENTRYP glFinish)(void);
extern void (APIENTRYP glFlush)(void);
extern void (APIENTRYP glBlendFunc)(GLenum sfactor, GLenum dfactor);
extern void (APIENTRYP glLogicOp)(GLenum opcode);
extern void (APIENTRYP glStencilFunc)(GLenum func, GLint ref, GLuint mask);
extern void (APIENTRYP glStencilOp)(GLenum fail, GLenum zfail, GLenum zpass);
extern void (APIENTRYP glDepthFunc)(GLenum func);
extern void (APIENTRYP glPixelStoref)(GLenum pname, GLfloat param);
extern void (APIENTRYP glPixelStorei)(GLenum pname, GLint param);
extern void (APIENTRYP glReadBuffer)(GLenum src);
extern void (APIENTRYP glReadPixels)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels);
extern void (APIENTRYP glGetBooleanv)(GLenum pname, GLboolean *data);
extern void (APIENTRYP glGetDoublev)(GLenum pname, GLdouble *data);
extern GLenum(APIENTRYP glGetError)(void);
extern void (APIENTRYP glGetFloatv)(GLenum pname, GLfloat *data);
extern void (APIENTRYP glGetIntegerv)(GLenum pname, GLint *data);
extern const GLubyte *(APIENTRYP glGetString)(GLenum name);
extern void (APIENTRYP glGetTexImage)(GLenum target, GLint level, GLenum format, GLenum type, void *pixels);
extern void (APIENTRYP glGetTexParameterfv)(GLenum target, GLenum pname, GLfloat *params);
extern void (APIENTRYP glGetTexParameteriv)(GLenum target, GLenum pname, GLint *params);
extern void (APIENTRYP glGetTexLevelParameterfv)(GLenum target, GLint level, GLenum pname, GLfloat *params);
extern void (APIENTRYP glGetTexLevelParameteriv)(GLenum target, GLint level, GLenum pname, GLint *params);
extern GLboolean(APIENTRYP glIsEnabled)(GLenum cap);
extern void (APIENTRYP glDepthRange)(GLdouble near, GLdouble far);
extern void (APIENTRYP glViewport)(GLint x, GLint y, GLsizei width, GLsizei height);

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
typedef void (APIENTRYP PFNGLDRAWARRAYSPROC) (GLenum mode, GLint first, GLsizei count);
typedef void (APIENTRYP PFNGLDRAWELEMENTSPROC) (GLenum mode, GLsizei count, GLenum type, const void *indices);
typedef void (APIENTRYP PFNGLGETPOINTERVPROC) (GLenum pname, void **params);
typedef void (APIENTRYP PFNGLPOLYGONOFFSETPROC) (GLfloat factor, GLfloat units);
typedef void (APIENTRYP PFNGLCOPYTEXIMAGE1DPROC) (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
typedef void (APIENTRYP PFNGLCOPYTEXIMAGE2DPROC) (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE1DPROC) (GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE2DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLTEXSUBIMAGE1DPROC) (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLTEXSUBIMAGE2DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLBINDTEXTUREPROC) (GLenum target, GLuint texture);
typedef void (APIENTRYP PFNGLDELETETEXTURESPROC) (GLsizei n, const GLuint *textures);
typedef void (APIENTRYP PFNGLGENTEXTURESPROC) (GLsizei n, GLuint *textures);
typedef GLboolean(APIENTRYP PFNGLISTEXTUREPROC) (GLuint texture);
extern void (APIENTRYP glDrawArrays)(GLenum mode, GLint first, GLsizei count);
extern void (APIENTRYP glDrawElements)(GLenum mode, GLsizei count, GLenum type, const void *indices);
extern void (APIENTRYP glGetPointerv)(GLenum pname, void **params);
extern void (APIENTRYP glPolygonOffset)(GLfloat factor, GLfloat units);
extern void (APIENTRYP glCopyTexImage1D)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
extern void (APIENTRYP glCopyTexImage2D)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
extern void (APIENTRYP glCopyTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
extern void (APIENTRYP glCopyTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
extern void (APIENTRYP glTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
extern void (APIENTRYP glTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
extern void (APIENTRYP glBindTexture)(GLenum target, GLuint texture);
extern void (APIENTRYP glDeleteTextures)(GLsizei n, const GLuint *textures);
extern void (APIENTRYP glGenTextures)(GLsizei n, GLuint *textures);
extern GLboolean(APIENTRYP glIsTexture)(GLuint texture);

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
typedef void (APIENTRYP PFNGLDRAWRANGEELEMENTSPROC) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices);
typedef void (APIENTRYP PFNGLTEXIMAGE3DPROC) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLTEXSUBIMAGE3DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE3DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
extern void (APIENTRYP glDrawRangeElements)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices);
extern void (APIENTRYP glTexImage3D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
extern void (APIENTRYP glTexSubImage3D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
extern void (APIENTRYP glCopyTexSubImage3D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);

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
typedef void (APIENTRYP PFNGLACTIVETEXTUREPROC) (GLenum texture);
typedef void (APIENTRYP PFNGLSAMPLECOVERAGEPROC) (GLfloat value, GLboolean invert);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE3DPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE2DPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE1DPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC) (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLGETCOMPRESSEDTEXIMAGEPROC) (GLenum target, GLint level, void *img);
extern void (APIENTRYP glActiveTexture)(GLenum texture);
extern void (APIENTRYP glSampleCoverage)(GLfloat value, GLboolean invert);
extern void (APIENTRYP glCompressedTexImage3D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data);
extern void (APIENTRYP glCompressedTexImage2D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data);
extern void (APIENTRYP glCompressedTexImage1D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data);
extern void (APIENTRYP glCompressedTexSubImage3D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
extern void (APIENTRYP glCompressedTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
extern void (APIENTRYP glCompressedTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
extern void (APIENTRYP glGetCompressedTexImage)(GLenum target, GLint level, void *img);

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
typedef void (APIENTRYP PFNGLBLENDFUNCSEPARATEPROC) (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSPROC) (GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount);
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSPROC) (GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount);
typedef void (APIENTRYP PFNGLPOINTPARAMETERFPROC) (GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLPOINTPARAMETERFVPROC) (GLenum pname, const GLfloat *params);
typedef void (APIENTRYP PFNGLPOINTPARAMETERIPROC) (GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLPOINTPARAMETERIVPROC) (GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLBLENDCOLORPROC) (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
typedef void (APIENTRYP PFNGLBLENDEQUATIONPROC) (GLenum mode);
extern void (APIENTRYP glBlendFuncSeparate)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
extern void (APIENTRYP glMultiDrawArrays)(GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount);
extern void (APIENTRYP glMultiDrawElements)(GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount);
extern void (APIENTRYP glPointParameterf)(GLenum pname, GLfloat param);
extern void (APIENTRYP glPointParameterfv)(GLenum pname, const GLfloat *params);
extern void (APIENTRYP glPointParameteri)(GLenum pname, GLint param);
extern void (APIENTRYP glPointParameteriv)(GLenum pname, const GLint *params);
extern void (APIENTRYP glBlendColor)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
extern void (APIENTRYP glBlendEquation)(GLenum mode);

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
typedef void (APIENTRYP PFNGLGENQUERIESPROC) (GLsizei n, GLuint *ids);
typedef void (APIENTRYP PFNGLDELETEQUERIESPROC) (GLsizei n, const GLuint *ids);
typedef GLboolean(APIENTRYP PFNGLISQUERYPROC) (GLuint id);
typedef void (APIENTRYP PFNGLBEGINQUERYPROC) (GLenum target, GLuint id);
typedef void (APIENTRYP PFNGLENDQUERYPROC) (GLenum target);
typedef void (APIENTRYP PFNGLGETQUERYIVPROC) (GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETQUERYOBJECTIVPROC) (GLuint id, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETQUERYOBJECTUIVPROC) (GLuint id, GLenum pname, GLuint *params);
typedef void (APIENTRYP PFNGLBINDBUFFERPROC) (GLenum target, GLuint buffer);
typedef void (APIENTRYP PFNGLDELETEBUFFERSPROC) (GLsizei n, const GLuint *buffers);
typedef void (APIENTRYP PFNGLGENBUFFERSPROC) (GLsizei n, GLuint *buffers);
typedef GLboolean(APIENTRYP PFNGLISBUFFERPROC) (GLuint buffer);
typedef void (APIENTRYP PFNGLBUFFERDATAPROC) (GLenum target, GLsizeiptr size, const void *data, GLenum usage);
typedef void (APIENTRYP PFNGLBUFFERSUBDATAPROC) (GLenum target, GLintptr offset, GLsizeiptr size, const void *data);
typedef void (APIENTRYP PFNGLGETBUFFERSUBDATAPROC) (GLenum target, GLintptr offset, GLsizeiptr size, void *data);
typedef void *(APIENTRYP PFNGLMAPBUFFERPROC) (GLenum target, GLenum access);
typedef GLboolean(APIENTRYP PFNGLUNMAPBUFFERPROC) (GLenum target);
typedef void (APIENTRYP PFNGLGETBUFFERPARAMETERIVPROC) (GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETBUFFERPOINTERVPROC) (GLenum target, GLenum pname, void **params);
extern void (APIENTRYP glGenQueries)(GLsizei n, GLuint *ids);
extern void (APIENTRYP glDeleteQueries)(GLsizei n, const GLuint *ids);
extern GLboolean(APIENTRYP glIsQuery)(GLuint id);
extern void (APIENTRYP glBeginQuery)(GLenum target, GLuint id);
extern void (APIENTRYP glEndQuery)(GLenum target);
extern void (APIENTRYP glGetQueryiv)(GLenum target, GLenum pname, GLint *params);
extern void (APIENTRYP glGetQueryObjectiv)(GLuint id, GLenum pname, GLint *params);
extern void (APIENTRYP glGetQueryObjectuiv)(GLuint id, GLenum pname, GLuint *params);
extern void (APIENTRYP glBindBuffer)(GLenum target, GLuint buffer);
extern void (APIENTRYP glDeleteBuffers)(GLsizei n, const GLuint *buffers);
extern void (APIENTRYP glGenBuffers)(GLsizei n, GLuint *buffers);
extern GLboolean(APIENTRYP glIsBuffer)(GLuint buffer);
extern void (APIENTRYP glBufferData)(GLenum target, GLsizeiptr size, const void *data, GLenum usage);
extern void (APIENTRYP glBufferSubData)(GLenum target, GLintptr offset, GLsizeiptr size, const void *data);
extern void (APIENTRYP glGetBufferSubData)(GLenum target, GLintptr offset, GLsizeiptr size, void *data);
extern void *(APIENTRYP glMapBuffer)(GLenum target, GLenum access);
extern GLboolean(APIENTRYP glUnmapBuffer)(GLenum target);
extern void (APIENTRYP glGetBufferParameteriv)(GLenum target, GLenum pname, GLint *params);
extern void (APIENTRYP glGetBufferPointerv)(GLenum target, GLenum pname, void **params);

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
typedef void (APIENTRYP PFNGLBLENDEQUATIONSEPARATEPROC) (GLenum modeRGB, GLenum modeAlpha);
typedef void (APIENTRYP PFNGLDRAWBUFFERSPROC) (GLsizei n, const GLenum *bufs);
typedef void (APIENTRYP PFNGLSTENCILOPSEPARATEPROC) (GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
typedef void (APIENTRYP PFNGLSTENCILFUNCSEPARATEPROC) (GLenum face, GLenum func, GLint ref, GLuint mask);
typedef void (APIENTRYP PFNGLSTENCILMASKSEPARATEPROC) (GLenum face, GLuint mask);
typedef void (APIENTRYP PFNGLATTACHSHADERPROC) (GLuint program, GLuint shader);
typedef void (APIENTRYP PFNGLBINDATTRIBLOCATIONPROC) (GLuint program, GLuint index, const GLchar *name);
typedef void (APIENTRYP PFNGLCOMPILESHADERPROC) (GLuint shader);
typedef GLuint(APIENTRYP PFNGLCREATEPROGRAMPROC) (void);
typedef GLuint(APIENTRYP PFNGLCREATESHADERPROC) (GLenum type);
typedef void (APIENTRYP PFNGLDELETEPROGRAMPROC) (GLuint program);
typedef void (APIENTRYP PFNGLDELETESHADERPROC) (GLuint shader);
typedef void (APIENTRYP PFNGLDETACHSHADERPROC) (GLuint program, GLuint shader);
typedef void (APIENTRYP PFNGLDISABLEVERTEXATTRIBARRAYPROC) (GLuint index);
typedef void (APIENTRYP PFNGLENABLEVERTEXATTRIBARRAYPROC) (GLuint index);
typedef void (APIENTRYP PFNGLGETACTIVEATTRIBPROC) (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMPROC) (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
typedef void (APIENTRYP PFNGLGETATTACHEDSHADERSPROC) (GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders);
typedef GLint(APIENTRYP PFNGLGETATTRIBLOCATIONPROC) (GLuint program, const GLchar *name);
typedef void (APIENTRYP PFNGLGETPROGRAMIVPROC) (GLuint program, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETPROGRAMINFOLOGPROC) (GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
typedef void (APIENTRYP PFNGLGETSHADERIVPROC) (GLuint shader, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETSHADERINFOLOGPROC) (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
typedef void (APIENTRYP PFNGLGETSHADERSOURCEPROC) (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source);
typedef GLint(APIENTRYP PFNGLGETUNIFORMLOCATIONPROC) (GLuint program, const GLchar *name);
typedef void (APIENTRYP PFNGLGETUNIFORMFVPROC) (GLuint program, GLint location, GLfloat *params);
typedef void (APIENTRYP PFNGLGETUNIFORMIVPROC) (GLuint program, GLint location, GLint *params);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBDVPROC) (GLuint index, GLenum pname, GLdouble *params);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBFVPROC) (GLuint index, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIVPROC) (GLuint index, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBPOINTERVPROC) (GLuint index, GLenum pname, void **pointer);
typedef GLboolean(APIENTRYP PFNGLISPROGRAMPROC) (GLuint program);
typedef GLboolean(APIENTRYP PFNGLISSHADERPROC) (GLuint shader);
typedef void (APIENTRYP PFNGLLINKPROGRAMPROC) (GLuint program);
typedef void (APIENTRYP PFNGLSHADERSOURCEPROC) (GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length);
typedef void (APIENTRYP PFNGLUSEPROGRAMPROC) (GLuint program);
typedef void (APIENTRYP PFNGLUNIFORM1FPROC) (GLint location, GLfloat v0);
typedef void (APIENTRYP PFNGLUNIFORM2FPROC) (GLint location, GLfloat v0, GLfloat v1);
typedef void (APIENTRYP PFNGLUNIFORM3FPROC) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
typedef void (APIENTRYP PFNGLUNIFORM4FPROC) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
typedef void (APIENTRYP PFNGLUNIFORM1IPROC) (GLint location, GLint v0);
typedef void (APIENTRYP PFNGLUNIFORM2IPROC) (GLint location, GLint v0, GLint v1);
typedef void (APIENTRYP PFNGLUNIFORM3IPROC) (GLint location, GLint v0, GLint v1, GLint v2);
typedef void (APIENTRYP PFNGLUNIFORM4IPROC) (GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
typedef void (APIENTRYP PFNGLUNIFORM1FVPROC) (GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORM2FVPROC) (GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORM3FVPROC) (GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORM4FVPROC) (GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORM1IVPROC) (GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLUNIFORM2IVPROC) (GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLUNIFORM3IVPROC) (GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLUNIFORM4IVPROC) (GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLVALIDATEPROGRAMPROC) (GLuint program);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1DPROC) (GLuint index, GLdouble x);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1DVPROC) (GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1FPROC) (GLuint index, GLfloat x);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1FVPROC) (GLuint index, const GLfloat *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1SPROC) (GLuint index, GLshort x);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1SVPROC) (GLuint index, const GLshort *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2DPROC) (GLuint index, GLdouble x, GLdouble y);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2DVPROC) (GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2FPROC) (GLuint index, GLfloat x, GLfloat y);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2FVPROC) (GLuint index, const GLfloat *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2SPROC) (GLuint index, GLshort x, GLshort y);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2SVPROC) (GLuint index, const GLshort *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3DPROC) (GLuint index, GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3DVPROC) (GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3FPROC) (GLuint index, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3FVPROC) (GLuint index, const GLfloat *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3SPROC) (GLuint index, GLshort x, GLshort y, GLshort z);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3SVPROC) (GLuint index, const GLshort *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NBVPROC) (GLuint index, const GLbyte *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NIVPROC) (GLuint index, const GLint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NSVPROC) (GLuint index, const GLshort *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUBPROC) (GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUBVPROC) (GLuint index, const GLubyte *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUIVPROC) (GLuint index, const GLuint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUSVPROC) (GLuint index, const GLushort *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4BVPROC) (GLuint index, const GLbyte *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4DPROC) (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4DVPROC) (GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4FPROC) (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4FVPROC) (GLuint index, const GLfloat *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4IVPROC) (GLuint index, const GLint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4SPROC) (GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4SVPROC) (GLuint index, const GLshort *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4UBVPROC) (GLuint index, const GLubyte *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4UIVPROC) (GLuint index, const GLuint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4USVPROC) (GLuint index, const GLushort *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBPOINTERPROC) (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);
extern void (APIENTRYP glBlendEquationSeparate)(GLenum modeRGB, GLenum modeAlpha);
extern void (APIENTRYP glDrawBuffers)(GLsizei n, const GLenum *bufs);
extern void (APIENTRYP glStencilOpSeparate)(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
extern void (APIENTRYP glStencilFuncSeparate)(GLenum face, GLenum func, GLint ref, GLuint mask);
extern void (APIENTRYP glStencilMaskSeparate)(GLenum face, GLuint mask);
extern void (APIENTRYP glAttachShader)(GLuint program, GLuint shader);
extern void (APIENTRYP glBindAttribLocation)(GLuint program, GLuint index, const GLchar *name);
extern void (APIENTRYP glCompileShader)(GLuint shader);
extern GLuint(APIENTRYP glCreateProgram)(void);
extern GLuint(APIENTRYP glCreateShader)(GLenum type);
extern void (APIENTRYP glDeleteProgram)(GLuint program);
extern void (APIENTRYP glDeleteShader)(GLuint shader);
extern void (APIENTRYP glDetachShader)(GLuint program, GLuint shader);
extern void (APIENTRYP glDisableVertexAttribArray)(GLuint index);
extern void (APIENTRYP glEnableVertexAttribArray)(GLuint index);
extern void (APIENTRYP glGetActiveAttrib)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
extern void (APIENTRYP glGetActiveUniform)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
extern void (APIENTRYP glGetAttachedShaders)(GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders);
extern GLint(APIENTRYP glGetAttribLocation)(GLuint program, const GLchar *name);
extern void (APIENTRYP glGetProgramiv)(GLuint program, GLenum pname, GLint *params);
extern void (APIENTRYP glGetProgramInfoLog)(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
extern void (APIENTRYP glGetShaderiv)(GLuint shader, GLenum pname, GLint *params);
extern void (APIENTRYP glGetShaderInfoLog)(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
extern void (APIENTRYP glGetShaderSource)(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source);
extern GLint(APIENTRYP glGetUniformLocation)(GLuint program, const GLchar *name);
extern void (APIENTRYP glGetUniformfv)(GLuint program, GLint location, GLfloat *params);
extern void (APIENTRYP glGetUniformiv)(GLuint program, GLint location, GLint *params);
extern void (APIENTRYP glGetVertexAttribdv)(GLuint index, GLenum pname, GLdouble *params);
extern void (APIENTRYP glGetVertexAttribfv)(GLuint index, GLenum pname, GLfloat *params);
extern void (APIENTRYP glGetVertexAttribiv)(GLuint index, GLenum pname, GLint *params);
extern void (APIENTRYP glGetVertexAttribPointerv)(GLuint index, GLenum pname, void **pointer);
extern GLboolean(APIENTRYP glIsProgram)(GLuint program);
extern GLboolean(APIENTRYP glIsShader)(GLuint shader);
extern void (APIENTRYP glLinkProgram)(GLuint program);
extern void (APIENTRYP glShaderSource)(GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length);
extern void (APIENTRYP glUseProgram)(GLuint program);
extern void (APIENTRYP glUniform1f)(GLint location, GLfloat v0);
extern void (APIENTRYP glUniform2f)(GLint location, GLfloat v0, GLfloat v1);
extern void (APIENTRYP glUniform3f)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
extern void (APIENTRYP glUniform4f)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
extern void (APIENTRYP glUniform1i)(GLint location, GLint v0);
extern void (APIENTRYP glUniform2i)(GLint location, GLint v0, GLint v1);
extern void (APIENTRYP glUniform3i)(GLint location, GLint v0, GLint v1, GLint v2);
extern void (APIENTRYP glUniform4i)(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
extern void (APIENTRYP glUniform1fv)(GLint location, GLsizei count, const GLfloat *value);
extern void (APIENTRYP glUniform2fv)(GLint location, GLsizei count, const GLfloat *value);
extern void (APIENTRYP glUniform3fv)(GLint location, GLsizei count, const GLfloat *value);
extern void (APIENTRYP glUniform4fv)(GLint location, GLsizei count, const GLfloat *value);
extern void (APIENTRYP glUniform1iv)(GLint location, GLsizei count, const GLint *value);
extern void (APIENTRYP glUniform2iv)(GLint location, GLsizei count, const GLint *value);
extern void (APIENTRYP glUniform3iv)(GLint location, GLsizei count, const GLint *value);
extern void (APIENTRYP glUniform4iv)(GLint location, GLsizei count, const GLint *value);
extern void (APIENTRYP glUniformMatrix2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
extern void (APIENTRYP glUniformMatrix3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
extern void (APIENTRYP glUniformMatrix4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
extern void (APIENTRYP glValidateProgram)(GLuint program);
extern void (APIENTRYP glVertexAttrib1d)(GLuint index, GLdouble x);
extern void (APIENTRYP glVertexAttrib1dv)(GLuint index, const GLdouble *v);
extern void (APIENTRYP glVertexAttrib1f)(GLuint index, GLfloat x);
extern void (APIENTRYP glVertexAttrib1fv)(GLuint index, const GLfloat *v);
extern void (APIENTRYP glVertexAttrib1s)(GLuint index, GLshort x);
extern void (APIENTRYP glVertexAttrib1sv)(GLuint index, const GLshort *v);
extern void (APIENTRYP glVertexAttrib2d)(GLuint index, GLdouble x, GLdouble y);
extern void (APIENTRYP glVertexAttrib2dv)(GLuint index, const GLdouble *v);
extern void (APIENTRYP glVertexAttrib2f)(GLuint index, GLfloat x, GLfloat y);
extern void (APIENTRYP glVertexAttrib2fv)(GLuint index, const GLfloat *v);
extern void (APIENTRYP glVertexAttrib2s)(GLuint index, GLshort x, GLshort y);
extern void (APIENTRYP glVertexAttrib2sv)(GLuint index, const GLshort *v);
extern void (APIENTRYP glVertexAttrib3d)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
extern void (APIENTRYP glVertexAttrib3dv)(GLuint index, const GLdouble *v);
extern void (APIENTRYP glVertexAttrib3f)(GLuint index, GLfloat x, GLfloat y, GLfloat z);
extern void (APIENTRYP glVertexAttrib3fv)(GLuint index, const GLfloat *v);
extern void (APIENTRYP glVertexAttrib3s)(GLuint index, GLshort x, GLshort y, GLshort z);
extern void (APIENTRYP glVertexAttrib3sv)(GLuint index, const GLshort *v);
extern void (APIENTRYP glVertexAttrib4Nbv)(GLuint index, const GLbyte *v);
extern void (APIENTRYP glVertexAttrib4Niv)(GLuint index, const GLint *v);
extern void (APIENTRYP glVertexAttrib4Nsv)(GLuint index, const GLshort *v);
extern void (APIENTRYP glVertexAttrib4Nub)(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
extern void (APIENTRYP glVertexAttrib4Nubv)(GLuint index, const GLubyte *v);
extern void (APIENTRYP glVertexAttrib4Nuiv)(GLuint index, const GLuint *v);
extern void (APIENTRYP glVertexAttrib4Nusv)(GLuint index, const GLushort *v);
extern void (APIENTRYP glVertexAttrib4bv)(GLuint index, const GLbyte *v);
extern void (APIENTRYP glVertexAttrib4d)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
extern void (APIENTRYP glVertexAttrib4dv)(GLuint index, const GLdouble *v);
extern void (APIENTRYP glVertexAttrib4f)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
extern void (APIENTRYP glVertexAttrib4fv)(GLuint index, const GLfloat *v);
extern void (APIENTRYP glVertexAttrib4iv)(GLuint index, const GLint *v);
extern void (APIENTRYP glVertexAttrib4s)(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
extern void (APIENTRYP glVertexAttrib4sv)(GLuint index, const GLshort *v);
extern void (APIENTRYP glVertexAttrib4ubv)(GLuint index, const GLubyte *v);
extern void (APIENTRYP glVertexAttrib4uiv)(GLuint index, const GLuint *v);
extern void (APIENTRYP glVertexAttrib4usv)(GLuint index, const GLushort *v);
extern void (APIENTRYP glVertexAttribPointer)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);

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
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X3FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X2FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X4FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X2FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X4FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X3FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
extern void (APIENTRYP glUniformMatrix2x3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
extern void (APIENTRYP glUniformMatrix3x2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
extern void (APIENTRYP glUniformMatrix2x4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
extern void (APIENTRYP glUniformMatrix4x2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
extern void (APIENTRYP glUniformMatrix3x4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
extern void (APIENTRYP glUniformMatrix4x3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);

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
typedef void (APIENTRYP PFNGLCOLORMASKIPROC) (GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
typedef void (APIENTRYP PFNGLGETBOOLEANI_VPROC) (GLenum target, GLuint index, GLboolean *data);
typedef void (APIENTRYP PFNGLGETINTEGERI_VPROC) (GLenum target, GLuint index, GLint *data);
typedef void (APIENTRYP PFNGLENABLEIPROC) (GLenum target, GLuint index);
typedef void (APIENTRYP PFNGLDISABLEIPROC) (GLenum target, GLuint index);
typedef GLboolean(APIENTRYP PFNGLISENABLEDIPROC) (GLenum target, GLuint index);
typedef void (APIENTRYP PFNGLBEGINTRANSFORMFEEDBACKPROC) (GLenum primitiveMode);
typedef void (APIENTRYP PFNGLENDTRANSFORMFEEDBACKPROC) (void);
typedef void (APIENTRYP PFNGLBINDBUFFERRANGEPROC) (GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLBINDBUFFERBASEPROC) (GLenum target, GLuint index, GLuint buffer);
typedef void (APIENTRYP PFNGLTRANSFORMFEEDBACKVARYINGSPROC) (GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode);
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKVARYINGPROC) (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
typedef void (APIENTRYP PFNGLCLAMPCOLORPROC) (GLenum target, GLenum clamp);
typedef void (APIENTRYP PFNGLBEGINCONDITIONALRENDERPROC) (GLuint id, GLenum mode);
typedef void (APIENTRYP PFNGLENDCONDITIONALRENDERPROC) (void);
typedef void (APIENTRYP PFNGLVERTEXATTRIBIPOINTERPROC) (GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIIVPROC) (GLuint index, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIUIVPROC) (GLuint index, GLenum pname, GLuint *params);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1IPROC) (GLuint index, GLint x);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2IPROC) (GLuint index, GLint x, GLint y);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3IPROC) (GLuint index, GLint x, GLint y, GLint z);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4IPROC) (GLuint index, GLint x, GLint y, GLint z, GLint w);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1UIPROC) (GLuint index, GLuint x);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2UIPROC) (GLuint index, GLuint x, GLuint y);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3UIPROC) (GLuint index, GLuint x, GLuint y, GLuint z);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UIPROC) (GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1IVPROC) (GLuint index, const GLint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2IVPROC) (GLuint index, const GLint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3IVPROC) (GLuint index, const GLint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4IVPROC) (GLuint index, const GLint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1UIVPROC) (GLuint index, const GLuint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2UIVPROC) (GLuint index, const GLuint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3UIVPROC) (GLuint index, const GLuint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UIVPROC) (GLuint index, const GLuint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4BVPROC) (GLuint index, const GLbyte *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4SVPROC) (GLuint index, const GLshort *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UBVPROC) (GLuint index, const GLubyte *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4USVPROC) (GLuint index, const GLushort *v);
typedef void (APIENTRYP PFNGLGETUNIFORMUIVPROC) (GLuint program, GLint location, GLuint *params);
typedef void (APIENTRYP PFNGLBINDFRAGDATALOCATIONPROC) (GLuint program, GLuint color, const GLchar *name);
typedef GLint(APIENTRYP PFNGLGETFRAGDATALOCATIONPROC) (GLuint program, const GLchar *name);
typedef void (APIENTRYP PFNGLUNIFORM1UIPROC) (GLint location, GLuint v0);
typedef void (APIENTRYP PFNGLUNIFORM2UIPROC) (GLint location, GLuint v0, GLuint v1);
typedef void (APIENTRYP PFNGLUNIFORM3UIPROC) (GLint location, GLuint v0, GLuint v1, GLuint v2);
typedef void (APIENTRYP PFNGLUNIFORM4UIPROC) (GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
typedef void (APIENTRYP PFNGLUNIFORM1UIVPROC) (GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLUNIFORM2UIVPROC) (GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLUNIFORM3UIVPROC) (GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLUNIFORM4UIVPROC) (GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLTEXPARAMETERIIVPROC) (GLenum target, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLTEXPARAMETERIUIVPROC) (GLenum target, GLenum pname, const GLuint *params);
typedef void (APIENTRYP PFNGLGETTEXPARAMETERIIVPROC) (GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETTEXPARAMETERIUIVPROC) (GLenum target, GLenum pname, GLuint *params);
typedef void (APIENTRYP PFNGLCLEARBUFFERIVPROC) (GLenum buffer, GLint drawbuffer, const GLint *value);
typedef void (APIENTRYP PFNGLCLEARBUFFERUIVPROC) (GLenum buffer, GLint drawbuffer, const GLuint *value);
typedef void (APIENTRYP PFNGLCLEARBUFFERFVPROC) (GLenum buffer, GLint drawbuffer, const GLfloat *value);
typedef void (APIENTRYP PFNGLCLEARBUFFERFIPROC) (GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
typedef const GLubyte *(APIENTRYP PFNGLGETSTRINGIPROC) (GLenum name, GLuint index);
typedef GLboolean(APIENTRYP PFNGLISRENDERBUFFERPROC) (GLuint renderbuffer);
typedef void (APIENTRYP PFNGLBINDRENDERBUFFERPROC) (GLenum target, GLuint renderbuffer);
typedef void (APIENTRYP PFNGLDELETERENDERBUFFERSPROC) (GLsizei n, const GLuint *renderbuffers);
typedef void (APIENTRYP PFNGLGENRENDERBUFFERSPROC) (GLsizei n, GLuint *renderbuffers);
typedef void (APIENTRYP PFNGLRENDERBUFFERSTORAGEPROC) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLGETRENDERBUFFERPARAMETERIVPROC) (GLenum target, GLenum pname, GLint *params);
typedef GLboolean(APIENTRYP PFNGLISFRAMEBUFFERPROC) (GLuint framebuffer);
typedef void (APIENTRYP PFNGLBINDFRAMEBUFFERPROC) (GLenum target, GLuint framebuffer);
typedef void (APIENTRYP PFNGLDELETEFRAMEBUFFERSPROC) (GLsizei n, const GLuint *framebuffers);
typedef void (APIENTRYP PFNGLGENFRAMEBUFFERSPROC) (GLsizei n, GLuint *framebuffers);
typedef GLenum(APIENTRYP PFNGLCHECKFRAMEBUFFERSTATUSPROC) (GLenum target);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE1DPROC) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE2DPROC) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE3DPROC) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
typedef void (APIENTRYP PFNGLFRAMEBUFFERRENDERBUFFERPROC) (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
typedef void (APIENTRYP PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC) (GLenum target, GLenum attachment, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGENERATEMIPMAPPROC) (GLenum target);
typedef void (APIENTRYP PFNGLBLITFRAMEBUFFERPROC) (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
typedef void (APIENTRYP PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURELAYERPROC) (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
typedef void *(APIENTRYP PFNGLMAPBUFFERRANGEPROC) (GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
typedef void (APIENTRYP PFNGLFLUSHMAPPEDBUFFERRANGEPROC) (GLenum target, GLintptr offset, GLsizeiptr length);
typedef void (APIENTRYP PFNGLBINDVERTEXARRAYPROC) (GLuint array);
typedef void (APIENTRYP PFNGLDELETEVERTEXARRAYSPROC) (GLsizei n, const GLuint *arrays);
typedef void (APIENTRYP PFNGLGENVERTEXARRAYSPROC) (GLsizei n, GLuint *arrays);
typedef GLboolean(APIENTRYP PFNGLISVERTEXARRAYPROC) (GLuint array);
extern void (APIENTRYP glColorMaski)(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
extern void (APIENTRYP glGetBooleani_v)(GLenum target, GLuint index, GLboolean *data);
extern void (APIENTRYP glGetIntegeri_v)(GLenum target, GLuint index, GLint *data);
extern void (APIENTRYP glEnablei)(GLenum target, GLuint index);
extern void (APIENTRYP glDisablei)(GLenum target, GLuint index);
extern GLboolean(APIENTRYP glIsEnabledi)(GLenum target, GLuint index);
extern void (APIENTRYP glBeginTransformFeedback)(GLenum primitiveMode);
extern void (APIENTRYP glEndTransformFeedback)(void);
extern void (APIENTRYP glBindBufferRange)(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
extern void (APIENTRYP glBindBufferBase)(GLenum target, GLuint index, GLuint buffer);
extern void (APIENTRYP glTransformFeedbackVaryings)(GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode);
extern void (APIENTRYP glGetTransformFeedbackVarying)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
extern void (APIENTRYP glClampColor)(GLenum target, GLenum clamp);
extern void (APIENTRYP glBeginConditionalRender)(GLuint id, GLenum mode);
extern void (APIENTRYP glEndConditionalRender)(void);
extern void (APIENTRYP glVertexAttribIPointer)(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
extern void (APIENTRYP glGetVertexAttribIiv)(GLuint index, GLenum pname, GLint *params);
extern void (APIENTRYP glGetVertexAttribIuiv)(GLuint index, GLenum pname, GLuint *params);
extern void (APIENTRYP glVertexAttribI1i)(GLuint index, GLint x);
extern void (APIENTRYP glVertexAttribI2i)(GLuint index, GLint x, GLint y);
extern void (APIENTRYP glVertexAttribI3i)(GLuint index, GLint x, GLint y, GLint z);
extern void (APIENTRYP glVertexAttribI4i)(GLuint index, GLint x, GLint y, GLint z, GLint w);
extern void (APIENTRYP glVertexAttribI1ui)(GLuint index, GLuint x);
extern void (APIENTRYP glVertexAttribI2ui)(GLuint index, GLuint x, GLuint y);
extern void (APIENTRYP glVertexAttribI3ui)(GLuint index, GLuint x, GLuint y, GLuint z);
extern void (APIENTRYP glVertexAttribI4ui)(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
extern void (APIENTRYP glVertexAttribI1iv)(GLuint index, const GLint *v);
extern void (APIENTRYP glVertexAttribI2iv)(GLuint index, const GLint *v);
extern void (APIENTRYP glVertexAttribI3iv)(GLuint index, const GLint *v);
extern void (APIENTRYP glVertexAttribI4iv)(GLuint index, const GLint *v);
extern void (APIENTRYP glVertexAttribI1uiv)(GLuint index, const GLuint *v);
extern void (APIENTRYP glVertexAttribI2uiv)(GLuint index, const GLuint *v);
extern void (APIENTRYP glVertexAttribI3uiv)(GLuint index, const GLuint *v);
extern void (APIENTRYP glVertexAttribI4uiv)(GLuint index, const GLuint *v);
extern void (APIENTRYP glVertexAttribI4bv)(GLuint index, const GLbyte *v);
extern void (APIENTRYP glVertexAttribI4sv)(GLuint index, const GLshort *v);
extern void (APIENTRYP glVertexAttribI4ubv)(GLuint index, const GLubyte *v);
extern void (APIENTRYP glVertexAttribI4usv)(GLuint index, const GLushort *v);
extern void (APIENTRYP glGetUniformuiv)(GLuint program, GLint location, GLuint *params);
extern void (APIENTRYP glBindFragDataLocation)(GLuint program, GLuint color, const GLchar *name);
extern GLint(APIENTRYP glGetFragDataLocation)(GLuint program, const GLchar *name);
extern void (APIENTRYP glUniform1ui)(GLint location, GLuint v0);
extern void (APIENTRYP glUniform2ui)(GLint location, GLuint v0, GLuint v1);
extern void (APIENTRYP glUniform3ui)(GLint location, GLuint v0, GLuint v1, GLuint v2);
extern void (APIENTRYP glUniform4ui)(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
extern void (APIENTRYP glUniform1uiv)(GLint location, GLsizei count, const GLuint *value);
extern void (APIENTRYP glUniform2uiv)(GLint location, GLsizei count, const GLuint *value);
extern void (APIENTRYP glUniform3uiv)(GLint location, GLsizei count, const GLuint *value);
extern void (APIENTRYP glUniform4uiv)(GLint location, GLsizei count, const GLuint *value);
extern void (APIENTRYP glTexParameterIiv)(GLenum target, GLenum pname, const GLint *params);
extern void (APIENTRYP glTexParameterIuiv)(GLenum target, GLenum pname, const GLuint *params);
extern void (APIENTRYP glGetTexParameterIiv)(GLenum target, GLenum pname, GLint *params);
extern void (APIENTRYP glGetTexParameterIuiv)(GLenum target, GLenum pname, GLuint *params);
extern void (APIENTRYP glClearBufferiv)(GLenum buffer, GLint drawbuffer, const GLint *value);
extern void (APIENTRYP glClearBufferuiv)(GLenum buffer, GLint drawbuffer, const GLuint *value);
extern void (APIENTRYP glClearBufferfv)(GLenum buffer, GLint drawbuffer, const GLfloat *value);
extern void (APIENTRYP glClearBufferfi)(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
extern const GLubyte *(APIENTRYP glGetStringi)(GLenum name, GLuint index);
extern GLboolean(APIENTRYP glIsRenderbuffer)(GLuint renderbuffer);
extern void (APIENTRYP glBindRenderbuffer)(GLenum target, GLuint renderbuffer);
extern void (APIENTRYP glDeleteRenderbuffers)(GLsizei n, const GLuint *renderbuffers);
extern void (APIENTRYP glGenRenderbuffers)(GLsizei n, GLuint *renderbuffers);
extern void (APIENTRYP glRenderbufferStorage)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
extern void (APIENTRYP glGetRenderbufferParameteriv)(GLenum target, GLenum pname, GLint *params);
extern GLboolean(APIENTRYP glIsFramebuffer)(GLuint framebuffer);
extern void (APIENTRYP glBindFramebuffer)(GLenum target, GLuint framebuffer);
extern void (APIENTRYP glDeleteFramebuffers)(GLsizei n, const GLuint *framebuffers);
extern void (APIENTRYP glGenFramebuffers)(GLsizei n, GLuint *framebuffers);
extern GLenum(APIENTRYP glCheckFramebufferStatus)(GLenum target);
extern void (APIENTRYP glFramebufferTexture1D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
extern void (APIENTRYP glFramebufferTexture2D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
extern void (APIENTRYP glFramebufferTexture3D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
extern void (APIENTRYP glFramebufferRenderbuffer)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
extern void (APIENTRYP glGetFramebufferAttachmentParameteriv)(GLenum target, GLenum attachment, GLenum pname, GLint *params);
extern void (APIENTRYP glGenerateMipmap)(GLenum target);
extern void (APIENTRYP glBlitFramebuffer)(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
extern void (APIENTRYP glRenderbufferStorageMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
extern void (APIENTRYP glFramebufferTextureLayer)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
extern void *(APIENTRYP glMapBufferRange)(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
extern void (APIENTRYP glFlushMappedBufferRange)(GLenum target, GLintptr offset, GLsizeiptr length);
extern void (APIENTRYP glBindVertexArray)(GLuint array);
extern void (APIENTRYP glDeleteVertexArrays)(GLsizei n, const GLuint *arrays);
extern void (APIENTRYP glGenVertexArrays)(GLsizei n, GLuint *arrays);
extern GLboolean(APIENTRYP glIsVertexArray)(GLuint array);

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
typedef void (APIENTRYP PFNGLDRAWARRAYSINSTANCEDPROC) (GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDPROC) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount);
typedef void (APIENTRYP PFNGLTEXBUFFERPROC) (GLenum target, GLenum internalformat, GLuint buffer);
typedef void (APIENTRYP PFNGLPRIMITIVERESTARTINDEXPROC) (GLuint index);
typedef void (APIENTRYP PFNGLCOPYBUFFERSUBDATAPROC) (GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLGETUNIFORMINDICESPROC) (GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices);
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMSIVPROC) (GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMNAMEPROC) (GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName);
typedef GLuint(APIENTRYP PFNGLGETUNIFORMBLOCKINDEXPROC) (GLuint program, const GLchar *uniformBlockName);
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMBLOCKIVPROC) (GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC) (GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName);
typedef void (APIENTRYP PFNGLUNIFORMBLOCKBINDINGPROC) (GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
extern void (APIENTRYP glDrawArraysInstanced)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
extern void (APIENTRYP glDrawElementsInstanced)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount);
extern void (APIENTRYP glTexBuffer)(GLenum target, GLenum internalformat, GLuint buffer);
extern void (APIENTRYP glPrimitiveRestartIndex)(GLuint index);
extern void (APIENTRYP glCopyBufferSubData)(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
extern void (APIENTRYP glGetUniformIndices)(GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices);
extern void (APIENTRYP glGetActiveUniformsiv)(GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params);
extern void (APIENTRYP glGetActiveUniformName)(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName);
extern GLuint(APIENTRYP glGetUniformBlockIndex)(GLuint program, const GLchar *uniformBlockName);
extern void (APIENTRYP glGetActiveUniformBlockiv)(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params);
extern void (APIENTRYP glGetActiveUniformBlockName)(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName);
extern void (APIENTRYP glUniformBlockBinding)(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);

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
typedef void (APIENTRYP PFNGLDRAWELEMENTSBASEVERTEXPROC) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex);
typedef void (APIENTRYP PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex);
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex);
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC) (GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount, const GLint *basevertex);
typedef void (APIENTRYP PFNGLPROVOKINGVERTEXPROC) (GLenum mode);
typedef GLsync(APIENTRYP PFNGLFENCESYNCPROC) (GLenum condition, GLbitfield flags);
typedef GLboolean(APIENTRYP PFNGLISSYNCPROC) (GLsync sync);
typedef void (APIENTRYP PFNGLDELETESYNCPROC) (GLsync sync);
typedef GLenum(APIENTRYP PFNGLCLIENTWAITSYNCPROC) (GLsync sync, GLbitfield flags, GLuint64 timeout);
typedef void (APIENTRYP PFNGLWAITSYNCPROC) (GLsync sync, GLbitfield flags, GLuint64 timeout);
typedef void (APIENTRYP PFNGLGETINTEGER64VPROC) (GLenum pname, GLint64 *data);
typedef void (APIENTRYP PFNGLGETSYNCIVPROC) (GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values);
typedef void (APIENTRYP PFNGLGETINTEGER64I_VPROC) (GLenum target, GLuint index, GLint64 *data);
typedef void (APIENTRYP PFNGLGETBUFFERPARAMETERI64VPROC) (GLenum target, GLenum pname, GLint64 *params);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTUREPROC) (GLenum target, GLenum attachment, GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLTEXIMAGE2DMULTISAMPLEPROC) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFNGLTEXIMAGE3DMULTISAMPLEPROC) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFNGLGETMULTISAMPLEFVPROC) (GLenum pname, GLuint index, GLfloat *val);
typedef void (APIENTRYP PFNGLSAMPLEMASKIPROC) (GLuint maskNumber, GLbitfield mask);
extern void (APIENTRYP glDrawElementsBaseVertex)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex);
extern void (APIENTRYP glDrawRangeElementsBaseVertex)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex);
extern void (APIENTRYP glDrawElementsInstancedBaseVertex)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex);
extern void (APIENTRYP glMultiDrawElementsBaseVertex)(GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount, const GLint *basevertex);
extern void (APIENTRYP glProvokingVertex)(GLenum mode);
extern GLsync(APIENTRYP glFenceSync)(GLenum condition, GLbitfield flags);
extern GLboolean(APIENTRYP glIsSync)(GLsync sync);
extern void (APIENTRYP glDeleteSync)(GLsync sync);
extern GLenum(APIENTRYP glClientWaitSync)(GLsync sync, GLbitfield flags, GLuint64 timeout);
extern void (APIENTRYP glWaitSync)(GLsync sync, GLbitfield flags, GLuint64 timeout);
extern void (APIENTRYP glGetInteger64v)(GLenum pname, GLint64 *data);
extern void (APIENTRYP glGetSynciv)(GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values);
extern void (APIENTRYP glGetInteger64i_v)(GLenum target, GLuint index, GLint64 *data);
extern void (APIENTRYP glGetBufferParameteri64v)(GLenum target, GLenum pname, GLint64 *params);
extern void (APIENTRYP glFramebufferTexture)(GLenum target, GLenum attachment, GLuint texture, GLint level);
extern void (APIENTRYP glTexImage2DMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
extern void (APIENTRYP glTexImage3DMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
extern void (APIENTRYP glGetMultisamplefv)(GLenum pname, GLuint index, GLfloat *val);
extern void (APIENTRYP glSampleMaski)(GLuint maskNumber, GLbitfield mask);

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
typedef void (APIENTRYP PFNGLBINDFRAGDATALOCATIONINDEXEDPROC) (GLuint program, GLuint colorNumber, GLuint index, const GLchar *name);
typedef GLint(APIENTRYP PFNGLGETFRAGDATAINDEXPROC) (GLuint program, const GLchar *name);
typedef void (APIENTRYP PFNGLGENSAMPLERSPROC) (GLsizei count, GLuint *samplers);
typedef void (APIENTRYP PFNGLDELETESAMPLERSPROC) (GLsizei count, const GLuint *samplers);
typedef GLboolean(APIENTRYP PFNGLISSAMPLERPROC) (GLuint sampler);
typedef void (APIENTRYP PFNGLBINDSAMPLERPROC) (GLuint unit, GLuint sampler);
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIPROC) (GLuint sampler, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIVPROC) (GLuint sampler, GLenum pname, const GLint *param);
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERFPROC) (GLuint sampler, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERFVPROC) (GLuint sampler, GLenum pname, const GLfloat *param);
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIIVPROC) (GLuint sampler, GLenum pname, const GLint *param);
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIUIVPROC) (GLuint sampler, GLenum pname, const GLuint *param);
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIVPROC) (GLuint sampler, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIIVPROC) (GLuint sampler, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERFVPROC) (GLuint sampler, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIUIVPROC) (GLuint sampler, GLenum pname, GLuint *params);
typedef void (APIENTRYP PFNGLQUERYCOUNTERPROC) (GLuint id, GLenum target);
typedef void (APIENTRYP PFNGLGETQUERYOBJECTI64VPROC) (GLuint id, GLenum pname, GLint64 *params);
typedef void (APIENTRYP PFNGLGETQUERYOBJECTUI64VPROC) (GLuint id, GLenum pname, GLuint64 *params);
typedef void (APIENTRYP PFNGLVERTEXATTRIBDIVISORPROC) (GLuint index, GLuint divisor);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP1UIPROC) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP1UIVPROC) (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP2UIPROC) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP2UIVPROC) (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP3UIPROC) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP3UIVPROC) (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP4UIPROC) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP4UIVPROC) (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
extern void (APIENTRYP glBindFragDataLocationIndexed)(GLuint program, GLuint colorNumber, GLuint index, const GLchar *name);
extern GLint(APIENTRYP glGetFragDataIndex)(GLuint program, const GLchar *name);
extern void (APIENTRYP glGenSamplers)(GLsizei count, GLuint *samplers);
extern void (APIENTRYP glDeleteSamplers)(GLsizei count, const GLuint *samplers);
extern GLboolean(APIENTRYP glIsSampler)(GLuint sampler);
extern void (APIENTRYP glBindSampler)(GLuint unit, GLuint sampler);
extern void (APIENTRYP glSamplerParameteri)(GLuint sampler, GLenum pname, GLint param);
extern void (APIENTRYP glSamplerParameteriv)(GLuint sampler, GLenum pname, const GLint *param);
extern void (APIENTRYP glSamplerParameterf)(GLuint sampler, GLenum pname, GLfloat param);
extern void (APIENTRYP glSamplerParameterfv)(GLuint sampler, GLenum pname, const GLfloat *param);
extern void (APIENTRYP glSamplerParameterIiv)(GLuint sampler, GLenum pname, const GLint *param);
extern void (APIENTRYP glSamplerParameterIuiv)(GLuint sampler, GLenum pname, const GLuint *param);
extern void (APIENTRYP glGetSamplerParameteriv)(GLuint sampler, GLenum pname, GLint *params);
extern void (APIENTRYP glGetSamplerParameterIiv)(GLuint sampler, GLenum pname, GLint *params);
extern void (APIENTRYP glGetSamplerParameterfv)(GLuint sampler, GLenum pname, GLfloat *params);
extern void (APIENTRYP glGetSamplerParameterIuiv)(GLuint sampler, GLenum pname, GLuint *params);
extern void (APIENTRYP glQueryCounter)(GLuint id, GLenum target);
extern void (APIENTRYP glGetQueryObjecti64v)(GLuint id, GLenum pname, GLint64 *params);
extern void (APIENTRYP glGetQueryObjectui64v)(GLuint id, GLenum pname, GLuint64 *params);
extern void (APIENTRYP glVertexAttribDivisor)(GLuint index, GLuint divisor);
extern void (APIENTRYP glVertexAttribP1ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
extern void (APIENTRYP glVertexAttribP1uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
extern void (APIENTRYP glVertexAttribP2ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
extern void (APIENTRYP glVertexAttribP2uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
extern void (APIENTRYP glVertexAttribP3ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
extern void (APIENTRYP glVertexAttribP3uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
extern void (APIENTRYP glVertexAttribP4ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
extern void (APIENTRYP glVertexAttribP4uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint *value);

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
typedef void (APIENTRYP PFNGLMINSAMPLESHADINGPROC) (GLfloat value);
typedef void (APIENTRYP PFNGLBLENDEQUATIONIPROC) (GLuint buf, GLenum mode);
typedef void (APIENTRYP PFNGLBLENDEQUATIONSEPARATEIPROC) (GLuint buf, GLenum modeRGB, GLenum modeAlpha);
typedef void (APIENTRYP PFNGLBLENDFUNCIPROC) (GLuint buf, GLenum src, GLenum dst);
typedef void (APIENTRYP PFNGLBLENDFUNCSEPARATEIPROC) (GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
typedef void (APIENTRYP PFNGLDRAWARRAYSINDIRECTPROC) (GLenum mode, const void *indirect);
typedef void (APIENTRYP PFNGLDRAWELEMENTSINDIRECTPROC) (GLenum mode, GLenum type, const void *indirect);
typedef void (APIENTRYP PFNGLUNIFORM1DPROC) (GLint location, GLdouble x);
typedef void (APIENTRYP PFNGLUNIFORM2DPROC) (GLint location, GLdouble x, GLdouble y);
typedef void (APIENTRYP PFNGLUNIFORM3DPROC) (GLint location, GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLUNIFORM4DPROC) (GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFNGLUNIFORM1DVPROC) (GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORM2DVPROC) (GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORM3DVPROC) (GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORM4DVPROC) (GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X3DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X4DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X2DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X4DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X2DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X3DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLGETUNIFORMDVPROC) (GLuint program, GLint location, GLdouble *params);
typedef GLint(APIENTRYP PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC) (GLuint program, GLenum shadertype, const GLchar *name);
typedef GLuint(APIENTRYP PFNGLGETSUBROUTINEINDEXPROC) (GLuint program, GLenum shadertype, const GLchar *name);
typedef void (APIENTRYP PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC) (GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint *values);
typedef void (APIENTRYP PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC) (GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name);
typedef void (APIENTRYP PFNGLGETACTIVESUBROUTINENAMEPROC) (GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name);
typedef void (APIENTRYP PFNGLUNIFORMSUBROUTINESUIVPROC) (GLenum shadertype, GLsizei count, const GLuint *indices);
typedef void (APIENTRYP PFNGLGETUNIFORMSUBROUTINEUIVPROC) (GLenum shadertype, GLint location, GLuint *params);
typedef void (APIENTRYP PFNGLGETPROGRAMSTAGEIVPROC) (GLuint program, GLenum shadertype, GLenum pname, GLint *values);
typedef void (APIENTRYP PFNGLPATCHPARAMETERIPROC) (GLenum pname, GLint value);
typedef void (APIENTRYP PFNGLPATCHPARAMETERFVPROC) (GLenum pname, const GLfloat *values);
typedef void (APIENTRYP PFNGLBINDTRANSFORMFEEDBACKPROC) (GLenum target, GLuint id);
typedef void (APIENTRYP PFNGLDELETETRANSFORMFEEDBACKSPROC) (GLsizei n, const GLuint *ids);
typedef void (APIENTRYP PFNGLGENTRANSFORMFEEDBACKSPROC) (GLsizei n, GLuint *ids);
typedef GLboolean(APIENTRYP PFNGLISTRANSFORMFEEDBACKPROC) (GLuint id);
typedef void (APIENTRYP PFNGLPAUSETRANSFORMFEEDBACKPROC) (void);
typedef void (APIENTRYP PFNGLRESUMETRANSFORMFEEDBACKPROC) (void);
typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKPROC) (GLenum mode, GLuint id);
typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC) (GLenum mode, GLuint id, GLuint stream);
typedef void (APIENTRYP PFNGLBEGINQUERYINDEXEDPROC) (GLenum target, GLuint index, GLuint id);
typedef void (APIENTRYP PFNGLENDQUERYINDEXEDPROC) (GLenum target, GLuint index);
typedef void (APIENTRYP PFNGLGETQUERYINDEXEDIVPROC) (GLenum target, GLuint index, GLenum pname, GLint *params);
extern void (APIENTRYP glMinSampleShading)(GLfloat value);
extern void (APIENTRYP glBlendEquationi)(GLuint buf, GLenum mode);
extern void (APIENTRYP glBlendEquationSeparatei)(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
extern void (APIENTRYP glBlendFunci)(GLuint buf, GLenum src, GLenum dst);
extern void (APIENTRYP glBlendFuncSeparatei)(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
extern void (APIENTRYP glDrawArraysIndirect)(GLenum mode, const void *indirect);
extern void (APIENTRYP glDrawElementsIndirect)(GLenum mode, GLenum type, const void *indirect);
extern void (APIENTRYP glUniform1d)(GLint location, GLdouble x);
extern void (APIENTRYP glUniform2d)(GLint location, GLdouble x, GLdouble y);
extern void (APIENTRYP glUniform3d)(GLint location, GLdouble x, GLdouble y, GLdouble z);
extern void (APIENTRYP glUniform4d)(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
extern void (APIENTRYP glUniform1dv)(GLint location, GLsizei count, const GLdouble *value);
extern void (APIENTRYP glUniform2dv)(GLint location, GLsizei count, const GLdouble *value);
extern void (APIENTRYP glUniform3dv)(GLint location, GLsizei count, const GLdouble *value);
extern void (APIENTRYP glUniform4dv)(GLint location, GLsizei count, const GLdouble *value);
extern void (APIENTRYP glUniformMatrix2dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
extern void (APIENTRYP glUniformMatrix3dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
extern void (APIENTRYP glUniformMatrix4dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
extern void (APIENTRYP glUniformMatrix2x3dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
extern void (APIENTRYP glUniformMatrix2x4dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
extern void (APIENTRYP glUniformMatrix3x2dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
extern void (APIENTRYP glUniformMatrix3x4dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
extern void (APIENTRYP glUniformMatrix4x2dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
extern void (APIENTRYP glUniformMatrix4x3dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
extern void (APIENTRYP glGetUniformdv)(GLuint program, GLint location, GLdouble *params);
extern GLint(APIENTRYP glGetSubroutineUniformLocation)(GLuint program, GLenum shadertype, const GLchar *name);
extern GLuint(APIENTRYP glGetSubroutineIndex)(GLuint program, GLenum shadertype, const GLchar *name);
extern void (APIENTRYP glGetActiveSubroutineUniformiv)(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint *values);
extern void (APIENTRYP glGetActiveSubroutineUniformName)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name);
extern void (APIENTRYP glGetActiveSubroutineName)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name);
extern void (APIENTRYP glUniformSubroutinesuiv)(GLenum shadertype, GLsizei count, const GLuint *indices);
extern void (APIENTRYP glGetUniformSubroutineuiv)(GLenum shadertype, GLint location, GLuint *params);
extern void (APIENTRYP glGetProgramStageiv)(GLuint program, GLenum shadertype, GLenum pname, GLint *values);
extern void (APIENTRYP glPatchParameteri)(GLenum pname, GLint value);
extern void (APIENTRYP glPatchParameterfv)(GLenum pname, const GLfloat *values);
extern void (APIENTRYP glBindTransformFeedback)(GLenum target, GLuint id);
extern void (APIENTRYP glDeleteTransformFeedbacks)(GLsizei n, const GLuint *ids);
extern void (APIENTRYP glGenTransformFeedbacks)(GLsizei n, GLuint *ids);
extern GLboolean(APIENTRYP glIsTransformFeedback)(GLuint id);
extern void (APIENTRYP glPauseTransformFeedback)(void);
extern void (APIENTRYP glResumeTransformFeedback)(void);
extern void (APIENTRYP glDrawTransformFeedback)(GLenum mode, GLuint id);
extern void (APIENTRYP glDrawTransformFeedbackStream)(GLenum mode, GLuint id, GLuint stream);
extern void (APIENTRYP glBeginQueryIndexed)(GLenum target, GLuint index, GLuint id);
extern void (APIENTRYP glEndQueryIndexed)(GLenum target, GLuint index);
extern void (APIENTRYP glGetQueryIndexediv)(GLenum target, GLuint index, GLenum pname, GLint *params);

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
typedef void (APIENTRYP PFNGLRELEASESHADERCOMPILERPROC) (void);
typedef void (APIENTRYP PFNGLSHADERBINARYPROC) (GLsizei count, const GLuint *shaders, GLenum binaryformat, const void *binary, GLsizei length);
typedef void (APIENTRYP PFNGLGETSHADERPRECISIONFORMATPROC) (GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision);
typedef void (APIENTRYP PFNGLDEPTHRANGEFPROC) (GLfloat n, GLfloat f);
typedef void (APIENTRYP PFNGLCLEARDEPTHFPROC) (GLfloat d);
typedef void (APIENTRYP PFNGLGETPROGRAMBINARYPROC) (GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary);
typedef void (APIENTRYP PFNGLPROGRAMBINARYPROC) (GLuint program, GLenum binaryFormat, const void *binary, GLsizei length);
typedef void (APIENTRYP PFNGLPROGRAMPARAMETERIPROC) (GLuint program, GLenum pname, GLint value);
typedef void (APIENTRYP PFNGLUSEPROGRAMSTAGESPROC) (GLuint pipeline, GLbitfield stages, GLuint program);
typedef void (APIENTRYP PFNGLACTIVESHADERPROGRAMPROC) (GLuint pipeline, GLuint program);
typedef GLuint(APIENTRYP PFNGLCREATESHADERPROGRAMVPROC) (GLenum type, GLsizei count, const GLchar *const*strings);
typedef void (APIENTRYP PFNGLBINDPROGRAMPIPELINEPROC) (GLuint pipeline);
typedef void (APIENTRYP PFNGLDELETEPROGRAMPIPELINESPROC) (GLsizei n, const GLuint *pipelines);
typedef void (APIENTRYP PFNGLGENPROGRAMPIPELINESPROC) (GLsizei n, GLuint *pipelines);
typedef GLboolean(APIENTRYP PFNGLISPROGRAMPIPELINEPROC) (GLuint pipeline);
typedef void (APIENTRYP PFNGLGETPROGRAMPIPELINEIVPROC) (GLuint pipeline, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1IPROC) (GLuint program, GLint location, GLint v0);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1IVPROC) (GLuint program, GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1FPROC) (GLuint program, GLint location, GLfloat v0);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1FVPROC) (GLuint program, GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1DPROC) (GLuint program, GLint location, GLdouble v0);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1DVPROC) (GLuint program, GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UIPROC) (GLuint program, GLint location, GLuint v0);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UIVPROC) (GLuint program, GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2IPROC) (GLuint program, GLint location, GLint v0, GLint v1);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2IVPROC) (GLuint program, GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2FPROC) (GLuint program, GLint location, GLfloat v0, GLfloat v1);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2FVPROC) (GLuint program, GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2DPROC) (GLuint program, GLint location, GLdouble v0, GLdouble v1);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2DVPROC) (GLuint program, GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UIPROC) (GLuint program, GLint location, GLuint v0, GLuint v1);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UIVPROC) (GLuint program, GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3IPROC) (GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3IVPROC) (GLuint program, GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3FPROC) (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3FVPROC) (GLuint program, GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3DPROC) (GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3DVPROC) (GLuint program, GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UIPROC) (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UIVPROC) (GLuint program, GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4IPROC) (GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4IVPROC) (GLuint program, GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4FPROC) (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4FVPROC) (GLuint program, GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4DPROC) (GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4DVPROC) (GLuint program, GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UIPROC) (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UIVPROC) (GLuint program, GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLVALIDATEPROGRAMPIPELINEPROC) (GLuint pipeline);
typedef void (APIENTRYP PFNGLGETPROGRAMPIPELINEINFOLOGPROC) (GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1DPROC) (GLuint index, GLdouble x);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL2DPROC) (GLuint index, GLdouble x, GLdouble y);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL3DPROC) (GLuint index, GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL4DPROC) (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1DVPROC) (GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL2DVPROC) (GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL3DVPROC) (GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL4DVPROC) (GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBLPOINTERPROC) (GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBLDVPROC) (GLuint index, GLenum pname, GLdouble *params);
typedef void (APIENTRYP PFNGLVIEWPORTARRAYVPROC) (GLuint first, GLsizei count, const GLfloat *v);
typedef void (APIENTRYP PFNGLVIEWPORTINDEXEDFPROC) (GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
typedef void (APIENTRYP PFNGLVIEWPORTINDEXEDFVPROC) (GLuint index, const GLfloat *v);
typedef void (APIENTRYP PFNGLSCISSORARRAYVPROC) (GLuint first, GLsizei count, const GLint *v);
typedef void (APIENTRYP PFNGLSCISSORINDEXEDPROC) (GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLSCISSORINDEXEDVPROC) (GLuint index, const GLint *v);
typedef void (APIENTRYP PFNGLDEPTHRANGEARRAYVPROC) (GLuint first, GLsizei count, const GLdouble *v);
typedef void (APIENTRYP PFNGLDEPTHRANGEINDEXEDPROC) (GLuint index, GLdouble n, GLdouble f);
typedef void (APIENTRYP PFNGLGETFLOATI_VPROC) (GLenum target, GLuint index, GLfloat *data);
typedef void (APIENTRYP PFNGLGETDOUBLEI_VPROC) (GLenum target, GLuint index, GLdouble *data);
extern void (APIENTRYP glReleaseShaderCompiler)(void);
extern void (APIENTRYP glShaderBinary)(GLsizei count, const GLuint *shaders, GLenum binaryformat, const void *binary, GLsizei length);
extern void (APIENTRYP glGetShaderPrecisionFormat)(GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision);
extern void (APIENTRYP glDepthRangef)(GLfloat n, GLfloat f);
extern void (APIENTRYP glClearDepthf)(GLfloat d);
extern void (APIENTRYP glGetProgramBinary)(GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary);
extern void (APIENTRYP glProgramBinary)(GLuint program, GLenum binaryFormat, const void *binary, GLsizei length);
extern void (APIENTRYP glProgramParameteri)(GLuint program, GLenum pname, GLint value);
extern void (APIENTRYP glUseProgramStages)(GLuint pipeline, GLbitfield stages, GLuint program);
extern void (APIENTRYP glActiveShaderProgram)(GLuint pipeline, GLuint program);
extern GLuint(APIENTRYP glCreateShaderProgramv)(GLenum type, GLsizei count, const GLchar *const*strings);
extern void (APIENTRYP glBindProgramPipeline)(GLuint pipeline);
extern void (APIENTRYP glDeleteProgramPipelines)(GLsizei n, const GLuint *pipelines);
extern void (APIENTRYP glGenProgramPipelines)(GLsizei n, GLuint *pipelines);
extern GLboolean(APIENTRYP glIsProgramPipeline)(GLuint pipeline);
extern void (APIENTRYP glGetProgramPipelineiv)(GLuint pipeline, GLenum pname, GLint *params);
extern void (APIENTRYP glProgramUniform1i)(GLuint program, GLint location, GLint v0);
extern void (APIENTRYP glProgramUniform1iv)(GLuint program, GLint location, GLsizei count, const GLint *value);
extern void (APIENTRYP glProgramUniform1f)(GLuint program, GLint location, GLfloat v0);
extern void (APIENTRYP glProgramUniform1fv)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
extern void (APIENTRYP glProgramUniform1d)(GLuint program, GLint location, GLdouble v0);
extern void (APIENTRYP glProgramUniform1dv)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
extern void (APIENTRYP glProgramUniform1ui)(GLuint program, GLint location, GLuint v0);
extern void (APIENTRYP glProgramUniform1uiv)(GLuint program, GLint location, GLsizei count, const GLuint *value);
extern void (APIENTRYP glProgramUniform2i)(GLuint program, GLint location, GLint v0, GLint v1);
extern void (APIENTRYP glProgramUniform2iv)(GLuint program, GLint location, GLsizei count, const GLint *value);
extern void (APIENTRYP glProgramUniform2f)(GLuint program, GLint location, GLfloat v0, GLfloat v1);
extern void (APIENTRYP glProgramUniform2fv)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
extern void (APIENTRYP glProgramUniform2d)(GLuint program, GLint location, GLdouble v0, GLdouble v1);
extern void (APIENTRYP glProgramUniform2dv)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
extern void (APIENTRYP glProgramUniform2ui)(GLuint program, GLint location, GLuint v0, GLuint v1);
extern void (APIENTRYP glProgramUniform2uiv)(GLuint program, GLint location, GLsizei count, const GLuint *value);
extern void (APIENTRYP glProgramUniform3i)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
extern void (APIENTRYP glProgramUniform3iv)(GLuint program, GLint location, GLsizei count, const GLint *value);
extern void (APIENTRYP glProgramUniform3f)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
extern void (APIENTRYP glProgramUniform3fv)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
extern void (APIENTRYP glProgramUniform3d)(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2);
extern void (APIENTRYP glProgramUniform3dv)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
extern void (APIENTRYP glProgramUniform3ui)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
extern void (APIENTRYP glProgramUniform3uiv)(GLuint program, GLint location, GLsizei count, const GLuint *value);
extern void (APIENTRYP glProgramUniform4i)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
extern void (APIENTRYP glProgramUniform4iv)(GLuint program, GLint location, GLsizei count, const GLint *value);
extern void (APIENTRYP glProgramUniform4f)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
extern void (APIENTRYP glProgramUniform4fv)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
extern void (APIENTRYP glProgramUniform4d)(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
extern void (APIENTRYP glProgramUniform4dv)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
extern void (APIENTRYP glProgramUniform4ui)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
extern void (APIENTRYP glProgramUniform4uiv)(GLuint program, GLint location, GLsizei count, const GLuint *value);
extern void (APIENTRYP glProgramUniformMatrix2fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
extern void (APIENTRYP glProgramUniformMatrix3fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
extern void (APIENTRYP glProgramUniformMatrix4fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
extern void (APIENTRYP glProgramUniformMatrix2dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
extern void (APIENTRYP glProgramUniformMatrix3dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
extern void (APIENTRYP glProgramUniformMatrix4dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
extern void (APIENTRYP glProgramUniformMatrix2x3fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
extern void (APIENTRYP glProgramUniformMatrix3x2fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
extern void (APIENTRYP glProgramUniformMatrix2x4fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
extern void (APIENTRYP glProgramUniformMatrix4x2fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
extern void (APIENTRYP glProgramUniformMatrix3x4fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
extern void (APIENTRYP glProgramUniformMatrix4x3fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
extern void (APIENTRYP glProgramUniformMatrix2x3dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
extern void (APIENTRYP glProgramUniformMatrix3x2dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
extern void (APIENTRYP glProgramUniformMatrix2x4dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
extern void (APIENTRYP glProgramUniformMatrix4x2dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
extern void (APIENTRYP glProgramUniformMatrix3x4dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
extern void (APIENTRYP glProgramUniformMatrix4x3dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
extern void (APIENTRYP glValidateProgramPipeline)(GLuint pipeline);
extern void (APIENTRYP glGetProgramPipelineInfoLog)(GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
extern void (APIENTRYP glVertexAttribL1d)(GLuint index, GLdouble x);
extern void (APIENTRYP glVertexAttribL2d)(GLuint index, GLdouble x, GLdouble y);
extern void (APIENTRYP glVertexAttribL3d)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
extern void (APIENTRYP glVertexAttribL4d)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
extern void (APIENTRYP glVertexAttribL1dv)(GLuint index, const GLdouble *v);
extern void (APIENTRYP glVertexAttribL2dv)(GLuint index, const GLdouble *v);
extern void (APIENTRYP glVertexAttribL3dv)(GLuint index, const GLdouble *v);
extern void (APIENTRYP glVertexAttribL4dv)(GLuint index, const GLdouble *v);
extern void (APIENTRYP glVertexAttribLPointer)(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
extern void (APIENTRYP glGetVertexAttribLdv)(GLuint index, GLenum pname, GLdouble *params);
extern void (APIENTRYP glViewportArrayv)(GLuint first, GLsizei count, const GLfloat *v);
extern void (APIENTRYP glViewportIndexedf)(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
extern void (APIENTRYP glViewportIndexedfv)(GLuint index, const GLfloat *v);
extern void (APIENTRYP glScissorArrayv)(GLuint first, GLsizei count, const GLint *v);
extern void (APIENTRYP glScissorIndexed)(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
extern void (APIENTRYP glScissorIndexedv)(GLuint index, const GLint *v);
extern void (APIENTRYP glDepthRangeArrayv)(GLuint first, GLsizei count, const GLdouble *v);
extern void (APIENTRYP glDepthRangeIndexed)(GLuint index, GLdouble n, GLdouble f);
extern void (APIENTRYP glGetFloati_v)(GLenum target, GLuint index, GLfloat *data);
extern void (APIENTRYP glGetDoublei_v)(GLenum target, GLuint index, GLdouble *data);

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
typedef void (APIENTRYP PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC) (GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLuint baseinstance);
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
typedef void (APIENTRYP PFNGLGETINTERNALFORMATIVPROC) (GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint *params);
typedef void (APIENTRYP PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC) (GLuint program, GLuint bufferIndex, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLBINDIMAGETEXTUREPROC) (GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
typedef void (APIENTRYP PFNGLMEMORYBARRIERPROC) (GLbitfield barriers);
typedef void (APIENTRYP PFNGLTEXSTORAGE1DPROC) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
typedef void (APIENTRYP PFNGLTEXSTORAGE2DPROC) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLTEXSTORAGE3DPROC) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC) (GLenum mode, GLuint id, GLsizei instancecount);
typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC) (GLenum mode, GLuint id, GLuint stream, GLsizei instancecount);
extern void (APIENTRYP glDrawArraysInstancedBaseInstance)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
extern void (APIENTRYP glDrawElementsInstancedBaseInstance)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLuint baseinstance);
extern void (APIENTRYP glDrawElementsInstancedBaseVertexBaseInstance)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
extern void (APIENTRYP glGetInternalformativ)(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint *params);
extern void (APIENTRYP glGetActiveAtomicCounterBufferiv)(GLuint program, GLuint bufferIndex, GLenum pname, GLint *params);
extern void (APIENTRYP glBindImageTexture)(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
extern void (APIENTRYP glMemoryBarrier)(GLbitfield barriers);
extern void (APIENTRYP glTexStorage1D)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
extern void (APIENTRYP glTexStorage2D)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
extern void (APIENTRYP glTexStorage3D)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
extern void (APIENTRYP glDrawTransformFeedbackInstanced)(GLenum mode, GLuint id, GLsizei instancecount);
extern void (APIENTRYP glDrawTransformFeedbackStreamInstanced)(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount);

typedef void (APIENTRY  *GLDEBUGPROC)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam);
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
typedef void (APIENTRYP PFNGLCLEARBUFFERDATAPROC) (GLenum target, GLenum internalformat, GLenum format, GLenum type, const void *data);
typedef void (APIENTRYP PFNGLCLEARBUFFERSUBDATAPROC) (GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
typedef void (APIENTRYP PFNGLDISPATCHCOMPUTEPROC) (GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
typedef void (APIENTRYP PFNGLDISPATCHCOMPUTEINDIRECTPROC) (GLintptr indirect);
typedef void (APIENTRYP PFNGLCOPYIMAGESUBDATAPROC) (GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
typedef void (APIENTRYP PFNGLFRAMEBUFFERPARAMETERIPROC) (GLenum target, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLGETFRAMEBUFFERPARAMETERIVPROC) (GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETINTERNALFORMATI64VPROC) (GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64 *params);
typedef void (APIENTRYP PFNGLINVALIDATETEXSUBIMAGEPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth);
typedef void (APIENTRYP PFNGLINVALIDATETEXIMAGEPROC) (GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLINVALIDATEBUFFERSUBDATAPROC) (GLuint buffer, GLintptr offset, GLsizeiptr length);
typedef void (APIENTRYP PFNGLINVALIDATEBUFFERDATAPROC) (GLuint buffer);
typedef void (APIENTRYP PFNGLINVALIDATEFRAMEBUFFERPROC) (GLenum target, GLsizei numAttachments, const GLenum *attachments);
typedef void (APIENTRYP PFNGLINVALIDATESUBFRAMEBUFFERPROC) (GLenum target, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTPROC) (GLenum mode, const void *indirect, GLsizei drawcount, GLsizei stride);
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTPROC) (GLenum mode, GLenum type, const void *indirect, GLsizei drawcount, GLsizei stride);
typedef void (APIENTRYP PFNGLGETPROGRAMINTERFACEIVPROC) (GLuint program, GLenum programInterface, GLenum pname, GLint *params);
typedef GLuint(APIENTRYP PFNGLGETPROGRAMRESOURCEINDEXPROC) (GLuint program, GLenum programInterface, const GLchar *name);
typedef void (APIENTRYP PFNGLGETPROGRAMRESOURCENAMEPROC) (GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name);
typedef void (APIENTRYP PFNGLGETPROGRAMRESOURCEIVPROC) (GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei bufSize, GLsizei *length, GLint *params);
typedef GLint(APIENTRYP PFNGLGETPROGRAMRESOURCELOCATIONPROC) (GLuint program, GLenum programInterface, const GLchar *name);
typedef GLint(APIENTRYP PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC) (GLuint program, GLenum programInterface, const GLchar *name);
typedef void (APIENTRYP PFNGLSHADERSTORAGEBLOCKBINDINGPROC) (GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
typedef void (APIENTRYP PFNGLTEXBUFFERRANGEPROC) (GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLTEXSTORAGE2DMULTISAMPLEPROC) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFNGLTEXSTORAGE3DMULTISAMPLEPROC) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFNGLTEXTUREVIEWPROC) (GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
typedef void (APIENTRYP PFNGLBINDVERTEXBUFFERPROC) (GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
typedef void (APIENTRYP PFNGLVERTEXATTRIBFORMATPROC) (GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLVERTEXATTRIBIFORMATPROC) (GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLVERTEXATTRIBLFORMATPROC) (GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLVERTEXATTRIBBINDINGPROC) (GLuint attribindex, GLuint bindingindex);
typedef void (APIENTRYP PFNGLVERTEXBINDINGDIVISORPROC) (GLuint bindingindex, GLuint divisor);
typedef void (APIENTRYP PFNGLDEBUGMESSAGECONTROLPROC) (GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
typedef void (APIENTRYP PFNGLDEBUGMESSAGEINSERTPROC) (GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf);
typedef void (APIENTRYP PFNGLDEBUGMESSAGECALLBACKPROC) (GLDEBUGPROC callback, const void *userParam);
typedef GLuint(APIENTRYP PFNGLGETDEBUGMESSAGELOGPROC) (GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog);
typedef void (APIENTRYP PFNGLPUSHDEBUGGROUPPROC) (GLenum source, GLuint id, GLsizei length, const GLchar *message);
typedef void (APIENTRYP PFNGLPOPDEBUGGROUPPROC) (void);
typedef void (APIENTRYP PFNGLOBJECTLABELPROC) (GLenum identifier, GLuint name, GLsizei length, const GLchar *label);
typedef void (APIENTRYP PFNGLGETOBJECTLABELPROC) (GLenum identifier, GLuint name, GLsizei bufSize, GLsizei *length, GLchar *label);
typedef void (APIENTRYP PFNGLOBJECTPTRLABELPROC) (const void *ptr, GLsizei length, const GLchar *label);
typedef void (APIENTRYP PFNGLGETOBJECTPTRLABELPROC) (const void *ptr, GLsizei bufSize, GLsizei *length, GLchar *label);
extern void (APIENTRYP glClearBufferData)(GLenum target, GLenum internalformat, GLenum format, GLenum type, const void *data);
extern void (APIENTRYP glClearBufferSubData)(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
extern void (APIENTRYP glDispatchCompute)(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
extern void (APIENTRYP glDispatchComputeIndirect)(GLintptr indirect);
extern void (APIENTRYP glCopyImageSubData)(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
extern void (APIENTRYP glFramebufferParameteri)(GLenum target, GLenum pname, GLint param);
extern void (APIENTRYP glGetFramebufferParameteriv)(GLenum target, GLenum pname, GLint *params);
extern void (APIENTRYP glGetInternalformati64v)(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64 *params);
extern void (APIENTRYP glInvalidateTexSubImage)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth);
extern void (APIENTRYP glInvalidateTexImage)(GLuint texture, GLint level);
extern void (APIENTRYP glInvalidateBufferSubData)(GLuint buffer, GLintptr offset, GLsizeiptr length);
extern void (APIENTRYP glInvalidateBufferData)(GLuint buffer);
extern void (APIENTRYP glInvalidateFramebuffer)(GLenum target, GLsizei numAttachments, const GLenum *attachments);
extern void (APIENTRYP glInvalidateSubFramebuffer)(GLenum target, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
extern void (APIENTRYP glMultiDrawArraysIndirect)(GLenum mode, const void *indirect, GLsizei drawcount, GLsizei stride);
extern void (APIENTRYP glMultiDrawElementsIndirect)(GLenum mode, GLenum type, const void *indirect, GLsizei drawcount, GLsizei stride);
extern void (APIENTRYP glGetProgramInterfaceiv)(GLuint program, GLenum programInterface, GLenum pname, GLint *params);
extern GLuint(APIENTRYP glGetProgramResourceIndex)(GLuint program, GLenum programInterface, const GLchar *name);
extern void (APIENTRYP glGetProgramResourceName)(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name);
extern void (APIENTRYP glGetProgramResourceiv)(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei bufSize, GLsizei *length, GLint *params);
extern GLint(APIENTRYP glGetProgramResourceLocation)(GLuint program, GLenum programInterface, const GLchar *name);
extern GLint(APIENTRYP glGetProgramResourceLocationIndex)(GLuint program, GLenum programInterface, const GLchar *name);
extern void (APIENTRYP glShaderStorageBlockBinding)(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
extern void (APIENTRYP glTexBufferRange)(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
extern void (APIENTRYP glTexStorage2DMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
extern void (APIENTRYP glTexStorage3DMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
extern void (APIENTRYP glTextureView)(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
extern void (APIENTRYP glBindVertexBuffer)(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
extern void (APIENTRYP glVertexAttribFormat)(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
extern void (APIENTRYP glVertexAttribIFormat)(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
extern void (APIENTRYP glVertexAttribLFormat)(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
extern void (APIENTRYP glVertexAttribBinding)(GLuint attribindex, GLuint bindingindex);
extern void (APIENTRYP glVertexBindingDivisor)(GLuint bindingindex, GLuint divisor);
extern void (APIENTRYP glDebugMessageControl)(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
extern void (APIENTRYP glDebugMessageInsert)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf);
extern void (APIENTRYP glDebugMessageCallback)(GLDEBUGPROC callback, const void *userParam);
extern GLuint(APIENTRYP glGetDebugMessageLog)(GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog);
extern void (APIENTRYP glPushDebugGroup)(GLenum source, GLuint id, GLsizei length, const GLchar *message);
extern void (APIENTRYP glPopDebugGroup)(void);
extern void (APIENTRYP glObjectLabel)(GLenum identifier, GLuint name, GLsizei length, const GLchar *label);
extern void (APIENTRYP glGetObjectLabel)(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei *length, GLchar *label);
extern void (APIENTRYP glObjectPtrLabel)(const void *ptr, GLsizei length, const GLchar *label);
extern void (APIENTRYP glGetObjectPtrLabel)(const void *ptr, GLsizei bufSize, GLsizei *length, GLchar *label);

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
typedef void (APIENTRYP PFNGLBUFFERSTORAGEPROC) (GLenum target, GLsizeiptr size, const void *data, GLbitfield flags);
typedef void (APIENTRYP PFNGLCLEARTEXIMAGEPROC) (GLuint texture, GLint level, GLenum format, GLenum type, const void *data);
typedef void (APIENTRYP PFNGLCLEARTEXSUBIMAGEPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *data);
typedef void (APIENTRYP PFNGLBINDBUFFERSBASEPROC) (GLenum target, GLuint first, GLsizei count, const GLuint *buffers);
typedef void (APIENTRYP PFNGLBINDBUFFERSRANGEPROC) (GLenum target, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizeiptr *sizes);
typedef void (APIENTRYP PFNGLBINDTEXTURESPROC) (GLuint first, GLsizei count, const GLuint *textures);
typedef void (APIENTRYP PFNGLBINDSAMPLERSPROC) (GLuint first, GLsizei count, const GLuint *samplers);
typedef void (APIENTRYP PFNGLBINDIMAGETEXTURESPROC) (GLuint first, GLsizei count, const GLuint *textures);
typedef void (APIENTRYP PFNGLBINDVERTEXBUFFERSPROC) (GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);
extern void (APIENTRYP glBufferStorage)(GLenum target, GLsizeiptr size, const void *data, GLbitfield flags);
extern void (APIENTRYP glClearTexImage)(GLuint texture, GLint level, GLenum format, GLenum type, const void *data);
extern void (APIENTRYP glClearTexSubImage)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *data);
extern void (APIENTRYP glBindBuffersBase)(GLenum target, GLuint first, GLsizei count, const GLuint *buffers);
extern void (APIENTRYP glBindBuffersRange)(GLenum target, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizeiptr *sizes);
extern void (APIENTRYP glBindTextures)(GLuint first, GLsizei count, const GLuint *textures);
extern void (APIENTRYP glBindSamplers)(GLuint first, GLsizei count, const GLuint *samplers);
extern void (APIENTRYP glBindImageTextures)(GLuint first, GLsizei count, const GLuint *textures);
extern void (APIENTRYP glBindVertexBuffers)(GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);

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
typedef void (APIENTRYP PFNGLCLIPCONTROLPROC) (GLenum origin, GLenum depth);
typedef void (APIENTRYP PFNGLCREATETRANSFORMFEEDBACKSPROC) (GLsizei n, GLuint *ids);
typedef void (APIENTRYP PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC) (GLuint xfb, GLuint index, GLuint buffer);
typedef void (APIENTRYP PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC) (GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKIVPROC) (GLuint xfb, GLenum pname, GLint *param);
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKI_VPROC) (GLuint xfb, GLenum pname, GLuint index, GLint *param);
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKI64_VPROC) (GLuint xfb, GLenum pname, GLuint index, GLint64 *param);
typedef void (APIENTRYP PFNGLCREATEBUFFERSPROC) (GLsizei n, GLuint *buffers);
typedef void (APIENTRYP PFNGLNAMEDBUFFERSTORAGEPROC) (GLuint buffer, GLsizeiptr size, const void *data, GLbitfield flags);
typedef void (APIENTRYP PFNGLNAMEDBUFFERDATAPROC) (GLuint buffer, GLsizeiptr size, const void *data, GLenum usage);
typedef void (APIENTRYP PFNGLNAMEDBUFFERSUBDATAPROC) (GLuint buffer, GLintptr offset, GLsizeiptr size, const void *data);
typedef void (APIENTRYP PFNGLCOPYNAMEDBUFFERSUBDATAPROC) (GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLCLEARNAMEDBUFFERDATAPROC) (GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void *data);
typedef void (APIENTRYP PFNGLCLEARNAMEDBUFFERSUBDATAPROC) (GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
typedef void *(APIENTRYP PFNGLMAPNAMEDBUFFERPROC) (GLuint buffer, GLenum access);
typedef void *(APIENTRYP PFNGLMAPNAMEDBUFFERRANGEPROC) (GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
typedef GLboolean(APIENTRYP PFNGLUNMAPNAMEDBUFFERPROC) (GLuint buffer);
typedef void (APIENTRYP PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC) (GLuint buffer, GLintptr offset, GLsizeiptr length);
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPARAMETERIVPROC) (GLuint buffer, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPARAMETERI64VPROC) (GLuint buffer, GLenum pname, GLint64 *params);
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPOINTERVPROC) (GLuint buffer, GLenum pname, void **params);
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERSUBDATAPROC) (GLuint buffer, GLintptr offset, GLsizeiptr size, void *data);
typedef void (APIENTRYP PFNGLCREATEFRAMEBUFFERSPROC) (GLsizei n, GLuint *framebuffers);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC) (GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC) (GLuint framebuffer, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTUREPROC) (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC) (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC) (GLuint framebuffer, GLenum buf);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC) (GLuint framebuffer, GLsizei n, const GLenum *bufs);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC) (GLuint framebuffer, GLenum src);
typedef void (APIENTRYP PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC) (GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments);
typedef void (APIENTRYP PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC) (GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERIVPROC) (GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint *value);
typedef void (APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC) (GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint *value);
typedef void (APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERFVPROC) (GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat *value);
typedef void (APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERFIPROC) (GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
typedef void (APIENTRYP PFNGLBLITNAMEDFRAMEBUFFERPROC) (GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
typedef GLenum(APIENTRYP PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC) (GLuint framebuffer, GLenum target);
typedef void (APIENTRYP PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC) (GLuint framebuffer, GLenum pname, GLint *param);
typedef void (APIENTRYP PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC) (GLuint framebuffer, GLenum attachment, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLCREATERENDERBUFFERSPROC) (GLsizei n, GLuint *renderbuffers);
typedef void (APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEPROC) (GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC) (GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC) (GLuint renderbuffer, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLCREATETEXTURESPROC) (GLenum target, GLsizei n, GLuint *textures);
typedef void (APIENTRYP PFNGLTEXTUREBUFFERPROC) (GLuint texture, GLenum internalformat, GLuint buffer);
typedef void (APIENTRYP PFNGLTEXTUREBUFFERRANGEPROC) (GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE1DPROC) (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE2DPROC) (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE3DPROC) (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC) (GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC) (GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE1DPROC) (GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE2DPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE3DPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC) (GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE1DPROC) (GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE2DPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE3DPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERFPROC) (GLuint texture, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERFVPROC) (GLuint texture, GLenum pname, const GLfloat *param);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIPROC) (GLuint texture, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIIVPROC) (GLuint texture, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIUIVPROC) (GLuint texture, GLenum pname, const GLuint *params);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIVPROC) (GLuint texture, GLenum pname, const GLint *param);
typedef void (APIENTRYP PFNGLGENERATETEXTUREMIPMAPPROC) (GLuint texture);
typedef void (APIENTRYP PFNGLBINDTEXTUREUNITPROC) (GLuint unit, GLuint texture);
typedef void (APIENTRYP PFNGLGETTEXTUREIMAGEPROC) (GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
typedef void (APIENTRYP PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC) (GLuint texture, GLint level, GLsizei bufSize, void *pixels);
typedef void (APIENTRYP PFNGLGETTEXTURELEVELPARAMETERFVPROC) (GLuint texture, GLint level, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETTEXTURELEVELPARAMETERIVPROC) (GLuint texture, GLint level, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERFVPROC) (GLuint texture, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIIVPROC) (GLuint texture, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIUIVPROC) (GLuint texture, GLenum pname, GLuint *params);
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIVPROC) (GLuint texture, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLCREATEVERTEXARRAYSPROC) (GLsizei n, GLuint *arrays);
typedef void (APIENTRYP PFNGLDISABLEVERTEXARRAYATTRIBPROC) (GLuint vaobj, GLuint index);
typedef void (APIENTRYP PFNGLENABLEVERTEXARRAYATTRIBPROC) (GLuint vaobj, GLuint index);
typedef void (APIENTRYP PFNGLVERTEXARRAYELEMENTBUFFERPROC) (GLuint vaobj, GLuint buffer);
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXBUFFERPROC) (GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXBUFFERSPROC) (GLuint vaobj, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);
typedef void (APIENTRYP PFNGLVERTEXARRAYATTRIBBINDINGPROC) (GLuint vaobj, GLuint attribindex, GLuint bindingindex);
typedef void (APIENTRYP PFNGLVERTEXARRAYATTRIBFORMATPROC) (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLVERTEXARRAYATTRIBIFORMATPROC) (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLVERTEXARRAYATTRIBLFORMATPROC) (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLVERTEXARRAYBINDINGDIVISORPROC) (GLuint vaobj, GLuint bindingindex, GLuint divisor);
typedef void (APIENTRYP PFNGLGETVERTEXARRAYIVPROC) (GLuint vaobj, GLenum pname, GLint *param);
typedef void (APIENTRYP PFNGLGETVERTEXARRAYINDEXEDIVPROC) (GLuint vaobj, GLuint index, GLenum pname, GLint *param);
typedef void (APIENTRYP PFNGLGETVERTEXARRAYINDEXED64IVPROC) (GLuint vaobj, GLuint index, GLenum pname, GLint64 *param);
typedef void (APIENTRYP PFNGLCREATESAMPLERSPROC) (GLsizei n, GLuint *samplers);
typedef void (APIENTRYP PFNGLCREATEPROGRAMPIPELINESPROC) (GLsizei n, GLuint *pipelines);
typedef void (APIENTRYP PFNGLCREATEQUERIESPROC) (GLenum target, GLsizei n, GLuint *ids);
typedef void (APIENTRYP PFNGLGETQUERYBUFFEROBJECTI64VPROC) (GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
typedef void (APIENTRYP PFNGLGETQUERYBUFFEROBJECTIVPROC) (GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
typedef void (APIENTRYP PFNGLGETQUERYBUFFEROBJECTUI64VPROC) (GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
typedef void (APIENTRYP PFNGLGETQUERYBUFFEROBJECTUIVPROC) (GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
typedef void (APIENTRYP PFNGLMEMORYBARRIERBYREGIONPROC) (GLbitfield barriers);
typedef void (APIENTRYP PFNGLGETTEXTURESUBIMAGEPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
typedef void (APIENTRYP PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void *pixels);
typedef GLenum(APIENTRYP PFNGLGETGRAPHICSRESETSTATUSPROC) (void);
typedef void (APIENTRYP PFNGLGETNCOMPRESSEDTEXIMAGEPROC) (GLenum target, GLint lod, GLsizei bufSize, void *pixels);
typedef void (APIENTRYP PFNGLGETNTEXIMAGEPROC) (GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
typedef void (APIENTRYP PFNGLGETNUNIFORMDVPROC) (GLuint program, GLint location, GLsizei bufSize, GLdouble *params);
typedef void (APIENTRYP PFNGLGETNUNIFORMFVPROC) (GLuint program, GLint location, GLsizei bufSize, GLfloat *params);
typedef void (APIENTRYP PFNGLGETNUNIFORMIVPROC) (GLuint program, GLint location, GLsizei bufSize, GLint *params);
typedef void (APIENTRYP PFNGLGETNUNIFORMUIVPROC) (GLuint program, GLint location, GLsizei bufSize, GLuint *params);
typedef void (APIENTRYP PFNGLREADNPIXELSPROC) (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data);
typedef void (APIENTRYP PFNGLTEXTUREBARRIERPROC) (void);
extern void (APIENTRYP glClipControl)(GLenum origin, GLenum depth);
extern void (APIENTRYP glCreateTransformFeedbacks)(GLsizei n, GLuint *ids);
extern void (APIENTRYP glTransformFeedbackBufferBase)(GLuint xfb, GLuint index, GLuint buffer);
extern void (APIENTRYP glTransformFeedbackBufferRange)(GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
extern void (APIENTRYP glGetTransformFeedbackiv)(GLuint xfb, GLenum pname, GLint *param);
extern void (APIENTRYP glGetTransformFeedbacki_v)(GLuint xfb, GLenum pname, GLuint index, GLint *param);
extern void (APIENTRYP glGetTransformFeedbacki64_v)(GLuint xfb, GLenum pname, GLuint index, GLint64 *param);
extern void (APIENTRYP glCreateBuffers)(GLsizei n, GLuint *buffers);
extern void (APIENTRYP glNamedBufferStorage)(GLuint buffer, GLsizeiptr size, const void *data, GLbitfield flags);
extern void (APIENTRYP glNamedBufferData)(GLuint buffer, GLsizeiptr size, const void *data, GLenum usage);
extern void (APIENTRYP glNamedBufferSubData)(GLuint buffer, GLintptr offset, GLsizeiptr size, const void *data);
extern void (APIENTRYP glCopyNamedBufferSubData)(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
extern void (APIENTRYP glClearNamedBufferData)(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void *data);
extern void (APIENTRYP glClearNamedBufferSubData)(GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
extern void *(APIENTRYP glMapNamedBuffer)(GLuint buffer, GLenum access);
extern void *(APIENTRYP glMapNamedBufferRange)(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
extern GLboolean(APIENTRYP glUnmapNamedBuffer)(GLuint buffer);
extern void (APIENTRYP glFlushMappedNamedBufferRange)(GLuint buffer, GLintptr offset, GLsizeiptr length);
extern void (APIENTRYP glGetNamedBufferParameteriv)(GLuint buffer, GLenum pname, GLint *params);
extern void (APIENTRYP glGetNamedBufferParameteri64v)(GLuint buffer, GLenum pname, GLint64 *params);
extern void (APIENTRYP glGetNamedBufferPointerv)(GLuint buffer, GLenum pname, void **params);
extern void (APIENTRYP glGetNamedBufferSubData)(GLuint buffer, GLintptr offset, GLsizeiptr size, void *data);
extern void (APIENTRYP glCreateFramebuffers)(GLsizei n, GLuint *framebuffers);
extern void (APIENTRYP glNamedFramebufferRenderbuffer)(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
extern void (APIENTRYP glNamedFramebufferParameteri)(GLuint framebuffer, GLenum pname, GLint param);
extern void (APIENTRYP glNamedFramebufferTexture)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
extern void (APIENTRYP glNamedFramebufferTextureLayer)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
extern void (APIENTRYP glNamedFramebufferDrawBuffer)(GLuint framebuffer, GLenum buf);
extern void (APIENTRYP glNamedFramebufferDrawBuffers)(GLuint framebuffer, GLsizei n, const GLenum *bufs);
extern void (APIENTRYP glNamedFramebufferReadBuffer)(GLuint framebuffer, GLenum src);
extern void (APIENTRYP glInvalidateNamedFramebufferData)(GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments);
extern void (APIENTRYP glInvalidateNamedFramebufferSubData)(GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
extern void (APIENTRYP glClearNamedFramebufferiv)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint *value);
extern void (APIENTRYP glClearNamedFramebufferuiv)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint *value);
extern void (APIENTRYP glClearNamedFramebufferfv)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat *value);
extern void (APIENTRYP glClearNamedFramebufferfi)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
extern void (APIENTRYP glBlitNamedFramebuffer)(GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
extern GLenum(APIENTRYP glCheckNamedFramebufferStatus)(GLuint framebuffer, GLenum target);
extern void (APIENTRYP glGetNamedFramebufferParameteriv)(GLuint framebuffer, GLenum pname, GLint *param);
extern void (APIENTRYP glGetNamedFramebufferAttachmentParameteriv)(GLuint framebuffer, GLenum attachment, GLenum pname, GLint *params);
extern void (APIENTRYP glCreateRenderbuffers)(GLsizei n, GLuint *renderbuffers);
extern void (APIENTRYP glNamedRenderbufferStorage)(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
extern void (APIENTRYP glNamedRenderbufferStorageMultisample)(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
extern void (APIENTRYP glGetNamedRenderbufferParameteriv)(GLuint renderbuffer, GLenum pname, GLint *params);
extern void (APIENTRYP glCreateTextures)(GLenum target, GLsizei n, GLuint *textures);
extern void (APIENTRYP glTextureBuffer)(GLuint texture, GLenum internalformat, GLuint buffer);
extern void (APIENTRYP glTextureBufferRange)(GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
extern void (APIENTRYP glTextureStorage1D)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width);
extern void (APIENTRYP glTextureStorage2D)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
extern void (APIENTRYP glTextureStorage3D)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
extern void (APIENTRYP glTextureStorage2DMultisample)(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
extern void (APIENTRYP glTextureStorage3DMultisample)(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
extern void (APIENTRYP glTextureSubImage1D)(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
extern void (APIENTRYP glTextureSubImage2D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
extern void (APIENTRYP glTextureSubImage3D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
extern void (APIENTRYP glCompressedTextureSubImage1D)(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
extern void (APIENTRYP glCompressedTextureSubImage2D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
extern void (APIENTRYP glCompressedTextureSubImage3D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
extern void (APIENTRYP glCopyTextureSubImage1D)(GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
extern void (APIENTRYP glCopyTextureSubImage2D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
extern void (APIENTRYP glCopyTextureSubImage3D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
extern void (APIENTRYP glTextureParameterf)(GLuint texture, GLenum pname, GLfloat param);
extern void (APIENTRYP glTextureParameterfv)(GLuint texture, GLenum pname, const GLfloat *param);
extern void (APIENTRYP glTextureParameteri)(GLuint texture, GLenum pname, GLint param);
extern void (APIENTRYP glTextureParameterIiv)(GLuint texture, GLenum pname, const GLint *params);
extern void (APIENTRYP glTextureParameterIuiv)(GLuint texture, GLenum pname, const GLuint *params);
extern void (APIENTRYP glTextureParameteriv)(GLuint texture, GLenum pname, const GLint *param);
extern void (APIENTRYP glGenerateTextureMipmap)(GLuint texture);
extern void (APIENTRYP glBindTextureUnit)(GLuint unit, GLuint texture);
extern void (APIENTRYP glGetTextureImage)(GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
extern void (APIENTRYP glGetCompressedTextureImage)(GLuint texture, GLint level, GLsizei bufSize, void *pixels);
extern void (APIENTRYP glGetTextureLevelParameterfv)(GLuint texture, GLint level, GLenum pname, GLfloat *params);
extern void (APIENTRYP glGetTextureLevelParameteriv)(GLuint texture, GLint level, GLenum pname, GLint *params);
extern void (APIENTRYP glGetTextureParameterfv)(GLuint texture, GLenum pname, GLfloat *params);
extern void (APIENTRYP glGetTextureParameterIiv)(GLuint texture, GLenum pname, GLint *params);
extern void (APIENTRYP glGetTextureParameterIuiv)(GLuint texture, GLenum pname, GLuint *params);
extern void (APIENTRYP glGetTextureParameteriv)(GLuint texture, GLenum pname, GLint *params);
extern void (APIENTRYP glCreateVertexArrays)(GLsizei n, GLuint *arrays);
extern void (APIENTRYP glDisableVertexArrayAttrib)(GLuint vaobj, GLuint index);
extern void (APIENTRYP glEnableVertexArrayAttrib)(GLuint vaobj, GLuint index);
extern void (APIENTRYP glVertexArrayElementBuffer)(GLuint vaobj, GLuint buffer);
extern void (APIENTRYP glVertexArrayVertexBuffer)(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
extern void (APIENTRYP glVertexArrayVertexBuffers)(GLuint vaobj, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);
extern void (APIENTRYP glVertexArrayAttribBinding)(GLuint vaobj, GLuint attribindex, GLuint bindingindex);
extern void (APIENTRYP glVertexArrayAttribFormat)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
extern void (APIENTRYP glVertexArrayAttribIFormat)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
extern void (APIENTRYP glVertexArrayAttribLFormat)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
extern void (APIENTRYP glVertexArrayBindingDivisor)(GLuint vaobj, GLuint bindingindex, GLuint divisor);
extern void (APIENTRYP glGetVertexArrayiv)(GLuint vaobj, GLenum pname, GLint *param);
extern void (APIENTRYP glGetVertexArrayIndexediv)(GLuint vaobj, GLuint index, GLenum pname, GLint *param);
extern void (APIENTRYP glGetVertexArrayIndexed64iv)(GLuint vaobj, GLuint index, GLenum pname, GLint64 *param);
extern void (APIENTRYP glCreateSamplers)(GLsizei n, GLuint *samplers);
extern void (APIENTRYP glCreateProgramPipelines)(GLsizei n, GLuint *pipelines);
extern void (APIENTRYP glCreateQueries)(GLenum target, GLsizei n, GLuint *ids);
extern void (APIENTRYP glGetQueryBufferObjecti64v)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
extern void (APIENTRYP glGetQueryBufferObjectiv)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
extern void (APIENTRYP glGetQueryBufferObjectui64v)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
extern void (APIENTRYP glGetQueryBufferObjectuiv)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
extern void (APIENTRYP glMemoryBarrierByRegion)(GLbitfield barriers);
extern void (APIENTRYP glGetTextureSubImage)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
extern void (APIENTRYP glGetCompressedTextureSubImage)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void *pixels);
extern GLenum(APIENTRYP glGetGraphicsResetStatus)(void);
extern void (APIENTRYP glGetnCompressedTexImage)(GLenum target, GLint lod, GLsizei bufSize, void *pixels);
extern void (APIENTRYP glGetnTexImage)(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
extern void (APIENTRYP glGetnUniformdv)(GLuint program, GLint location, GLsizei bufSize, GLdouble *params);
extern void (APIENTRYP glGetnUniformfv)(GLuint program, GLint location, GLsizei bufSize, GLfloat *params);
extern void (APIENTRYP glGetnUniformiv)(GLuint program, GLint location, GLsizei bufSize, GLint *params);
extern void (APIENTRYP glGetnUniformuiv)(GLuint program, GLint location, GLsizei bufSize, GLuint *params);
extern void (APIENTRYP glReadnPixels)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data);
extern void (APIENTRYP glTextureBarrier)(void);

typedef uint64_t GLuint64EXT;
#define GL_UNSIGNED_INT64_ARB             0x140F
typedef GLuint64(APIENTRYP PFNGLGETTEXTUREHANDLEARBPROC) (GLuint texture);
typedef GLuint64(APIENTRYP PFNGLGETTEXTURESAMPLERHANDLEARBPROC) (GLuint texture, GLuint sampler);
typedef void (APIENTRYP PFNGLMAKETEXTUREHANDLERESIDENTARBPROC) (GLuint64 handle);
typedef void (APIENTRYP PFNGLMAKETEXTUREHANDLENONRESIDENTARBPROC) (GLuint64 handle);
typedef GLuint64(APIENTRYP PFNGLGETIMAGEHANDLEARBPROC) (GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format);
typedef void (APIENTRYP PFNGLMAKEIMAGEHANDLERESIDENTARBPROC) (GLuint64 handle, GLenum access);
typedef void (APIENTRYP PFNGLMAKEIMAGEHANDLENONRESIDENTARBPROC) (GLuint64 handle);
typedef void (APIENTRYP PFNGLUNIFORMHANDLEUI64ARBPROC) (GLint location, GLuint64 value);
typedef void (APIENTRYP PFNGLUNIFORMHANDLEUI64VARBPROC) (GLint location, GLsizei count, const GLuint64 *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMHANDLEUI64ARBPROC) (GLuint program, GLint location, GLuint64 value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMHANDLEUI64VARBPROC) (GLuint program, GLint location, GLsizei count, const GLuint64 *values);
typedef GLboolean(APIENTRYP PFNGLISTEXTUREHANDLERESIDENTARBPROC) (GLuint64 handle);
typedef GLboolean(APIENTRYP PFNGLISIMAGEHANDLERESIDENTARBPROC) (GLuint64 handle);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1UI64ARBPROC) (GLuint index, GLuint64EXT x);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1UI64VARBPROC) (GLuint index, const GLuint64EXT *v);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBLUI64VARBPROC) (GLuint index, GLenum pname, GLuint64EXT *params);
extern GLuint64(APIENTRYP glGetTextureHandleARB)(GLuint texture);
extern GLuint64(APIENTRYP glGetTextureSamplerHandleARB)(GLuint texture, GLuint sampler);
extern void (APIENTRYP glMakeTextureHandleResidentARB)(GLuint64 handle);
extern void (APIENTRYP glMakeTextureHandleNonResidentARB)(GLuint64 handle);
extern GLuint64(APIENTRYP glGetImageHandleARB)(GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format);
extern void (APIENTRYP glMakeImageHandleResidentARB)(GLuint64 handle, GLenum access);
extern void (APIENTRYP glMakeImageHandleNonResidentARB)(GLuint64 handle);
extern void (APIENTRYP glUniformHandleui64ARB)(GLint location, GLuint64 value);
extern void (APIENTRYP glUniformHandleui64vARB)(GLint location, GLsizei count, const GLuint64 *value);
extern void (APIENTRYP glProgramUniformHandleui64ARB)(GLuint program, GLint location, GLuint64 value);
extern void (APIENTRYP glProgramUniformHandleui64vARB)(GLuint program, GLint location, GLsizei count, const GLuint64 *values);
extern GLboolean(APIENTRYP glIsTextureHandleResidentARB)(GLuint64 handle);
extern GLboolean(APIENTRYP glIsImageHandleResidentARB)(GLuint64 handle);
extern void (APIENTRYP glVertexAttribL1ui64ARB)(GLuint index, GLuint64EXT x);
extern void (APIENTRYP glVertexAttribL1ui64vARB)(GLuint index, const GLuint64EXT *v);
extern void (APIENTRYP glGetVertexAttribLui64vARB)(GLuint index, GLenum pname, GLuint64EXT *params);

struct _cl_context;
struct _cl_event;
#define GL_SYNC_CL_EVENT_ARB              0x8240
#define GL_SYNC_CL_EVENT_COMPLETE_ARB     0x8241
typedef GLsync(APIENTRYP PFNGLCREATESYNCFROMCLEVENTARBPROC) (struct _cl_context *context, struct _cl_event *event, GLbitfield flags);
extern GLsync(APIENTRYP glCreateSyncFromCLeventARB)(struct _cl_context *context, struct _cl_event *event, GLbitfield flags);

#define GL_MAX_COMPUTE_VARIABLE_GROUP_INVOCATIONS_ARB 0x9344
#define GL_MAX_COMPUTE_FIXED_GROUP_INVOCATIONS_ARB 0x90EB
#define GL_MAX_COMPUTE_VARIABLE_GROUP_SIZE_ARB 0x9345
#define GL_MAX_COMPUTE_FIXED_GROUP_SIZE_ARB 0x91BF
typedef void (APIENTRYP PFNGLDISPATCHCOMPUTEGROUPSIZEARBPROC) (GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z, GLuint group_size_x, GLuint group_size_y, GLuint group_size_z);
extern void (APIENTRYP glDispatchComputeGroupSizeARB)(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z, GLuint group_size_x, GLuint group_size_y, GLuint group_size_z);

typedef void (APIENTRY  *GLDEBUGPROCARB)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam);
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
typedef void (APIENTRYP PFNGLDEBUGMESSAGECONTROLARBPROC) (GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
typedef void (APIENTRYP PFNGLDEBUGMESSAGEINSERTARBPROC) (GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf);
typedef void (APIENTRYP PFNGLDEBUGMESSAGECALLBACKARBPROC) (GLDEBUGPROCARB callback, const void *userParam);
typedef GLuint(APIENTRYP PFNGLGETDEBUGMESSAGELOGARBPROC) (GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog);
extern void (APIENTRYP glDebugMessageControlARB)(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
extern void (APIENTRYP glDebugMessageInsertARB)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf);
extern void (APIENTRYP glDebugMessageCallbackARB)(GLDEBUGPROCARB callback, const void *userParam);
extern GLuint(APIENTRYP glGetDebugMessageLogARB)(GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog);

typedef void (APIENTRYP PFNGLBLENDEQUATIONIARBPROC) (GLuint buf, GLenum mode);
typedef void (APIENTRYP PFNGLBLENDEQUATIONSEPARATEIARBPROC) (GLuint buf, GLenum modeRGB, GLenum modeAlpha);
typedef void (APIENTRYP PFNGLBLENDFUNCIARBPROC) (GLuint buf, GLenum src, GLenum dst);
typedef void (APIENTRYP PFNGLBLENDFUNCSEPARATEIARBPROC) (GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
extern void (APIENTRYP glBlendEquationiARB)(GLuint buf, GLenum mode);
extern void (APIENTRYP glBlendEquationSeparateiARB)(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
extern void (APIENTRYP glBlendFunciARB)(GLuint buf, GLenum src, GLenum dst);
extern void (APIENTRYP glBlendFuncSeparateiARB)(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);

#define GL_BLEND_COLOR                    0x8005
#define GL_BLEND_EQUATION                 0x8009

#define GL_PARAMETER_BUFFER_ARB           0x80EE
#define GL_PARAMETER_BUFFER_BINDING_ARB   0x80EF
typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTCOUNTARBPROC) (GLenum mode, GLintptr indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTARBPROC) (GLenum mode, GLenum type, GLintptr indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
extern void (APIENTRYP glMultiDrawArraysIndirectCountARB)(GLenum mode, GLintptr indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
extern void (APIENTRYP glMultiDrawElementsIndirectCountARB)(GLenum mode, GLenum type, GLintptr indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);

#define GL_SRGB_DECODE_ARB                0x8299

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

#define GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT_ARB 0x00000004
#define GL_LOSE_CONTEXT_ON_RESET_ARB      0x8252
#define GL_GUILTY_CONTEXT_RESET_ARB       0x8253
#define GL_INNOCENT_CONTEXT_RESET_ARB     0x8254
#define GL_UNKNOWN_CONTEXT_RESET_ARB      0x8255
#define GL_RESET_NOTIFICATION_STRATEGY_ARB 0x8256
#define GL_NO_RESET_NOTIFICATION_ARB      0x8261
typedef GLenum(APIENTRYP PFNGLGETGRAPHICSRESETSTATUSARBPROC) (void);
typedef void (APIENTRYP PFNGLGETNTEXIMAGEARBPROC) (GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *img);
typedef void (APIENTRYP PFNGLREADNPIXELSARBPROC) (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data);
typedef void (APIENTRYP PFNGLGETNCOMPRESSEDTEXIMAGEARBPROC) (GLenum target, GLint lod, GLsizei bufSize, void *img);
typedef void (APIENTRYP PFNGLGETNUNIFORMFVARBPROC) (GLuint program, GLint location, GLsizei bufSize, GLfloat *params);
typedef void (APIENTRYP PFNGLGETNUNIFORMIVARBPROC) (GLuint program, GLint location, GLsizei bufSize, GLint *params);
typedef void (APIENTRYP PFNGLGETNUNIFORMUIVARBPROC) (GLuint program, GLint location, GLsizei bufSize, GLuint *params);
typedef void (APIENTRYP PFNGLGETNUNIFORMDVARBPROC) (GLuint program, GLint location, GLsizei bufSize, GLdouble *params);
extern GLenum(APIENTRYP glGetGraphicsResetStatusARB)(void);
extern void (APIENTRYP glGetnTexImageARB)(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *img);
extern void (APIENTRYP glReadnPixelsARB)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data);
extern void (APIENTRYP glGetnCompressedTexImageARB)(GLenum target, GLint lod, GLsizei bufSize, void *img);
extern void (APIENTRYP glGetnUniformfvARB)(GLuint program, GLint location, GLsizei bufSize, GLfloat *params);
extern void (APIENTRYP glGetnUniformivARB)(GLuint program, GLint location, GLsizei bufSize, GLint *params);
extern void (APIENTRYP glGetnUniformuivARB)(GLuint program, GLint location, GLsizei bufSize, GLuint *params);
extern void (APIENTRYP glGetnUniformdvARB)(GLuint program, GLint location, GLsizei bufSize, GLdouble *params);

#define GL_SAMPLE_SHADING_ARB             0x8C36
#define GL_MIN_SAMPLE_SHADING_VALUE_ARB   0x8C37
typedef void (APIENTRYP PFNGLMINSAMPLESHADINGARBPROC) (GLfloat value);
extern void (APIENTRYP glMinSampleShadingARB)(GLfloat value);

#define GL_SHADER_INCLUDE_ARB             0x8DAE
#define GL_NAMED_STRING_LENGTH_ARB        0x8DE9
#define GL_NAMED_STRING_TYPE_ARB          0x8DEA
typedef void (APIENTRYP PFNGLNAMEDSTRINGARBPROC) (GLenum type, GLint namelen, const GLchar *name, GLint stringlen, const GLchar *string);
typedef void (APIENTRYP PFNGLDELETENAMEDSTRINGARBPROC) (GLint namelen, const GLchar *name);
typedef void (APIENTRYP PFNGLCOMPILESHADERINCLUDEARBPROC) (GLuint shader, GLsizei count, const GLchar *const*path, const GLint *length);
typedef GLboolean(APIENTRYP PFNGLISNAMEDSTRINGARBPROC) (GLint namelen, const GLchar *name);
typedef void (APIENTRYP PFNGLGETNAMEDSTRINGARBPROC) (GLint namelen, const GLchar *name, GLsizei bufSize, GLint *stringlen, GLchar *string);
typedef void (APIENTRYP PFNGLGETNAMEDSTRINGIVARBPROC) (GLint namelen, const GLchar *name, GLenum pname, GLint *params);
extern void (APIENTRYP glNamedStringARB)(GLenum type, GLint namelen, const GLchar *name, GLint stringlen, const GLchar *string);
extern void (APIENTRYP glDeleteNamedStringARB)(GLint namelen, const GLchar *name);
extern void (APIENTRYP glCompileShaderIncludeARB)(GLuint shader, GLsizei count, const GLchar *const*path, const GLint *length);
extern GLboolean(APIENTRYP glIsNamedStringARB)(GLint namelen, const GLchar *name);
extern void (APIENTRYP glGetNamedStringARB)(GLint namelen, const GLchar *name, GLsizei bufSize, GLint *stringlen, GLchar *string);
extern void (APIENTRYP glGetNamedStringivARB)(GLint namelen, const GLchar *name, GLenum pname, GLint *params);

#define GL_SPARSE_STORAGE_BIT_ARB         0x0400
#define GL_SPARSE_BUFFER_PAGE_SIZE_ARB    0x82F8
typedef void (APIENTRYP PFNGLBUFFERPAGECOMMITMENTARBPROC) (GLenum target, GLintptr offset, GLsizeiptr size, GLboolean commit);
typedef void (APIENTRYP PFNGLNAMEDBUFFERPAGECOMMITMENTEXTPROC) (GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit);
typedef void (APIENTRYP PFNGLNAMEDBUFFERPAGECOMMITMENTARBPROC) (GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit);
extern void (APIENTRYP glBufferPageCommitmentARB)(GLenum target, GLintptr offset, GLsizeiptr size, GLboolean commit);
extern void (APIENTRYP glNamedBufferPageCommitmentEXT)(GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit);
extern void (APIENTRYP glNamedBufferPageCommitmentARB)(GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit);

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
typedef void (APIENTRYP PFNGLTEXPAGECOMMITMENTARBPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit);
extern void (APIENTRYP glTexPageCommitmentARB)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit);

#define GL_COMPRESSED_RGBA_BPTC_UNORM_ARB 0x8E8C
#define GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM_ARB 0x8E8D
#define GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT_ARB 0x8E8E
#define GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT_ARB 0x8E8F

#define GL_TEXTURE_CUBE_MAP_ARRAY_ARB     0x9009
#define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY_ARB 0x900A
#define GL_PROXY_TEXTURE_CUBE_MAP_ARRAY_ARB 0x900B
#define GL_SAMPLER_CUBE_MAP_ARRAY_ARB     0x900C
#define GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW_ARB 0x900D
#define GL_INT_SAMPLER_CUBE_MAP_ARRAY_ARB 0x900E
#define GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY_ARB 0x900F

#define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET_ARB 0x8E5E
#define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET_ARB 0x8E5F
#define GL_MAX_PROGRAM_TEXTURE_GATHER_COMPONENTS_ARB 0x8F9F

#define GL_TRANSFORM_FEEDBACK_OVERFLOW_ARB 0x82EC
#define GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW_ARB 0x82ED

#define GL_CONTEXT_FLAG_NO_ERROR_BIT_KHR  0x00000008

#define GL_CONTEXT_ROBUST_ACCESS          0x90F3

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

// definitions of function pointers
#ifdef JUSTGL_IMPLEMENTATION
void (APIENTRYP glCullFace)(GLenum mode);
void (APIENTRYP glFrontFace)(GLenum mode);
void (APIENTRYP glHint)(GLenum target, GLenum mode);
void (APIENTRYP glLineWidth)(GLfloat width);
void (APIENTRYP glPointSize)(GLfloat size);
void (APIENTRYP glPolygonMode)(GLenum face, GLenum mode);
void (APIENTRYP glScissor)(GLint x, GLint y, GLsizei width, GLsizei height);
void (APIENTRYP glTexParameterf)(GLenum target, GLenum pname, GLfloat param);
void (APIENTRYP glTexParameterfv)(GLenum target, GLenum pname, const GLfloat *params);
void (APIENTRYP glTexParameteri)(GLenum target, GLenum pname, GLint param);
void (APIENTRYP glTexParameteriv)(GLenum target, GLenum pname, const GLint *params);
void (APIENTRYP glTexImage1D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels);
void (APIENTRYP glTexImage2D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
void (APIENTRYP glDrawBuffer)(GLenum buf);
void (APIENTRYP glClear)(GLbitfield mask);
void (APIENTRYP glClearColor)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
void (APIENTRYP glClearStencil)(GLint s);
void (APIENTRYP glClearDepth)(GLdouble depth);
void (APIENTRYP glStencilMask)(GLuint mask);
void (APIENTRYP glColorMask)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
void (APIENTRYP glDepthMask)(GLboolean flag);
void (APIENTRYP glDisable)(GLenum cap);
void (APIENTRYP glEnable)(GLenum cap);
void (APIENTRYP glFinish)(void);
void (APIENTRYP glFlush)(void);
void (APIENTRYP glBlendFunc)(GLenum sfactor, GLenum dfactor);
void (APIENTRYP glLogicOp)(GLenum opcode);
void (APIENTRYP glStencilFunc)(GLenum func, GLint ref, GLuint mask);
void (APIENTRYP glStencilOp)(GLenum fail, GLenum zfail, GLenum zpass);
void (APIENTRYP glDepthFunc)(GLenum func);
void (APIENTRYP glPixelStoref)(GLenum pname, GLfloat param);
void (APIENTRYP glPixelStorei)(GLenum pname, GLint param);
void (APIENTRYP glReadBuffer)(GLenum src);
void (APIENTRYP glReadPixels)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels);
void (APIENTRYP glGetBooleanv)(GLenum pname, GLboolean *data);
void (APIENTRYP glGetDoublev)(GLenum pname, GLdouble *data);
GLenum(APIENTRYP glGetError)(void);
void (APIENTRYP glGetFloatv)(GLenum pname, GLfloat *data);
void (APIENTRYP glGetIntegerv)(GLenum pname, GLint *data);
const GLubyte *(APIENTRYP glGetString)(GLenum name);
void (APIENTRYP glGetTexImage)(GLenum target, GLint level, GLenum format, GLenum type, void *pixels);
void (APIENTRYP glGetTexParameterfv)(GLenum target, GLenum pname, GLfloat *params);
void (APIENTRYP glGetTexParameteriv)(GLenum target, GLenum pname, GLint *params);
void (APIENTRYP glGetTexLevelParameterfv)(GLenum target, GLint level, GLenum pname, GLfloat *params);
void (APIENTRYP glGetTexLevelParameteriv)(GLenum target, GLint level, GLenum pname, GLint *params);
GLboolean(APIENTRYP glIsEnabled)(GLenum cap);
void (APIENTRYP glDepthRange)(GLdouble near, GLdouble far);
void (APIENTRYP glViewport)(GLint x, GLint y, GLsizei width, GLsizei height);
void (APIENTRYP glDrawArrays)(GLenum mode, GLint first, GLsizei count);
void (APIENTRYP glDrawElements)(GLenum mode, GLsizei count, GLenum type, const void *indices);
void (APIENTRYP glGetPointerv)(GLenum pname, void **params);
void (APIENTRYP glPolygonOffset)(GLfloat factor, GLfloat units);
void (APIENTRYP glCopyTexImage1D)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
void (APIENTRYP glCopyTexImage2D)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
void (APIENTRYP glCopyTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
void (APIENTRYP glCopyTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
void (APIENTRYP glTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
void (APIENTRYP glTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
void (APIENTRYP glBindTexture)(GLenum target, GLuint texture);
void (APIENTRYP glDeleteTextures)(GLsizei n, const GLuint *textures);
void (APIENTRYP glGenTextures)(GLsizei n, GLuint *textures);
GLboolean(APIENTRYP glIsTexture)(GLuint texture);
void (APIENTRYP glDrawRangeElements)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices);
void (APIENTRYP glTexImage3D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
void (APIENTRYP glTexSubImage3D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
void (APIENTRYP glCopyTexSubImage3D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
void (APIENTRYP glActiveTexture)(GLenum texture);
void (APIENTRYP glSampleCoverage)(GLfloat value, GLboolean invert);
void (APIENTRYP glCompressedTexImage3D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data);
void (APIENTRYP glCompressedTexImage2D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data);
void (APIENTRYP glCompressedTexImage1D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data);
void (APIENTRYP glCompressedTexSubImage3D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
void (APIENTRYP glCompressedTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
void (APIENTRYP glCompressedTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
void (APIENTRYP glGetCompressedTexImage)(GLenum target, GLint level, void *img);
void (APIENTRYP glBlendFuncSeparate)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
void (APIENTRYP glMultiDrawArrays)(GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount);
void (APIENTRYP glMultiDrawElements)(GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount);
void (APIENTRYP glPointParameterf)(GLenum pname, GLfloat param);
void (APIENTRYP glPointParameterfv)(GLenum pname, const GLfloat *params);
void (APIENTRYP glPointParameteri)(GLenum pname, GLint param);
void (APIENTRYP glPointParameteriv)(GLenum pname, const GLint *params);
void (APIENTRYP glBlendColor)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
void (APIENTRYP glBlendEquation)(GLenum mode);
void (APIENTRYP glGenQueries)(GLsizei n, GLuint *ids);
void (APIENTRYP glDeleteQueries)(GLsizei n, const GLuint *ids);
GLboolean(APIENTRYP glIsQuery)(GLuint id);
void (APIENTRYP glBeginQuery)(GLenum target, GLuint id);
void (APIENTRYP glEndQuery)(GLenum target);
void (APIENTRYP glGetQueryiv)(GLenum target, GLenum pname, GLint *params);
void (APIENTRYP glGetQueryObjectiv)(GLuint id, GLenum pname, GLint *params);
void (APIENTRYP glGetQueryObjectuiv)(GLuint id, GLenum pname, GLuint *params);
void (APIENTRYP glBindBuffer)(GLenum target, GLuint buffer);
void (APIENTRYP glDeleteBuffers)(GLsizei n, const GLuint *buffers);
void (APIENTRYP glGenBuffers)(GLsizei n, GLuint *buffers);
GLboolean(APIENTRYP glIsBuffer)(GLuint buffer);
void (APIENTRYP glBufferData)(GLenum target, GLsizeiptr size, const void *data, GLenum usage);
void (APIENTRYP glBufferSubData)(GLenum target, GLintptr offset, GLsizeiptr size, const void *data);
void (APIENTRYP glGetBufferSubData)(GLenum target, GLintptr offset, GLsizeiptr size, void *data);
void *(APIENTRYP glMapBuffer)(GLenum target, GLenum access);
GLboolean(APIENTRYP glUnmapBuffer)(GLenum target);
void (APIENTRYP glGetBufferParameteriv)(GLenum target, GLenum pname, GLint *params);
void (APIENTRYP glGetBufferPointerv)(GLenum target, GLenum pname, void **params);
void (APIENTRYP glBlendEquationSeparate)(GLenum modeRGB, GLenum modeAlpha);
void (APIENTRYP glDrawBuffers)(GLsizei n, const GLenum *bufs);
void (APIENTRYP glStencilOpSeparate)(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
void (APIENTRYP glStencilFuncSeparate)(GLenum face, GLenum func, GLint ref, GLuint mask);
void (APIENTRYP glStencilMaskSeparate)(GLenum face, GLuint mask);
void (APIENTRYP glAttachShader)(GLuint program, GLuint shader);
void (APIENTRYP glBindAttribLocation)(GLuint program, GLuint index, const GLchar *name);
void (APIENTRYP glCompileShader)(GLuint shader);
GLuint(APIENTRYP glCreateProgram)(void);
GLuint(APIENTRYP glCreateShader)(GLenum type);
void (APIENTRYP glDeleteProgram)(GLuint program);
void (APIENTRYP glDeleteShader)(GLuint shader);
void (APIENTRYP glDetachShader)(GLuint program, GLuint shader);
void (APIENTRYP glDisableVertexAttribArray)(GLuint index);
void (APIENTRYP glEnableVertexAttribArray)(GLuint index);
void (APIENTRYP glGetActiveAttrib)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
void (APIENTRYP glGetActiveUniform)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
void (APIENTRYP glGetAttachedShaders)(GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders);
GLint(APIENTRYP glGetAttribLocation)(GLuint program, const GLchar *name);
void (APIENTRYP glGetProgramiv)(GLuint program, GLenum pname, GLint *params);
void (APIENTRYP glGetProgramInfoLog)(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
void (APIENTRYP glGetShaderiv)(GLuint shader, GLenum pname, GLint *params);
void (APIENTRYP glGetShaderInfoLog)(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
void (APIENTRYP glGetShaderSource)(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source);
GLint(APIENTRYP glGetUniformLocation)(GLuint program, const GLchar *name);
void (APIENTRYP glGetUniformfv)(GLuint program, GLint location, GLfloat *params);
void (APIENTRYP glGetUniformiv)(GLuint program, GLint location, GLint *params);
void (APIENTRYP glGetVertexAttribdv)(GLuint index, GLenum pname, GLdouble *params);
void (APIENTRYP glGetVertexAttribfv)(GLuint index, GLenum pname, GLfloat *params);
void (APIENTRYP glGetVertexAttribiv)(GLuint index, GLenum pname, GLint *params);
void (APIENTRYP glGetVertexAttribPointerv)(GLuint index, GLenum pname, void **pointer);
GLboolean(APIENTRYP glIsProgram)(GLuint program);
GLboolean(APIENTRYP glIsShader)(GLuint shader);
void (APIENTRYP glLinkProgram)(GLuint program);
void (APIENTRYP glShaderSource)(GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length);
void (APIENTRYP glUseProgram)(GLuint program);
void (APIENTRYP glUniform1f)(GLint location, GLfloat v0);
void (APIENTRYP glUniform2f)(GLint location, GLfloat v0, GLfloat v1);
void (APIENTRYP glUniform3f)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
void (APIENTRYP glUniform4f)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
void (APIENTRYP glUniform1i)(GLint location, GLint v0);
void (APIENTRYP glUniform2i)(GLint location, GLint v0, GLint v1);
void (APIENTRYP glUniform3i)(GLint location, GLint v0, GLint v1, GLint v2);
void (APIENTRYP glUniform4i)(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
void (APIENTRYP glUniform1fv)(GLint location, GLsizei count, const GLfloat *value);
void (APIENTRYP glUniform2fv)(GLint location, GLsizei count, const GLfloat *value);
void (APIENTRYP glUniform3fv)(GLint location, GLsizei count, const GLfloat *value);
void (APIENTRYP glUniform4fv)(GLint location, GLsizei count, const GLfloat *value);
void (APIENTRYP glUniform1iv)(GLint location, GLsizei count, const GLint *value);
void (APIENTRYP glUniform2iv)(GLint location, GLsizei count, const GLint *value);
void (APIENTRYP glUniform3iv)(GLint location, GLsizei count, const GLint *value);
void (APIENTRYP glUniform4iv)(GLint location, GLsizei count, const GLint *value);
void (APIENTRYP glUniformMatrix2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
void (APIENTRYP glUniformMatrix3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
void (APIENTRYP glUniformMatrix4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
void (APIENTRYP glValidateProgram)(GLuint program);
void (APIENTRYP glVertexAttrib1d)(GLuint index, GLdouble x);
void (APIENTRYP glVertexAttrib1dv)(GLuint index, const GLdouble *v);
void (APIENTRYP glVertexAttrib1f)(GLuint index, GLfloat x);
void (APIENTRYP glVertexAttrib1fv)(GLuint index, const GLfloat *v);
void (APIENTRYP glVertexAttrib1s)(GLuint index, GLshort x);
void (APIENTRYP glVertexAttrib1sv)(GLuint index, const GLshort *v);
void (APIENTRYP glVertexAttrib2d)(GLuint index, GLdouble x, GLdouble y);
void (APIENTRYP glVertexAttrib2dv)(GLuint index, const GLdouble *v);
void (APIENTRYP glVertexAttrib2f)(GLuint index, GLfloat x, GLfloat y);
void (APIENTRYP glVertexAttrib2fv)(GLuint index, const GLfloat *v);
void (APIENTRYP glVertexAttrib2s)(GLuint index, GLshort x, GLshort y);
void (APIENTRYP glVertexAttrib2sv)(GLuint index, const GLshort *v);
void (APIENTRYP glVertexAttrib3d)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
void (APIENTRYP glVertexAttrib3dv)(GLuint index, const GLdouble *v);
void (APIENTRYP glVertexAttrib3f)(GLuint index, GLfloat x, GLfloat y, GLfloat z);
void (APIENTRYP glVertexAttrib3fv)(GLuint index, const GLfloat *v);
void (APIENTRYP glVertexAttrib3s)(GLuint index, GLshort x, GLshort y, GLshort z);
void (APIENTRYP glVertexAttrib3sv)(GLuint index, const GLshort *v);
void (APIENTRYP glVertexAttrib4Nbv)(GLuint index, const GLbyte *v);
void (APIENTRYP glVertexAttrib4Niv)(GLuint index, const GLint *v);
void (APIENTRYP glVertexAttrib4Nsv)(GLuint index, const GLshort *v);
void (APIENTRYP glVertexAttrib4Nub)(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
void (APIENTRYP glVertexAttrib4Nubv)(GLuint index, const GLubyte *v);
void (APIENTRYP glVertexAttrib4Nuiv)(GLuint index, const GLuint *v);
void (APIENTRYP glVertexAttrib4Nusv)(GLuint index, const GLushort *v);
void (APIENTRYP glVertexAttrib4bv)(GLuint index, const GLbyte *v);
void (APIENTRYP glVertexAttrib4d)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void (APIENTRYP glVertexAttrib4dv)(GLuint index, const GLdouble *v);
void (APIENTRYP glVertexAttrib4f)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void (APIENTRYP glVertexAttrib4fv)(GLuint index, const GLfloat *v);
void (APIENTRYP glVertexAttrib4iv)(GLuint index, const GLint *v);
void (APIENTRYP glVertexAttrib4s)(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
void (APIENTRYP glVertexAttrib4sv)(GLuint index, const GLshort *v);
void (APIENTRYP glVertexAttrib4ubv)(GLuint index, const GLubyte *v);
void (APIENTRYP glVertexAttrib4uiv)(GLuint index, const GLuint *v);
void (APIENTRYP glVertexAttrib4usv)(GLuint index, const GLushort *v);
void (APIENTRYP glVertexAttribPointer)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);
void (APIENTRYP glUniformMatrix2x3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
void (APIENTRYP glUniformMatrix3x2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
void (APIENTRYP glUniformMatrix2x4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
void (APIENTRYP glUniformMatrix4x2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
void (APIENTRYP glUniformMatrix3x4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
void (APIENTRYP glUniformMatrix4x3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
void (APIENTRYP glColorMaski)(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
void (APIENTRYP glGetBooleani_v)(GLenum target, GLuint index, GLboolean *data);
void (APIENTRYP glGetIntegeri_v)(GLenum target, GLuint index, GLint *data);
void (APIENTRYP glEnablei)(GLenum target, GLuint index);
void (APIENTRYP glDisablei)(GLenum target, GLuint index);
GLboolean(APIENTRYP glIsEnabledi)(GLenum target, GLuint index);
void (APIENTRYP glBeginTransformFeedback)(GLenum primitiveMode);
void (APIENTRYP glEndTransformFeedback)(void);
void (APIENTRYP glBindBufferRange)(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
void (APIENTRYP glBindBufferBase)(GLenum target, GLuint index, GLuint buffer);
void (APIENTRYP glTransformFeedbackVaryings)(GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode);
void (APIENTRYP glGetTransformFeedbackVarying)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
void (APIENTRYP glClampColor)(GLenum target, GLenum clamp);
void (APIENTRYP glBeginConditionalRender)(GLuint id, GLenum mode);
void (APIENTRYP glEndConditionalRender)(void);
void (APIENTRYP glVertexAttribIPointer)(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
void (APIENTRYP glGetVertexAttribIiv)(GLuint index, GLenum pname, GLint *params);
void (APIENTRYP glGetVertexAttribIuiv)(GLuint index, GLenum pname, GLuint *params);
void (APIENTRYP glVertexAttribI1i)(GLuint index, GLint x);
void (APIENTRYP glVertexAttribI2i)(GLuint index, GLint x, GLint y);
void (APIENTRYP glVertexAttribI3i)(GLuint index, GLint x, GLint y, GLint z);
void (APIENTRYP glVertexAttribI4i)(GLuint index, GLint x, GLint y, GLint z, GLint w);
void (APIENTRYP glVertexAttribI1ui)(GLuint index, GLuint x);
void (APIENTRYP glVertexAttribI2ui)(GLuint index, GLuint x, GLuint y);
void (APIENTRYP glVertexAttribI3ui)(GLuint index, GLuint x, GLuint y, GLuint z);
void (APIENTRYP glVertexAttribI4ui)(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
void (APIENTRYP glVertexAttribI1iv)(GLuint index, const GLint *v);
void (APIENTRYP glVertexAttribI2iv)(GLuint index, const GLint *v);
void (APIENTRYP glVertexAttribI3iv)(GLuint index, const GLint *v);
void (APIENTRYP glVertexAttribI4iv)(GLuint index, const GLint *v);
void (APIENTRYP glVertexAttribI1uiv)(GLuint index, const GLuint *v);
void (APIENTRYP glVertexAttribI2uiv)(GLuint index, const GLuint *v);
void (APIENTRYP glVertexAttribI3uiv)(GLuint index, const GLuint *v);
void (APIENTRYP glVertexAttribI4uiv)(GLuint index, const GLuint *v);
void (APIENTRYP glVertexAttribI4bv)(GLuint index, const GLbyte *v);
void (APIENTRYP glVertexAttribI4sv)(GLuint index, const GLshort *v);
void (APIENTRYP glVertexAttribI4ubv)(GLuint index, const GLubyte *v);
void (APIENTRYP glVertexAttribI4usv)(GLuint index, const GLushort *v);
void (APIENTRYP glGetUniformuiv)(GLuint program, GLint location, GLuint *params);
void (APIENTRYP glBindFragDataLocation)(GLuint program, GLuint color, const GLchar *name);
GLint(APIENTRYP glGetFragDataLocation)(GLuint program, const GLchar *name);
void (APIENTRYP glUniform1ui)(GLint location, GLuint v0);
void (APIENTRYP glUniform2ui)(GLint location, GLuint v0, GLuint v1);
void (APIENTRYP glUniform3ui)(GLint location, GLuint v0, GLuint v1, GLuint v2);
void (APIENTRYP glUniform4ui)(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
void (APIENTRYP glUniform1uiv)(GLint location, GLsizei count, const GLuint *value);
void (APIENTRYP glUniform2uiv)(GLint location, GLsizei count, const GLuint *value);
void (APIENTRYP glUniform3uiv)(GLint location, GLsizei count, const GLuint *value);
void (APIENTRYP glUniform4uiv)(GLint location, GLsizei count, const GLuint *value);
void (APIENTRYP glTexParameterIiv)(GLenum target, GLenum pname, const GLint *params);
void (APIENTRYP glTexParameterIuiv)(GLenum target, GLenum pname, const GLuint *params);
void (APIENTRYP glGetTexParameterIiv)(GLenum target, GLenum pname, GLint *params);
void (APIENTRYP glGetTexParameterIuiv)(GLenum target, GLenum pname, GLuint *params);
void (APIENTRYP glClearBufferiv)(GLenum buffer, GLint drawbuffer, const GLint *value);
void (APIENTRYP glClearBufferuiv)(GLenum buffer, GLint drawbuffer, const GLuint *value);
void (APIENTRYP glClearBufferfv)(GLenum buffer, GLint drawbuffer, const GLfloat *value);
void (APIENTRYP glClearBufferfi)(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
const GLubyte *(APIENTRYP glGetStringi)(GLenum name, GLuint index);
GLboolean(APIENTRYP glIsRenderbuffer)(GLuint renderbuffer);
void (APIENTRYP glBindRenderbuffer)(GLenum target, GLuint renderbuffer);
void (APIENTRYP glDeleteRenderbuffers)(GLsizei n, const GLuint *renderbuffers);
void (APIENTRYP glGenRenderbuffers)(GLsizei n, GLuint *renderbuffers);
void (APIENTRYP glRenderbufferStorage)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
void (APIENTRYP glGetRenderbufferParameteriv)(GLenum target, GLenum pname, GLint *params);
GLboolean(APIENTRYP glIsFramebuffer)(GLuint framebuffer);
void (APIENTRYP glBindFramebuffer)(GLenum target, GLuint framebuffer);
void (APIENTRYP glDeleteFramebuffers)(GLsizei n, const GLuint *framebuffers);
void (APIENTRYP glGenFramebuffers)(GLsizei n, GLuint *framebuffers);
GLenum(APIENTRYP glCheckFramebufferStatus)(GLenum target);
void (APIENTRYP glFramebufferTexture1D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
void (APIENTRYP glFramebufferTexture2D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
void (APIENTRYP glFramebufferTexture3D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
void (APIENTRYP glFramebufferRenderbuffer)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
void (APIENTRYP glGetFramebufferAttachmentParameteriv)(GLenum target, GLenum attachment, GLenum pname, GLint *params);
void (APIENTRYP glGenerateMipmap)(GLenum target);
void (APIENTRYP glBlitFramebuffer)(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
void (APIENTRYP glRenderbufferStorageMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
void (APIENTRYP glFramebufferTextureLayer)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
void *(APIENTRYP glMapBufferRange)(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
void (APIENTRYP glFlushMappedBufferRange)(GLenum target, GLintptr offset, GLsizeiptr length);
void (APIENTRYP glBindVertexArray)(GLuint array);
void (APIENTRYP glDeleteVertexArrays)(GLsizei n, const GLuint *arrays);
void (APIENTRYP glGenVertexArrays)(GLsizei n, GLuint *arrays);
GLboolean(APIENTRYP glIsVertexArray)(GLuint array);
void (APIENTRYP glDrawArraysInstanced)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
void (APIENTRYP glDrawElementsInstanced)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount);
void (APIENTRYP glTexBuffer)(GLenum target, GLenum internalformat, GLuint buffer);
void (APIENTRYP glPrimitiveRestartIndex)(GLuint index);
void (APIENTRYP glCopyBufferSubData)(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
void (APIENTRYP glGetUniformIndices)(GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices);
void (APIENTRYP glGetActiveUniformsiv)(GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params);
void (APIENTRYP glGetActiveUniformName)(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName);
GLuint(APIENTRYP glGetUniformBlockIndex)(GLuint program, const GLchar *uniformBlockName);
void (APIENTRYP glGetActiveUniformBlockiv)(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params);
void (APIENTRYP glGetActiveUniformBlockName)(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName);
void (APIENTRYP glUniformBlockBinding)(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
void (APIENTRYP glDrawElementsBaseVertex)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex);
void (APIENTRYP glDrawRangeElementsBaseVertex)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex);
void (APIENTRYP glDrawElementsInstancedBaseVertex)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex);
void (APIENTRYP glMultiDrawElementsBaseVertex)(GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount, const GLint *basevertex);
void (APIENTRYP glProvokingVertex)(GLenum mode);
GLsync(APIENTRYP glFenceSync)(GLenum condition, GLbitfield flags);
GLboolean(APIENTRYP glIsSync)(GLsync sync);
void (APIENTRYP glDeleteSync)(GLsync sync);
GLenum(APIENTRYP glClientWaitSync)(GLsync sync, GLbitfield flags, GLuint64 timeout);
void (APIENTRYP glWaitSync)(GLsync sync, GLbitfield flags, GLuint64 timeout);
void (APIENTRYP glGetInteger64v)(GLenum pname, GLint64 *data);
void (APIENTRYP glGetSynciv)(GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values);
void (APIENTRYP glGetInteger64i_v)(GLenum target, GLuint index, GLint64 *data);
void (APIENTRYP glGetBufferParameteri64v)(GLenum target, GLenum pname, GLint64 *params);
void (APIENTRYP glFramebufferTexture)(GLenum target, GLenum attachment, GLuint texture, GLint level);
void (APIENTRYP glTexImage2DMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
void (APIENTRYP glTexImage3DMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
void (APIENTRYP glGetMultisamplefv)(GLenum pname, GLuint index, GLfloat *val);
void (APIENTRYP glSampleMaski)(GLuint maskNumber, GLbitfield mask);
void (APIENTRYP glBindFragDataLocationIndexed)(GLuint program, GLuint colorNumber, GLuint index, const GLchar *name);
GLint(APIENTRYP glGetFragDataIndex)(GLuint program, const GLchar *name);
void (APIENTRYP glGenSamplers)(GLsizei count, GLuint *samplers);
void (APIENTRYP glDeleteSamplers)(GLsizei count, const GLuint *samplers);
GLboolean(APIENTRYP glIsSampler)(GLuint sampler);
void (APIENTRYP glBindSampler)(GLuint unit, GLuint sampler);
void (APIENTRYP glSamplerParameteri)(GLuint sampler, GLenum pname, GLint param);
void (APIENTRYP glSamplerParameteriv)(GLuint sampler, GLenum pname, const GLint *param);
void (APIENTRYP glSamplerParameterf)(GLuint sampler, GLenum pname, GLfloat param);
void (APIENTRYP glSamplerParameterfv)(GLuint sampler, GLenum pname, const GLfloat *param);
void (APIENTRYP glSamplerParameterIiv)(GLuint sampler, GLenum pname, const GLint *param);
void (APIENTRYP glSamplerParameterIuiv)(GLuint sampler, GLenum pname, const GLuint *param);
void (APIENTRYP glGetSamplerParameteriv)(GLuint sampler, GLenum pname, GLint *params);
void (APIENTRYP glGetSamplerParameterIiv)(GLuint sampler, GLenum pname, GLint *params);
void (APIENTRYP glGetSamplerParameterfv)(GLuint sampler, GLenum pname, GLfloat *params);
void (APIENTRYP glGetSamplerParameterIuiv)(GLuint sampler, GLenum pname, GLuint *params);
void (APIENTRYP glQueryCounter)(GLuint id, GLenum target);
void (APIENTRYP glGetQueryObjecti64v)(GLuint id, GLenum pname, GLint64 *params);
void (APIENTRYP glGetQueryObjectui64v)(GLuint id, GLenum pname, GLuint64 *params);
void (APIENTRYP glVertexAttribDivisor)(GLuint index, GLuint divisor);
void (APIENTRYP glVertexAttribP1ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
void (APIENTRYP glVertexAttribP1uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
void (APIENTRYP glVertexAttribP2ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
void (APIENTRYP glVertexAttribP2uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
void (APIENTRYP glVertexAttribP3ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
void (APIENTRYP glVertexAttribP3uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
void (APIENTRYP glVertexAttribP4ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
void (APIENTRYP glVertexAttribP4uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
void (APIENTRYP glMinSampleShading)(GLfloat value);
void (APIENTRYP glBlendEquationi)(GLuint buf, GLenum mode);
void (APIENTRYP glBlendEquationSeparatei)(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
void (APIENTRYP glBlendFunci)(GLuint buf, GLenum src, GLenum dst);
void (APIENTRYP glBlendFuncSeparatei)(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
void (APIENTRYP glDrawArraysIndirect)(GLenum mode, const void *indirect);
void (APIENTRYP glDrawElementsIndirect)(GLenum mode, GLenum type, const void *indirect);
void (APIENTRYP glUniform1d)(GLint location, GLdouble x);
void (APIENTRYP glUniform2d)(GLint location, GLdouble x, GLdouble y);
void (APIENTRYP glUniform3d)(GLint location, GLdouble x, GLdouble y, GLdouble z);
void (APIENTRYP glUniform4d)(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void (APIENTRYP glUniform1dv)(GLint location, GLsizei count, const GLdouble *value);
void (APIENTRYP glUniform2dv)(GLint location, GLsizei count, const GLdouble *value);
void (APIENTRYP glUniform3dv)(GLint location, GLsizei count, const GLdouble *value);
void (APIENTRYP glUniform4dv)(GLint location, GLsizei count, const GLdouble *value);
void (APIENTRYP glUniformMatrix2dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
void (APIENTRYP glUniformMatrix3dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
void (APIENTRYP glUniformMatrix4dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
void (APIENTRYP glUniformMatrix2x3dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
void (APIENTRYP glUniformMatrix2x4dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
void (APIENTRYP glUniformMatrix3x2dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
void (APIENTRYP glUniformMatrix3x4dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
void (APIENTRYP glUniformMatrix4x2dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
void (APIENTRYP glUniformMatrix4x3dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
void (APIENTRYP glGetUniformdv)(GLuint program, GLint location, GLdouble *params);
GLint(APIENTRYP glGetSubroutineUniformLocation)(GLuint program, GLenum shadertype, const GLchar *name);
GLuint(APIENTRYP glGetSubroutineIndex)(GLuint program, GLenum shadertype, const GLchar *name);
void (APIENTRYP glGetActiveSubroutineUniformiv)(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint *values);
void (APIENTRYP glGetActiveSubroutineUniformName)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name);
void (APIENTRYP glGetActiveSubroutineName)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name);
void (APIENTRYP glUniformSubroutinesuiv)(GLenum shadertype, GLsizei count, const GLuint *indices);
void (APIENTRYP glGetUniformSubroutineuiv)(GLenum shadertype, GLint location, GLuint *params);
void (APIENTRYP glGetProgramStageiv)(GLuint program, GLenum shadertype, GLenum pname, GLint *values);
void (APIENTRYP glPatchParameteri)(GLenum pname, GLint value);
void (APIENTRYP glPatchParameterfv)(GLenum pname, const GLfloat *values);
void (APIENTRYP glBindTransformFeedback)(GLenum target, GLuint id);
void (APIENTRYP glDeleteTransformFeedbacks)(GLsizei n, const GLuint *ids);
void (APIENTRYP glGenTransformFeedbacks)(GLsizei n, GLuint *ids);
GLboolean(APIENTRYP glIsTransformFeedback)(GLuint id);
void (APIENTRYP glPauseTransformFeedback)(void);
void (APIENTRYP glResumeTransformFeedback)(void);
void (APIENTRYP glDrawTransformFeedback)(GLenum mode, GLuint id);
void (APIENTRYP glDrawTransformFeedbackStream)(GLenum mode, GLuint id, GLuint stream);
void (APIENTRYP glBeginQueryIndexed)(GLenum target, GLuint index, GLuint id);
void (APIENTRYP glEndQueryIndexed)(GLenum target, GLuint index);
void (APIENTRYP glGetQueryIndexediv)(GLenum target, GLuint index, GLenum pname, GLint *params);
void (APIENTRYP glReleaseShaderCompiler)(void);
void (APIENTRYP glShaderBinary)(GLsizei count, const GLuint *shaders, GLenum binaryformat, const void *binary, GLsizei length);
void (APIENTRYP glGetShaderPrecisionFormat)(GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision);
void (APIENTRYP glDepthRangef)(GLfloat n, GLfloat f);
void (APIENTRYP glClearDepthf)(GLfloat d);
void (APIENTRYP glGetProgramBinary)(GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary);
void (APIENTRYP glProgramBinary)(GLuint program, GLenum binaryFormat, const void *binary, GLsizei length);
void (APIENTRYP glProgramParameteri)(GLuint program, GLenum pname, GLint value);
void (APIENTRYP glUseProgramStages)(GLuint pipeline, GLbitfield stages, GLuint program);
void (APIENTRYP glActiveShaderProgram)(GLuint pipeline, GLuint program);
GLuint(APIENTRYP glCreateShaderProgramv)(GLenum type, GLsizei count, const GLchar *const*strings);
void (APIENTRYP glBindProgramPipeline)(GLuint pipeline);
void (APIENTRYP glDeleteProgramPipelines)(GLsizei n, const GLuint *pipelines);
void (APIENTRYP glGenProgramPipelines)(GLsizei n, GLuint *pipelines);
GLboolean(APIENTRYP glIsProgramPipeline)(GLuint pipeline);
void (APIENTRYP glGetProgramPipelineiv)(GLuint pipeline, GLenum pname, GLint *params);
void (APIENTRYP glProgramUniform1i)(GLuint program, GLint location, GLint v0);
void (APIENTRYP glProgramUniform1iv)(GLuint program, GLint location, GLsizei count, const GLint *value);
void (APIENTRYP glProgramUniform1f)(GLuint program, GLint location, GLfloat v0);
void (APIENTRYP glProgramUniform1fv)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
void (APIENTRYP glProgramUniform1d)(GLuint program, GLint location, GLdouble v0);
void (APIENTRYP glProgramUniform1dv)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
void (APIENTRYP glProgramUniform1ui)(GLuint program, GLint location, GLuint v0);
void (APIENTRYP glProgramUniform1uiv)(GLuint program, GLint location, GLsizei count, const GLuint *value);
void (APIENTRYP glProgramUniform2i)(GLuint program, GLint location, GLint v0, GLint v1);
void (APIENTRYP glProgramUniform2iv)(GLuint program, GLint location, GLsizei count, const GLint *value);
void (APIENTRYP glProgramUniform2f)(GLuint program, GLint location, GLfloat v0, GLfloat v1);
void (APIENTRYP glProgramUniform2fv)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
void (APIENTRYP glProgramUniform2d)(GLuint program, GLint location, GLdouble v0, GLdouble v1);
void (APIENTRYP glProgramUniform2dv)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
void (APIENTRYP glProgramUniform2ui)(GLuint program, GLint location, GLuint v0, GLuint v1);
void (APIENTRYP glProgramUniform2uiv)(GLuint program, GLint location, GLsizei count, const GLuint *value);
void (APIENTRYP glProgramUniform3i)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
void (APIENTRYP glProgramUniform3iv)(GLuint program, GLint location, GLsizei count, const GLint *value);
void (APIENTRYP glProgramUniform3f)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
void (APIENTRYP glProgramUniform3fv)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
void (APIENTRYP glProgramUniform3d)(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2);
void (APIENTRYP glProgramUniform3dv)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
void (APIENTRYP glProgramUniform3ui)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
void (APIENTRYP glProgramUniform3uiv)(GLuint program, GLint location, GLsizei count, const GLuint *value);
void (APIENTRYP glProgramUniform4i)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
void (APIENTRYP glProgramUniform4iv)(GLuint program, GLint location, GLsizei count, const GLint *value);
void (APIENTRYP glProgramUniform4f)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
void (APIENTRYP glProgramUniform4fv)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
void (APIENTRYP glProgramUniform4d)(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
void (APIENTRYP glProgramUniform4dv)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
void (APIENTRYP glProgramUniform4ui)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
void (APIENTRYP glProgramUniform4uiv)(GLuint program, GLint location, GLsizei count, const GLuint *value);
void (APIENTRYP glProgramUniformMatrix2fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
void (APIENTRYP glProgramUniformMatrix3fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
void (APIENTRYP glProgramUniformMatrix4fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
void (APIENTRYP glProgramUniformMatrix2dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
void (APIENTRYP glProgramUniformMatrix3dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
void (APIENTRYP glProgramUniformMatrix4dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
void (APIENTRYP glProgramUniformMatrix2x3fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
void (APIENTRYP glProgramUniformMatrix3x2fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
void (APIENTRYP glProgramUniformMatrix2x4fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
void (APIENTRYP glProgramUniformMatrix4x2fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
void (APIENTRYP glProgramUniformMatrix3x4fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
void (APIENTRYP glProgramUniformMatrix4x3fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
void (APIENTRYP glProgramUniformMatrix2x3dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
void (APIENTRYP glProgramUniformMatrix3x2dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
void (APIENTRYP glProgramUniformMatrix2x4dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
void (APIENTRYP glProgramUniformMatrix4x2dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
void (APIENTRYP glProgramUniformMatrix3x4dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
void (APIENTRYP glProgramUniformMatrix4x3dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
void (APIENTRYP glValidateProgramPipeline)(GLuint pipeline);
void (APIENTRYP glGetProgramPipelineInfoLog)(GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
void (APIENTRYP glVertexAttribL1d)(GLuint index, GLdouble x);
void (APIENTRYP glVertexAttribL2d)(GLuint index, GLdouble x, GLdouble y);
void (APIENTRYP glVertexAttribL3d)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
void (APIENTRYP glVertexAttribL4d)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void (APIENTRYP glVertexAttribL1dv)(GLuint index, const GLdouble *v);
void (APIENTRYP glVertexAttribL2dv)(GLuint index, const GLdouble *v);
void (APIENTRYP glVertexAttribL3dv)(GLuint index, const GLdouble *v);
void (APIENTRYP glVertexAttribL4dv)(GLuint index, const GLdouble *v);
void (APIENTRYP glVertexAttribLPointer)(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
void (APIENTRYP glGetVertexAttribLdv)(GLuint index, GLenum pname, GLdouble *params);
void (APIENTRYP glViewportArrayv)(GLuint first, GLsizei count, const GLfloat *v);
void (APIENTRYP glViewportIndexedf)(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
void (APIENTRYP glViewportIndexedfv)(GLuint index, const GLfloat *v);
void (APIENTRYP glScissorArrayv)(GLuint first, GLsizei count, const GLint *v);
void (APIENTRYP glScissorIndexed)(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
void (APIENTRYP glScissorIndexedv)(GLuint index, const GLint *v);
void (APIENTRYP glDepthRangeArrayv)(GLuint first, GLsizei count, const GLdouble *v);
void (APIENTRYP glDepthRangeIndexed)(GLuint index, GLdouble n, GLdouble f);
void (APIENTRYP glGetFloati_v)(GLenum target, GLuint index, GLfloat *data);
void (APIENTRYP glGetDoublei_v)(GLenum target, GLuint index, GLdouble *data);
void (APIENTRYP glDrawArraysInstancedBaseInstance)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
void (APIENTRYP glDrawElementsInstancedBaseInstance)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLuint baseinstance);
void (APIENTRYP glDrawElementsInstancedBaseVertexBaseInstance)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
void (APIENTRYP glGetInternalformativ)(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint *params);
void (APIENTRYP glGetActiveAtomicCounterBufferiv)(GLuint program, GLuint bufferIndex, GLenum pname, GLint *params);
void (APIENTRYP glBindImageTexture)(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
void (APIENTRYP glMemoryBarrier)(GLbitfield barriers);
void (APIENTRYP glTexStorage1D)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
void (APIENTRYP glTexStorage2D)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
void (APIENTRYP glTexStorage3D)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
void (APIENTRYP glDrawTransformFeedbackInstanced)(GLenum mode, GLuint id, GLsizei instancecount);
void (APIENTRYP glDrawTransformFeedbackStreamInstanced)(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount);
void (APIENTRYP glClearBufferData)(GLenum target, GLenum internalformat, GLenum format, GLenum type, const void *data);
void (APIENTRYP glClearBufferSubData)(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
void (APIENTRYP glDispatchCompute)(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
void (APIENTRYP glDispatchComputeIndirect)(GLintptr indirect);
void (APIENTRYP glCopyImageSubData)(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
void (APIENTRYP glFramebufferParameteri)(GLenum target, GLenum pname, GLint param);
void (APIENTRYP glGetFramebufferParameteriv)(GLenum target, GLenum pname, GLint *params);
void (APIENTRYP glGetInternalformati64v)(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64 *params);
void (APIENTRYP glInvalidateTexSubImage)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth);
void (APIENTRYP glInvalidateTexImage)(GLuint texture, GLint level);
void (APIENTRYP glInvalidateBufferSubData)(GLuint buffer, GLintptr offset, GLsizeiptr length);
void (APIENTRYP glInvalidateBufferData)(GLuint buffer);
void (APIENTRYP glInvalidateFramebuffer)(GLenum target, GLsizei numAttachments, const GLenum *attachments);
void (APIENTRYP glInvalidateSubFramebuffer)(GLenum target, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
void (APIENTRYP glMultiDrawArraysIndirect)(GLenum mode, const void *indirect, GLsizei drawcount, GLsizei stride);
void (APIENTRYP glMultiDrawElementsIndirect)(GLenum mode, GLenum type, const void *indirect, GLsizei drawcount, GLsizei stride);
void (APIENTRYP glGetProgramInterfaceiv)(GLuint program, GLenum programInterface, GLenum pname, GLint *params);
GLuint(APIENTRYP glGetProgramResourceIndex)(GLuint program, GLenum programInterface, const GLchar *name);
void (APIENTRYP glGetProgramResourceName)(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name);
void (APIENTRYP glGetProgramResourceiv)(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei bufSize, GLsizei *length, GLint *params);
GLint(APIENTRYP glGetProgramResourceLocation)(GLuint program, GLenum programInterface, const GLchar *name);
GLint(APIENTRYP glGetProgramResourceLocationIndex)(GLuint program, GLenum programInterface, const GLchar *name);
void (APIENTRYP glShaderStorageBlockBinding)(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
void (APIENTRYP glTexBufferRange)(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
void (APIENTRYP glTexStorage2DMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
void (APIENTRYP glTexStorage3DMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
void (APIENTRYP glTextureView)(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
void (APIENTRYP glBindVertexBuffer)(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
void (APIENTRYP glVertexAttribFormat)(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
void (APIENTRYP glVertexAttribIFormat)(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
void (APIENTRYP glVertexAttribLFormat)(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
void (APIENTRYP glVertexAttribBinding)(GLuint attribindex, GLuint bindingindex);
void (APIENTRYP glVertexBindingDivisor)(GLuint bindingindex, GLuint divisor);
void (APIENTRYP glDebugMessageControl)(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
void (APIENTRYP glDebugMessageInsert)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf);
void (APIENTRYP glDebugMessageCallback)(GLDEBUGPROC callback, const void *userParam);
GLuint(APIENTRYP glGetDebugMessageLog)(GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog);
void (APIENTRYP glPushDebugGroup)(GLenum source, GLuint id, GLsizei length, const GLchar *message);
void (APIENTRYP glPopDebugGroup)(void);
void (APIENTRYP glObjectLabel)(GLenum identifier, GLuint name, GLsizei length, const GLchar *label);
void (APIENTRYP glGetObjectLabel)(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei *length, GLchar *label);
void (APIENTRYP glObjectPtrLabel)(const void *ptr, GLsizei length, const GLchar *label);
void (APIENTRYP glGetObjectPtrLabel)(const void *ptr, GLsizei bufSize, GLsizei *length, GLchar *label);
void (APIENTRYP glBufferStorage)(GLenum target, GLsizeiptr size, const void *data, GLbitfield flags);
void (APIENTRYP glClearTexImage)(GLuint texture, GLint level, GLenum format, GLenum type, const void *data);
void (APIENTRYP glClearTexSubImage)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *data);
void (APIENTRYP glBindBuffersBase)(GLenum target, GLuint first, GLsizei count, const GLuint *buffers);
void (APIENTRYP glBindBuffersRange)(GLenum target, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizeiptr *sizes);
void (APIENTRYP glBindTextures)(GLuint first, GLsizei count, const GLuint *textures);
void (APIENTRYP glBindSamplers)(GLuint first, GLsizei count, const GLuint *samplers);
void (APIENTRYP glBindImageTextures)(GLuint first, GLsizei count, const GLuint *textures);
void (APIENTRYP glBindVertexBuffers)(GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);
void (APIENTRYP glClipControl)(GLenum origin, GLenum depth);
void (APIENTRYP glCreateTransformFeedbacks)(GLsizei n, GLuint *ids);
void (APIENTRYP glTransformFeedbackBufferBase)(GLuint xfb, GLuint index, GLuint buffer);
void (APIENTRYP glTransformFeedbackBufferRange)(GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
void (APIENTRYP glGetTransformFeedbackiv)(GLuint xfb, GLenum pname, GLint *param);
void (APIENTRYP glGetTransformFeedbacki_v)(GLuint xfb, GLenum pname, GLuint index, GLint *param);
void (APIENTRYP glGetTransformFeedbacki64_v)(GLuint xfb, GLenum pname, GLuint index, GLint64 *param);
void (APIENTRYP glCreateBuffers)(GLsizei n, GLuint *buffers);
void (APIENTRYP glNamedBufferStorage)(GLuint buffer, GLsizeiptr size, const void *data, GLbitfield flags);
void (APIENTRYP glNamedBufferData)(GLuint buffer, GLsizeiptr size, const void *data, GLenum usage);
void (APIENTRYP glNamedBufferSubData)(GLuint buffer, GLintptr offset, GLsizeiptr size, const void *data);
void (APIENTRYP glCopyNamedBufferSubData)(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
void (APIENTRYP glClearNamedBufferData)(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void *data);
void (APIENTRYP glClearNamedBufferSubData)(GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
void *(APIENTRYP glMapNamedBuffer)(GLuint buffer, GLenum access);
void *(APIENTRYP glMapNamedBufferRange)(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
GLboolean(APIENTRYP glUnmapNamedBuffer)(GLuint buffer);
void (APIENTRYP glFlushMappedNamedBufferRange)(GLuint buffer, GLintptr offset, GLsizeiptr length);
void (APIENTRYP glGetNamedBufferParameteriv)(GLuint buffer, GLenum pname, GLint *params);
void (APIENTRYP glGetNamedBufferParameteri64v)(GLuint buffer, GLenum pname, GLint64 *params);
void (APIENTRYP glGetNamedBufferPointerv)(GLuint buffer, GLenum pname, void **params);
void (APIENTRYP glGetNamedBufferSubData)(GLuint buffer, GLintptr offset, GLsizeiptr size, void *data);
void (APIENTRYP glCreateFramebuffers)(GLsizei n, GLuint *framebuffers);
void (APIENTRYP glNamedFramebufferRenderbuffer)(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
void (APIENTRYP glNamedFramebufferParameteri)(GLuint framebuffer, GLenum pname, GLint param);
void (APIENTRYP glNamedFramebufferTexture)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
void (APIENTRYP glNamedFramebufferTextureLayer)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
void (APIENTRYP glNamedFramebufferDrawBuffer)(GLuint framebuffer, GLenum buf);
void (APIENTRYP glNamedFramebufferDrawBuffers)(GLuint framebuffer, GLsizei n, const GLenum *bufs);
void (APIENTRYP glNamedFramebufferReadBuffer)(GLuint framebuffer, GLenum src);
void (APIENTRYP glInvalidateNamedFramebufferData)(GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments);
void (APIENTRYP glInvalidateNamedFramebufferSubData)(GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
void (APIENTRYP glClearNamedFramebufferiv)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint *value);
void (APIENTRYP glClearNamedFramebufferuiv)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint *value);
void (APIENTRYP glClearNamedFramebufferfv)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat *value);
void (APIENTRYP glClearNamedFramebufferfi)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
void (APIENTRYP glBlitNamedFramebuffer)(GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
GLenum(APIENTRYP glCheckNamedFramebufferStatus)(GLuint framebuffer, GLenum target);
void (APIENTRYP glGetNamedFramebufferParameteriv)(GLuint framebuffer, GLenum pname, GLint *param);
void (APIENTRYP glGetNamedFramebufferAttachmentParameteriv)(GLuint framebuffer, GLenum attachment, GLenum pname, GLint *params);
void (APIENTRYP glCreateRenderbuffers)(GLsizei n, GLuint *renderbuffers);
void (APIENTRYP glNamedRenderbufferStorage)(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
void (APIENTRYP glNamedRenderbufferStorageMultisample)(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
void (APIENTRYP glGetNamedRenderbufferParameteriv)(GLuint renderbuffer, GLenum pname, GLint *params);
void (APIENTRYP glCreateTextures)(GLenum target, GLsizei n, GLuint *textures);
void (APIENTRYP glTextureBuffer)(GLuint texture, GLenum internalformat, GLuint buffer);
void (APIENTRYP glTextureBufferRange)(GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
void (APIENTRYP glTextureStorage1D)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width);
void (APIENTRYP glTextureStorage2D)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
void (APIENTRYP glTextureStorage3D)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
void (APIENTRYP glTextureStorage2DMultisample)(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
void (APIENTRYP glTextureStorage3DMultisample)(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
void (APIENTRYP glTextureSubImage1D)(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
void (APIENTRYP glTextureSubImage2D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
void (APIENTRYP glTextureSubImage3D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
void (APIENTRYP glCompressedTextureSubImage1D)(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
void (APIENTRYP glCompressedTextureSubImage2D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
void (APIENTRYP glCompressedTextureSubImage3D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
void (APIENTRYP glCopyTextureSubImage1D)(GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
void (APIENTRYP glCopyTextureSubImage2D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
void (APIENTRYP glCopyTextureSubImage3D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
void (APIENTRYP glTextureParameterf)(GLuint texture, GLenum pname, GLfloat param);
void (APIENTRYP glTextureParameterfv)(GLuint texture, GLenum pname, const GLfloat *param);
void (APIENTRYP glTextureParameteri)(GLuint texture, GLenum pname, GLint param);
void (APIENTRYP glTextureParameterIiv)(GLuint texture, GLenum pname, const GLint *params);
void (APIENTRYP glTextureParameterIuiv)(GLuint texture, GLenum pname, const GLuint *params);
void (APIENTRYP glTextureParameteriv)(GLuint texture, GLenum pname, const GLint *param);
void (APIENTRYP glGenerateTextureMipmap)(GLuint texture);
void (APIENTRYP glBindTextureUnit)(GLuint unit, GLuint texture);
void (APIENTRYP glGetTextureImage)(GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
void (APIENTRYP glGetCompressedTextureImage)(GLuint texture, GLint level, GLsizei bufSize, void *pixels);
void (APIENTRYP glGetTextureLevelParameterfv)(GLuint texture, GLint level, GLenum pname, GLfloat *params);
void (APIENTRYP glGetTextureLevelParameteriv)(GLuint texture, GLint level, GLenum pname, GLint *params);
void (APIENTRYP glGetTextureParameterfv)(GLuint texture, GLenum pname, GLfloat *params);
void (APIENTRYP glGetTextureParameterIiv)(GLuint texture, GLenum pname, GLint *params);
void (APIENTRYP glGetTextureParameterIuiv)(GLuint texture, GLenum pname, GLuint *params);
void (APIENTRYP glGetTextureParameteriv)(GLuint texture, GLenum pname, GLint *params);
void (APIENTRYP glCreateVertexArrays)(GLsizei n, GLuint *arrays);
void (APIENTRYP glDisableVertexArrayAttrib)(GLuint vaobj, GLuint index);
void (APIENTRYP glEnableVertexArrayAttrib)(GLuint vaobj, GLuint index);
void (APIENTRYP glVertexArrayElementBuffer)(GLuint vaobj, GLuint buffer);
void (APIENTRYP glVertexArrayVertexBuffer)(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
void (APIENTRYP glVertexArrayVertexBuffers)(GLuint vaobj, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);
void (APIENTRYP glVertexArrayAttribBinding)(GLuint vaobj, GLuint attribindex, GLuint bindingindex);
void (APIENTRYP glVertexArrayAttribFormat)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
void (APIENTRYP glVertexArrayAttribIFormat)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
void (APIENTRYP glVertexArrayAttribLFormat)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
void (APIENTRYP glVertexArrayBindingDivisor)(GLuint vaobj, GLuint bindingindex, GLuint divisor);
void (APIENTRYP glGetVertexArrayiv)(GLuint vaobj, GLenum pname, GLint *param);
void (APIENTRYP glGetVertexArrayIndexediv)(GLuint vaobj, GLuint index, GLenum pname, GLint *param);
void (APIENTRYP glGetVertexArrayIndexed64iv)(GLuint vaobj, GLuint index, GLenum pname, GLint64 *param);
void (APIENTRYP glCreateSamplers)(GLsizei n, GLuint *samplers);
void (APIENTRYP glCreateProgramPipelines)(GLsizei n, GLuint *pipelines);
void (APIENTRYP glCreateQueries)(GLenum target, GLsizei n, GLuint *ids);
void (APIENTRYP glGetQueryBufferObjecti64v)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
void (APIENTRYP glGetQueryBufferObjectiv)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
void (APIENTRYP glGetQueryBufferObjectui64v)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
void (APIENTRYP glGetQueryBufferObjectuiv)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
void (APIENTRYP glMemoryBarrierByRegion)(GLbitfield barriers);
void (APIENTRYP glGetTextureSubImage)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
void (APIENTRYP glGetCompressedTextureSubImage)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void *pixels);
GLenum(APIENTRYP glGetGraphicsResetStatus)(void);
void (APIENTRYP glGetnCompressedTexImage)(GLenum target, GLint lod, GLsizei bufSize, void *pixels);
void (APIENTRYP glGetnTexImage)(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
void (APIENTRYP glGetnUniformdv)(GLuint program, GLint location, GLsizei bufSize, GLdouble *params);
void (APIENTRYP glGetnUniformfv)(GLuint program, GLint location, GLsizei bufSize, GLfloat *params);
void (APIENTRYP glGetnUniformiv)(GLuint program, GLint location, GLsizei bufSize, GLint *params);
void (APIENTRYP glGetnUniformuiv)(GLuint program, GLint location, GLsizei bufSize, GLuint *params);
void (APIENTRYP glReadnPixels)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data);
void (APIENTRYP glTextureBarrier)(void);
GLuint64(APIENTRYP glGetTextureHandleARB)(GLuint texture);
GLuint64(APIENTRYP glGetTextureSamplerHandleARB)(GLuint texture, GLuint sampler);
void (APIENTRYP glMakeTextureHandleResidentARB)(GLuint64 handle);
void (APIENTRYP glMakeTextureHandleNonResidentARB)(GLuint64 handle);
GLuint64(APIENTRYP glGetImageHandleARB)(GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format);
void (APIENTRYP glMakeImageHandleResidentARB)(GLuint64 handle, GLenum access);
void (APIENTRYP glMakeImageHandleNonResidentARB)(GLuint64 handle);
void (APIENTRYP glUniformHandleui64ARB)(GLint location, GLuint64 value);
void (APIENTRYP glUniformHandleui64vARB)(GLint location, GLsizei count, const GLuint64 *value);
void (APIENTRYP glProgramUniformHandleui64ARB)(GLuint program, GLint location, GLuint64 value);
void (APIENTRYP glProgramUniformHandleui64vARB)(GLuint program, GLint location, GLsizei count, const GLuint64 *values);
GLboolean(APIENTRYP glIsTextureHandleResidentARB)(GLuint64 handle);
GLboolean(APIENTRYP glIsImageHandleResidentARB)(GLuint64 handle);
void (APIENTRYP glVertexAttribL1ui64ARB)(GLuint index, GLuint64EXT x);
void (APIENTRYP glVertexAttribL1ui64vARB)(GLuint index, const GLuint64EXT *v);
void (APIENTRYP glGetVertexAttribLui64vARB)(GLuint index, GLenum pname, GLuint64EXT *params);
GLsync(APIENTRYP glCreateSyncFromCLeventARB)(struct _cl_context *context, struct _cl_event *event, GLbitfield flags);
void (APIENTRYP glDispatchComputeGroupSizeARB)(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z, GLuint group_size_x, GLuint group_size_y, GLuint group_size_z);
void (APIENTRYP glDebugMessageControlARB)(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
void (APIENTRYP glDebugMessageInsertARB)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf);
void (APIENTRYP glDebugMessageCallbackARB)(GLDEBUGPROCARB callback, const void *userParam);
GLuint(APIENTRYP glGetDebugMessageLogARB)(GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog);
void (APIENTRYP glBlendEquationiARB)(GLuint buf, GLenum mode);
void (APIENTRYP glBlendEquationSeparateiARB)(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
void (APIENTRYP glBlendFunciARB)(GLuint buf, GLenum src, GLenum dst);
void (APIENTRYP glBlendFuncSeparateiARB)(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
void (APIENTRYP glMultiDrawArraysIndirectCountARB)(GLenum mode, GLintptr indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
void (APIENTRYP glMultiDrawElementsIndirectCountARB)(GLenum mode, GLenum type, GLintptr indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
GLenum(APIENTRYP glGetGraphicsResetStatusARB)(void);
void (APIENTRYP glGetnTexImageARB)(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *img);
void (APIENTRYP glReadnPixelsARB)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data);
void (APIENTRYP glGetnCompressedTexImageARB)(GLenum target, GLint lod, GLsizei bufSize, void *img);
void (APIENTRYP glGetnUniformfvARB)(GLuint program, GLint location, GLsizei bufSize, GLfloat *params);
void (APIENTRYP glGetnUniformivARB)(GLuint program, GLint location, GLsizei bufSize, GLint *params);
void (APIENTRYP glGetnUniformuivARB)(GLuint program, GLint location, GLsizei bufSize, GLuint *params);
void (APIENTRYP glGetnUniformdvARB)(GLuint program, GLint location, GLsizei bufSize, GLdouble *params);
void (APIENTRYP glMinSampleShadingARB)(GLfloat value);
void (APIENTRYP glNamedStringARB)(GLenum type, GLint namelen, const GLchar *name, GLint stringlen, const GLchar *string);
void (APIENTRYP glDeleteNamedStringARB)(GLint namelen, const GLchar *name);
void (APIENTRYP glCompileShaderIncludeARB)(GLuint shader, GLsizei count, const GLchar *const*path, const GLint *length);
GLboolean(APIENTRYP glIsNamedStringARB)(GLint namelen, const GLchar *name);
void (APIENTRYP glGetNamedStringARB)(GLint namelen, const GLchar *name, GLsizei bufSize, GLint *stringlen, GLchar *string);
void (APIENTRYP glGetNamedStringivARB)(GLint namelen, const GLchar *name, GLenum pname, GLint *params);
void (APIENTRYP glBufferPageCommitmentARB)(GLenum target, GLintptr offset, GLsizeiptr size, GLboolean commit);
void (APIENTRYP glNamedBufferPageCommitmentEXT)(GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit);
void (APIENTRYP glNamedBufferPageCommitmentARB)(GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit);
void (APIENTRYP glTexPageCommitmentARB)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit);
#endif // JUSTGL_IMPLEMENTATION

#endif // __glcorearb_h_

// only include wglext on win32
#ifdef _WIN32

// A tweaked version of wglext.h is pasted inline between __wglext_h_.
// The license associated to this chunk of code is also included inline.
// That license applies to that part of the code only.
// The rest of the code in this file is under the license at the top of this file.
#ifndef __wglext_h_
#define __wglext_h_ 1

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
    ** Khronos $Revision: 31597 $ on $Date: 2015-06-25 16:32:35 -0400 (Thu, 25 Jun 2015) $
    */

#define WGL_WGLEXT_VERSION 20150623

/* Generated C header for:
 * API: wgl
 * Versions considered: .*
 * Versions emitted: _nomatch_^
 * Default extensions included: wgl
 * Additional extensions included: _nomatch_^
 * Extensions removed: _nomatch_^
 */

#define WGL_FRONT_COLOR_BUFFER_BIT_ARB    0x00000001
#define WGL_BACK_COLOR_BUFFER_BIT_ARB     0x00000002
#define WGL_DEPTH_BUFFER_BIT_ARB          0x00000004
#define WGL_STENCIL_BUFFER_BIT_ARB        0x00000008
typedef HANDLE (WINAPI * PFNWGLCREATEBUFFERREGIONARBPROC) (HDC hDC, int iLayerPlane, UINT uType);
typedef VOID (WINAPI * PFNWGLDELETEBUFFERREGIONARBPROC) (HANDLE hRegion);
typedef BOOL (WINAPI * PFNWGLSAVEBUFFERREGIONARBPROC) (HANDLE hRegion, int x, int y, int width, int height);
typedef BOOL (WINAPI * PFNWGLRESTOREBUFFERREGIONARBPROC) (HANDLE hRegion, int x, int y, int width, int height, int xSrc, int ySrc);
extern HANDLE (WINAPI * wglCreateBufferRegionARB)(HDC hDC, int iLayerPlane, UINT uType);
extern VOID (WINAPI * wglDeleteBufferRegionARB)(HANDLE hRegion);
extern BOOL (WINAPI * wglSaveBufferRegionARB)(HANDLE hRegion, int x, int y, int width, int height);
extern BOOL (WINAPI * wglRestoreBufferRegionARB)(HANDLE hRegion, int x, int y, int width, int height, int xSrc, int ySrc);

#define WGL_CONTEXT_RELEASE_BEHAVIOR_ARB  0x2097
#define WGL_CONTEXT_RELEASE_BEHAVIOR_NONE_ARB 0
#define WGL_CONTEXT_RELEASE_BEHAVIOR_FLUSH_ARB 0x2098

#define WGL_CONTEXT_DEBUG_BIT_ARB         0x00000001
#define WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB 0x00000002
#define WGL_CONTEXT_MAJOR_VERSION_ARB     0x2091
#define WGL_CONTEXT_MINOR_VERSION_ARB     0x2092
#define WGL_CONTEXT_LAYER_PLANE_ARB       0x2093
#define WGL_CONTEXT_FLAGS_ARB             0x2094
#define ERROR_INVALID_VERSION_ARB         0x2095
typedef HGLRC (WINAPI * PFNWGLCREATECONTEXTATTRIBSARBPROC) (HDC hDC, HGLRC hShareContext, const int *attribList);
extern HGLRC (WINAPI * wglCreateContextAttribsARB)(HDC hDC, HGLRC hShareContext, const int *attribList);

#define WGL_CONTEXT_PROFILE_MASK_ARB      0x9126
#define WGL_CONTEXT_CORE_PROFILE_BIT_ARB  0x00000001
#define WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB 0x00000002
#define ERROR_INVALID_PROFILE_ARB         0x2096

#define WGL_CONTEXT_ROBUST_ACCESS_BIT_ARB 0x00000004
#define WGL_LOSE_CONTEXT_ON_RESET_ARB     0x8252
#define WGL_CONTEXT_RESET_NOTIFICATION_STRATEGY_ARB 0x8256
#define WGL_NO_RESET_NOTIFICATION_ARB     0x8261

typedef const char *(WINAPI * PFNWGLGETEXTENSIONSSTRINGARBPROC) (HDC hdc);
extern const char *(WINAPI * wglGetExtensionsStringARB)(HDC hdc);

#define WGL_FRAMEBUFFER_SRGB_CAPABLE_ARB  0x20A9

#define ERROR_INVALID_PIXEL_TYPE_ARB      0x2043
#define ERROR_INCOMPATIBLE_DEVICE_CONTEXTS_ARB 0x2054
typedef BOOL (WINAPI * PFNWGLMAKECONTEXTCURRENTARBPROC) (HDC hDrawDC, HDC hReadDC, HGLRC hglrc);
typedef HDC (WINAPI * PFNWGLGETCURRENTREADDCARBPROC) (void);
extern BOOL (WINAPI * wglMakeContextCurrentARB)(HDC hDrawDC, HDC hReadDC, HGLRC hglrc);
extern HDC (WINAPI * wglGetCurrentReadDCARB)(void);

#define WGL_SAMPLE_BUFFERS_ARB            0x2041
#define WGL_SAMPLES_ARB                   0x2042

DECLARE_HANDLE(HPBUFFERARB);
#define WGL_DRAW_TO_PBUFFER_ARB           0x202D
#define WGL_MAX_PBUFFER_PIXELS_ARB        0x202E
#define WGL_MAX_PBUFFER_WIDTH_ARB         0x202F
#define WGL_MAX_PBUFFER_HEIGHT_ARB        0x2030
#define WGL_PBUFFER_LARGEST_ARB           0x2033
#define WGL_PBUFFER_WIDTH_ARB             0x2034
#define WGL_PBUFFER_HEIGHT_ARB            0x2035
#define WGL_PBUFFER_LOST_ARB              0x2036
typedef HPBUFFERARB (WINAPI * PFNWGLCREATEPBUFFERARBPROC) (HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int *piAttribList);
typedef HDC (WINAPI * PFNWGLGETPBUFFERDCARBPROC) (HPBUFFERARB hPbuffer);
typedef int (WINAPI * PFNWGLRELEASEPBUFFERDCARBPROC) (HPBUFFERARB hPbuffer, HDC hDC);
typedef BOOL (WINAPI * PFNWGLDESTROYPBUFFERARBPROC) (HPBUFFERARB hPbuffer);
typedef BOOL (WINAPI * PFNWGLQUERYPBUFFERARBPROC) (HPBUFFERARB hPbuffer, int iAttribute, int *piValue);
extern HPBUFFERARB (WINAPI * wglCreatePbufferARB)(HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int *piAttribList);
extern HDC (WINAPI * wglGetPbufferDCARB)(HPBUFFERARB hPbuffer);
extern int (WINAPI * wglReleasePbufferDCARB)(HPBUFFERARB hPbuffer, HDC hDC);
extern BOOL (WINAPI * wglDestroyPbufferARB)(HPBUFFERARB hPbuffer);
extern BOOL (WINAPI * wglQueryPbufferARB)(HPBUFFERARB hPbuffer, int iAttribute, int *piValue);

#define WGL_NUMBER_PIXEL_FORMATS_ARB      0x2000
#define WGL_DRAW_TO_WINDOW_ARB            0x2001
#define WGL_DRAW_TO_BITMAP_ARB            0x2002
#define WGL_ACCELERATION_ARB              0x2003
#define WGL_NEED_PALETTE_ARB              0x2004
#define WGL_NEED_SYSTEM_PALETTE_ARB       0x2005
#define WGL_SWAP_LAYER_BUFFERS_ARB        0x2006
#define WGL_SWAP_METHOD_ARB               0x2007
#define WGL_NUMBER_OVERLAYS_ARB           0x2008
#define WGL_NUMBER_UNDERLAYS_ARB          0x2009
#define WGL_TRANSPARENT_ARB               0x200A
#define WGL_TRANSPARENT_RED_VALUE_ARB     0x2037
#define WGL_TRANSPARENT_GREEN_VALUE_ARB   0x2038
#define WGL_TRANSPARENT_BLUE_VALUE_ARB    0x2039
#define WGL_TRANSPARENT_ALPHA_VALUE_ARB   0x203A
#define WGL_TRANSPARENT_INDEX_VALUE_ARB   0x203B
#define WGL_SHARE_DEPTH_ARB               0x200C
#define WGL_SHARE_STENCIL_ARB             0x200D
#define WGL_SHARE_ACCUM_ARB               0x200E
#define WGL_SUPPORT_GDI_ARB               0x200F
#define WGL_SUPPORT_OPENGL_ARB            0x2010
#define WGL_DOUBLE_BUFFER_ARB             0x2011
#define WGL_STEREO_ARB                    0x2012
#define WGL_PIXEL_TYPE_ARB                0x2013
#define WGL_COLOR_BITS_ARB                0x2014
#define WGL_RED_BITS_ARB                  0x2015
#define WGL_RED_SHIFT_ARB                 0x2016
#define WGL_GREEN_BITS_ARB                0x2017
#define WGL_GREEN_SHIFT_ARB               0x2018
#define WGL_BLUE_BITS_ARB                 0x2019
#define WGL_BLUE_SHIFT_ARB                0x201A
#define WGL_ALPHA_BITS_ARB                0x201B
#define WGL_ALPHA_SHIFT_ARB               0x201C
#define WGL_ACCUM_BITS_ARB                0x201D
#define WGL_ACCUM_RED_BITS_ARB            0x201E
#define WGL_ACCUM_GREEN_BITS_ARB          0x201F
#define WGL_ACCUM_BLUE_BITS_ARB           0x2020
#define WGL_ACCUM_ALPHA_BITS_ARB          0x2021
#define WGL_DEPTH_BITS_ARB                0x2022
#define WGL_STENCIL_BITS_ARB              0x2023
#define WGL_AUX_BUFFERS_ARB               0x2024
#define WGL_NO_ACCELERATION_ARB           0x2025
#define WGL_GENERIC_ACCELERATION_ARB      0x2026
#define WGL_FULL_ACCELERATION_ARB         0x2027
#define WGL_SWAP_EXCHANGE_ARB             0x2028
#define WGL_SWAP_COPY_ARB                 0x2029
#define WGL_SWAP_UNDEFINED_ARB            0x202A
#define WGL_TYPE_RGBA_ARB                 0x202B
#define WGL_TYPE_COLORINDEX_ARB           0x202C
typedef BOOL (WINAPI * PFNWGLGETPIXELFORMATATTRIBIVARBPROC) (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int *piAttributes, int *piValues);
typedef BOOL (WINAPI * PFNWGLGETPIXELFORMATATTRIBFVARBPROC) (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int *piAttributes, FLOAT *pfValues);
typedef BOOL (WINAPI * PFNWGLCHOOSEPIXELFORMATARBPROC) (HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats);
extern BOOL (WINAPI * wglGetPixelFormatAttribivARB)(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int *piAttributes, int *piValues);
extern BOOL (WINAPI * wglGetPixelFormatAttribfvARB)(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int *piAttributes, FLOAT *pfValues);
extern BOOL (WINAPI * wglChoosePixelFormatARB)(HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats);

#define WGL_TYPE_RGBA_FLOAT_ARB           0x21A0

#define WGL_BIND_TO_TEXTURE_RGB_ARB       0x2070
#define WGL_BIND_TO_TEXTURE_RGBA_ARB      0x2071
#define WGL_TEXTURE_FORMAT_ARB            0x2072
#define WGL_TEXTURE_TARGET_ARB            0x2073
#define WGL_MIPMAP_TEXTURE_ARB            0x2074
#define WGL_TEXTURE_RGB_ARB               0x2075
#define WGL_TEXTURE_RGBA_ARB              0x2076
#define WGL_NO_TEXTURE_ARB                0x2077
#define WGL_TEXTURE_CUBE_MAP_ARB          0x2078
#define WGL_TEXTURE_1D_ARB                0x2079
#define WGL_TEXTURE_2D_ARB                0x207A
#define WGL_MIPMAP_LEVEL_ARB              0x207B
#define WGL_CUBE_MAP_FACE_ARB             0x207C
#define WGL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB 0x207D
#define WGL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB 0x207E
#define WGL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB 0x207F
#define WGL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB 0x2080
#define WGL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB 0x2081
#define WGL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB 0x2082
#define WGL_FRONT_LEFT_ARB                0x2083
#define WGL_FRONT_RIGHT_ARB               0x2084
#define WGL_BACK_LEFT_ARB                 0x2085
#define WGL_BACK_RIGHT_ARB                0x2086
#define WGL_AUX0_ARB                      0x2087
#define WGL_AUX1_ARB                      0x2088
#define WGL_AUX2_ARB                      0x2089
#define WGL_AUX3_ARB                      0x208A
#define WGL_AUX4_ARB                      0x208B
#define WGL_AUX5_ARB                      0x208C
#define WGL_AUX6_ARB                      0x208D
#define WGL_AUX7_ARB                      0x208E
#define WGL_AUX8_ARB                      0x208F
#define WGL_AUX9_ARB                      0x2090
typedef BOOL (WINAPI * PFNWGLBINDTEXIMAGEARBPROC) (HPBUFFERARB hPbuffer, int iBuffer);
typedef BOOL (WINAPI * PFNWGLRELEASETEXIMAGEARBPROC) (HPBUFFERARB hPbuffer, int iBuffer);
typedef BOOL (WINAPI * PFNWGLSETPBUFFERATTRIBARBPROC) (HPBUFFERARB hPbuffer, const int *piAttribList);
extern BOOL (WINAPI * wglBindTexImageARB)(HPBUFFERARB hPbuffer, int iBuffer);
extern BOOL (WINAPI * wglReleaseTexImageARB)(HPBUFFERARB hPbuffer, int iBuffer);
extern BOOL (WINAPI * wglSetPbufferAttribARB)(HPBUFFERARB hPbuffer, const int *piAttribList);

#define WGL_CONTEXT_RESET_ISOLATION_BIT_ARB 0x00000008

#define WGL_SAMPLE_BUFFERS_3DFX           0x2060
#define WGL_SAMPLES_3DFX                  0x2061

#define WGL_STEREO_EMITTER_ENABLE_3DL     0x2055
#define WGL_STEREO_EMITTER_DISABLE_3DL    0x2056
#define WGL_STEREO_POLARITY_NORMAL_3DL    0x2057
#define WGL_STEREO_POLARITY_INVERT_3DL    0x2058
typedef BOOL (WINAPI * PFNWGLSETSTEREOEMITTERSTATE3DLPROC) (HDC hDC, UINT uState);
extern BOOL (WINAPI * wglSetStereoEmitterState3DL)(HDC hDC, UINT uState);

#define WGL_GPU_VENDOR_AMD                0x1F00
#define WGL_GPU_RENDERER_STRING_AMD       0x1F01
#define WGL_GPU_OPENGL_VERSION_STRING_AMD 0x1F02
#define WGL_GPU_FASTEST_TARGET_GPUS_AMD   0x21A2
#define WGL_GPU_RAM_AMD                   0x21A3
#define WGL_GPU_CLOCK_AMD                 0x21A4
#define WGL_GPU_NUM_PIPES_AMD             0x21A5
#define WGL_GPU_NUM_SIMD_AMD              0x21A6
#define WGL_GPU_NUM_RB_AMD                0x21A7
#define WGL_GPU_NUM_SPI_AMD               0x21A8
typedef UINT (WINAPI * PFNWGLGETGPUIDSAMDPROC) (UINT maxCount, UINT *ids);
typedef INT (WINAPI * PFNWGLGETGPUINFOAMDPROC) (UINT id, int property, GLenum dataType, UINT size, void *data);
typedef UINT (WINAPI * PFNWGLGETCONTEXTGPUIDAMDPROC) (HGLRC hglrc);
typedef HGLRC (WINAPI * PFNWGLCREATEASSOCIATEDCONTEXTAMDPROC) (UINT id);
typedef HGLRC (WINAPI * PFNWGLCREATEASSOCIATEDCONTEXTATTRIBSAMDPROC) (UINT id, HGLRC hShareContext, const int *attribList);
typedef BOOL (WINAPI * PFNWGLDELETEASSOCIATEDCONTEXTAMDPROC) (HGLRC hglrc);
typedef BOOL (WINAPI * PFNWGLMAKEASSOCIATEDCONTEXTCURRENTAMDPROC) (HGLRC hglrc);
typedef HGLRC (WINAPI * PFNWGLGETCURRENTASSOCIATEDCONTEXTAMDPROC) (void);
typedef VOID (WINAPI * PFNWGLBLITCONTEXTFRAMEBUFFERAMDPROC) (HGLRC dstCtx, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
extern UINT (WINAPI * wglGetGPUIDsAMD)(UINT maxCount, UINT *ids);
extern INT (WINAPI * wglGetGPUInfoAMD)(UINT id, int property, GLenum dataType, UINT size, void *data);
extern UINT (WINAPI * wglGetContextGPUIDAMD)(HGLRC hglrc);
extern HGLRC (WINAPI * wglCreateAssociatedContextAMD)(UINT id);
extern HGLRC (WINAPI * wglCreateAssociatedContextAttribsAMD)(UINT id, HGLRC hShareContext, const int *attribList);
extern BOOL (WINAPI * wglDeleteAssociatedContextAMD)(HGLRC hglrc);
extern BOOL (WINAPI * wglMakeAssociatedContextCurrentAMD)(HGLRC hglrc);
extern HGLRC (WINAPI * wglGetCurrentAssociatedContextAMD)(void);
extern VOID (WINAPI * wglBlitContextFramebufferAMD)(HGLRC dstCtx, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);

#define WGL_TYPE_RGBA_FLOAT_ATI           0x21A0

#define WGL_CONTEXT_ES2_PROFILE_BIT_EXT   0x00000004

#define WGL_CONTEXT_ES_PROFILE_BIT_EXT    0x00000004

#define WGL_DEPTH_FLOAT_EXT               0x2040

typedef GLboolean (WINAPI * PFNWGLCREATEDISPLAYCOLORTABLEEXTPROC) (GLushort id);
typedef GLboolean (WINAPI * PFNWGLLOADDISPLAYCOLORTABLEEXTPROC) (const GLushort *table, GLuint length);
typedef GLboolean (WINAPI * PFNWGLBINDDISPLAYCOLORTABLEEXTPROC) (GLushort id);
typedef VOID (WINAPI * PFNWGLDESTROYDISPLAYCOLORTABLEEXTPROC) (GLushort id);
extern GLboolean (WINAPI * wglCreateDisplayColorTableEXT)(GLushort id);
extern GLboolean (WINAPI * wglLoadDisplayColorTableEXT)(const GLushort *table, GLuint length);
extern GLboolean (WINAPI * wglBindDisplayColorTableEXT)(GLushort id);
extern VOID (WINAPI * wglDestroyDisplayColorTableEXT)(GLushort id);

typedef const char *(WINAPI * PFNWGLGETEXTENSIONSSTRINGEXTPROC) (void);
extern const char *(WINAPI * wglGetExtensionsStringEXT)(void);

#define WGL_FRAMEBUFFER_SRGB_CAPABLE_EXT  0x20A9

#define ERROR_INVALID_PIXEL_TYPE_EXT      0x2043
typedef BOOL (WINAPI * PFNWGLMAKECONTEXTCURRENTEXTPROC) (HDC hDrawDC, HDC hReadDC, HGLRC hglrc);
typedef HDC (WINAPI * PFNWGLGETCURRENTREADDCEXTPROC) (void);
extern BOOL (WINAPI * wglMakeContextCurrentEXT)(HDC hDrawDC, HDC hReadDC, HGLRC hglrc);
extern HDC (WINAPI * wglGetCurrentReadDCEXT)(void);

#define WGL_SAMPLE_BUFFERS_EXT            0x2041
#define WGL_SAMPLES_EXT                   0x2042

DECLARE_HANDLE(HPBUFFEREXT);
#define WGL_DRAW_TO_PBUFFER_EXT           0x202D
#define WGL_MAX_PBUFFER_PIXELS_EXT        0x202E
#define WGL_MAX_PBUFFER_WIDTH_EXT         0x202F
#define WGL_MAX_PBUFFER_HEIGHT_EXT        0x2030
#define WGL_OPTIMAL_PBUFFER_WIDTH_EXT     0x2031
#define WGL_OPTIMAL_PBUFFER_HEIGHT_EXT    0x2032
#define WGL_PBUFFER_LARGEST_EXT           0x2033
#define WGL_PBUFFER_WIDTH_EXT             0x2034
#define WGL_PBUFFER_HEIGHT_EXT            0x2035
typedef HPBUFFEREXT (WINAPI * PFNWGLCREATEPBUFFEREXTPROC) (HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int *piAttribList);
typedef HDC (WINAPI * PFNWGLGETPBUFFERDCEXTPROC) (HPBUFFEREXT hPbuffer);
typedef int (WINAPI * PFNWGLRELEASEPBUFFERDCEXTPROC) (HPBUFFEREXT hPbuffer, HDC hDC);
typedef BOOL (WINAPI * PFNWGLDESTROYPBUFFEREXTPROC) (HPBUFFEREXT hPbuffer);
typedef BOOL (WINAPI * PFNWGLQUERYPBUFFEREXTPROC) (HPBUFFEREXT hPbuffer, int iAttribute, int *piValue);
extern HPBUFFEREXT (WINAPI * wglCreatePbufferEXT)(HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int *piAttribList);
extern HDC (WINAPI * wglGetPbufferDCEXT)(HPBUFFEREXT hPbuffer);
extern int (WINAPI * wglReleasePbufferDCEXT)(HPBUFFEREXT hPbuffer, HDC hDC);
extern BOOL (WINAPI * wglDestroyPbufferEXT)(HPBUFFEREXT hPbuffer);
extern BOOL (WINAPI * wglQueryPbufferEXT)(HPBUFFEREXT hPbuffer, int iAttribute, int *piValue);

#define WGL_NUMBER_PIXEL_FORMATS_EXT      0x2000
#define WGL_DRAW_TO_WINDOW_EXT            0x2001
#define WGL_DRAW_TO_BITMAP_EXT            0x2002
#define WGL_ACCELERATION_EXT              0x2003
#define WGL_NEED_PALETTE_EXT              0x2004
#define WGL_NEED_SYSTEM_PALETTE_EXT       0x2005
#define WGL_SWAP_LAYER_BUFFERS_EXT        0x2006
#define WGL_SWAP_METHOD_EXT               0x2007
#define WGL_NUMBER_OVERLAYS_EXT           0x2008
#define WGL_NUMBER_UNDERLAYS_EXT          0x2009
#define WGL_TRANSPARENT_EXT               0x200A
#define WGL_TRANSPARENT_VALUE_EXT         0x200B
#define WGL_SHARE_DEPTH_EXT               0x200C
#define WGL_SHARE_STENCIL_EXT             0x200D
#define WGL_SHARE_ACCUM_EXT               0x200E
#define WGL_SUPPORT_GDI_EXT               0x200F
#define WGL_SUPPORT_OPENGL_EXT            0x2010
#define WGL_DOUBLE_BUFFER_EXT             0x2011
#define WGL_STEREO_EXT                    0x2012
#define WGL_PIXEL_TYPE_EXT                0x2013
#define WGL_COLOR_BITS_EXT                0x2014
#define WGL_RED_BITS_EXT                  0x2015
#define WGL_RED_SHIFT_EXT                 0x2016
#define WGL_GREEN_BITS_EXT                0x2017
#define WGL_GREEN_SHIFT_EXT               0x2018
#define WGL_BLUE_BITS_EXT                 0x2019
#define WGL_BLUE_SHIFT_EXT                0x201A
#define WGL_ALPHA_BITS_EXT                0x201B
#define WGL_ALPHA_SHIFT_EXT               0x201C
#define WGL_ACCUM_BITS_EXT                0x201D
#define WGL_ACCUM_RED_BITS_EXT            0x201E
#define WGL_ACCUM_GREEN_BITS_EXT          0x201F
#define WGL_ACCUM_BLUE_BITS_EXT           0x2020
#define WGL_ACCUM_ALPHA_BITS_EXT          0x2021
#define WGL_DEPTH_BITS_EXT                0x2022
#define WGL_STENCIL_BITS_EXT              0x2023
#define WGL_AUX_BUFFERS_EXT               0x2024
#define WGL_NO_ACCELERATION_EXT           0x2025
#define WGL_GENERIC_ACCELERATION_EXT      0x2026
#define WGL_FULL_ACCELERATION_EXT         0x2027
#define WGL_SWAP_EXCHANGE_EXT             0x2028
#define WGL_SWAP_COPY_EXT                 0x2029
#define WGL_SWAP_UNDEFINED_EXT            0x202A
#define WGL_TYPE_RGBA_EXT                 0x202B
#define WGL_TYPE_COLORINDEX_EXT           0x202C
typedef BOOL (WINAPI * PFNWGLGETPIXELFORMATATTRIBIVEXTPROC) (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int *piAttributes, int *piValues);
typedef BOOL (WINAPI * PFNWGLGETPIXELFORMATATTRIBFVEXTPROC) (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int *piAttributes, FLOAT *pfValues);
typedef BOOL (WINAPI * PFNWGLCHOOSEPIXELFORMATEXTPROC) (HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats);
extern BOOL (WINAPI * wglGetPixelFormatAttribivEXT)(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int *piAttributes, int *piValues);
extern BOOL (WINAPI * wglGetPixelFormatAttribfvEXT)(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int *piAttributes, FLOAT *pfValues);
extern BOOL (WINAPI * wglChoosePixelFormatEXT)(HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats);

#define WGL_TYPE_RGBA_UNSIGNED_FLOAT_EXT  0x20A8

typedef BOOL (WINAPI * PFNWGLSWAPINTERVALEXTPROC) (int interval);
typedef int (WINAPI * PFNWGLGETSWAPINTERVALEXTPROC) (void);
extern BOOL (WINAPI * wglSwapIntervalEXT)(int interval);
extern int (WINAPI * wglGetSwapIntervalEXT)(void);

#define WGL_DIGITAL_VIDEO_CURSOR_ALPHA_FRAMEBUFFER_I3D 0x2050
#define WGL_DIGITAL_VIDEO_CURSOR_ALPHA_VALUE_I3D 0x2051
#define WGL_DIGITAL_VIDEO_CURSOR_INCLUDED_I3D 0x2052
#define WGL_DIGITAL_VIDEO_GAMMA_CORRECTED_I3D 0x2053
typedef BOOL (WINAPI * PFNWGLGETDIGITALVIDEOPARAMETERSI3DPROC) (HDC hDC, int iAttribute, int *piValue);
typedef BOOL (WINAPI * PFNWGLSETDIGITALVIDEOPARAMETERSI3DPROC) (HDC hDC, int iAttribute, const int *piValue);
extern BOOL (WINAPI * wglGetDigitalVideoParametersI3D)(HDC hDC, int iAttribute, int *piValue);
extern BOOL (WINAPI * wglSetDigitalVideoParametersI3D)(HDC hDC, int iAttribute, const int *piValue);

#define WGL_GAMMA_TABLE_SIZE_I3D          0x204E
#define WGL_GAMMA_EXCLUDE_DESKTOP_I3D     0x204F
typedef BOOL (WINAPI * PFNWGLGETGAMMATABLEPARAMETERSI3DPROC) (HDC hDC, int iAttribute, int *piValue);
typedef BOOL (WINAPI * PFNWGLSETGAMMATABLEPARAMETERSI3DPROC) (HDC hDC, int iAttribute, const int *piValue);
typedef BOOL (WINAPI * PFNWGLGETGAMMATABLEI3DPROC) (HDC hDC, int iEntries, USHORT *puRed, USHORT *puGreen, USHORT *puBlue);
typedef BOOL (WINAPI * PFNWGLSETGAMMATABLEI3DPROC) (HDC hDC, int iEntries, const USHORT *puRed, const USHORT *puGreen, const USHORT *puBlue);
extern BOOL (WINAPI * wglGetGammaTableParametersI3D)(HDC hDC, int iAttribute, int *piValue);
extern BOOL (WINAPI * wglSetGammaTableParametersI3D)(HDC hDC, int iAttribute, const int *piValue);
extern BOOL (WINAPI * wglGetGammaTableI3D)(HDC hDC, int iEntries, USHORT *puRed, USHORT *puGreen, USHORT *puBlue);
extern BOOL (WINAPI * wglSetGammaTableI3D)(HDC hDC, int iEntries, const USHORT *puRed, const USHORT *puGreen, const USHORT *puBlue);

#define WGL_GENLOCK_SOURCE_MULTIVIEW_I3D  0x2044
#define WGL_GENLOCK_SOURCE_EXTERNAL_SYNC_I3D 0x2045
#define WGL_GENLOCK_SOURCE_EXTERNAL_FIELD_I3D 0x2046
#define WGL_GENLOCK_SOURCE_EXTERNAL_TTL_I3D 0x2047
#define WGL_GENLOCK_SOURCE_DIGITAL_SYNC_I3D 0x2048
#define WGL_GENLOCK_SOURCE_DIGITAL_FIELD_I3D 0x2049
#define WGL_GENLOCK_SOURCE_EDGE_FALLING_I3D 0x204A
#define WGL_GENLOCK_SOURCE_EDGE_RISING_I3D 0x204B
#define WGL_GENLOCK_SOURCE_EDGE_BOTH_I3D  0x204C
typedef BOOL (WINAPI * PFNWGLENABLEGENLOCKI3DPROC) (HDC hDC);
typedef BOOL (WINAPI * PFNWGLDISABLEGENLOCKI3DPROC) (HDC hDC);
typedef BOOL (WINAPI * PFNWGLISENABLEDGENLOCKI3DPROC) (HDC hDC, BOOL *pFlag);
typedef BOOL (WINAPI * PFNWGLGENLOCKSOURCEI3DPROC) (HDC hDC, UINT uSource);
typedef BOOL (WINAPI * PFNWGLGETGENLOCKSOURCEI3DPROC) (HDC hDC, UINT *uSource);
typedef BOOL (WINAPI * PFNWGLGENLOCKSOURCEEDGEI3DPROC) (HDC hDC, UINT uEdge);
typedef BOOL (WINAPI * PFNWGLGETGENLOCKSOURCEEDGEI3DPROC) (HDC hDC, UINT *uEdge);
typedef BOOL (WINAPI * PFNWGLGENLOCKSAMPLERATEI3DPROC) (HDC hDC, UINT uRate);
typedef BOOL (WINAPI * PFNWGLGETGENLOCKSAMPLERATEI3DPROC) (HDC hDC, UINT *uRate);
typedef BOOL (WINAPI * PFNWGLGENLOCKSOURCEDELAYI3DPROC) (HDC hDC, UINT uDelay);
typedef BOOL (WINAPI * PFNWGLGETGENLOCKSOURCEDELAYI3DPROC) (HDC hDC, UINT *uDelay);
typedef BOOL (WINAPI * PFNWGLQUERYGENLOCKMAXSOURCEDELAYI3DPROC) (HDC hDC, UINT *uMaxLineDelay, UINT *uMaxPixelDelay);
extern BOOL (WINAPI * wglEnableGenlockI3D)(HDC hDC);
extern BOOL (WINAPI * wglDisableGenlockI3D)(HDC hDC);
extern BOOL (WINAPI * wglIsEnabledGenlockI3D)(HDC hDC, BOOL *pFlag);
extern BOOL (WINAPI * wglGenlockSourceI3D)(HDC hDC, UINT uSource);
extern BOOL (WINAPI * wglGetGenlockSourceI3D)(HDC hDC, UINT *uSource);
extern BOOL (WINAPI * wglGenlockSourceEdgeI3D)(HDC hDC, UINT uEdge);
extern BOOL (WINAPI * wglGetGenlockSourceEdgeI3D)(HDC hDC, UINT *uEdge);
extern BOOL (WINAPI * wglGenlockSampleRateI3D)(HDC hDC, UINT uRate);
extern BOOL (WINAPI * wglGetGenlockSampleRateI3D)(HDC hDC, UINT *uRate);
extern BOOL (WINAPI * wglGenlockSourceDelayI3D)(HDC hDC, UINT uDelay);
extern BOOL (WINAPI * wglGetGenlockSourceDelayI3D)(HDC hDC, UINT *uDelay);
extern BOOL (WINAPI * wglQueryGenlockMaxSourceDelayI3D)(HDC hDC, UINT *uMaxLineDelay, UINT *uMaxPixelDelay);

#define WGL_IMAGE_BUFFER_MIN_ACCESS_I3D   0x00000001
#define WGL_IMAGE_BUFFER_LOCK_I3D         0x00000002
typedef LPVOID (WINAPI * PFNWGLCREATEIMAGEBUFFERI3DPROC) (HDC hDC, DWORD dwSize, UINT uFlags);
typedef BOOL (WINAPI * PFNWGLDESTROYIMAGEBUFFERI3DPROC) (HDC hDC, LPVOID pAddress);
typedef BOOL (WINAPI * PFNWGLASSOCIATEIMAGEBUFFEREVENTSI3DPROC) (HDC hDC, const HANDLE *pEvent, const LPVOID *pAddress, const DWORD *pSize, UINT count);
typedef BOOL (WINAPI * PFNWGLRELEASEIMAGEBUFFEREVENTSI3DPROC) (HDC hDC, const LPVOID *pAddress, UINT count);
extern LPVOID (WINAPI * wglCreateImageBufferI3D)(HDC hDC, DWORD dwSize, UINT uFlags);
extern BOOL (WINAPI * wglDestroyImageBufferI3D)(HDC hDC, LPVOID pAddress);
extern BOOL (WINAPI * wglAssociateImageBufferEventsI3D)(HDC hDC, const HANDLE *pEvent, const LPVOID *pAddress, const DWORD *pSize, UINT count);
extern BOOL (WINAPI * wglReleaseImageBufferEventsI3D)(HDC hDC, const LPVOID *pAddress, UINT count);

typedef BOOL (WINAPI * PFNWGLENABLEFRAMELOCKI3DPROC) (void);
typedef BOOL (WINAPI * PFNWGLDISABLEFRAMELOCKI3DPROC) (void);
typedef BOOL (WINAPI * PFNWGLISENABLEDFRAMELOCKI3DPROC) (BOOL *pFlag);
typedef BOOL (WINAPI * PFNWGLQUERYFRAMELOCKMASTERI3DPROC) (BOOL *pFlag);
extern BOOL (WINAPI * wglEnableFrameLockI3D)(void);
extern BOOL (WINAPI * wglDisableFrameLockI3D)(void);
extern BOOL (WINAPI * wglIsEnabledFrameLockI3D)(BOOL *pFlag);
extern BOOL (WINAPI * wglQueryFrameLockMasterI3D)(BOOL *pFlag);

typedef BOOL (WINAPI * PFNWGLGETFRAMEUSAGEI3DPROC) (float *pUsage);
typedef BOOL (WINAPI * PFNWGLBEGINFRAMETRACKINGI3DPROC) (void);
typedef BOOL (WINAPI * PFNWGLENDFRAMETRACKINGI3DPROC) (void);
typedef BOOL (WINAPI * PFNWGLQUERYFRAMETRACKINGI3DPROC) (DWORD *pFrameCount, DWORD *pMissedFrames, float *pLastMissedUsage);
extern BOOL (WINAPI * wglGetFrameUsageI3D)(float *pUsage);
extern BOOL (WINAPI * wglBeginFrameTrackingI3D)(void);
extern BOOL (WINAPI * wglEndFrameTrackingI3D)(void);
extern BOOL (WINAPI * wglQueryFrameTrackingI3D)(DWORD *pFrameCount, DWORD *pMissedFrames, float *pLastMissedUsage);

#define WGL_ACCESS_READ_ONLY_NV           0x00000000
#define WGL_ACCESS_READ_WRITE_NV          0x00000001
#define WGL_ACCESS_WRITE_DISCARD_NV       0x00000002
typedef BOOL (WINAPI * PFNWGLDXSETRESOURCESHAREHANDLENVPROC) (void *dxObject, HANDLE shareHandle);
typedef HANDLE (WINAPI * PFNWGLDXOPENDEVICENVPROC) (void *dxDevice);
typedef BOOL (WINAPI * PFNWGLDXCLOSEDEVICENVPROC) (HANDLE hDevice);
typedef HANDLE (WINAPI * PFNWGLDXREGISTEROBJECTNVPROC) (HANDLE hDevice, void *dxObject, GLuint name, GLenum type, GLenum access);
typedef BOOL (WINAPI * PFNWGLDXUNREGISTEROBJECTNVPROC) (HANDLE hDevice, HANDLE hObject);
typedef BOOL (WINAPI * PFNWGLDXOBJECTACCESSNVPROC) (HANDLE hObject, GLenum access);
typedef BOOL (WINAPI * PFNWGLDXLOCKOBJECTSNVPROC) (HANDLE hDevice, GLint count, HANDLE *hObjects);
typedef BOOL (WINAPI * PFNWGLDXUNLOCKOBJECTSNVPROC) (HANDLE hDevice, GLint count, HANDLE *hObjects);
extern BOOL (WINAPI * wglDXSetResourceShareHandleNV)(void *dxObject, HANDLE shareHandle);
extern HANDLE (WINAPI * wglDXOpenDeviceNV)(void *dxDevice);
extern BOOL (WINAPI * wglDXCloseDeviceNV)(HANDLE hDevice);
extern HANDLE (WINAPI * wglDXRegisterObjectNV)(HANDLE hDevice, void *dxObject, GLuint name, GLenum type, GLenum access);
extern BOOL (WINAPI * wglDXUnregisterObjectNV)(HANDLE hDevice, HANDLE hObject);
extern BOOL (WINAPI * wglDXObjectAccessNV)(HANDLE hObject, GLenum access);
extern BOOL (WINAPI * wglDXLockObjectsNV)(HANDLE hDevice, GLint count, HANDLE *hObjects);
extern BOOL (WINAPI * wglDXUnlockObjectsNV)(HANDLE hDevice, GLint count, HANDLE *hObjects);

typedef BOOL (WINAPI * PFNWGLCOPYIMAGESUBDATANVPROC) (HGLRC hSrcRC, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, HGLRC hDstRC, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth);
extern BOOL (WINAPI * wglCopyImageSubDataNV)(HGLRC hSrcRC, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, HGLRC hDstRC, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth);

typedef BOOL (WINAPI * PFNWGLDELAYBEFORESWAPNVPROC) (HDC hDC, GLfloat seconds);
extern BOOL (WINAPI * wglDelayBeforeSwapNV)(HDC hDC, GLfloat seconds);

#define WGL_FLOAT_COMPONENTS_NV           0x20B0
#define WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_R_NV 0x20B1
#define WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_RG_NV 0x20B2
#define WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_RGB_NV 0x20B3
#define WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_RGBA_NV 0x20B4
#define WGL_TEXTURE_FLOAT_R_NV            0x20B5
#define WGL_TEXTURE_FLOAT_RG_NV           0x20B6
#define WGL_TEXTURE_FLOAT_RGB_NV          0x20B7
#define WGL_TEXTURE_FLOAT_RGBA_NV         0x20B8

DECLARE_HANDLE(HGPUNV);
struct _GPU_DEVICE {
    DWORD  cb;
    CHAR   DeviceName[32];
    CHAR   DeviceString[128];
    DWORD  Flags;
    RECT   rcVirtualScreen;
};
typedef struct _GPU_DEVICE *PGPU_DEVICE;
#define ERROR_INCOMPATIBLE_AFFINITY_MASKS_NV 0x20D0
#define ERROR_MISSING_AFFINITY_MASK_NV    0x20D1
typedef BOOL (WINAPI * PFNWGLENUMGPUSNVPROC) (UINT iGpuIndex, HGPUNV *phGpu);
typedef BOOL (WINAPI * PFNWGLENUMGPUDEVICESNVPROC) (HGPUNV hGpu, UINT iDeviceIndex, PGPU_DEVICE lpGpuDevice);
typedef HDC (WINAPI * PFNWGLCREATEAFFINITYDCNVPROC) (const HGPUNV *phGpuList);
typedef BOOL (WINAPI * PFNWGLENUMGPUSFROMAFFINITYDCNVPROC) (HDC hAffinityDC, UINT iGpuIndex, HGPUNV *hGpu);
typedef BOOL (WINAPI * PFNWGLDELETEDCNVPROC) (HDC hdc);
extern BOOL (WINAPI * wglEnumGpusNV)(UINT iGpuIndex, HGPUNV *phGpu);
extern BOOL (WINAPI * wglEnumGpuDevicesNV)(HGPUNV hGpu, UINT iDeviceIndex, PGPU_DEVICE lpGpuDevice);
extern HDC (WINAPI * wglCreateAffinityDCNV)(const HGPUNV *phGpuList);
extern BOOL (WINAPI * wglEnumGpusFromAffinityDCNV)(HDC hAffinityDC, UINT iGpuIndex, HGPUNV *hGpu);
extern BOOL (WINAPI * wglDeleteDCNV)(HDC hdc);

#define WGL_COVERAGE_SAMPLES_NV           0x2042
#define WGL_COLOR_SAMPLES_NV              0x20B9

DECLARE_HANDLE(HVIDEOOUTPUTDEVICENV);
#define WGL_NUM_VIDEO_SLOTS_NV            0x20F0
typedef int (WINAPI * PFNWGLENUMERATEVIDEODEVICESNVPROC) (HDC hDC, HVIDEOOUTPUTDEVICENV *phDeviceList);
typedef BOOL (WINAPI * PFNWGLBINDVIDEODEVICENVPROC) (HDC hDC, unsigned int uVideoSlot, HVIDEOOUTPUTDEVICENV hVideoDevice, const int *piAttribList);
typedef BOOL (WINAPI * PFNWGLQUERYCURRENTCONTEXTNVPROC) (int iAttribute, int *piValue);
extern int (WINAPI * wglEnumerateVideoDevicesNV)(HDC hDC, HVIDEOOUTPUTDEVICENV *phDeviceList);
extern BOOL (WINAPI * wglBindVideoDeviceNV)(HDC hDC, unsigned int uVideoSlot, HVIDEOOUTPUTDEVICENV hVideoDevice, const int *piAttribList);
extern BOOL (WINAPI * wglQueryCurrentContextNV)(int iAttribute, int *piValue);

#define WGL_BIND_TO_TEXTURE_DEPTH_NV      0x20A3
#define WGL_BIND_TO_TEXTURE_RECTANGLE_DEPTH_NV 0x20A4
#define WGL_DEPTH_TEXTURE_FORMAT_NV       0x20A5
#define WGL_TEXTURE_DEPTH_COMPONENT_NV    0x20A6
#define WGL_DEPTH_COMPONENT_NV            0x20A7

#define WGL_BIND_TO_TEXTURE_RECTANGLE_RGB_NV 0x20A0
#define WGL_BIND_TO_TEXTURE_RECTANGLE_RGBA_NV 0x20A1
#define WGL_TEXTURE_RECTANGLE_NV          0x20A2

typedef BOOL (WINAPI * PFNWGLJOINSWAPGROUPNVPROC) (HDC hDC, GLuint group);
typedef BOOL (WINAPI * PFNWGLBINDSWAPBARRIERNVPROC) (GLuint group, GLuint barrier);
typedef BOOL (WINAPI * PFNWGLQUERYSWAPGROUPNVPROC) (HDC hDC, GLuint *group, GLuint *barrier);
typedef BOOL (WINAPI * PFNWGLQUERYMAXSWAPGROUPSNVPROC) (HDC hDC, GLuint *maxGroups, GLuint *maxBarriers);
typedef BOOL (WINAPI * PFNWGLQUERYFRAMECOUNTNVPROC) (HDC hDC, GLuint *count);
typedef BOOL (WINAPI * PFNWGLRESETFRAMECOUNTNVPROC) (HDC hDC);
extern BOOL (WINAPI * wglJoinSwapGroupNV)(HDC hDC, GLuint group);
extern BOOL (WINAPI * wglBindSwapBarrierNV)(GLuint group, GLuint barrier);
extern BOOL (WINAPI * wglQuerySwapGroupNV)(HDC hDC, GLuint *group, GLuint *barrier);
extern BOOL (WINAPI * wglQueryMaxSwapGroupsNV)(HDC hDC, GLuint *maxGroups, GLuint *maxBarriers);
extern BOOL (WINAPI * wglQueryFrameCountNV)(HDC hDC, GLuint *count);
extern BOOL (WINAPI * wglResetFrameCountNV)(HDC hDC);

typedef void *(WINAPI * PFNWGLALLOCATEMEMORYNVPROC) (GLsizei size, GLfloat readfreq, GLfloat writefreq, GLfloat priority);
typedef void (WINAPI * PFNWGLFREEMEMORYNVPROC) (void *pointer);
extern void *(WINAPI * wglAllocateMemoryNV)(GLsizei size, GLfloat readfreq, GLfloat writefreq, GLfloat priority);
extern void (WINAPI * wglFreeMemoryNV)(void *pointer);

DECLARE_HANDLE(HVIDEOINPUTDEVICENV);
#define WGL_UNIQUE_ID_NV                  0x20CE
#define WGL_NUM_VIDEO_CAPTURE_SLOTS_NV    0x20CF
typedef BOOL (WINAPI * PFNWGLBINDVIDEOCAPTUREDEVICENVPROC) (UINT uVideoSlot, HVIDEOINPUTDEVICENV hDevice);
typedef UINT (WINAPI * PFNWGLENUMERATEVIDEOCAPTUREDEVICESNVPROC) (HDC hDc, HVIDEOINPUTDEVICENV *phDeviceList);
typedef BOOL (WINAPI * PFNWGLLOCKVIDEOCAPTUREDEVICENVPROC) (HDC hDc, HVIDEOINPUTDEVICENV hDevice);
typedef BOOL (WINAPI * PFNWGLQUERYVIDEOCAPTUREDEVICENVPROC) (HDC hDc, HVIDEOINPUTDEVICENV hDevice, int iAttribute, int *piValue);
typedef BOOL (WINAPI * PFNWGLRELEASEVIDEOCAPTUREDEVICENVPROC) (HDC hDc, HVIDEOINPUTDEVICENV hDevice);
extern BOOL (WINAPI * wglBindVideoCaptureDeviceNV)(UINT uVideoSlot, HVIDEOINPUTDEVICENV hDevice);
extern UINT (WINAPI * wglEnumerateVideoCaptureDevicesNV)(HDC hDc, HVIDEOINPUTDEVICENV *phDeviceList);
extern BOOL (WINAPI * wglLockVideoCaptureDeviceNV)(HDC hDc, HVIDEOINPUTDEVICENV hDevice);
extern BOOL (WINAPI * wglQueryVideoCaptureDeviceNV)(HDC hDc, HVIDEOINPUTDEVICENV hDevice, int iAttribute, int *piValue);
extern BOOL (WINAPI * wglReleaseVideoCaptureDeviceNV)(HDC hDc, HVIDEOINPUTDEVICENV hDevice);

DECLARE_HANDLE(HPVIDEODEV);
#define WGL_BIND_TO_VIDEO_RGB_NV          0x20C0
#define WGL_BIND_TO_VIDEO_RGBA_NV         0x20C1
#define WGL_BIND_TO_VIDEO_RGB_AND_DEPTH_NV 0x20C2
#define WGL_VIDEO_OUT_COLOR_NV            0x20C3
#define WGL_VIDEO_OUT_ALPHA_NV            0x20C4
#define WGL_VIDEO_OUT_DEPTH_NV            0x20C5
#define WGL_VIDEO_OUT_COLOR_AND_ALPHA_NV  0x20C6
#define WGL_VIDEO_OUT_COLOR_AND_DEPTH_NV  0x20C7
#define WGL_VIDEO_OUT_FRAME               0x20C8
#define WGL_VIDEO_OUT_FIELD_1             0x20C9
#define WGL_VIDEO_OUT_FIELD_2             0x20CA
#define WGL_VIDEO_OUT_STACKED_FIELDS_1_2  0x20CB
#define WGL_VIDEO_OUT_STACKED_FIELDS_2_1  0x20CC
typedef BOOL (WINAPI * PFNWGLGETVIDEODEVICENVPROC) (HDC hDC, int numDevices, HPVIDEODEV *hVideoDevice);
typedef BOOL (WINAPI * PFNWGLRELEASEVIDEODEVICENVPROC) (HPVIDEODEV hVideoDevice);
typedef BOOL (WINAPI * PFNWGLBINDVIDEOIMAGENVPROC) (HPVIDEODEV hVideoDevice, HPBUFFERARB hPbuffer, int iVideoBuffer);
typedef BOOL (WINAPI * PFNWGLRELEASEVIDEOIMAGENVPROC) (HPBUFFERARB hPbuffer, int iVideoBuffer);
typedef BOOL (WINAPI * PFNWGLSENDPBUFFERTOVIDEONVPROC) (HPBUFFERARB hPbuffer, int iBufferType, unsigned long *pulCounterPbuffer, BOOL bBlock);
typedef BOOL (WINAPI * PFNWGLGETVIDEOINFONVPROC) (HPVIDEODEV hpVideoDevice, unsigned long *pulCounterOutputPbuffer, unsigned long *pulCounterOutputVideo);
extern BOOL (WINAPI * wglGetVideoDeviceNV)(HDC hDC, int numDevices, HPVIDEODEV *hVideoDevice);
extern BOOL (WINAPI * wglReleaseVideoDeviceNV)(HPVIDEODEV hVideoDevice);
extern BOOL (WINAPI * wglBindVideoImageNV)(HPVIDEODEV hVideoDevice, HPBUFFERARB hPbuffer, int iVideoBuffer);
extern BOOL (WINAPI * wglReleaseVideoImageNV)(HPBUFFERARB hPbuffer, int iVideoBuffer);
extern BOOL (WINAPI * wglSendPbufferToVideoNV)(HPBUFFERARB hPbuffer, int iBufferType, unsigned long *pulCounterPbuffer, BOOL bBlock);
extern BOOL (WINAPI * wglGetVideoInfoNV)(HPVIDEODEV hpVideoDevice, unsigned long *pulCounterOutputPbuffer, unsigned long *pulCounterOutputVideo);

typedef BOOL (WINAPI * PFNWGLGETSYNCVALUESOMLPROC) (HDC hdc, INT64 *ust, INT64 *msc, INT64 *sbc);
typedef BOOL (WINAPI * PFNWGLGETMSCRATEOMLPROC) (HDC hdc, INT32 *numerator, INT32 *denominator);
typedef INT64 (WINAPI * PFNWGLSWAPBUFFERSMSCOMLPROC) (HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder);
typedef INT64 (WINAPI * PFNWGLSWAPLAYERBUFFERSMSCOMLPROC) (HDC hdc, int fuPlanes, INT64 target_msc, INT64 divisor, INT64 remainder);
typedef BOOL (WINAPI * PFNWGLWAITFORMSCOMLPROC) (HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder, INT64 *ust, INT64 *msc, INT64 *sbc);
typedef BOOL (WINAPI * PFNWGLWAITFORSBCOMLPROC) (HDC hdc, INT64 target_sbc, INT64 *ust, INT64 *msc, INT64 *sbc);
extern BOOL (WINAPI * wglGetSyncValuesOML)(HDC hdc, INT64 *ust, INT64 *msc, INT64 *sbc);
extern BOOL (WINAPI * wglGetMscRateOML)(HDC hdc, INT32 *numerator, INT32 *denominator);
extern INT64 (WINAPI * wglSwapBuffersMscOML)(HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder);
extern INT64 (WINAPI * wglSwapLayerBuffersMscOML)(HDC hdc, int fuPlanes, INT64 target_msc, INT64 divisor, INT64 remainder);
extern BOOL (WINAPI * wglWaitForMscOML)(HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder, INT64 *ust, INT64 *msc, INT64 *sbc);
extern BOOL (WINAPI * wglWaitForSbcOML)(HDC hdc, INT64 target_sbc, INT64 *ust, INT64 *msc, INT64 *sbc);

// definitions of function pointers
#ifdef JUSTGL_IMPLEMENTATION
HANDLE (WINAPI * wglCreateBufferRegionARB)(HDC hDC, int iLayerPlane, UINT uType);
VOID (WINAPI * wglDeleteBufferRegionARB)(HANDLE hRegion);
BOOL (WINAPI * wglSaveBufferRegionARB)(HANDLE hRegion, int x, int y, int width, int height);
BOOL (WINAPI * wglRestoreBufferRegionARB)(HANDLE hRegion, int x, int y, int width, int height, int xSrc, int ySrc);
HGLRC (WINAPI * wglCreateContextAttribsARB)(HDC hDC, HGLRC hShareContext, const int *attribList);
const char *(WINAPI * wglGetExtensionsStringARB)(HDC hdc);
BOOL (WINAPI * wglMakeContextCurrentARB)(HDC hDrawDC, HDC hReadDC, HGLRC hglrc);
HDC (WINAPI * wglGetCurrentReadDCARB)(void);
HPBUFFERARB (WINAPI * wglCreatePbufferARB)(HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int *piAttribList);
HDC (WINAPI * wglGetPbufferDCARB)(HPBUFFERARB hPbuffer);
int (WINAPI * wglReleasePbufferDCARB)(HPBUFFERARB hPbuffer, HDC hDC);
BOOL (WINAPI * wglDestroyPbufferARB)(HPBUFFERARB hPbuffer);
BOOL (WINAPI * wglQueryPbufferARB)(HPBUFFERARB hPbuffer, int iAttribute, int *piValue);
BOOL (WINAPI * wglGetPixelFormatAttribivARB)(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int *piAttributes, int *piValues);
BOOL (WINAPI * wglGetPixelFormatAttribfvARB)(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int *piAttributes, FLOAT *pfValues);
BOOL (WINAPI * wglChoosePixelFormatARB)(HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats);
BOOL (WINAPI * wglBindTexImageARB)(HPBUFFERARB hPbuffer, int iBuffer);
BOOL (WINAPI * wglReleaseTexImageARB)(HPBUFFERARB hPbuffer, int iBuffer);
BOOL (WINAPI * wglSetPbufferAttribARB)(HPBUFFERARB hPbuffer, const int *piAttribList);
BOOL (WINAPI * wglSetStereoEmitterState3DL)(HDC hDC, UINT uState);
UINT (WINAPI * wglGetGPUIDsAMD)(UINT maxCount, UINT *ids);
INT (WINAPI * wglGetGPUInfoAMD)(UINT id, int property, GLenum dataType, UINT size, void *data);
UINT (WINAPI * wglGetContextGPUIDAMD)(HGLRC hglrc);
HGLRC (WINAPI * wglCreateAssociatedContextAMD)(UINT id);
HGLRC (WINAPI * wglCreateAssociatedContextAttribsAMD)(UINT id, HGLRC hShareContext, const int *attribList);
BOOL (WINAPI * wglDeleteAssociatedContextAMD)(HGLRC hglrc);
BOOL (WINAPI * wglMakeAssociatedContextCurrentAMD)(HGLRC hglrc);
HGLRC (WINAPI * wglGetCurrentAssociatedContextAMD)(void);
VOID (WINAPI * wglBlitContextFramebufferAMD)(HGLRC dstCtx, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
GLboolean (WINAPI * wglCreateDisplayColorTableEXT)(GLushort id);
GLboolean (WINAPI * wglLoadDisplayColorTableEXT)(const GLushort *table, GLuint length);
GLboolean (WINAPI * wglBindDisplayColorTableEXT)(GLushort id);
VOID (WINAPI * wglDestroyDisplayColorTableEXT)(GLushort id);
const char *(WINAPI * wglGetExtensionsStringEXT)(void);
BOOL (WINAPI * wglMakeContextCurrentEXT)(HDC hDrawDC, HDC hReadDC, HGLRC hglrc);
HDC (WINAPI * wglGetCurrentReadDCEXT)(void);
HPBUFFEREXT (WINAPI * wglCreatePbufferEXT)(HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int *piAttribList);
HDC (WINAPI * wglGetPbufferDCEXT)(HPBUFFEREXT hPbuffer);
int (WINAPI * wglReleasePbufferDCEXT)(HPBUFFEREXT hPbuffer, HDC hDC);
BOOL (WINAPI * wglDestroyPbufferEXT)(HPBUFFEREXT hPbuffer);
BOOL (WINAPI * wglQueryPbufferEXT)(HPBUFFEREXT hPbuffer, int iAttribute, int *piValue);
BOOL (WINAPI * wglGetPixelFormatAttribivEXT)(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int *piAttributes, int *piValues);
BOOL (WINAPI * wglGetPixelFormatAttribfvEXT)(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int *piAttributes, FLOAT *pfValues);
BOOL (WINAPI * wglChoosePixelFormatEXT)(HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats);
BOOL (WINAPI * wglSwapIntervalEXT)(int interval);
int (WINAPI * wglGetSwapIntervalEXT)(void);
BOOL (WINAPI * wglGetDigitalVideoParametersI3D)(HDC hDC, int iAttribute, int *piValue);
BOOL (WINAPI * wglSetDigitalVideoParametersI3D)(HDC hDC, int iAttribute, const int *piValue);
BOOL (WINAPI * wglGetGammaTableParametersI3D)(HDC hDC, int iAttribute, int *piValue);
BOOL (WINAPI * wglSetGammaTableParametersI3D)(HDC hDC, int iAttribute, const int *piValue);
BOOL (WINAPI * wglGetGammaTableI3D)(HDC hDC, int iEntries, USHORT *puRed, USHORT *puGreen, USHORT *puBlue);
BOOL (WINAPI * wglSetGammaTableI3D)(HDC hDC, int iEntries, const USHORT *puRed, const USHORT *puGreen, const USHORT *puBlue);
BOOL (WINAPI * wglEnableGenlockI3D)(HDC hDC);
BOOL (WINAPI * wglDisableGenlockI3D)(HDC hDC);
BOOL (WINAPI * wglIsEnabledGenlockI3D)(HDC hDC, BOOL *pFlag);
BOOL (WINAPI * wglGenlockSourceI3D)(HDC hDC, UINT uSource);
BOOL (WINAPI * wglGetGenlockSourceI3D)(HDC hDC, UINT *uSource);
BOOL (WINAPI * wglGenlockSourceEdgeI3D)(HDC hDC, UINT uEdge);
BOOL (WINAPI * wglGetGenlockSourceEdgeI3D)(HDC hDC, UINT *uEdge);
BOOL (WINAPI * wglGenlockSampleRateI3D)(HDC hDC, UINT uRate);
BOOL (WINAPI * wglGetGenlockSampleRateI3D)(HDC hDC, UINT *uRate);
BOOL (WINAPI * wglGenlockSourceDelayI3D)(HDC hDC, UINT uDelay);
BOOL (WINAPI * wglGetGenlockSourceDelayI3D)(HDC hDC, UINT *uDelay);
BOOL (WINAPI * wglQueryGenlockMaxSourceDelayI3D)(HDC hDC, UINT *uMaxLineDelay, UINT *uMaxPixelDelay);
LPVOID (WINAPI * wglCreateImageBufferI3D)(HDC hDC, DWORD dwSize, UINT uFlags);
BOOL (WINAPI * wglDestroyImageBufferI3D)(HDC hDC, LPVOID pAddress);
BOOL (WINAPI * wglAssociateImageBufferEventsI3D)(HDC hDC, const HANDLE *pEvent, const LPVOID *pAddress, const DWORD *pSize, UINT count);
BOOL (WINAPI * wglReleaseImageBufferEventsI3D)(HDC hDC, const LPVOID *pAddress, UINT count);
BOOL (WINAPI * wglEnableFrameLockI3D)(void);
BOOL (WINAPI * wglDisableFrameLockI3D)(void);
BOOL (WINAPI * wglIsEnabledFrameLockI3D)(BOOL *pFlag);
BOOL (WINAPI * wglQueryFrameLockMasterI3D)(BOOL *pFlag);
BOOL (WINAPI * wglGetFrameUsageI3D)(float *pUsage);
BOOL (WINAPI * wglBeginFrameTrackingI3D)(void);
BOOL (WINAPI * wglEndFrameTrackingI3D)(void);
BOOL (WINAPI * wglQueryFrameTrackingI3D)(DWORD *pFrameCount, DWORD *pMissedFrames, float *pLastMissedUsage);
BOOL (WINAPI * wglDXSetResourceShareHandleNV)(void *dxObject, HANDLE shareHandle);
HANDLE (WINAPI * wglDXOpenDeviceNV)(void *dxDevice);
BOOL (WINAPI * wglDXCloseDeviceNV)(HANDLE hDevice);
HANDLE (WINAPI * wglDXRegisterObjectNV)(HANDLE hDevice, void *dxObject, GLuint name, GLenum type, GLenum access);
BOOL (WINAPI * wglDXUnregisterObjectNV)(HANDLE hDevice, HANDLE hObject);
BOOL (WINAPI * wglDXObjectAccessNV)(HANDLE hObject, GLenum access);
BOOL (WINAPI * wglDXLockObjectsNV)(HANDLE hDevice, GLint count, HANDLE *hObjects);
BOOL (WINAPI * wglDXUnlockObjectsNV)(HANDLE hDevice, GLint count, HANDLE *hObjects);
BOOL (WINAPI * wglCopyImageSubDataNV)(HGLRC hSrcRC, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, HGLRC hDstRC, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth);
BOOL (WINAPI * wglDelayBeforeSwapNV)(HDC hDC, GLfloat seconds);
BOOL (WINAPI * wglEnumGpusNV)(UINT iGpuIndex, HGPUNV *phGpu);
BOOL (WINAPI * wglEnumGpuDevicesNV)(HGPUNV hGpu, UINT iDeviceIndex, PGPU_DEVICE lpGpuDevice);
HDC (WINAPI * wglCreateAffinityDCNV)(const HGPUNV *phGpuList);
BOOL (WINAPI * wglEnumGpusFromAffinityDCNV)(HDC hAffinityDC, UINT iGpuIndex, HGPUNV *hGpu);
BOOL (WINAPI * wglDeleteDCNV)(HDC hdc);
int (WINAPI * wglEnumerateVideoDevicesNV)(HDC hDC, HVIDEOOUTPUTDEVICENV *phDeviceList);
BOOL (WINAPI * wglBindVideoDeviceNV)(HDC hDC, unsigned int uVideoSlot, HVIDEOOUTPUTDEVICENV hVideoDevice, const int *piAttribList);
BOOL (WINAPI * wglQueryCurrentContextNV)(int iAttribute, int *piValue);
BOOL (WINAPI * wglJoinSwapGroupNV)(HDC hDC, GLuint group);
BOOL (WINAPI * wglBindSwapBarrierNV)(GLuint group, GLuint barrier);
BOOL (WINAPI * wglQuerySwapGroupNV)(HDC hDC, GLuint *group, GLuint *barrier);
BOOL (WINAPI * wglQueryMaxSwapGroupsNV)(HDC hDC, GLuint *maxGroups, GLuint *maxBarriers);
BOOL (WINAPI * wglQueryFrameCountNV)(HDC hDC, GLuint *count);
BOOL (WINAPI * wglResetFrameCountNV)(HDC hDC);
void *(WINAPI * wglAllocateMemoryNV)(GLsizei size, GLfloat readfreq, GLfloat writefreq, GLfloat priority);
void (WINAPI * wglFreeMemoryNV)(void *pointer);
BOOL (WINAPI * wglBindVideoCaptureDeviceNV)(UINT uVideoSlot, HVIDEOINPUTDEVICENV hDevice);
UINT (WINAPI * wglEnumerateVideoCaptureDevicesNV)(HDC hDc, HVIDEOINPUTDEVICENV *phDeviceList);
BOOL (WINAPI * wglLockVideoCaptureDeviceNV)(HDC hDc, HVIDEOINPUTDEVICENV hDevice);
BOOL (WINAPI * wglQueryVideoCaptureDeviceNV)(HDC hDc, HVIDEOINPUTDEVICENV hDevice, int iAttribute, int *piValue);
BOOL (WINAPI * wglReleaseVideoCaptureDeviceNV)(HDC hDc, HVIDEOINPUTDEVICENV hDevice);
BOOL (WINAPI * wglGetVideoDeviceNV)(HDC hDC, int numDevices, HPVIDEODEV *hVideoDevice);
BOOL (WINAPI * wglReleaseVideoDeviceNV)(HPVIDEODEV hVideoDevice);
BOOL (WINAPI * wglBindVideoImageNV)(HPVIDEODEV hVideoDevice, HPBUFFERARB hPbuffer, int iVideoBuffer);
BOOL (WINAPI * wglReleaseVideoImageNV)(HPBUFFERARB hPbuffer, int iVideoBuffer);
BOOL (WINAPI * wglSendPbufferToVideoNV)(HPBUFFERARB hPbuffer, int iBufferType, unsigned long *pulCounterPbuffer, BOOL bBlock);
BOOL (WINAPI * wglGetVideoInfoNV)(HPVIDEODEV hpVideoDevice, unsigned long *pulCounterOutputPbuffer, unsigned long *pulCounterOutputVideo);
BOOL (WINAPI * wglGetSyncValuesOML)(HDC hdc, INT64 *ust, INT64 *msc, INT64 *sbc);
BOOL (WINAPI * wglGetMscRateOML)(HDC hdc, INT32 *numerator, INT32 *denominator);
INT64 (WINAPI * wglSwapBuffersMscOML)(HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder);
INT64 (WINAPI * wglSwapLayerBuffersMscOML)(HDC hdc, int fuPlanes, INT64 target_msc, INT64 divisor, INT64 remainder);
BOOL (WINAPI * wglWaitForMscOML)(HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder, INT64 *ust, INT64 *msc, INT64 *sbc);
BOOL (WINAPI * wglWaitForSbcOML)(HDC hdc, INT64 target_sbc, INT64 *ust, INT64 *msc, INT64 *sbc);
#endif // JUSTGL_IMPLEMENTATION

#endif // __wglext_h_

#endif // _WIN32

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
    GLuint baseVertex;
    GLuint baseInstance;
} GLDrawElementsIndirectCommand;

#endif // JUSTGL_H_INCLUDED

#ifdef JUSTGL_IMPLEMENTATION

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

// internal forward declarations
void InitJGLProcs();

void InitDefaultWindowConfig(WindowConfig* pConfig)
{
    pConfig->ClientWidth = 640;
    pConfig->ClientHeight = 480;
    pConfig->WindowTitle = "JustGL";

    pConfig->MajorGLVersion = 3;
    pConfig->MinorGLVersion = 2;

#ifdef NDEBUG
    pConfig->DebugContext = 0;
#else
    pConfig->DebugContext = 1;
#endif
    pConfig->ForwardCompatibleContext = 0;
    pConfig->CompatibilityProfileContext = 0;

    pConfig->EnableFramebufferDepth = 1;
    pConfig->EnableFramebufferStencil = 1;
    pConfig->MultisampleCount = 1;
    pConfig->FramebufferSRGBCapable = 0;
}

// argh C++
#ifdef __cplusplus
#define PROC_CAST *(void**)&
#else
#define PROC_CAST
#endif

#ifdef _WIN32

HMODULE g_hModuleOpenGL32;
HWND g_hWnd;
HDC g_hDC;
HGLRC g_hGLRC;

typedef HGLRC(WINAPI * PFNWGLCREATECONTEXT) (HDC hdc);
typedef BOOL(WINAPI * PFNWGLDELETECONTEXT) (HGLRC hglrc);
typedef BOOL(WINAPI * PFNWGLMAKECURRENT) (HDC hdc, HGLRC hglrc);
typedef PROC(WINAPI * PFNWGLGETPROCADDRESS) (LPCSTR lpszProc);

PFNWGLCREATECONTEXT pfnwglCreateContext;
PFNWGLDELETECONTEXT pfnwglDeleteContext;
PFNWGLMAKECURRENT pfnwglMakeCurrent;
PFNWGLGETPROCADDRESS pfnwglGetProcAddress;

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
    if (b)
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

void AssertWGL(BOOL b)
{
    if (b)
    {
        return;
    }

    DWORD id = GetLastError() & 0xFFFF;

    char buf[256];
    sprintf_s(buf, sizeof(buf), "WGL error: %s, id %d",
        id == ERROR_INVALID_VERSION_ARB ? "ERROR_INVALID_VERSION_ARB" :
        id == ERROR_INVALID_PROFILE_ARB ? "ERROR_INVALID_PROFILE_ARB" :
        id == ERROR_INVALID_PIXEL_TYPE_ARB ? "ERROR_INVALID_PIXEL_TYPE_ARB" :
        id == ERROR_INCOMPATIBLE_DEVICE_CONTEXTS_ARB ? "ERROR_INCOMPATIBLE_DEVICE_CONTEXTS_ARB" :
        id == ERROR_INCOMPATIBLE_AFFINITY_MASKS_NV ? "ERROR_INCOMPATIBLE_AFFINITY_MASKS_NV" :
        id == ERROR_MISSING_AFFINITY_MASK_NV ? "ERROR_MISSING_AFFINITY_MASK_NV" :
        "(unknown)",
        id);

    int choice = MessageBoxA(g_hWnd, buf, NULL, MB_ABORTRETRYIGNORE);
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

void InitJGL(const WindowConfig& config)
{
    g_hModuleOpenGL32 = LoadLibraryW(L"opengl32.dll");
    AssertWin32(g_hModuleOpenGL32 != NULL);

    PROC_CAST pfnwglCreateContext = GetProcAddress(g_hModuleOpenGL32, "wglCreateContext");
    AssertWin32(pfnwglCreateContext != NULL);
    PROC_CAST pfnwglDeleteContext = GetProcAddress(g_hModuleOpenGL32, "wglDeleteContext");
    AssertWin32(pfnwglDeleteContext != NULL);
    PROC_CAST pfnwglMakeCurrent = GetProcAddress(g_hModuleOpenGL32, "wglMakeCurrent");
    AssertWin32(pfnwglMakeCurrent != NULL);
    PROC_CAST pfnwglGetProcAddress = GetProcAddress(g_hModuleOpenGL32, "wglGetProcAddress");
    AssertWin32(pfnwglGetProcAddress != NULL);

    HMODULE hInstance = GetModuleHandle(NULL);
    AssertWin32(hInstance != NULL);

    static const LPWSTR kWindowClassName = L"WindowClass";

    WNDCLASSEXW wc;
    ZeroMemory(&wc, sizeof(wc));
    wc.cbSize = sizeof(wc);
    wc.style = CS_OWNDC;
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpszClassName = kWindowClassName;
    AssertWin32(RegisterClassExW(&wc) != 0);

    // Have to create a basic window to create a basic context to create a fancy context...
    HWND hWnd_basic = CreateWindowW(kWindowClassName, L"basic", 0, 0, 0, 0, 0, 0, 0, hInstance, 0);
    AssertWin32(hWnd_basic != NULL);

    HDC hDC_basic = GetDC(hWnd_basic);
    AssertWin32(hDC_basic != NULL);

    PIXELFORMATDESCRIPTOR pfd;
    ZeroMemory(&pfd, sizeof(pfd));
    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 32;
    pfd.cDepthBits = config.EnableFramebufferDepth ? 24 : 0;
    pfd.cStencilBits = config.EnableFramebufferDepth ? 8 : 0;
    pfd.iLayerType = PFD_MAIN_PLANE;

    int basicPixelFormat = ChoosePixelFormat(hDC_basic, &pfd);
    AssertWin32(basicPixelFormat != 0);
    AssertWin32(SetPixelFormat(hDC_basic, basicPixelFormat, &pfd));

    HGLRC hGLRC_basic = pfnwglCreateContext(hDC_basic);
    AssertWin32(hGLRC_basic != NULL);

    AssertWin32(pfnwglMakeCurrent(hDC_basic, hGLRC_basic));

    PFNWGLCHOOSEPIXELFORMATARBPROC pfnwglChoosePixelFormatARB;
    PFNWGLCREATECONTEXTATTRIBSARBPROC pfnwglCreateContextAttribsARB;

    PROC_CAST pfnwglChoosePixelFormatARB = pfnwglGetProcAddress("wglChoosePixelFormatARB");
    PROC_CAST pfnwglCreateContextAttribsARB = pfnwglGetProcAddress("wglCreateContextAttribsARB");

    int fancyPixelFormat = basicPixelFormat;
    if (pfnwglChoosePixelFormatARB != NULL)
    {
        // Can get a fancier pixel format!
        static const int kMaxAttribs = 256;
        int attribs[kMaxAttribs * 2 + 1];
        
        int unconditionalAttribs[] = {
            WGL_DRAW_TO_WINDOW_ARB,   GL_TRUE,
            WGL_ACCELERATION_ARB,     WGL_FULL_ACCELERATION_ARB,
            WGL_SUPPORT_OPENGL_ARB,   GL_TRUE,
            WGL_DOUBLE_BUFFER_ARB,    GL_TRUE,
            WGL_RED_BITS_ARB,         8,
            WGL_GREEN_BITS_ARB,       8,
            WGL_BLUE_BITS_ARB,        8,
            WGL_ALPHA_BITS_ARB,       8,
            WGL_ACCUM_BITS_ARB,       0,
            WGL_ACCUM_RED_BITS_ARB,   0,
            WGL_ACCUM_GREEN_BITS_ARB, 0,
            WGL_ACCUM_BLUE_BITS_ARB,  0,
            WGL_ACCUM_ALPHA_BITS_ARB, 0,
            WGL_PIXEL_TYPE_ARB,       WGL_TYPE_RGBA_ARB,
            WGL_COLOR_BITS_ARB,       32,
            WGL_DEPTH_BITS_ARB,       config.EnableFramebufferDepth ? 24 : 0,
            WGL_STENCIL_BITS_ARB,     config.EnableFramebufferStencil ? 8 : 0,
            WGL_AUX_BUFFERS_ARB,      0
        };

        int currAttrib = 0;
        for (int i = 0; i < sizeof(unconditionalAttribs) / sizeof(*unconditionalAttribs) / 2; i++)
        {
            attribs[currAttrib * 2 + 0] = unconditionalAttribs[i * 2 + 0];
            attribs[currAttrib * 2 + 1] = unconditionalAttribs[i * 2 + 1];
            currAttrib++;
        }

        if (config.MultisampleCount > 1)
        {
            attribs[currAttrib * 2 + 0] = WGL_SAMPLE_BUFFERS_ARB;
            attribs[currAttrib * 2 + 1] = 1;
            currAttrib++;

            attribs[currAttrib * 2 + 0] = WGL_SAMPLES_ARB;
            attribs[currAttrib * 2 + 1] = config.MultisampleCount;
            currAttrib++;
        }

        if (config.FramebufferSRGBCapable)
        {
            attribs[currAttrib * 2 + 0] = WGL_FRAMEBUFFER_SRGB_CAPABLE_ARB;
            attribs[currAttrib * 2 + 1] = GL_TRUE;
            currAttrib++;
        }

        assert(currAttrib < kMaxAttribs);

        attribs[currAttrib * 2] = 0;

        UINT numSupportedFormats;
        AssertWGL(pfnwglChoosePixelFormatARB(hDC_basic, attribs, NULL, 1, &fancyPixelFormat, &numSupportedFormats));
        if (numSupportedFormats > 0)
        {
            AssertWin32(DescribePixelFormat(hDC_basic, fancyPixelFormat, sizeof(pfd), &pfd));
        }
    }

    HWND hWnd = hWnd_basic;
    HDC hDC = hDC_basic;
    HGLRC hGLRC = hGLRC_basic;

    if (pfnwglCreateContextAttribsARB != NULL || fancyPixelFormat != basicPixelFormat)
    {
        HWND hWnd_fancy = CreateWindowW(kWindowClassName, L"fancy", 0, 0, 0, 0, 0, 0, 0, hInstance, 0);
        AssertWin32(hWnd_fancy != NULL);

        HDC hDC_fancy = GetDC(hWnd_fancy);
        AssertWin32(hDC_fancy != NULL);

        AssertWin32(SetPixelFormat(hDC_fancy, fancyPixelFormat, &pfd));

        HGLRC hGLRC_fancy;
        if (pfnwglCreateContextAttribsARB != NULL)
        {
            int contextFlags = 0;
            if (config.DebugContext) 
            {
                contextFlags |= WGL_CONTEXT_DEBUG_BIT_ARB;
            }
            if (config.ForwardCompatibleContext)
            {
                contextFlags |= WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB;
            }

            int contextProfileMask = 0;
            if (config.CompatibilityProfileContext)
            {
                contextProfileMask = WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB;
            }
            else
            {
                contextProfileMask = WGL_CONTEXT_CORE_PROFILE_BIT_ARB;
            }

            int contextAttribs[] = {
                WGL_CONTEXT_MAJOR_VERSION_ARB, config.MajorGLVersion,
                WGL_CONTEXT_MINOR_VERSION_ARB, config.MinorGLVersion,
                WGL_CONTEXT_FLAGS_ARB, contextFlags,
                WGL_CONTEXT_PROFILE_MASK_ARB, contextProfileMask,
                0
            };

            hGLRC_fancy = pfnwglCreateContextAttribsARB(hDC_fancy, NULL, contextAttribs);
            AssertWGL(hGLRC_fancy != NULL);
        }
        else
        {
            hGLRC_fancy = pfnwglCreateContext(hDC_fancy);
            AssertWGL(hGLRC_fancy != NULL);
        }

        AssertWin32(pfnwglMakeCurrent(NULL, NULL));
        AssertWin32(pfnwglDeleteContext(hGLRC_basic));
        AssertWin32(DestroyWindow(hWnd_basic));
        
        AssertWin32(pfnwglMakeCurrent(hDC_fancy, hGLRC_fancy));

        hGLRC = hGLRC_fancy;
        hDC = hDC_fancy;
        hWnd = hWnd_fancy;
    }

    wchar_t* wtitle = (wchar_t*)malloc(sizeof(wchar_t) * (strlen(config.WindowTitle) + 1));
    int i;
    for (i = 0; config.WindowTitle[i] != '\0'; i++)
    {
        wtitle[i] = config.WindowTitle[i];
    }
    wtitle[i] = '\0';

    AssertWin32(SetWindowTextW(hWnd, wtitle));
    free(wtitle);

    g_hWnd = hWnd;
    g_hDC = hDC;
    g_hGLRC = hGLRC;
}

int main()
{
    WindowConfig config;
    InitDefaultWindowConfig(&config);
    ConfigGL(&config);
    
    InitJGL(config);
    InitJGLProcs();

    // Initial resizing of the window
    DWORD dwStyle = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX;
    SetLastError(0);
    AssertWin32(SetWindowLong(g_hWnd, GWL_STYLE, dwStyle) != 0 || GetLastError() == 0);
    
    RECT wr = { 0, 0, config.ClientWidth, config.ClientHeight };
    AssertWin32(AdjustWindowRect(&wr, dwStyle, FALSE) != 0);
    AssertWin32(SetWindowPos(g_hWnd, HWND_NOTOPMOST, 0, 0, wr.right - wr.left, wr.bottom - wr.top, SWP_NOMOVE));

    ShowWindow(g_hWnd, SW_SHOWNORMAL);

    InitGL();

    for (;;)
    {
        AssertWin32(pfnwglMakeCurrent(g_hDC, g_hGLRC));

        MSG msg;
        while (PeekMessageW(&msg, NULL, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessageW(&msg);
        }

        PaintGL();

        AssertWin32(SwapBuffers(g_hDC));
    }

    return 0;
}
#endif // _WIN32

// cross-platform OpenGL proc setup
void InitJGLProcs()
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

    // wglext functions
#ifdef _WIN32
    PROC_CAST wglCreateBufferRegionARB = GetProcGL("wglCreateBufferRegionARB");
    PROC_CAST wglDeleteBufferRegionARB = GetProcGL("wglDeleteBufferRegionARB");
    PROC_CAST wglSaveBufferRegionARB = GetProcGL("wglSaveBufferRegionARB");
    PROC_CAST wglRestoreBufferRegionARB = GetProcGL("wglRestoreBufferRegionARB");
    PROC_CAST wglCreateContextAttribsARB = GetProcGL("wglCreateContextAttribsARB");
    PROC_CAST wglGetExtensionsStringARB = GetProcGL("wglGetExtensionsStringARB");
    PROC_CAST wglMakeContextCurrentARB = GetProcGL("wglMakeContextCurrentARB");
    PROC_CAST wglGetCurrentReadDCARB = GetProcGL("wglGetCurrentReadDCARB");
    PROC_CAST wglCreatePbufferARB = GetProcGL("wglCreatePbufferARB");
    PROC_CAST wglGetPbufferDCARB = GetProcGL("wglGetPbufferDCARB");
    PROC_CAST wglReleasePbufferDCARB = GetProcGL("wglReleasePbufferDCARB");
    PROC_CAST wglDestroyPbufferARB = GetProcGL("wglDestroyPbufferARB");
    PROC_CAST wglQueryPbufferARB = GetProcGL("wglQueryPbufferARB");
    PROC_CAST wglGetPixelFormatAttribivARB = GetProcGL("wglGetPixelFormatAttribivARB");
    PROC_CAST wglGetPixelFormatAttribfvARB = GetProcGL("wglGetPixelFormatAttribfvARB");
    PROC_CAST wglChoosePixelFormatARB = GetProcGL("wglChoosePixelFormatARB");
    PROC_CAST wglBindTexImageARB = GetProcGL("wglBindTexImageARB");
    PROC_CAST wglReleaseTexImageARB = GetProcGL("wglReleaseTexImageARB");
    PROC_CAST wglSetPbufferAttribARB = GetProcGL("wglSetPbufferAttribARB");
    PROC_CAST wglSetStereoEmitterState3DL = GetProcGL("wglSetStereoEmitterState3DL");
    PROC_CAST wglGetGPUIDsAMD = GetProcGL("wglGetGPUIDsAMD");
    PROC_CAST wglGetGPUInfoAMD = GetProcGL("wglGetGPUInfoAMD");
    PROC_CAST wglGetContextGPUIDAMD = GetProcGL("wglGetContextGPUIDAMD");
    PROC_CAST wglCreateAssociatedContextAMD = GetProcGL("wglCreateAssociatedContextAMD");
    PROC_CAST wglCreateAssociatedContextAttribsAMD = GetProcGL("wglCreateAssociatedContextAttribsAMD");
    PROC_CAST wglDeleteAssociatedContextAMD = GetProcGL("wglDeleteAssociatedContextAMD");
    PROC_CAST wglMakeAssociatedContextCurrentAMD = GetProcGL("wglMakeAssociatedContextCurrentAMD");
    PROC_CAST wglGetCurrentAssociatedContextAMD = GetProcGL("wglGetCurrentAssociatedContextAMD");
    PROC_CAST wglBlitContextFramebufferAMD = GetProcGL("wglBlitContextFramebufferAMD");
    PROC_CAST wglCreateDisplayColorTableEXT = GetProcGL("wglCreateDisplayColorTableEXT");
    PROC_CAST wglLoadDisplayColorTableEXT = GetProcGL("wglLoadDisplayColorTableEXT");
    PROC_CAST wglBindDisplayColorTableEXT = GetProcGL("wglBindDisplayColorTableEXT");
    PROC_CAST wglDestroyDisplayColorTableEXT = GetProcGL("wglDestroyDisplayColorTableEXT");
    PROC_CAST wglGetExtensionsStringEXT = GetProcGL("wglGetExtensionsStringEXT");
    PROC_CAST wglMakeContextCurrentEXT = GetProcGL("wglMakeContextCurrentEXT");
    PROC_CAST wglGetCurrentReadDCEXT = GetProcGL("wglGetCurrentReadDCEXT");
    PROC_CAST wglCreatePbufferEXT = GetProcGL("wglCreatePbufferEXT");
    PROC_CAST wglGetPbufferDCEXT = GetProcGL("wglGetPbufferDCEXT");
    PROC_CAST wglReleasePbufferDCEXT = GetProcGL("wglReleasePbufferDCEXT");
    PROC_CAST wglDestroyPbufferEXT = GetProcGL("wglDestroyPbufferEXT");
    PROC_CAST wglQueryPbufferEXT = GetProcGL("wglQueryPbufferEXT");
    PROC_CAST wglGetPixelFormatAttribivEXT = GetProcGL("wglGetPixelFormatAttribivEXT");
    PROC_CAST wglGetPixelFormatAttribfvEXT = GetProcGL("wglGetPixelFormatAttribfvEXT");
    PROC_CAST wglChoosePixelFormatEXT = GetProcGL("wglChoosePixelFormatEXT");
    PROC_CAST wglSwapIntervalEXT = GetProcGL("wglSwapIntervalEXT");
    PROC_CAST wglGetSwapIntervalEXT = GetProcGL("wglGetSwapIntervalEXT");
    PROC_CAST wglGetDigitalVideoParametersI3D = GetProcGL("wglGetDigitalVideoParametersI3D");
    PROC_CAST wglSetDigitalVideoParametersI3D = GetProcGL("wglSetDigitalVideoParametersI3D");
    PROC_CAST wglGetGammaTableParametersI3D = GetProcGL("wglGetGammaTableParametersI3D");
    PROC_CAST wglSetGammaTableParametersI3D = GetProcGL("wglSetGammaTableParametersI3D");
    PROC_CAST wglGetGammaTableI3D = GetProcGL("wglGetGammaTableI3D");
    PROC_CAST wglSetGammaTableI3D = GetProcGL("wglSetGammaTableI3D");
    PROC_CAST wglEnableGenlockI3D = GetProcGL("wglEnableGenlockI3D");
    PROC_CAST wglDisableGenlockI3D = GetProcGL("wglDisableGenlockI3D");
    PROC_CAST wglIsEnabledGenlockI3D = GetProcGL("wglIsEnabledGenlockI3D");
    PROC_CAST wglGenlockSourceI3D = GetProcGL("wglGenlockSourceI3D");
    PROC_CAST wglGetGenlockSourceI3D = GetProcGL("wglGetGenlockSourceI3D");
    PROC_CAST wglGenlockSourceEdgeI3D = GetProcGL("wglGenlockSourceEdgeI3D");
    PROC_CAST wglGetGenlockSourceEdgeI3D = GetProcGL("wglGetGenlockSourceEdgeI3D");
    PROC_CAST wglGenlockSampleRateI3D = GetProcGL("wglGenlockSampleRateI3D");
    PROC_CAST wglGetGenlockSampleRateI3D = GetProcGL("wglGetGenlockSampleRateI3D");
    PROC_CAST wglGenlockSourceDelayI3D = GetProcGL("wglGenlockSourceDelayI3D");
    PROC_CAST wglGetGenlockSourceDelayI3D = GetProcGL("wglGetGenlockSourceDelayI3D");
    PROC_CAST wglQueryGenlockMaxSourceDelayI3D = GetProcGL("wglQueryGenlockMaxSourceDelayI3D");
    PROC_CAST wglCreateImageBufferI3D = GetProcGL("wglCreateImageBufferI3D");
    PROC_CAST wglDestroyImageBufferI3D = GetProcGL("wglDestroyImageBufferI3D");
    PROC_CAST wglAssociateImageBufferEventsI3D = GetProcGL("wglAssociateImageBufferEventsI3D");
    PROC_CAST wglReleaseImageBufferEventsI3D = GetProcGL("wglReleaseImageBufferEventsI3D");
    PROC_CAST wglEnableFrameLockI3D = GetProcGL("wglEnableFrameLockI3D");
    PROC_CAST wglDisableFrameLockI3D = GetProcGL("wglDisableFrameLockI3D");
    PROC_CAST wglIsEnabledFrameLockI3D = GetProcGL("wglIsEnabledFrameLockI3D");
    PROC_CAST wglQueryFrameLockMasterI3D = GetProcGL("wglQueryFrameLockMasterI3D");
    PROC_CAST wglGetFrameUsageI3D = GetProcGL("wglGetFrameUsageI3D");
    PROC_CAST wglBeginFrameTrackingI3D = GetProcGL("wglBeginFrameTrackingI3D");
    PROC_CAST wglEndFrameTrackingI3D = GetProcGL("wglEndFrameTrackingI3D");
    PROC_CAST wglQueryFrameTrackingI3D = GetProcGL("wglQueryFrameTrackingI3D");
    PROC_CAST wglDXSetResourceShareHandleNV = GetProcGL("wglDXSetResourceShareHandleNV");
    PROC_CAST wglDXOpenDeviceNV = GetProcGL("wglDXOpenDeviceNV");
    PROC_CAST wglDXCloseDeviceNV = GetProcGL("wglDXCloseDeviceNV");
    PROC_CAST wglDXRegisterObjectNV = GetProcGL("wglDXRegisterObjectNV");
    PROC_CAST wglDXUnregisterObjectNV = GetProcGL("wglDXUnregisterObjectNV");
    PROC_CAST wglDXObjectAccessNV = GetProcGL("wglDXObjectAccessNV");
    PROC_CAST wglDXLockObjectsNV = GetProcGL("wglDXLockObjectsNV");
    PROC_CAST wglDXUnlockObjectsNV = GetProcGL("wglDXUnlockObjectsNV");
    PROC_CAST wglCopyImageSubDataNV = GetProcGL("wglCopyImageSubDataNV");
    PROC_CAST wglDelayBeforeSwapNV = GetProcGL("wglDelayBeforeSwapNV");
    PROC_CAST wglEnumGpusNV = GetProcGL("wglEnumGpusNV");
    PROC_CAST wglEnumGpuDevicesNV = GetProcGL("wglEnumGpuDevicesNV");
    PROC_CAST wglCreateAffinityDCNV = GetProcGL("wglCreateAffinityDCNV");
    PROC_CAST wglEnumGpusFromAffinityDCNV = GetProcGL("wglEnumGpusFromAffinityDCNV");
    PROC_CAST wglDeleteDCNV = GetProcGL("wglDeleteDCNV");
    PROC_CAST wglEnumerateVideoDevicesNV = GetProcGL("wglEnumerateVideoDevicesNV");
    PROC_CAST wglBindVideoDeviceNV = GetProcGL("wglBindVideoDeviceNV");
    PROC_CAST wglQueryCurrentContextNV = GetProcGL("wglQueryCurrentContextNV");
    PROC_CAST wglJoinSwapGroupNV = GetProcGL("wglJoinSwapGroupNV");
    PROC_CAST wglBindSwapBarrierNV = GetProcGL("wglBindSwapBarrierNV");
    PROC_CAST wglQuerySwapGroupNV = GetProcGL("wglQuerySwapGroupNV");
    PROC_CAST wglQueryMaxSwapGroupsNV = GetProcGL("wglQueryMaxSwapGroupsNV");
    PROC_CAST wglQueryFrameCountNV = GetProcGL("wglQueryFrameCountNV");
    PROC_CAST wglResetFrameCountNV = GetProcGL("wglResetFrameCountNV");
    PROC_CAST wglAllocateMemoryNV = GetProcGL("wglAllocateMemoryNV");
    PROC_CAST wglFreeMemoryNV = GetProcGL("wglFreeMemoryNV");
    PROC_CAST wglBindVideoCaptureDeviceNV = GetProcGL("wglBindVideoCaptureDeviceNV");
    PROC_CAST wglEnumerateVideoCaptureDevicesNV = GetProcGL("wglEnumerateVideoCaptureDevicesNV");
    PROC_CAST wglLockVideoCaptureDeviceNV = GetProcGL("wglLockVideoCaptureDeviceNV");
    PROC_CAST wglQueryVideoCaptureDeviceNV = GetProcGL("wglQueryVideoCaptureDeviceNV");
    PROC_CAST wglReleaseVideoCaptureDeviceNV = GetProcGL("wglReleaseVideoCaptureDeviceNV");
    PROC_CAST wglGetVideoDeviceNV = GetProcGL("wglGetVideoDeviceNV");
    PROC_CAST wglReleaseVideoDeviceNV = GetProcGL("wglReleaseVideoDeviceNV");
    PROC_CAST wglBindVideoImageNV = GetProcGL("wglBindVideoImageNV");
    PROC_CAST wglReleaseVideoImageNV = GetProcGL("wglReleaseVideoImageNV");
    PROC_CAST wglSendPbufferToVideoNV = GetProcGL("wglSendPbufferToVideoNV");
    PROC_CAST wglGetVideoInfoNV = GetProcGL("wglGetVideoInfoNV");
    PROC_CAST wglGetSyncValuesOML = GetProcGL("wglGetSyncValuesOML");
    PROC_CAST wglGetMscRateOML = GetProcGL("wglGetMscRateOML");
    PROC_CAST wglSwapBuffersMscOML = GetProcGL("wglSwapBuffersMscOML");
    PROC_CAST wglSwapLayerBuffersMscOML = GetProcGL("wglSwapLayerBuffersMscOML");
    PROC_CAST wglWaitForMscOML = GetProcGL("wglWaitForMscOML");
    PROC_CAST wglWaitForSbcOML = GetProcGL("wglWaitForSbcOML");
#endif
}

#endif // JUSTGL_IMPLEMENTATION