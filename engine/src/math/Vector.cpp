#include <math/Vector.hpp>

using namespace GE::Math;

Vector2 operator*(const float &a, const Vector2& b)
{
    return Vector2(a*b.x,a*b.y);
}

Vector3 operator*(const float &a, const Vector3& b)
{
    return Vector3(a*b.x,a*b.y,a*b.z);
}

Vector4 operator*(const float &a, const Vector4& b)
{
    return Vector4(a*b.x,a*b.y,a*b.z,a*b.w);
}