#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>
#include <iostream>

namespace GE
{
namespace Math
{

//Vector2

/*

| x |
| y |

*/

struct Vector2 {
public:
    float x, y;
    Vector2(float new_x, float new_y)
        { x = new_x; y = new_y; }
    Vector2()
        { x = 0; y = 0; }
	bool operator==(const Vector2& b)
		{ return (x == b.x) && (y == b.y); }
	bool operator!=(const Vector2& b)
		{ return (x != b.x) || (y != b.y); }
    Vector2 operator+(const Vector2& b)
        { return Vector2(x + b.x, y + b.y); }
    Vector2& operator+=(const Vector2& b)
        { x += b.x; y += b.y; return *this; }
    static float Dot(const Vector2& a, const Vector2& b)
        { return a.x * b.x + a.y * b.y; }
    Vector2 operator*(const float& b)
        { return Vector2(b*x,b*y); }
    Vector2 operator*(const Vector2 &b)
        { return Vector2(x*b.x,y*b.y); }
    Vector2 Normalize()
        { float mag = sqrt(x*x + y*y); return Vector2(x/mag,y/mag); }
    friend std::ostream& operator<<(std::ostream& os, const Vector2& out);
};

Vector2 operator*(const float &a, const Vector2& b);

//Vector 3

/*

| x |
| y |
| z |

*/

struct Vector3 {
public:
    float x, y, z;
    Vector3(float new_x, float new_y, float new_z)
        { x = new_x; y = new_y; z = new_z; }
    Vector3(Vector2 partial, float new_z)
        { x = partial.x; y = partial.y; z = new_z; }
    Vector3()
        { x = 0; y = 0; z = 0; }
    Vector3 operator+(const Vector3& b)
        { return Vector3(x + b.x, y + b.y, z + b.z); }
    Vector3& operator+=(const Vector3& b)
        { x += b.x; y += b.y; z += b.z; return *this; }
    static float Dot(const Vector3& a, const Vector3& b)
        { return a.x * b.x + a.y * b.y + a.z * b.z; }
    static Vector3 Cross(const Vector3 &a, const Vector3 &b)
        { return Vector3(a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x); }
    Vector3 operator*(const float& b)
        { return Vector3(b*x,b*y,b*z); }
    Vector3 operator*(const Vector3 &b)
        { return Vector3(x*b.x,y*b.y,z*b.z); }
    Vector3 Normalize()
        { float mag = sqrt(x*x + y*y + z*z); return Vector3(x/mag,y/mag,z/mag); }
    friend std::ostream& operator<<(std::ostream& os, const Vector3& out);
};

Vector3 operator*(const float &a, const Vector3 &b);

//Vector4

/*

| x |
| y |
| z |
| w |

*/

struct Vector4 {
public:
    float x, y, z, w;
    Vector4(float new_x, float new_y, float new_z, float new_w)
        { x = new_x; y = new_y; z = new_z; w = new_w; }
    Vector4(Vector3 partial, float new_w)
        { x = partial.x; y = partial.y; z = partial.z; w = new_w; }
    Vector4()
        { x = 0; y = 0; z = 0; w = 0; }
    Vector4 operator+(const Vector4& b)
        { return Vector4(x + b.x, y + b.y, z + b.z, w + b.w); }
    Vector4& operator+=(const Vector4& b)
        { x += b.x; y += b.y; z += b.z; w += b.w; return *this; }
    static float Dot(const Vector4& a, const Vector4& b)
        { return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w; }
    Vector4 operator*(const float& b)
        { return Vector4(b*x,b*y,b*z,b*w); }
    Vector4 operator*(const Vector4 &b)
        { return Vector4(x*b.x,y*b.y,z*b.z,w*b.w); }
    Vector4 Normalize()
        { float mag = sqrt(x*x + y*y + z*z + w*w); return Vector4(x/mag,y/mag,z/mag,w/mag); }
    friend std::ostream& operator<<(std::ostream& os, const Vector4& out);
};

Vector4 operator*(const float &a, const Vector4 &b);

} //End of namespace "Math"
} //End of namespace "GE"

#endif // VECTOR
