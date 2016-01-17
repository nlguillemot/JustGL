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

#ifndef JUSTGL_CAMERA_H
#define JUSTGL_CAMERA_H

#include "justgl_math.h"
#include "justgl.h"

struct Event;

class FlythroughCamera
{
public:
    FlythroughCamera() = default;

    FlythroughCamera(
        float speed,
        vec3 eyePosition,
        vec3 lookDirection,
        vec3 upDirection = vec3(0.0f, 1.0f, 0.0f))
        : FlythroughCamera()
    {
        Speed = speed;
        EyePosition = eyePosition;
        LookDirection = lookDirection;
        UpDirection = upDirection;
    }

    void Activate();
    void Deactivate();

    bool HandleEvent(const Event* ev);
    void Update(float dt_Sec);

    mat4 GetWorldView() const;

    bool Activated = false;

    // eg. when you return from alt tab and the mouse is off-center
    bool IgnoreNextMove = true;
    
    Scancode LeftKey = SC_A;
    Scancode RightKey = SC_D;
    Scancode CrouchKey = SC_LeftControl;
    Scancode JumpKey = SC_Spacebar;
    Scancode ForwardKey = SC_W;
    Scancode BackwardKey = SC_S;
    Scancode RunKey = SC_LeftShift;

    bool LeftHeld = false;
    bool RightHeld = false;
    bool CrouchHeld = false;
    bool JumpHeld = false;
    bool ForwardHeld = false;
    bool BackwardHeld = false;
    bool RunHeld = false;

    // yaw is rotation about y (note: right hand rotation)
    int PendingYawTicks = 0;
    // pitch is rotation about x (note: right hand rotation)
    int PendingPitchTicks = 0;
    
    float DegreesPerRotationTick = 0.1f;
    float Speed = 100.0f;
    float RunMultiplier = 2.0f;

    vec3 EyePosition = vec3(0.0f, 0.0f, 0.0f);
    vec3 LookDirection = vec3(0.0f, 0.0f, 1.0f);
    vec3 UpDirection = vec3(0.0f, 1.0f, 0.0f);
};

void NormalizePlaneEquation(float plane[4]);
void FrustumFromModelViewProjection(const float* mvp, float frustum[6][4]);

#endif // JUSTGL_CAMERA_H