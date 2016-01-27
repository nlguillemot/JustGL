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

#include "justgl_visibility.h"
#include "justgl_math.h"

#include <cmath>
#include <cassert>
#include <algorithm>

#include <xmmintrin.h>

void PrincipalComponentsFromPoints(
    int nPoints, const float* pointXYZs,
    float principalComponents[3][3])
{
    assert(nPoints > 0);

    const float(*pts)[3] = (const float (*)[3])pointXYZs;

    // compute the mean position
    float m[3] = { 0.0, 0.0, 0.0 };
    for (int i = 0; i < nPoints; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            m[j] += pts[i][j];
        }
    }
    for (int j = 0; j < 3; j++)
    {
        m[j] /= nPoints;
    }

    // covariance matrix: represents correlation between x,y,z coordinates
    mat3 cov(0);
    for (int i = 0; i < nPoints; i++)
    {
        float dx = pts[i][0] - m[0];
        float dy = pts[i][1] - m[1];
        float dz = pts[i][2] - m[2];

        cov[0][0] += dx * dx;
        cov[1][0] += dx * dy;
        cov[1][1] += dy * dy;
        cov[2][0] += dx * dz;
        cov[2][1] += dy * dz;
        cov[2][2] += dz * dz;
    }
    cov[0][0] /= nPoints;
    cov[1][0] /= nPoints;
    cov[1][1] /= nPoints;
    cov[2][0] /= nPoints;
    cov[2][1] /= nPoints;
    cov[2][2] /= nPoints;
    cov[0][1] = cov[1][0];
    cov[0][2] = cov[2][0];
    cov[1][2] = cov[2][1];

    vec3 eigenvalues;
    mat3 eigenvectors;
    eigendecompose(cov, eigenvalues, eigenvectors);

    // now that we have the eigenvectors, just need to sort them by magnitude.
    double magSquared[3];
    for (int eigIdx = 0; eigIdx < 3; eigIdx++)
    {
        for (int i = 0; i < 3; i++)
        {
            principalComponents[eigIdx][i] = eigenvectors[eigIdx][i] * eigenvalues[i];
        }

        magSquared[eigIdx] =
            principalComponents[eigIdx][0] * principalComponents[eigIdx][0] +
            principalComponents[eigIdx][1] * principalComponents[eigIdx][1] +
            principalComponents[eigIdx][2] * principalComponents[eigIdx][2];
    }
    if (magSquared[0] < magSquared[1]) {
        std::swap(principalComponents[0], principalComponents[1]);
        std::swap(magSquared[0], magSquared[1]);
    }
    if (magSquared[0] < magSquared[2]) {
        std::swap(principalComponents[0], principalComponents[2]);
        std::swap(magSquared[0], magSquared[2]);
    }
    if (magSquared[1] < magSquared[2]) {
        std::swap(principalComponents[1], principalComponents[2]);
        std::swap(magSquared[1], magSquared[2]);
    }
}

void BoundingSphereFromPoints(
    int nPoints, const float* pointXYZs,
    float boundingSphere[4])
{
    assert(nPoints > 0);

    const vec3* pts = (const vec3*)pointXYZs;

    vec3 mean = vec3(0);
    for (int i = 0; i < nPoints; i++)
    {
        mean += pts[i];
    }
    mean /= float(nPoints);

    // covariance matrix: correlation between x,y,z coordinates
    mat3 cov(0);
    for (int i = 0; i < nPoints; i++)
    {
        vec3 delta = pts[i] - mean;
        
        cov[0][0] += delta.x * delta.x;
        cov[1][0] += delta.x * delta.y;
        cov[1][1] += delta.y * delta.y;
        cov[2][0] += delta.x * delta.z;
        cov[2][1] += delta.y * delta.z;
        cov[2][2] += delta.z * delta.z;
    }
    cov[0][0] /= nPoints;
    cov[1][0] /= nPoints;
    cov[1][1] /= nPoints;
    cov[2][0] /= nPoints;
    cov[2][1] /= nPoints;
    cov[2][2] /= nPoints;
    cov[0][1] = cov[1][0];
    cov[0][2] = cov[2][0];
    cov[1][2] = cov[2][1];

    vec3 eigenvalues;
    mat3 eigenvectors;
    eigendecompose(cov, eigenvalues, eigenvectors);

    // find the principal component
    int principal = -1;
    float principalLenSquared;
    for (int i = 0; i < 3; i++)
    {
        eigenvectors[i] *= eigenvalues[i];
        float lenSquared = lengthSquared(eigenvectors[i]);
        if (principal == -1 || lenSquared > principalLenSquared)
        {
            principal = i;
            principalLenSquared = lenSquared;
        }
    }

    // compute the points which are most and least aligned with the principal component
    float minDotProduct = INFINITY;
    float maxDotProduct = -INFINITY;
    int minIdx = 0, maxIdx = 0;
    for (int i = 0; i < nPoints; i++)
    {
        float d =
            pts[i].x * eigenvectors[principal].x +
            pts[i].y * eigenvectors[principal].y +
            pts[i].z * eigenvectors[principal].z;
        
        if (d < minDotProduct)
        {
            minDotProduct = d;
            minIdx = i;
        }
        if (d > maxDotProduct)
        {
            maxDotProduct = d;
            maxIdx = i;
        }
    }

    // construct an initial guess at the sphere
    float center[3] = {
        (pts[minIdx][0] + pts[maxIdx][0]) / 2.0f,
        (pts[minIdx][1] + pts[maxIdx][1]) / 2.0f,
        (pts[minIdx][2] + pts[maxIdx][2]) / 2.0f,
    };
    float radius = std::sqrt(
        (pts[minIdx][0] - center[0]) * (pts[minIdx][0] - center[0]) +
        (pts[minIdx][1] - center[1]) * (pts[minIdx][1] - center[1]) +
        (pts[minIdx][2] - center[2]) * (pts[minIdx][2] - center[2]));

    // expand sphere for any points that don't lie in the guess
    for (int i = 0; i < nPoints; i++)
    {
        float distSquared =
            (pts[i][0] - center[0]) * (pts[i][0] - center[0]) +
            (pts[i][1] - center[1]) * (pts[i][1] - center[1]) +
            (pts[i][2] - center[2]) * (pts[i][2] - center[2]);
        if (distSquared > radius * radius)
        {
            for (int j = 0; j < 3; j++)
            {
                float tangentPoint = center[j] - radius * (pts[i][j] - center[j]) / std::sqrt(distSquared);
                center[j] = (tangentPoint + pts[i][j]) / 2.0f;
            }
            radius = std::sqrt(
                (pts[i][0] - center[0]) * (pts[i][0] - center[0]) +
                (pts[i][1] - center[1]) * (pts[i][1] - center[1]) +
                (pts[i][2] - center[2]) * (pts[i][2] - center[2]));
        }
    }

    // done!
    boundingSphere[0] = center[0];
    boundingSphere[1] = center[1];
    boundingSphere[2] = center[2];
    boundingSphere[3] = radius;
}

void FrustumFromMVP(const float mvp[16], float frustum[6][4])
{
    const float(&p)[4][4] = (const float(&)[4][4])*mvp;

    // left
    frustum[0][0] = p[0][3] + p[0][0];
    frustum[0][1] = p[1][3] + p[1][0];
    frustum[0][2] = p[2][3] + p[2][0];
    frustum[0][3] = p[3][3] + p[3][0];

    // right
    frustum[1][0] = p[0][3] - p[0][0];
    frustum[1][1] = p[1][3] - p[1][0];
    frustum[1][2] = p[2][3] - p[2][0];
    frustum[1][3] = p[3][3] - p[3][0];

    // bottom
    frustum[2][0] = p[0][3] + p[0][1];
    frustum[2][1] = p[1][3] + p[1][1];
    frustum[2][2] = p[2][3] + p[2][1];
    frustum[2][3] = p[3][3] + p[3][1];

    // top
    frustum[3][0] = p[0][3] - p[0][1];
    frustum[3][1] = p[1][3] - p[1][1];
    frustum[3][2] = p[2][3] - p[2][1];
    frustum[3][3] = p[3][3] - p[3][1];

    // near
    frustum[4][0] = p[0][3] + p[0][2];
    frustum[4][1] = p[1][3] + p[1][2];
    frustum[4][2] = p[2][3] + p[2][2];
    frustum[4][3] = p[3][3] + p[3][2];

    // far
    frustum[5][0] = p[0][3] - p[0][2];
    frustum[5][1] = p[1][3] - p[1][2];
    frustum[5][2] = p[2][3] - p[2][2];
    frustum[5][3] = p[3][3] - p[3][2];

    for (int i = 0; i < 6; i++)
    {
        // normalize the plane equation
        float mag = sqrt(
            frustum[i][0] * frustum[i][0] +
            frustum[i][1] * frustum[i][1] +
            frustum[i][2] * frustum[i][2]);

        frustum[i][0] = frustum[i][0] / mag;
        frustum[i][1] = frustum[i][1] / mag;
        frustum[i][2] = frustum[i][2] / mag;
        frustum[i][3] = frustum[i][3] / mag;
    }
}

void FrustumCullSpheres(
    int nSpheres,
    const float* sphereCenterXs,
    const float* sphereCenterYs,
    const float* sphereCenterZs,
    const float* sphereRadii,
    const float frustumPlanes[6][4],
    int* visibilityResults)
{
    // alignment check
    assert((uintptr_t)sphereCenterXs % 16 == 0);
    assert((uintptr_t)sphereCenterYs % 16 == 0);
    assert((uintptr_t)sphereCenterZs % 16 == 0);
    assert((uintptr_t)sphereRadii % 16 == 0);
    assert((uintptr_t)visibilityResults % 16 == 0);

    for (int i = 0; i < 6; i++)
    {
        float normLengthSq =
            frustumPlanes[i][0] * frustumPlanes[i][0] +
            frustumPlanes[i][1] * frustumPlanes[i][1] +
            frustumPlanes[i][2] * frustumPlanes[i][2];
        assert(std::abs(normLengthSq - 1.0f) < 0.0001f && "Assuming normalized plane normal");
    }

    auto fcull1 = [&frustumPlanes](
        float cx, float cy, float cz, float r, int& result)
    {
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

        result = !outside;
    };

    auto fcull4 = [&frustumPlanes](
        const __m128& cx, const __m128& cy, const __m128& cz,
        const __m128& r,
        __m128& result)
    {
        __m128 outside = _mm_setzero_ps();

        for (int p = 0; p < 6; p++)
        {
            __m128 outDistance =
                _mm_xor_ps(_mm_set1_ps(-0.0),
                    _mm_add_ps(_mm_add_ps(_mm_add_ps(
                        _mm_mul_ps(cx, _mm_set1_ps(frustumPlanes[p][0])),
                        _mm_mul_ps(cy, _mm_set1_ps(frustumPlanes[p][1]))),
                        _mm_mul_ps(cz, _mm_set1_ps(frustumPlanes[p][2]))),
                        _mm_set1_ps(frustumPlanes[p][3])));

            outside = _mm_or_ps(outside, _mm_cmpgt_ps(outDistance, r));
        }

        result = _mm_cmpeq_ps(outside, _mm_setzero_ps());
    };

    const __m128* centerXs = (const __m128*)sphereCenterXs;
    const __m128* centerYs = (const __m128*)sphereCenterYs;
    const __m128* centerZs = (const __m128*)sphereCenterZs;
    const __m128* radii = (const __m128*)sphereRadii;
    __m128* results = (__m128*)visibilityResults;

    int numVectors = nSpheres / 4;
    int numScalars = nSpheres - numVectors * 4;
    for (int i = 0; i < numVectors; i++)
    {
        fcull4(centerXs[i], centerYs[i], centerZs[i], radii[i], results[i]);
    }
    for (int i = numVectors * 4; i < numVectors * 4 + numScalars; i++)
    {
        fcull1(
            sphereCenterXs[i], sphereCenterYs[i], sphereCenterZs[i],
            sphereRadii[i],
            visibilityResults[i]);
    }
}

void FrustumCullSpheresFromMVP(
    int nSpheres,
    const float* sphereCenterXs,
    const float* sphereCenterYs,
    const float* sphereCenterZs,
    const float* sphereRadii,
    const float modelViewProjection[16],
    int* visibilityResults)
{
    float frustumPlanes[6][4];
    FrustumFromMVP(modelViewProjection, frustumPlanes);
    FrustumCullSpheres(
        nSpheres,
        sphereCenterXs, sphereCenterYs, sphereCenterZs,
        sphereRadii,
        frustumPlanes,
        visibilityResults);
}