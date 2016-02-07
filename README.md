# JustGL

Just GL it!

## How to use

1. Add `justgl.h` to your project (from this repo.)
2. Start filling in `mygl.cpp`, starting from the template below.

Optionally, move the JUSTGL_IMPLEMENTATION into its own justgl.cpp for cleanliness.

## `mygl.cpp`
    #define JUSTGL_IMPLEMENTATION
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
