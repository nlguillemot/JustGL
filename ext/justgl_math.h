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

#ifndef JUSTGL_MATH_H
#define JUSTGL_MATH_H

#include <cmath>
#include <cassert>
#include <algorithm>

template<class T>
inline T degtorad(T deg)
{
    return deg * T(3.14159265359) / T(180);
}

template<class T>
inline T radtodeg(T rad)
{
    return rad / T(3.14159265359) * T(180);
}

template<class T>
struct vec2_t
{
    union
    {
        T e[2];
        struct
        {
            T x, y;
        };
    };

    static const int N = 2;

    vec2_t()
    {
        for (int i = 0; i < N; i++)
        {
            e[i] = T(0);
        }
    }

    vec2_t(const vec2_t& other)
    {
        for (int i = 0; i < N; i++)
        {
            e[i] = other.e[i];
        }
    }

    vec2_t& operator=(const vec2_t& other)
    {
        for (int i = 0; i < N; i++)
        {
            e[i] = other.e[i];
        }
        return *this;
    }

    template<class U>
    explicit vec2_t(const vec2_t<U>& other)
    {
        x = T(other.x);
        y = T(other.y);
    }

    vec2_t(T x, T y)
    {
        e[0] = x;
        e[1] = y;
    }

    explicit vec2_t(T u)
    {
        for (int i = 0; i < N; i++)
        {
            e[i] = u;
        }
    }

    T& operator[](int i)
    {
        return e[i];
    }

    const T& operator[](int i) const
    {
        return e[i];
    }

    vec2_t& operator+=(const vec2_t& other)
    {
        for (int i = 0; i < N; i++)
        {
            e[i] += other.e[i];
        }
        return *this;
    }

    vec2_t& operator-=(const vec2_t& other)
    {
        for (int i = 0; i < N; i++)
        {
            e[i] -= other.e[i];
        }
        return *this;
    }

    vec2_t& operator*=(const vec2_t& other)
    {
        for (int i = 0; i < N; i++)
        {
            e[i] *= other.e[i];
        }
        return *this;
    }
    
    vec2_t& operator*=(T u)
    {
        for (int i = 0; i < N; i++)
        {
            e[i] *= u;
        }
        return *this;
    }

    vec2_t& operator/=(const vec2_t& other)
    {
        for (int i = 0; i < N; i++)
        {
            e[i] /= other.e[i];
        }
        return *this;
    }

    vec2_t& operator/=(T u)
    {
        for (int i = 0; i < N; i++)
        {
            e[i] /= u;
        }
        return *this;
    }
};

template<class T>
inline vec2_t<T> operator-(const vec2_t<T>& v)
{
    return vec2_t<T>(-v.x, -v.y);
}

template<class T>
inline vec2_t<T> operator+(const vec2_t<T>& v)
{
    return vec2_t<T>(+v.x, +v.y);
}

template<class T>
inline vec2_t<T> operator+(vec2_t<T> a, const vec2_t<T>& b)
{
    a += b;
    return a;
}

template<class T>
inline vec2_t<T> operator-(vec2_t<T> a, const vec2_t<T>& b)
{
    a -= b;
    return a;
}

template<class T>
inline vec2_t<T> operator*(vec2_t<T> a, const vec2_t<T>& b)
{
    a *= b;
    return a;
}

template<class T>
inline vec2_t<T> operator*(vec2_t<T> a, T u)
{
    a *= u;
    return a;
}

template<class T>
inline vec2_t<T> operator*(T u, vec2_t<T> a)
{
    return vec2_t<T>(u * a.x, u * a.y);
}

template<class T>
inline vec2_t<T> operator/(vec2_t<T> a, const vec2_t<T>& b)
{
    a /= b;
    return a;
}

template<class T>
inline vec2_t<T> operator/(vec2_t<T> a, T u)
{
    a /= u;
    return a;
}

template<class T>
inline vec2_t<bool> operator==(const vec2_t<T>& a, const vec2_t<T>& b)
{
    return vec2_t<bool>(a.x == b.x, a.y == b.y);
}

template<class T>
inline vec2_t<bool> operator!=(const vec2_t<T>& a, const vec2_t<T>& b)
{
    return vec2_t<bool>(a.x != b.x, a.y != b.y);
}

template<class T>
inline vec2_t<bool> operator<(const vec2_t<T>& a, const vec2_t<T>& b)
{
    return vec2_t<bool>(a.x < b.x, a.y < b.y);
}

template<class T>
inline vec2_t<bool> operator>(const vec2_t<T>& a, const vec2_t<T>& b)
{
    return vec2_t<bool>(a.x > b.x, a.y > b.y);
}

template<class T>
inline vec2_t<bool> operator<=(const vec2_t<T>& a, const vec2_t<T>& b)
{
    return vec2_t<bool>(a.x <= b.x, a.y <= b.y);
}

template<class T>
inline vec2_t<bool> operator>=(const vec2_t<T>& a, const vec2_t<T>& b)
{
    return vec2_t<bool>(a.x >= b.x, a.y >= b.y);
}

template<class T>
inline vec2_t<bool> operator!(const vec2_t<bool>& v)
{
    return vec2_t<bool>(!v.x, !v.y);
}

inline bool any(const vec2_t<bool>& v)
{
    return v.x || v.y;
}

inline bool all(const vec2_t<bool>& v)
{
    return v.x && v.y;
}

template<class T>
inline T dot(const vec2_t<T>& a, const vec2_t<T>& b)
{
    T d = T(0);
    for (int i = 0; i < vec2_t<T>::N; i++)
    {
        d += a[i] * b[i];
    }
    return d;
}

template<class T>
inline T length(const vec2_t<T>& v)
{
    using std::sqrt;
    return sqrt(dot(v, v));
}

template<class T>
inline T lengthSquared(const vec2_t<T>& v)
{
    return dot(v, v);
}

template<class T>
inline vec2_t<T> normalize(const vec2_t<T>& v)
{
    return v / length(v);
}

template<class T>
inline vec2_t<T> abs(const vec2_t<T>& v)
{
    using std::abs;
    return vec2_t<T>(abs(v.x), abs(v.y));
}

template<class T>
inline vec2_t<T> min(const vec2_t<T>& a, const vec2_t<T>& b)
{
    using std::min;
    return vec2_t<T>(min(a.x, b.x), min(a.y, b.y));
}

template<class T>
inline vec2_t<T> max(const vec2_t<T>& a, const vec2_t<T>& b)
{
    using std::max;
    return vec2_t<T>(max(a.x, b.x), max(a.y, b.y));
}

template<class T>
inline size_t size(const vec2_t<T>& v)
{
    return 2;
}

template<class T>
struct vec3_t
{
    union
    {
        T e[3];
        struct
        {
            T x, y, z;
        };
    };

    static const int N = 3;

    vec3_t()
    {
        for (int i = 0; i < N; i++)
        {
            e[i] = T(0);
        }
    }

    vec3_t(const vec3_t& other)
    {
        for (int i = 0; i < N; i++)
        {
            e[i] = other.e[i];
        }
    }

    vec3_t& operator=(const vec3_t& other)
    {
        for (int i = 0; i < N; i++)
        {
            e[i] = other.e[i];
        }
        return *this;
    }

    template<class U>
    explicit vec3_t(const vec3_t<U>& other)
    {
        x = T(other.x);
        y = T(other.y);
        z = T(other.z);
    }

    vec3_t(T x, T y, T z)
    {
        e[0] = x;
        e[1] = y;
        e[2] = z;
    }

    vec3_t(T x, const vec2_t<T>& yz)
    {
        e[0] = x;
        e[1] = yz[0];
        e[2] = yz[1];
    }

    vec3_t(const vec2_t<T>& xy, T z)
    {
        e[0] = xy[0];
        e[1] = xy[1];
        e[2] = z;
    }

    explicit vec3_t(T u)
    {
        for (int i = 0; i < N; i++)
        {
            e[i] = u;
        }
    }

    T& operator[](int i)
    {
        return e[i];
    }

    const T& operator[](int i) const
    {
        return e[i];
    }

    vec3_t& operator+=(const vec3_t& other)
    {
        for (int i = 0; i < N; i++)
        {
            e[i] += other.e[i];
        }
        return *this;
    }

    vec3_t& operator-=(const vec3_t& other)
    {
        for (int i = 0; i < N; i++)
        {
            e[i] -= other.e[i];
        }
        return *this;
    }

    vec3_t& operator*=(const vec3_t& other)
    {
        for (int i = 0; i < N; i++)
        {
            e[i] *= other.e[i];
        }
        return *this;
    }

    vec3_t& operator*=(T u)
    {
        for (int i = 0; i < N; i++)
        {
            e[i] *= u;
        }
        return *this;
    }

    vec3_t& operator/=(const vec3_t& other)
    {
        for (int i = 0; i < N; i++)
        {
            e[i] /= other.e[i];
        }
        return *this;
    }

    vec3_t& operator/=(T u)
    {
        for (int i = 0; i < N; i++)
        {
            e[i] /= u;
        }
        return *this;
    }

    vec2_t<T>& xy()
    {
        return (vec2_t<T>&)e[0];
    }

    const vec2_t<T>& xy() const
    {
        return (const vec2_t<T>&)e[0];
    }

    vec2_t<T>& yz()
    {
        return (vec2_t<T>&)e[1];
    }

    const vec2_t<T>& yz() const
    {
        return (const vec2_t<T>&)e[1];
    }
};

template<class T>
inline vec3_t<T> operator-(const vec3_t<T>& v)
{
    return vec3_t<T>(-v.x, -v.y, -v.z);
}

template<class T>
inline vec3_t<T> operator+(const vec3_t<T>& v)
{
    return vec3_t<T>(+v.x, +v.y, +v.z);
}

template<class T>
inline vec3_t<T> operator+(vec3_t<T> a, const vec3_t<T>& b)
{
    return a += b;
}

template<class T>
inline vec3_t<T> operator-(vec3_t<T> a, const vec3_t<T>& b)
{
    return a -= b;
}

template<class T>
inline vec3_t<T> operator*(vec3_t<T> a, const vec3_t<T>& b)
{
    return a *= b;
}

template<class T>
inline vec3_t<T> operator*(vec3_t<T> a, T u)
{
    return a *= u;
}

template<class T>
inline vec3_t<T> operator*(T u, vec3_t<T> a)
{
    return vec3_t<T>(u * a.x, u * a.y, u * a.z);
}

template<class T>
inline vec3_t<T> operator/(vec3_t<T> a, const vec3_t<T>& b)
{
    a /= b;
    return a;
}

template<class T>
inline vec3_t<T> operator/(vec3_t<T> a, T u)
{
    a /= u;
    return a;
}

template<class T>
inline vec3_t<bool> operator==(const vec3_t<T>& a, const vec3_t<T>& b)
{
    return vec3_t<bool>(a.x == b.x, a.y == b.y, a.z == b.z);
}

template<class T>
inline vec3_t<bool> operator!=(const vec3_t<T>& a, const vec3_t<T>& b)
{
    return vec3_t<bool>(a.x != b.x, a.y != b.y, a.z != b.z);
}

template<class T>
inline vec3_t<bool> operator<(const vec3_t<T>& a, const vec3_t<T>& b)
{
    return vec3_t<bool>(a.x < b.x, a.y < b.y, a.z < b.z);
}

template<class T>
inline vec3_t<bool> operator>(const vec3_t<T>& a, const vec3_t<T>& b)
{
    return vec3_t<bool>(a.x > b.x, a.y > b.y, a.z > b.z);
}

template<class T>
inline vec3_t<bool> operator<=(const vec3_t<T>& a, const vec3_t<T>& b)
{
    return vec3_t<bool>(a.x <= b.x, a.y <= b.y, a.z <= b.z);
}

template<class T>
inline vec3_t<bool> operator>=(const vec3_t<T>& a, const vec3_t<T>& b)
{
    return vec3_t<bool>(a.x >= b.x, a.y >= b.y, a.z >= b.z);
}

template<class T>
inline vec3_t<bool> operator!(const vec3_t<bool>& v)
{
    return vec3_t<bool>(!v.x, !v.y, !v.z);
}

inline bool any(const vec3_t<bool>& v)
{
    return v.x || v.y || v.z;
}

inline bool all(const vec3_t<bool>& v)
{
    return v.x && v.y && v.z;
}

template<class T>
inline T dot(const vec3_t<T>& a, const vec3_t<T>& b)
{
    T d = T(0);
    for (int i = 0; i < vec3_t<T>::N; i++)
    {
        d += a[i] * b[i];
    }
    return d;
}

template<class T>
inline T length(const vec3_t<T>& v)
{
    using std::sqrt;
    return sqrt(dot(v, v));
}

template<class T>
inline T lengthSquared(const vec3_t<T>& v)
{
    return dot(v, v);
}

template<class T>
inline vec3_t<T> normalize(const vec3_t<T>& v)
{
    return v / length(v);
}

template<class T>
inline void coordinateSystem(const vec3_t<T>& v1, vec3_t<T>& v2, vec3_t<T>& v3)
{
    using std::abs;
    using std::sqrt;

    // assuming v1 is already normalized
    assert(abs(length(v1) - T(1)) < T(0.001));

    if (abs(v1.x) > abs(v1.y))
    {
        T invLen = T(1) / sqrt(v1.x * v1.x + v1.z * v1.z);
        v2 = vec3_t<T>(-v1.z * invLen, T(0), v1.x * invLen);
    }
    else
    {
        T invLen = T(1) / sqrt(v1.y * v1.y + v1.z * v1.z);
        v2 = vec3_t<T>(T(0), v1.z * invLen, -v1.y * invLen);
    }
    v3 = cross(v1, v2);
}

template<class T>
inline vec3_t<T> cross(const vec3_t<T>& a, const vec3_t<T>& b)
{
    return vec3_t<T>(
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x);
}

template<class T>
inline vec3_t<T> abs(const vec3_t<T>& v)
{
    using std::abs;
    return vec3_t<T>(abs(v.x), abs(v.y), abs(v.z));
}

template<class T>
inline vec3_t<T> min(const vec3_t<T>& a, const vec3_t<T>& b)
{
    using std::min;
    return vec3_t<T>(min(a.x, b.x), min(a.y, b.y), min(a.z, b.z));
}

template<class T>
inline vec3_t<T> max(const vec3_t<T>& a, const vec3_t<T>& b)
{
    using std::max;
    return vec3_t<T>(max(a.x, b.x), max(a.y, b.y), max(a.z, b.z));
}

template<class T>
inline size_t size(const vec3_t<T>& v)
{
    return 3;
}

template<class T>
struct vec4_t
{
    union
    {
        T e[4];
        
        struct
        {
            T x, y, z, w;
        };
    };

    static const int N = 4;

    vec4_t()
    {
        for (int i = 0; i < N; i++)
        {
            e[i] = T(0);
        }
    }

    vec4_t(const vec4_t& other)
    {
        for (int i = 0; i < N; i++)
        {
            e[i] = other.e[i];
        }
    }

    vec4_t& operator=(const vec4_t& other)
    {
        for (int i = 0; i < N; i++)
        {
            e[i] = other.e[i];
        }
        return *this;
    }

    template<class U>
    explicit vec4_t(const vec4_t<U>& other)
    {
        x = T(other.x);
        y = T(other.y);
        z = T(other.z);
        w = T(other.w);
    }

    vec4_t(T x, T y, T z, T w)
    {
        e[0] = x;
        e[1] = y;
        e[2] = z;
        e[3] = w;
    }

    vec4_t(T x, const vec3_t<T>& yzw)
    {
        e[0] = x;
        e[1] = yzw[0];
        e[2] = yzw[1];
        e[3] = yzw[2];
    }

    vec4_t(const vec3_t<T>& xyz, T w)
    {
        e[0] = xyz[0];
        e[1] = xyz[1];
        e[2] = xyz[2];
        e[3] = w;
    }

    vec4_t(T x, T y, const vec2_t<T>& zw)
    {
        e[0] = x;
        e[1] = y;
        e[2] = zw[0];
        e[3] = zw[1];
    }

    vec4_t(T x, const vec2_t<T>& yz, T w)
    {
        e[0] = x;
        e[1] = yz[0];
        e[2] = yz[1];
        e[3] = w;
    }

    vec4_t(const vec2_t<T>& xy, T z, T w)
    {
        e[0] = xy[0];
        e[1] = xy[1];
        e[2] = z;
        e[3] = w;
    }

    vec4_t(const vec2_t<T>& xy, const vec2_t<T>& zw)
    {
        e[0] = xy[0];
        e[1] = xy[1];
        e[2] = zw[0];
        e[3] = zw[1];
    }

    explicit vec4_t(T u)
    {
        for (int i = 0; i < N; i++)
        {
            e[i] = u;
        }
    }

    T& operator[](int i)
    {
        return e[i];
    }

    const T& operator[](int i) const
    {
        return e[i];
    }

    vec4_t& operator+=(const vec4_t& other)
    {
        for (int i = 0; i < N; i++)
        {
            e[i] += other.e[i];
        }
        return *this;
    }

    vec4_t& operator-=(const vec4_t& other)
    {
        for (int i = 0; i < N; i++)
        {
            e[i] -= other.e[i];
        }
        return *this;
    }

    vec4_t& operator*=(const vec4_t& other)
    {
        for (int i = 0; i < N; i++)
        {
            e[i] *= other.e[i];
        }
        return *this;
    }

    vec4_t& operator*=(T u)
    {
        for (int i = 0; i < N; i++)
        {
            e[i] *= u;
        }
        return *this;
    }

    vec4_t& operator/=(const vec4_t& other)
    {
        for (int i = 0; i < N; i++)
        {
            e[i] /= other.e[i];
        }
        return *this;
    }

    vec4_t& operator/=(T u)
    {
        for (int i = 0; i < N; i++)
        {
            e[i] /= u;
        }
        return *this;
    }

    vec2_t<T>& xy()
    {
        return (vec2_t<T>&)e[0];
    }

    const vec2_t<T>& xy() const
    {
        return (const vec2_t<T>&)e[0];
    }

    vec3_t<T>& xyz()
    {
        return (vec3_t<T>&)e[0];
    }

    const vec3_t<T>& xyz() const
    {
        return (const vec3_t<T>&)e[0];
    }

    vec2_t<T>& yz()
    {
        return (vec2_t<T>&)e[1];
    }

    const vec2_t<T>& yz() const
    {
        return (const vec2_t<T>&)e[1];
    }

    vec3_t<T>& yzw()
    {
        return (vec3_t<T>&)e[1];
    }

    const vec3_t<T>& yzw() const
    {
        return (const vec3_t<T>&)e[1];
    }

    vec2_t<T>& zw()
    {
        return (vec2_t<T>&)e[2];
    }

    const vec2_t<T>& zw() const
    {
        return (const vec2_t<T>&)e[2];
    }
};

template<class T>
inline vec4_t<T> operator-(const vec4_t<T>& v)
{
    return vec4_t<T>(-v.x, -v.y, -v.z, -v.w);
}

template<class T>
inline vec4_t<T> operator+(const vec4_t<T>& v)
{
    return vec4_t<T>(+v.x, +v.y, +v.z, +v.w);
}

template<class T>
inline vec4_t<T> operator+(vec4_t<T> a, const vec4_t<T>& b)
{
    a += b;
    return a;
}

template<class T>
inline vec4_t<T> operator-(vec4_t<T> a, const vec4_t<T>& b)
{
    a -= b;
    return a;
}

template<class T>
inline vec4_t<T> operator*(vec4_t<T> a, const vec4_t<T>& b)
{
    a *= b;
    return a;
}

template<class T>
inline vec4_t<T> operator*(vec4_t<T> a, T u)
{
    a *= u;
    return a;
}

template<class T>
inline vec4_t<T> operator*(T u, vec4_t<T> a)
{
    return vec4_t<T>(u * a.x, u * a.y, u * a.z, u * a.w);
}

template<class T>
inline vec4_t<T> operator/(vec4_t<T> a, const vec4_t<T>& b)
{
    a /= b;
    return a;
}

template<class T>
inline vec4_t<T> operator/(vec4_t<T> a, T u)
{
    a /= u;
    return a;
}

template<class T>
inline vec4_t<bool> operator==(const vec4_t<T>& a, const vec4_t<T>& b)
{
    return vec4_t<bool>(a.x == b.x, a.y == b.y, a.z == b.z, a.w == b.w);
}

template<class T>
inline vec4_t<bool> operator!=(const vec4_t<T>& a, const vec4_t<T>& b)
{
    return vec4_t<bool>(a.x != b.x, a.y != b.y, a.z != b.z, a.w != b.w);
}

template<class T>
inline vec4_t<bool> operator<(const vec4_t<T>& a, const vec4_t<T>& b)
{
    return vec4_t<bool>(a.x < b.x, a.y < b.y, a.z < b.z, a.w < b.w);
}

template<class T>
inline vec4_t<bool> operator>(const vec4_t<T>& a, const vec4_t<T>& b)
{
    return vec4_t<bool>(a.x > b.x, a.y > b.y, a.z > b.z, a.w > b.w);
}

template<class T>
inline vec4_t<bool> operator<=(const vec4_t<T>& a, const vec4_t<T>& b)
{
    return vec4_t<bool>(a.x <= b.x, a.y <= b.y, a.z <= b.z, a.w <= b.w);
}

template<class T>
inline vec4_t<bool> operator>=(const vec4_t<T>& a, const vec4_t<T>& b)
{
    return vec4_t<bool>(a.x >= b.x, a.y >= b.y, a.z >= b.z, a.w >= b.w);
}

template<class T>
inline vec4_t<bool> operator!(const vec4_t<bool>& v)
{
    return vec4_t<bool>(!v.x, !v.y, !v.z, !v.w);
}

inline bool any(const vec4_t<bool>& v)
{
    return v.x || v.y || v.z || v.w;
}

inline bool all(const vec4_t<bool>& v)
{
    return v.x && v.y && v.z && v.w;
}

template<class T>
inline T dot(const vec4_t<T>& a, const vec4_t<T>& b)
{
    T d = T(0);
    for (int i = 0; i < vec4_t<T>::N; i++)
    {
        d += a[i] * b[i];
    }
    return d;
}

template<class T>
inline T length(const vec4_t<T>& v)
{
    using std::sqrt;
    return sqrt(dot(v, v));
}

template<class T>
inline T lengthSquared(const vec4_t<T>& v)
{
    return dot(v, v);
}

template<class T>
vec4_t<T> normalize(const vec4_t<T>& v)
{
    return v / length(v);
}

template<class T>
vec4_t<T> abs(const vec4_t<T>& v)
{
    using std::abs;
    return vec4_t<T>(abs(v.x), abs(v.y), abs(v.z), abs(v.w));
}

template<class T>
inline vec4_t<T> min(const vec4_t<T>& a, const vec4_t<T>& b)
{
    using std::min;
    return vec4_t<T>(min(a.x, b.x), min(a.y, b.y), min(a.z, b.z), min(a.w, b.w));
}

template<class T>
inline vec4_t<T> max(const vec4_t<T>& a, const vec4_t<T>& b)
{
    using std::max;
    return vec4_t<T>(max(a.x, b.x), max(a.y, b.y), max(a.z, b.z), max(a.w, b.w));
}

template<class T>
inline size_t size(const vec4_t<T>& v)
{
    return 4;
}

template<class T>
struct mat2_t
{
    T e[4];

    static const int NCols = 2;
    static const int NRows = 2;

    mat2_t()
    {
        for (int c = 0; c < NCols; c++)
        {
            for (int r = 0; r < NRows; r++)
            {
                int i = NRows * c + r;

                if (c == r)
                {
                    e[i] = T(1);
                }
                else
                {
                    e[i] = T(0);
                }
            }
        }
    }

    mat2_t(const mat2_t& other)
    {
        for (int i = 0; i < NCols * NRows; i++)
        {
            e[i] = other.e[i];
        }
    }

    mat2_t& operator=(const mat2_t& other)
    {
        for (int i = 0; i < NCols * NRows; i++)
        {
            e[i] = other.e[i];
        }
        return *this;
    }

    template<class U>
    explicit mat2_t(const mat2_t<U>& other)
    {
        for (int i = 0; i < NCols * NRows; i++)
        {
            e[i] = T(other.e[i]);
        }
    }

    explicit mat2_t(T u)
    {
        for (int c = 0; c < NCols; c++)
        {
            for (int r = 0; r < NRows; r++)
            {
                int i = NRows * c + r;

                if (c == r)
                {
                    e[i] = u;
                }
                else
                {
                    e[i] = T(0);
                }
            }
        }
    }

    mat2_t(
        const vec2_t<T>& col0,
        const vec2_t<T>& col1)
    {
        (vec2_t<T>&)e[0] = col0;
        (vec2_t<T>&)e[2] = col1;
    }

    mat2_t(
        T c0r0, T c0r1,
        T c1r0, T c1r1)
    {
        e[0] = c0r0;
        e[1] = c0r1;
        e[2] = c1r0;
        e[3] = c1r1;
    }

    vec2_t<T>& operator[](int col)
    {
        return (vec2_t<T>&)e[col * NRows];
    }

    const vec2_t<T>& operator[](int col) const
    {
        return (const vec2_t<T>&)e[col * NRows];
    }

    mat2_t& operator*=(const mat2_t& other)
    {
        for (int r = 0; r < NRows; r++)
        {
            vec2_t<T> row(e[0 + r], e[2 + r]);

            for (int c = 0; c < NCols; c++)
            {
                e[c * NRows + r] = dot(row, other[c]);
            }
        }
        return *this;
    }

    mat2_t& operator+=(const mat2_t& other)
    {
        for (int i = 0; i < NCols * NRows; i++)
        {
            e[i] += other.e[i];
        }
        return *this;
    }
    
    mat2_t& operator-=(const mat2_t& other)
    {
        for (int i = 0; i < NCols * NRows; i++)
        {
            e[i] -= other.e[i];
        }
        return *this;
    }
};

template<class T>
inline mat2_t<T> operator*(mat2_t<T> a, const mat2_t<T>& b)
{
    return a *= b;
}

template<class T>
inline mat2_t<T> operator+(mat2_t<T> a, const mat2_t<T>& b)
{
    return a += b;
}

template<class T>
inline mat2_t<T> operator-(mat2_t<T> a, const mat2_t<T>& b)
{
    return a -= b;
}

template<class T>
inline vec2_t<T> operator*(const mat2_t<T>& m, const vec2_t<T>& v)
{
    return vec2_t<T>(
        dot(vec2_t<T>(m.e[0], m.e[2]), v),
        dot(vec2_t<T>(m.e[1], m.e[3]), v));
}

template<class T>
inline vec2_t<T> operator*(const vec2_t<T>& a, const vec2_t<T>& m)
{
    return vec2_t<T>(dot(a, m[0]), dot(a, m[1]));
}

template<class T>
inline mat2_t<T> transpose(const mat2_t<T>& m)
{
    const T* e = m.e;
    return mat2_t<T>(
        e[0], e[2],
        e[1], e[3]);
}

template<class T>
inline T trace(const mat2_t<T>& m)
{
    return m[0][0] + m[1][1];
}

template<class T>
inline T det(const mat2_t<T>& m)
{
    return m[0][0] * m[1][1] - m[0][1] * m[1][0];
}

template<class T>
struct mat3_t
{
    T e[9];

    static const int NCols = 3;
    static const int NRows = 3;

    mat3_t()
    {
        for (int c = 0; c < NCols; c++)
        {
            for (int r = 0; r < NRows; r++)
            {
                int i = NRows * c + r;

                if (c == r)
                {
                    e[i] = T(1);
                }
                else
                {
                    e[i] = T(0);
                }
            }
        }
    }

    mat3_t(const mat3_t& other)
    {
        for (int i = 0; i < NCols * NRows; i++)
        {
            e[i] = other.e[i];
        }
    }

    mat3_t& operator=(const mat3_t& other)
    {
        for (int i = 0; i < NCols * NRows; i++)
        {
            e[i] = other.e[i];
        }
        return *this;
    }

    template<class U>
    explicit mat3_t(const mat3_t<U>& other)
    {
        for (int i = 0; i < NCols * NRows; i++)
        {
            e[i] = T(other.e[i]);
        }
    }

    explicit mat3_t(T u)
    {
        for (int c = 0; c < NCols; c++)
        {
            for (int r = 0; r < NRows; r++)
            {
                int i = NRows * c + r;

                if (c == r)
                {
                    e[i] = u;
                }
                else
                {
                    e[i] = T(0);
                }
            }
        }
    }

    explicit mat3_t(const mat2_t<T>& other)
    {
        for (int c = 0; c < NCols; c++)
        {
            for (int r = 0; r < NRows; r++)
            {
                int i = NRows * c + r;

                if (c < 2 && r < 2)
                {
                    e[i] = other.e[mat3_t<T>::NRows * c + r]
                }
                else if (c == r)
                {
                    e[i] = T(1);
                }
                else
                {
                    e[i] = T(0);
                }
            }
        }
    }

    mat3_t(
        const vec3_t<T>& col0,
        const vec3_t<T>& col1,
        const vec3_t<T>& col2)
    {
        (vec3_t<T>&)e[0] = col0;
        (vec3_t<T>&)e[3] = col1;
        (vec3_t<T>&)e[6] = col2;
    }

    mat3_t(
        T c0r0, T c0r1, T c0r2,
        T c1r0, T c1r1, T c1r2,
        T c2r0, T c2r1, T c2r2)
    {
        e[0] = c0r0;
        e[1] = c0r1;
        e[2] = c0r2;
        e[3] = c1r0;
        e[4] = c1r1;
        e[5] = c1r2;
        e[6] = c2r0;
        e[7] = c2r1;
        e[8] = c2r2;
    }

    vec3_t<T>& operator[](int col)
    {
        return (vec3_t<T>&)e[col * NRows];
    }

    const vec3_t<T>& operator[](int col) const
    {
        return (const vec3_t<T>&)e[col * NRows];
    }

    mat3_t& operator*=(const mat3_t& other)
    {
        for (int r = 0; r < NRows; r++)
        {
            vec3_t<T> row(e[0 + r], e[3 + r], e[6 + r]);

            for (int c = 0; c < NCols; c++)
            {
                e[c * NRows + r] = dot(row, other[c]);
            }
        }
        return *this;
    }

    mat3_t& operator+=(const mat3_t& other)
    {
        for (int i = 0; i < NCols * NRows; i++)
        {
            e[i] += other.e[i];
        }
        return *this;
    }

    mat3_t& operator-=(const mat3_t& other)
    {
        for (int i = 0; i < NCols * NRows; i++)
        {
            e[i] -= other.e[i];
        }
        return *this;
    }

    static mat3_t axisRotationDegrees(T degrees, const vec3_t<T>& axis)
    {
        T th = degtorad(degrees);
        T c = cos(th);
        T s = sin(th);

        return mat3_t(
            // column 1
            c + (T(1) - c) * axis.x * axis.x, 
            (T(1) - c) * axis.x * axis.y + s * axis.z,
            (T(1) - c) * axis.x * axis.z - s * axis.y,
            // column 2
            (T(1) - c) * axis.x * axis.y - s * axis.z,
            c + (T(1) - c) * axis.y * axis.y,
            (T(1) - c) * axis.y * axis.z + s * axis.x,
            // column 3
            (T(1) - c) * axis.x * axis.z + s * axis.y,
            (T(1) - c) * axis.y * axis.z - s * axis.x,
            c + (T(1) - c) * axis.z * axis.z);
    }
};

template<class T>
inline mat3_t<T> operator*(mat3_t<T> a, const mat3_t<T>& b)
{
    return a *= b;
}

template<class T>
inline mat3_t<T> operator+(mat3_t<T> a, const mat3_t<T>& b)
{
    return a += b;
}

template<class T>
inline mat3_t<T> operator-(mat3_t<T> a, const mat3_t<T>& b)
{
    return a -= b;
}

template<class T>
inline vec3_t<T> operator*(const mat3_t<T>& m, const vec3_t<T>& v)
{
    return vec3_t<T>(
        dot(vec3_t<T>(m.e[0], m.e[3], m.e[6]), v),
        dot(vec3_t<T>(m.e[1], m.e[4], m.e[7]), v),
        dot(vec3_t<T>(m.e[2], m.e[5], m.e[8]), v));
}

template<class T>
inline vec3_t<T> operator*(const vec3_t<T>& a, const mat3_t<T>& m)
{
    return vec3_t<T>(dot(a, m[0]), dot(a, m[1]), dot(a, m[2]));
}

template<class T>
inline mat3_t<T> transpose(const mat3_t<T>& m)
{
    const T* e = m.e;
    return mat3_t<T>(
        e[0], e[3], e[6],
        e[1], e[4], e[7],
        e[2], e[5], e[8]);
}

template<class T>
inline T trace(const mat3_t<T>& m)
{
    return m[0][0] + m[1][1] + m[2][2];
}

template<class T>
inline T det(const mat3_t<T>& m)
{
    return
        + m[0][0] * m[1][1] * m[2][2]
        + m[1][0] * m[2][1] * m[0][2]
        + m[2][0] * m[0][1] * m[1][2]
        - m[2][0] * m[1][1] * m[0][2]
        - m[1][0] * m[0][1] * m[2][2]
        - m[0][0] * m[2][1] * m[1][2];
}

template<class T>
struct mat4_t
{
    T e[16];

    static const int NCols = 4;
    static const int NRows = 4;

    mat4_t()
    {
        for (int c = 0; c < NCols; c++)
        {
            for (int r = 0; r < NRows; r++)
            {
                int i = NRows * c + r;

                if (c == r)
                {
                    e[i] = T(1);
                }
                else
                {
                    e[i] = T(0);
                }
            }
        }
    }

    mat4_t(const mat4_t& other)
    {
        for (int i = 0; i < NCols * NRows; i++)
        {
            e[i] = other.e[i];
        }
    }

    mat4_t& operator=(const mat4_t& other)
    {
        for (int i = 0; i < NCols * NRows; i++)
        {
            e[i] = other.e[i];
        }
        return *this;
    }

    template<class U>
    explicit mat4_t(const mat4_t<U>& other)
    {
        for (int i = 0; i < NCols * NRows; i++)
        {
            e[i] = T(other.e[i]);
        }
    }

    explicit mat4_t(T u)
    {
        for (int c = 0; c < NCols; c++)
        {
            for (int r = 0; r < NRows; r++)
            {
                int i = NRows * c + r;

                if (c == r)
                {
                    e[i] = u;
                }
                else
                {
                    e[i] = T(0);
                }
            }
        }
    }

    explicit mat4_t(const mat2_t<T>& other)
    {
        for (int c = 0; c < NCols; c++)
        {
            for (int r = 0; r < NRows; r++)
            {
                int i = NRows * c + r;

                if (c < 2 && r < 2)
                {
                    e[i] = other.e[mat2_t<T>::NRows * c + r]
                }
                else if (c == r)
                {
                    e[i] = T(1);
                }
                else
                {
                    e[i] = T(0);
                }
            }
        }
    }

    explicit mat4_t(const mat3_t<T>& other)
    {
        for (int c = 0; c < NCols; c++)
        {
            for (int r = 0; r < NRows; r++)
            {
                int i = NRows * c + r;

                if (c < 3 && r < 3)
                {
                    e[i] = other.e[mat3_t<T>::NRows * c + r]
                }
                else if (c == r)
                {
                    e[i] = T(1);
                }
                else
                {
                    e[i] = T(0);
                }
            }
        }
    }

    mat4_t(
        const vec4_t<T>& col0,
        const vec4_t<T>& col1,
        const vec4_t<T>& col2,
        const vec4_t<T>& col3)
    {
        (vec4_t<T>&)e[0] = col0;
        (vec4_t<T>&)e[4] = col1;
        (vec4_t<T>&)e[8] = col2;
        (vec4_t<T>&)e[12] = col3;
    }

    mat4_t(
        T c0r0, T c0r1, T c0r2, T c0r3,
        T c1r0, T c1r1, T c1r2, T c1r3,
        T c2r0, T c2r1, T c2r2, T c2r3,
        T c3r0, T c3r1, T c3r2, T c3r3)
    {
        e[0] = c0r0;
        e[1] = c0r1;
        e[2] = c0r2;
        e[3] = c0r3;
        e[4] = c1r0;
        e[5] = c1r1;
        e[6] = c1r2;
        e[7] = c1r3;
        e[8] = c2r0;
        e[9] = c2r1;
        e[10] = c2r2;
        e[11] = c2r3;
        e[12] = c3r0;
        e[13] = c3r1;
        e[14] = c3r2;
        e[15] = c3r3;
    }

    vec4_t<T>& operator[](int col)
    {
        return (vec4_t<T>&)e[col * NRows];
    }
    
    const vec4_t<T>& operator[](int col) const
    {
        return (const vec4_t<T>&)e[col * NRows];
    }

    mat4_t& operator*=(const mat4_t& other)
    {
        for (int r = 0; r < NRows; r++)
        {
            vec4_t<T> row(e[0  + r], e[4  + r], e[8  + r], e[12 + r]);

            for (int c = 0; c < NCols; c++)
            {
                e[c * NRows + r] = dot(row, other[c]);
            }
        }
        return *this;
    }

    mat4_t& operator*=(T u)
    {
        for (T& x : e)
        {
            x *= u;
        }
        return *this;
    }

    mat4_t& operator+=(const mat4_t& other)
    {
        for (int i = 0; i < NCols * NRows; i++)
        {
            e[i] += other.e[i];
        }
        return *this;
    }

    mat4_t& operator-=(const mat4_t& other)
    {
        for (int i = 0; i < NCols * NRows; i++)
        {
            e[i] -= other.e[i];
        }
        return *this;
    }

    mat4_t& operator/=(T u)
    {
        for (T& x : e)
        {
            x /= u;
        }
        return *this;
    }

    static mat4_t ortho(T left, T right, T bottom, T top, T nearVal, T farVal)
    {
        T tx = -(right + left) / (right - left);
        T ty = -(top + bottom) / (top - bottom);
        T tz = -(farVal + nearVal) / (farVal - nearVal);

        return mat4_t(
            T(2) / (right - left), T(0), T(0), T(0),
            T(0), T(2) / (top - bottom), T(0), T(0),
            T(0), T(0), T(-2) / (farVal - nearVal), T(0),
            tx, ty, tz, T(1));
    }

    static mat4_t ortho2D(T left, T right, T bottom, T top)
    {
        return ortho(left, right, bottom, top, T(-1), T(1));
    }

    static mat4_t frustum(T left, T right, T bottom, T top, T nearVal, T farVal)
    {
        T a = (right + left) / (right - left);
        T b = (top + bottom) / (top - bottom);
        T c = -(farVal + nearVal) / (farVal - nearVal);
        T d = -(2 * farVal * nearVal) / (farVal - nearVal);

        return mat4_t(
            T(2) * nearVal / (right - left), T(0), T(0), T(0),
            T(0), T(2) * nearVal / (top - bottom), T(0), T(0),
            a, b, c, T(-1),
            T(0), T(0), d, T(0));
    }

    static mat4_t perspective(T fovy, T aspect, T zNear, T zFar)
    {
        T fovyRad = fovy * T(3.14159265359) / T(180);
        T f = std::tan(fovyRad / T(2));

        return mat4_t(
            f / aspect, T(0), T(0), T(0),
            T(0), f, T(0), T(0),
            T(0), T(0), (zFar + zNear) / (zNear - zFar), T(-1),
            T(0), T(0), T(2) * zFar * zNear / (zNear - zFar), T(0));
    }

    static mat4_t lookAt(const vec3_t<T>& eye, const vec3_t<T>& center, const vec3_t<T>& up)
    {
        vec3_t<T> f = normalize(center - eye);
        vec3_t<T> s = normalize(cross(f, normalize(up)));
        vec3_t<T> u = normalize(cross(s, f));
        vec3_t<T> t(-dot(s, eye), -dot(u, eye), dot(f, eye));
        return mat4_t(
            s[0],  u[0], -f[0], T(0),
            s[1],  u[1], -f[1], T(0),
            s[2],  u[2], -f[2], T(0),
            t[0],  t[1],  t[2], T(1));
    }

    static mat4_t lookTo(const vec3_t<T>& eye, const vec3_t<T>& look, const vec3_t<T>& up)
    {
        vec3_t<T> f = normalize(look);
        vec3_t<T> s = normalize(cross(f, normalize(up)));
        vec3_t<T> u = normalize(cross(s, f));
        vec3_t<T> t(-dot(s, eye), -dot(u, eye), dot(f, eye));
        return mat4_t(
            s[0],  u[0], -f[0], T(0),
            s[1],  u[1], -f[1], T(0),
            s[2],  u[2], -f[2], T(0),
            t[0],  t[1],  t[2], T(1));
    }
};

template<class T>
inline mat4_t<T> operator*(mat4_t<T> a, const mat4_t<T>& b)
{
    return a *= b;
}

template<class T>
inline mat4_t<T> operator+(mat4_t<T> a, const mat4_t<T>& b)
{
    return a += b;
}

template<class T>
inline mat4_t<T> operator-(mat4_t<T> a, const mat4_t<T>& b)
{
    return a -= b;
}

template<class T>
inline vec4_t<T> operator*(const mat4_t<T>& m, const vec4_t<T>& v)
{
    return vec4_t<T>(
        dot(vec4_t<T>(m.e[0], m.e[4], m.e[8],  m.e[12]), v),
        dot(vec4_t<T>(m.e[1], m.e[5], m.e[9],  m.e[13]), v),
        dot(vec4_t<T>(m.e[2], m.e[6], m.e[10], m.e[14]), v),
        dot(vec4_t<T>(m.e[3], m.e[7], m.e[11], m.e[15]), v));
}

template<class T>
inline vec4_t<T> operator*(const vec4_t<T>& a, const mat4_t<T>& m)
{
    return vec4_t<T>(
        dot(a, m[0]), dot(a, m[1]), dot(a, m[2]), dot(a, m[3]));
}

template<class T>
inline mat4_t<T> operator*(mat4_t<T> m, T u)
{
    return m *= u;
}

template<class T>
inline mat4_t<T> operator*(T u, mat4_t<T> m)
{
    return m *= u;
}

template<class T>
inline mat4_t<T> operator/(mat4_t<T> m, T u)
{
    return m /= u;
}

template<class T>
inline mat4_t<T> transpose(const mat4_t<T>& m)
{
    const T* e = m.e;
    return mat4_t<T>(
        e[0], e[4], e[8],  e[12],
        e[1], e[5], e[9],  e[13],
        e[2], e[6], e[10], e[14],
        e[3], e[7], e[11], e[15]);
}

template<class T>
inline T trace(const mat4_t<T>& m)
{
    return m[0][0] + m[1][1] + m[2][2] + m[3][3];
}

template<class T>
inline T det(const mat4_t<T>& m)
{
    return
        + m[0][0] * m[1][1] * m[2][2] * m[3][3] + m[0][0] * m[2][1] * m[3][2] * m[1][3] + m[0][0] * m[3][1] * m[1][2] * m[2][3]
        + m[1][0] * m[0][1] * m[3][2] * m[2][3] + m[1][0] * m[2][1] * m[0][2] * m[3][3] + m[1][0] * m[3][1] * m[2][2] * m[0][3]
        + m[2][0] * m[0][1] * m[1][2] * m[3][3] + m[2][0] * m[1][1] * m[3][2] * m[0][3] + m[2][0] * m[3][1] * m[0][2] * m[1][3]
        + m[3][0] * m[0][1] * m[2][2] * m[1][3] + m[3][0] * m[1][1] * m[0][2] * m[2][3] + m[3][0] * m[2][1] * m[1][2] * m[0][3]
        - m[0][0] * m[1][1] * m[3][2] * m[2][3] - m[0][0] * m[2][1] * m[1][2] * m[3][3] - m[0][0] * m[3][1] * m[2][2] * m[1][3]
        - m[1][0] * m[0][1] * m[2][2] * m[3][3] - m[1][0] * m[2][1] * m[3][2] * m[0][3] - m[1][0] * m[3][1] * m[0][2] * m[2][3]
        - m[2][0] * m[0][1] * m[3][2] * m[1][3] - m[2][0] * m[1][1] * m[0][2] * m[3][3] - m[2][0] * m[3][1] * m[1][2] * m[0][3]
        - m[3][0] * m[0][1] * m[1][2] * m[2][3] - m[3][0] * m[1][1] * m[2][2] * m[0][3] - m[3][0] * m[2][1] * m[0][2] * m[1][3];
}

template<class T>
inline mat4_t<T> inverse(const mat4_t<T>& m)
{
    T c00 = m[2][2] * m[3][3] - m[3][2] * m[2][3];
    T c02 = m[1][2] * m[3][3] - m[3][2] * m[1][3];
    T c03 = m[1][2] * m[2][3] - m[2][2] * m[1][3];
      
    T c04 = m[2][1] * m[3][3] - m[3][1] * m[2][3];
    T c06 = m[1][1] * m[3][3] - m[3][1] * m[1][3];
    T c07 = m[1][1] * m[2][3] - m[2][1] * m[1][3];
      
    T c08 = m[2][1] * m[3][2] - m[3][1] * m[2][2];
    T c10 = m[1][1] * m[3][2] - m[3][1] * m[1][2];
    T c11 = m[1][1] * m[2][2] - m[2][1] * m[1][2];
      
    T c12 = m[2][0] * m[3][3] - m[3][0] * m[2][3];
    T c14 = m[1][0] * m[3][3] - m[3][0] * m[1][3];
    T c15 = m[1][0] * m[2][3] - m[2][0] * m[1][3];
      
    T c16 = m[2][0] * m[3][2] - m[3][0] * m[2][2];
    T c18 = m[1][0] * m[3][2] - m[3][0] * m[1][2];
    T c19 = m[1][0] * m[2][2] - m[2][0] * m[1][2];
      
    T c20 = m[2][0] * m[3][1] - m[3][0] * m[2][1];
    T c22 = m[1][0] * m[3][1] - m[3][0] * m[1][1];
    T c23 = m[1][0] * m[2][1] - m[2][0] * m[1][1];

    vec4_t<T> f0(c00, c00, c02, c03);
    vec4_t<T> f1(c04, c04, c06, c07);
    vec4_t<T> f2(c08, c08, c10, c11);
    vec4_t<T> f3(c12, c12, c14, c15);
    vec4_t<T> f4(c16, c16, c18, c19);
    vec4_t<T> f5(c20, c20, c22, c23);

    vec4_t<T> v0(m[1][0], m[0][0], m[0][0], m[0][0]);
    vec4_t<T> v1(m[1][1], m[0][1], m[0][1], m[0][1]);
    vec4_t<T> v2(m[1][2], m[0][2], m[0][2], m[0][2]);
    vec4_t<T> v3(m[1][3], m[0][3], m[0][3], m[0][3]);

    vec4_t<T> inv0(v1 * f0 - v2 * f1 + v3 * f2);
    vec4_t<T> inv1(v0 * f0 - v2 * f3 + v3 * f4);
    vec4_t<T> inv2(v0 * f1 - v1 * f3 + v3 * f5);
    vec4_t<T> inv3(v0 * f2 - v1 * f4 + v2 * f5);

    vec4_t<T> sgnA(+1, -1, +1, -1);
    vec4_t<T> sgnB(-1, +1, -1, +1);
    mat4_t<T> inv(inv0 * sgnA, inv1 * sgnB, inv2 * sgnA, inv3 * sgnB);

    vec4_t<T> r0(inv[0][0], inv[1][0], inv[2][0], inv[3][0]);

    vec4_t<T> d0(m[0] * r0);
    T d1 = (d0.x + d0.y) + (d0.z + d0.w);

    assert(std::abs(d1) != 0.0);
    
    return inv / d1;
}

template<class T>
inline void eigendecompose(
    mat3_t<T> m, vec3_t<T>& eigenvalues, mat3_t<T>& eigenvectors,
    int maxSweeps = 32, T epsilon = T(1.0e-10))
{
    // Finds eigenvalues & vectors of a 3x3 symmetric matrix using the Jacobi method
    // Based on listing 16.7 of Mathematics for 3D Game Programming and Computer Graphics

    // This algorithm iteratively makes the off-diagonals smaller.
    // This is done by repeatedly multiplying the matrix M by R^T * M * R,
    // where R is a rotation matrix that anhilates one of the three off-diagonal entries.
    //
    // When it converges, the diagonal of M will store the eigenvalues,
    // and the columns of R_1 R_2 R_3 ... R_m will store the eigenvectors.

    // Input matrix must be symmetric
    assert(m[1][0] == m[0][1]);
    assert(m[2][0] == m[0][2]);
    assert(m[2][1] == m[1][2]);

    // initially no rotation
    eigenvectors = mat3_t<T>();

    auto annihilate = [&](
        int c, int r, 
        T* other1, T* other2 /* the other off 2 diagonals */)
    {
        if (m[c][r] == T(0))
        {
            return;
        }

        T u = (m[r][r] - m[c][c]) * T(0.5) / m[c][r];
        T u2 = u * u;
        T u2p1 = u2 + T(1);
        T t = (u2p1 != u2) ?
            ((u < T(0)) ? T(-1) : T(1)) * (sqrt(u2p1) - abs(u))
            : T(0.5) / u;
        T cosine = T(1) / sqrt(t * t + T(1));
        T sine = cosine * t;

        m[c][c] -= t * m[c][r];
        m[r][r] += t * m[c][r];
        m[c][r] = T(0);

        T temp = cosine * (*other1) - sine * (*other2);
        *other2 = sine * (*other1) + cosine * (*other2);
        *other1 = temp;

        for (int i = 0; i < 3; i++)
        {
            T temp = cosine * eigenvectors[c][i] - sine * eigenvectors[r][i];
            eigenvectors[r][i] = sine * eigenvectors[c][i] + cosine * eigenvectors[r][i];
            eigenvectors[c][i] = temp;
        }
    };

    for (int sweep = 0; sweep < maxSweeps; sweep++)
    {
        // If all off-diagonals are small enough, we have converged to a solution.
        if (abs(m[0][1]) < epsilon && abs(m[0][2]) < epsilon && abs(m[1][2]) < epsilon)
        {
            break;
        }

        annihilate(0, 1, &m[0][2], &m[1][2]);
        annihilate(0, 2, &m[0][1], &m[1][2]);
        annihilate(1, 2, &m[0][1], &m[0][2]);
    }

    eigenvalues = vec3_t<T>(m[0][0], m[1][1], m[2][2]);
}

using vec2 = vec2_t<float>;
using dvec2 = vec2_t<double>;
using ivec2 = vec2_t<int>;
using uvec2 = vec2_t<unsigned int>;
using bvec2 = vec2_t<bool>;

using vec3 = vec3_t<float>;
using dvec3 = vec3_t<double>;
using ivec3 = vec3_t<int>;
using uvec3 = vec3_t<unsigned int>;
using bvec3 = vec3_t<bool>;

using vec4 = vec4_t<float>;
using dvec4 = vec4_t<double>;
using ivec4 = vec4_t<int>;
using uvec4 = vec4_t<unsigned int>;
using bvec4 = vec4_t<bool>;

using mat2 = mat2_t<float>;
using dmat2 = mat2_t<double>;
using imat2 = mat2_t<int>;
using umat2 = mat2_t<unsigned int>;

using mat3 = mat3_t<float>;
using dmat3 = mat3_t<double>;
using imat3 = mat3_t<int>;
using umat3 = mat3_t<unsigned int>;

using mat4 = mat4_t<float>;
using dmat4 = mat4_t<double>;
using imat4 = mat4_t<int>;
using umat4 = mat4_t<unsigned int>;

#endif // JUSTGL_MATH_H