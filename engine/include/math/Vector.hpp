#ifndef VECTOR_H
#define VECTOR_H

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
    Vector2 operator+(const Vector2& b)
        { return Vector2(x + b.x, y + b.y); }
    Vector2& operator+=(const Vector2& b)
        { x += b.x; y += b.y; return *this; }
    float Dot(const Vector2& a, const Vector2& b)
        { return a.x * b.x + a.y * b.y; }
    Vector2 operator*(const float& b)
        { return Vector2(b*x,b*y); }
    Vector2 operator*(const Vector2 &b)
        { return Vector2(x*b.x,y*b.y); }
};

extern Vector2 operator*(const float &a, const Vector2& b);

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
    Vector3()
        { x = 0; y = 0; z = 0; }
    Vector3 operator+(const Vector3& b)
        { return Vector3(x + b.x, y + b.y, z + b.z); }
    Vector3& operator+=(const Vector3& b)
        { x += b.x; y += b.y; z += b.z; return *this; }
    float Dot(const Vector3& a, const Vector3& b)
        { return a.x * b.x + a.y * b.y + a.z * b.z; }
    Vector3 Cross(const Vector3 &a, const Vector3 &b)
        { return Vector3(a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x); }
    Vector3 operator*(const float& b)
        { return Vector3(b*x,b*y,b*z); }
    Vector3 operator*(const Vector3 &b)
        { return Vector3(x*b.x,y*b.y,z*b.z); }
};

extern Vector3 operator*(const float &a, const Vector3 &b);

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
    Vector4()
        { x = 0; y = 0; z = 0; w = 0; }
    Vector4 operator+(const Vector4& b)
        { return Vector4(x + b.x, y + b.y, z + b.z, w + b.w); }
    Vector4& operator+=(const Vector4& b)
        { x += b.x; y += b.y; z += b.z; w += b.w; return *this; }
    float Dot(const Vector4& a, const Vector4& b)
        { return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w; }
    Vector4 operator*(const float& b)
        { return Vector4(b*x,b*y,b*z,b*w); }
    Vector4 operator*(const Vector4 &b)
        { return Vector4(x*b.x,y*b.y,z*b.z,w*b.w); }
};

extern Vector4 operator*(const float &a, const Vector4 &b);

} //End of namespace "Math"
} //End of namespace "GE"

#endif // VECTOR
