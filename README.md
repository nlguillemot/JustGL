# JustGL
Just GL it!

## How to use
1. Add `justgl.h` to your project (from this repo.)
2. Create `justgl.cpp` in your project (as below.)
3. Create `mygl.cpp` in your project (as below.)
4. Start filling in `mygl.cpp`.

## Extensions

There are utilities in the `ext` folder you can also add to your project.

They are not necessary, and designed for my own rapid prototyping purposes.

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
        // TODO: Update camera for new aspect ratio
    }
    
    void PaintGL()
    {
        // TODO: render scene
    }
