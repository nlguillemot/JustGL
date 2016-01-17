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

#include "justgl_culling.h"

#include <cassert>
#include <cmath>

// warning C4752: found Intel(R) Advanced Vector Extensions; consider using /arch:AVX
#pragma warning(disable : 4752)
#include <intrin.h>

void FrustumCullSpheres(
    int nSpheres,
    const float* sphereCenterXs,
    const float* sphereCenterYs,
    const float* sphereCenterZs,
    const float* sphereRadii,
    const float frustumPlanes[6][4],
    int* visibilityResults)
{
    for (int i = 0; i < 6; i++)
    {
        float normLengthSq =
            frustumPlanes[i][0] * frustumPlanes[i][0] +
            frustumPlanes[i][1] * frustumPlanes[i][1] +
            frustumPlanes[i][2] * frustumPlanes[i][2];
        assert(std::abs(normLengthSq - 1.0f) < 0.0001f && "Assuming normalized plane normal");
    }

    const __m256* centerXs = (const __m256*)sphereCenterXs;
    const __m256* centerYs = (const __m256*)sphereCenterYs;
    const __m256* centerZs = (const __m256*)sphereCenterZs;
    const __m256* radii    = (const __m256*)sphereRadii;
    __m256* result = (__m256*)visibilityResults;

    int numVectors = nSpheres / 8;
    int numScalars = nSpheres - numVectors * 8;
    for (int i = 0; i < numVectors; i++)
    {
        __m256 cx = centerXs[i];
        __m256 cy = centerYs[i];
        __m256 cz = centerZs[i];
        __m256 rs = radii[i];

        __m256 outside = _mm256_setzero_ps();

        for (int p = 0; p < 6; p++)
        {
            __m256 outDistance =
                _mm256_xor_ps(_mm256_set1_ps(-0.0),
                _mm256_add_ps(_mm256_add_ps(_mm256_add_ps(
                    _mm256_mul_ps(cx, _mm256_set1_ps(frustumPlanes[p][0])),
                    _mm256_mul_ps(cy, _mm256_set1_ps(frustumPlanes[p][1]))),
                    _mm256_mul_ps(cz, _mm256_set1_ps(frustumPlanes[p][2]))),
                    _mm256_set1_ps(frustumPlanes[p][3])));

            outside = _mm256_or_ps(outside, _mm256_cmp_ps(outDistance, rs, _CMP_NLE_US));
        }

        result[i] = _mm256_cmp_ps(outside, _mm256_setzero_ps(), _CMP_EQ_US);
    }

    for (int i = numVectors * 8; i < numVectors * 8 + numScalars; i++)
    {
        float cx = sphereCenterXs[i];
        float cy = sphereCenterXs[i];
        float cz = sphereCenterXs[i];
        float r = sphereRadii[i];
        
        bool outside = false;
        for (int p = 0; p < 6; p++)
        {
            float outDistance = -(
                cx * frustumPlanes[p][0] + 
                cy * frustumPlanes[p][1] + 
                cz * frustumPlanes[p][2] + 
                frustumPlanes[p][3]);

            if (outDistance > r)
            {
                outside = true;
                break;
            }
        }

        visibilityResults[i] = outside;
    }
}