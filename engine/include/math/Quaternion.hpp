#ifndef QUATERNION_H
#define QUATERNION_H

#include <cmath>
#include <math/Vector.hpp>

//Temporary - Remove when we include something that defines this
const double PI = 3.14159265358979323846264338327950288;

namespace GE
{
namespace Math
{

class Quaternion
{
public:
    union
    {
        struct
        {
            float w, x, y, z;
        };
        float q[4];
    };
    Quaternion& operator=(const Matrix3 &rhs);
    Quaternion& operator+=(const Quaternion &rhs);
    Quaternion operator+(const Quaternion &rhs);
    Quaternion& operator*=(const Quaternion &rhs);
    Quaternion operator*(const Quaternion &rhs);
    Quaternion Conjugate() const;
    void Normalize();
    Vector3 Direction() const;
};

extern Quaternion operator*(float lhs, const Quaternion &rhs);

extern Quaternion Matrix2Quat(const Matrix3 &mat);
extern Matrix3 Quat2Matrix(const Quaternion &quat);

extern Quaternion SLERP(Quaternion p, Quaternion q, float t);

} //End of namespace "Math"
} //End of namespace "GE"

#endif // QUATERNION_H
