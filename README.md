# JustGL
Just GL it!

## How to use
1. Add `justgl.h` to your project (from this repo.)
2. Create `justgl.cpp` in your project (as below.)
3. Create `mygl.cpp` in your project (as below.)
4. Start filling in `mygl.cpp`.

## `justgl.cpp`
    #define JUSTGL_IMPLEMENTATION
    #include "justgl.h"

## `mygl.cpp`
    #include "justgl.h"

    void ConfigGL(WindowConfig* pConfig)
    {
        // TODO: Fill in the desired config for your application
    }
    
    void InitGL()
    {
        // TODO: One-time initialization
    }
    
    void ResizeGL(int width, int height)
    {
        // TODO: Update camera/viewport
    }
    
    void PaintGL()
    {
        Event ev;
        while (PollEvents(&ev))
        {
            // TODO: Handle event
        }

        // TODO: render scene
    }

## Extensions

There are utilities in the `ext` folder you can also add to your project.

They are not necessary, and designed for my own rapid prototyping purposes.

What follows is a sample program making use of the extensions.

## `myglext.cpp`
    #include "justgl.h"
    
    #include "ext/justgl_shader.h"
    #include "ext/justgl_obj.h"
    #include "ext/justgl_math.h"
    #include "ext/justgl_debug.h"
    #include "ext/justgl_image.h"
    
    #include "stb_image.h"

    // Shaders are recompiled when updated with UpdateShaders().
    // By the way, #include in shaders is handled!
    Shader
    sceneVS{ "scene.vert" },
    sceneFS{ "scene.frag" };
    
    ShaderProgram
    sceneSP{ &sceneVS, &sceneFS };
    
    // palette allows sharing materials between meshes
    MaterialPalette palette;

    // this mesh will be loaded and rendered
    MeshObject mesh;
    
    // Camera state
    mat4 worldView;
    mat4 viewProjection;
    mat4 worldViewProjection;
    
    // Initial setup for the window
    void ConfigGL(WindowConfig* pConfig)
    {
        pConfig->ClientWidth = 640;
        pConfig->ClientHeight = 480;
        pConfig->WindowTitle = "JustGL Test";
        
        pConfig->MajorGLVersion = 4;
        pConfig->MinorGLVersion = 3;
        pConfig->MultisampleCount = 16;
        pConfig->FramebufferSRGBCapable = 1;
    }

    // Quick and easy OpenGL debug callback
    void APIENTRY DebugCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam)
    {
        std::string s = FormatGLDebugCallback(source, type, id, severity, length, message);
        fprintf(stderr, "%s\n", s.c_str());
    }
    
    // One-time initialization
    void InitGL()
    {
        // JustGL's built-in image loader can't handle many formats.
        // Hook in stb_image to load more formats.
        static std::function<Image(const std::string&)> stbLoader = 
        [](const std::string& filename)
        {
            int x, y, comp;
            stbi_uc* data = stbi_load(filename.c_str(), &x, &y, &comp, 4);
            if (!data)
            {
                return Image();
            }

            Image img;
            img.Data = std::shared_ptr<uint8_t>(data, [](uint8_t* ptr) { stbi_image_free(ptr); });
            img.BytesPerPixel = 4;
            img.Width = x;
            img.Height = y;
            img.Depth = 1;
            return std::move(img);
        };

        Image::CustomImageLoader = &stbLoader;

    #ifndef NDEBUG
        // Enable GL debugging in debug builds
        glDebugMessageCallback(DebugCallback, NULL);
        glEnable(GL_DEBUG_OUTPUT);
        glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    #endif

        if (!LoadObj("mesh.obj", "", &mesh, &palette))
        {
            fprintf(stderr, "failed to load mesh.obj\n");
            exit(-1);
        }
    }
    
    // Update viewport and camera
    void ResizeGL(int width, int height)
    {
        glViewport(0, 0, width, height);
        viewProjection = mat4::perspective(70.0f, (float)width / height, 0.01f, 5000.0f);
    }

    // Render a new frame of animation
    void PaintGL()
    {
        // TODO: Some kind of sleep to throttle FPS?
        
        Event ev;
        while (PollEvents(&ev))
        {
            // TODO: Some kind of simple camera movement?
        }
        
        // If any shaders' timestamp has changed, recompile them.
        // If a shader failed to compile, just ditch the frame of animation.
        if (!UpdateShaders())
        {
            return;
        }

        // clear screen (duh)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        // set graphics pipeline state
        glEnable(GL_FRAMEBUFFER_SRGB);
        glEnable(GL_DEPTH_TEST);
        glUseProgram(scene_sp.Handle);
        glBindVertexArray(mesh.VertexArray);
        
        // update camera
        worldView = mat4::lookAt(vec3(0, 100, 0), vec3(100, 100, 0), vec3(0, 1, 0));
        worldViewProjection = viewProjection * worldView;
        GLint cameraLoc = glGetUniformLocation(sceneSP.Handle, "worldViewProjection");
        if (cameraLoc != -1)
        {
            glUniformMatrix4fv(cameraLoc, 1, GL_FALSE, worldViewProjection.e);
        }
        
        // draw all meshes
        for (size_t drawIdx = 0; drawIdx < mesh.CPUIndirectDrawBuffer.size(); drawIdx++)
        {
            // get the material of this mesh
            int materialID = mesh.GroupMaterialIDs[drawIdx];
            const Material& material = palette.Materials[materialID];

            // if the mesh has a diffuse texture, set it
            int diffuseID = material.map_Kd;
            if (diffuseID == -1)
            {
                glBindTexture(GL_TEXTURE_2D, 0);
            }
            else
            {
                glBindTexture(GL_TEXTURE_2D, palette.Textures[diffuseID]);
            }

            // draw the mesh
            size_t drawOffset = sizeof(GLDrawElementsIndirectCommand) * drawIdx;
            glDrawElementsIndirect(GL_TRIANGLES, GL_UNSIGNED_INT, (void*)drawOffset);
        }
    }