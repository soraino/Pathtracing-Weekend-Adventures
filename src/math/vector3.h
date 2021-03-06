#ifndef __MATH_VECTOR3_H__
#define __MATH_VECTOR3_H__

#include <math.h>
#include <stdlib.h>
#include <iostream>

template<class T>
class Vector3
{
public:
    Vector3() : x(0), y(0), z(0) {}
    Vector3(T _x, T _y, T _z) : x(_x), y(_y), z(_z) {}
    Vector3(T t) : x(t), y(t), z(t) {}
    Vector3(const Vector3<T>& copy) : x(copy.x), y(copy.y), z(copy.z) {}
    Vector3(const T* const d) : x(d[0]), y(d[1]), z(d[2]) {}

    inline const Vector3<T>& operator+() const { return *this; }
    inline Vector3<T> operator-() const { return Vector3<T>(-x, -y, -z); }
    inline T operator[](int i) const { return m_Data[i]; }
    inline T& operator[](int i) { return m_Data[i]; }

    inline Vector3<T>& operator+=(const Vector3<T>& v) { x += v.x; y += v.y; z += v.z; return *this; };
    inline Vector3<T>& operator-=(const Vector3<T>& v) { x -= v.x; y -= v.y; z -= v.z; return *this; };
    inline Vector3<T>& operator*=(const Vector3<T>& v) { x *= v.x; y *= v.y; z *= v.z; return *this; };
    inline Vector3<T>& operator/=(const Vector3<T>& v) { x /= v.x; y /= v.y; z /= v.z; return *this; };
    inline Vector3<T>& operator*=(const float t) { x *= t; y *= t; z *= t; return *this; };
    inline Vector3<T>& operator/=(const float t) { x /= t; y /= t; z /= t; return *this; };
    inline bool operator==(const Vector3<T>& v) { return (x == v.x) && (y == v.y) && (z == v.z); }

public:
    inline const float SquareMagnitude() const { return x * x + y * y + z * z; }
    inline const float Magnitude() const { return sqrt(SquareMagnitude()); }

    inline Vector3<T> Normalized() const { return m_Data / Magnitude(); };

public:
    union
    {
        struct
        {
            T x, y, z;
        };

        struct
        {
            T r, g, b;
        };

        struct
        {
            T m_Data[3];
        };
    };
};

typedef Vector3<float>		Vector3f;
typedef Vector3<int>		Vector3i;
typedef Vector3<unsigned>	Vector3u;
typedef Vector3<double>		Vector3d;

template<class T>
inline Vector3<T> operator+(const Vector3<T>& v1, const Vector3<T>& v2)
{
    return Vector3<T>(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

template<class T>
inline Vector3<T> operator-(const Vector3<T>& v1, const Vector3<T>& v2)
{
    return Vector3<T>(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

template<class T>
inline Vector3<T> operator*(const Vector3<T>& v1, const Vector3<T>& v2)
{
    return Vector3<T>(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
}

template<class T>
inline Vector3<T> operator/(const Vector3<T>& v1, const Vector3<T>& v2)
{
    return Vector3<T>(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z);
}

template<class T>
inline Vector3<T> operator*(const Vector3<T>& v, float t)
{
    return Vector3<T>(v.x * t, v.y * t, v.z * t);
}

template<class T>
inline Vector3<T> operator*(float t, const Vector3<T>& v)
{
    return Vector3<T>(v.x * t, v.y * t, v.z * t);
}

template<class T>
inline Vector3<T> operator/(const Vector3<T>& v, float t)
{
    return Vector3<T>(v.x / t, v.y / t, v.z / t);
}

template<class T>
inline void Normalize(const Vector3<T>& v)
{
    v = v.Normalized();
}

template<class T>
inline float Dot(const Vector3<T>& v1, const Vector3<T>& v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

template<class T>
inline Vector3<T> Cross(const Vector3<T>& v1, const Vector3<T>& v2)
{
    return Vector3<T>((v1.y * v2.z - v1.z * v2.y),
                     -(v1.x * v2.z - v1.z * v2.x),
                      (v1.x * v2.y - v1.y * v2.x));
}
#endif // !__MATH_VECTOR3_H__
