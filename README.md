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
        // TODO: Select width, height, GL version...
    }
    
    void InitGL()
    {
        // TODO: Load scene
    }
    
    void ResizeGL(int width, int height)
    {
        // TODO: Update camera/viewport
    }
    
    int PaintGL()
    {
        Event ev;
        while (PollEvents(&ev))
        {
            // TODO: Handle event
        }

        // TODO: render scene
        
        return 1;
    }

## Extensions

There are utilities in the `ext` folder you can also add to your project.

They are not necessary, and designed for my own rapid prototyping purposes.
