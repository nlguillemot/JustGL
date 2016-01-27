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

#ifndef JUSTGL_VISIBILITY_H
#define JUSTGL_VISIBILITY_H

#include <cstdint>

void BoundingSphereFromPoints(
    int nPoints, const float* pointXYZs,
    float boundingSphere[4]); // x, y, z, r

void FrustumFromMVP(const float mvp[16], float frustum[6][4]);

void FrustumCullSpheres(
    int nSpheres,
    const float* sphereCenterXs,
    const float* sphereCenterYs,
    const float* sphereCenterZs,
    const float* sphereRadii,
    const float frustumPlanes[6][4],
    int* visibilityResults);

void FrustumCullSpheresFromMVP(
    int nSpheres,
    const float* sphereCenterXs,
    const float* sphereCenterYs,
    const float* sphereCenterZs,
    const float* sphereRadii,
    const float worldView[16],
    int* visibilityResults);

#endif // JUSTGL_VISIBILITY_H