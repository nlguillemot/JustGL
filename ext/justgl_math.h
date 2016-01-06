#ifndef JUSTGL_MATH_H
#define JUSTGL_MATH_H

#include <cmath>

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
    a = u * a;
    return a;
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
};

template<class T>
inline vec3_t<T> operator+(vec3_t<T> a, const vec3_t<T>& b)
{
    a += b;
    return a;
}

template<class T>
inline vec3_t<T> operator-(vec3_t<T> a, const vec3_t<T>& b)
{
    a -= b;
    return a;
}

template<class T>
inline vec3_t<T> operator*(vec3_t<T> a, const vec3_t<T>& b)
{
    a *= b;
    return a;
}

template<class T>
inline vec3_t<T> operator*(vec3_t<T> a, T u)
{
    a *= u;
    return a;
}

template<class T>
inline vec3_t<T> operator*(T u, vec3_t<T> a)
{
    a = u * a;
    return a;
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
inline vec3_t<T> cross(const vec3_t<T>& a, const vec3_t<T>& b)
{
    return vec3_t<T>(
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x);
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
};

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
    a = u * a;
    return a;
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
struct mat2_t
{
    T e[4];

    static const int NCols = 2;
    static const int NRows = 2;

    mat2_t()
    {
        for (int c = 0; c < NCols; c++)
        {
            int i = NRows * c + r;
            for (int r = 0; r < NRows; r++)
            {
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

    explicit mat2_t(T u)
    {
        for (int c = 0; c < NCols; c++)
        {
            int i = NRows * c + r;
            for (int r = 0; r < NRows; r++)
            {
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
};

template<class T>
inline mat2_t<T> operator*(mat2_t<T> a, const mat2_t<T>& b)
{
    a *= b;
    return a;
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
            int i = NRows * c + r;
            for (int r = 0; r < NRows; r++)
            {
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

    explicit mat3_t(T u)
    {
        for (int c = 0; c < NCols; c++)
        {
            int i = NRows * c + r;
            for (int r = 0; r < NRows; r++)
            {
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
            int i = NRows * c + r;
            for (int r = 0; r < NRows; r++)
            {
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
};

template<class T>
inline mat3_t<T> operator*(mat3_t<T> a, const mat3_t<T>& b)
{
    a *= b;
    return a;
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
            int i = NRows * c + r;
            for (int r = 0; r < NRows; r++)
            {
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

    explicit mat4_t(T u)
    {
        for (int c = 0; c < NCols; c++)
        {
            int i = NRows * c + r;
            for (int r = 0; r < NRows; r++)
            {
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
            int i = NRows * c + r;
            for (int r = 0; r < NRows; r++)
            {
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
            int i = NRows * c + r;
            for (int r = 0; r < NRows; r++)
            {
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
        vec3_t<T> s = cross(f, normalize(up));
        vec3_t<T> u = cross(normalize(s), f);
        return mat4_t(
            s[0], u[0], -f[0], T(0),
            s[1], u[1], -f[1], T(0),
            s[2], u[2], -f[2], T(0),
            -eye.x, -eye.y, -eye.z, T(1));
    }
};

template<class T>
inline mat4_t<T> operator*(mat4_t<T> a, const mat4_t<T>& b)
{
    a *= b;
    return a;
}

using vec2 = vec2_t<float>;
using dvec2 = vec2_t<double>;
using ivec2 = vec2_t<int>;
using uvec2 = vec2_t<unsigned int>;

using vec3 = vec3_t<float>;
using dvec3 = vec3_t<double>;
using ivec3 = vec3_t<int>;
using uvec3 = vec3_t<unsigned int>;

using vec4 = vec4_t<float>;
using dvec4 = vec4_t<double>;
using ivec4 = vec4_t<int>;
using uvec4 = vec4_t<unsigned int>;

using mat2 = mat4_t<float>;
using dmat2 = mat4_t<double>;
using imat2 = mat4_t<int>;
using umat2 = mat4_t<unsigned int>;

using mat3 = mat4_t<float>;
using dmat3 = mat4_t<double>;
using imat3 = mat4_t<int>;
using umat3 = mat4_t<unsigned int>;

using mat4 = mat4_t<float>;
using dmat4 = mat4_t<double>;
using imat4 = mat4_t<int>;
using umat4 = mat4_t<unsigned int>;

#endif // JUSTGL_MATH_H