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

#include "justgl_camera.h"

#include <cstdio>
#include <algorithm>

void FlythroughCamera::Activate()
{
    if (Activated)
    {
        return;
    }

        ShowMouseCursor(0);
        ClipMouseCursorToWindow(1);

    if (IsWindowCurrentlyActive() && IsMouseCursorInsideClientArea())
    {
        int clientWidth, clientHeight;
        GetClientAreaSize(&clientWidth, &clientHeight);
        SetMousePosition(clientWidth / 2, clientHeight / 2);
    }

    Activated = true;
}

void FlythroughCamera::Deactivate()
{
    if (!Activated)
    {
        return;
    }

    int clientWidth, clientHeight;
    GetClientAreaSize(&clientWidth, &clientHeight);
    SetMousePosition(clientWidth / 2, clientHeight / 2);
    
    ClipMouseCursorToWindow(0);
    ShowMouseCursor(1);
    
    Activated = false;
}

bool FlythroughCamera::HandleEvent(const Event* ev)
{
    if (!Activated)
    {
        return false;
    }

    if (ev->Type == ET_Key)
    {
        if (ev->Key.Scan == LeftKey)
        {
            LeftHeld = ev->Key.Pressed != 0;
            return true;
        }
        else if (ev->Key.Scan == RightKey)
        {
            RightHeld = ev->Key.Pressed != 0;
            return true;
        }
        else if (ev->Key.Scan == CrouchKey)
        {
            CrouchHeld = ev->Key.Pressed != 0;
            return true;
        }
        else if (ev->Key.Scan == JumpKey)
        {
            JumpHeld = ev->Key.Pressed != 0;
            return true;
        }
        else if (ev->Key.Scan == ForwardKey)
        {
            ForwardHeld = ev->Key.Pressed != 0;
            return true;
        }
        else if (ev->Key.Scan == BackwardKey)
        {
            BackwardHeld = ev->Key.Pressed != 0;
            return true;
        }
        else if (ev->Key.Scan == RunKey)
        {
            RunHeld = ev->Key.Pressed != 0;
            return true;
        }
    }
    else if (ev->Type == ET_MouseMove)
    {
        if (IsWindowCurrentlyActive() && IsMouseCursorInsideClientArea())
        {
            int clientWidth, clientHeight;
            GetClientAreaSize(&clientWidth, &clientHeight);

            if (ev->Move.X != clientWidth / 2 || ev->Move.Y != clientHeight / 2)
            {
                if (!IgnoreNextMove)
                {
                    PendingYawTicks -= (ev->Move.X - clientWidth / 2);
                    PendingPitchTicks -= (ev->Move.Y - clientHeight / 2);
                }
                SetMousePosition(clientWidth / 2, clientHeight / 2);
                IgnoreNextMove = false;
                return true;
            }
        }
    }

    return false;
}

void FlythroughCamera::Update(float dt_Sec)
{
    if (!Activated || !IsWindowCurrentlyActive() || !IsMouseCursorInsideClientArea())
    {
        IgnoreNextMove = true;
        return;
    }

    vec3 across = normalize(cross(LookDirection, UpDirection));
    vec3 forward = normalize(LookDirection);
    vec3 upward = cross(across, forward);

    mat3 viewWorld(across, upward, -forward);
    mat3 worldView(transpose(viewWorld));

    if (RightHeld - LeftHeld != 0 ||
        ForwardHeld - BackwardHeld != 0)
    {
        vec3 xzMovement =
            float(RightHeld - LeftHeld) * across +
            float(ForwardHeld - BackwardHeld) * forward;
        xzMovement = normalize(xzMovement);
        
        float speed = Speed;
        if (RunHeld)
        {
            speed *= RunMultiplier;
        }

        EyePosition += xzMovement * speed * dt_Sec;
    }

    if (JumpHeld - CrouchHeld != 0)
    {
        vec3 yMovement = float(JumpHeld - CrouchHeld) * UpDirection;
        yMovement = normalize(yMovement);

        float speed = Speed;
        if (RunHeld)
        {
            speed *= RunMultiplier;
        }

        EyePosition += yMovement * speed * dt_Sec;
    }

    if (PendingYawTicks != 0 || PendingPitchTicks != 0)
    {
        float yawDegrees = DegreesPerRotationTick * PendingYawTicks;
        mat3 yRotation = mat3::axisRotationDegrees(yawDegrees, vec3(0.0f, 1.0f, 0.0f));
        PendingYawTicks = 0;

        float maxPitchDegrees = std::max(0.0f, radtodeg(acos(dot(LookDirection, UpDirection))) - 10.0f);
        float minPitchDegrees = std::max(0.0f, radtodeg(acos(dot(LookDirection, -UpDirection))) - 10.0f);
        float pitchDegrees = DegreesPerRotationTick * PendingPitchTicks;
        if (pitchDegrees > 0.0f && pitchDegrees > maxPitchDegrees)
        {
            pitchDegrees = maxPitchDegrees;
        }
        if (pitchDegrees < 0.0f && -pitchDegrees > minPitchDegrees)
        {
            pitchDegrees = -minPitchDegrees;
        }

        mat3 xRotation = mat3::axisRotationDegrees(pitchDegrees, across);
        PendingPitchTicks = 0;

        LookDirection = xRotation * yRotation * LookDirection;
    }
}

mat4 FlythroughCamera::GetWorldView() const
{
    return mat4::lookTo(EyePosition, LookDirection, UpDirection);
}