#include <cmath>
//For sin, acos, sqrt, etc. So, could be replaced easily.

#include <math/Matrix.hpp>
#include <math/Quaternion.hpp>

namespace GE
{
namespace Math
{

//Replace a quaternion with another one.
Quaternion& Quaternion::operator=(const Matrix3 &rhs)
{
	*this = Matrix2Quat(rhs);
	return *this;
}

//Add quaternions with the + operator.
Quaternion Quaternion::operator+(const Quaternion &rhs)
{
	Quaternion result;
	for (unsigned i = 0; i < 4; ++i)
	{
		result.q[i] = q[i] + rhs.q[i];
	}
	return result;
}

//Add a quaternion to an existing one.
Quaternion& Quaternion::operator+=(const Quaternion &rhs)
{
	for (unsigned i = 0; i < 4; ++i)
	{
		q[i] += rhs.q[i];
	}
	return *this;
}

//Use the * operator to multiply quaternions.
Quaternion Quaternion::operator*(const Quaternion &rhs)
{
	Quaternion result;
	result.q[0] = w*rhs.w - x*rhs.x - y*rhs.y - z*rhs.z;
	result.q[1] = x*rhs.w + w*rhs.x + y*rhs.z - z*rhs.y;
	result.q[2] = y*rhs.w + w*rhs.y + z*rhs.x - x*rhs.z;
	result.q[3] = z*rhs.w + w*rhs.z + x*rhs.y - y*rhs.x;
	return result;
}

//Use the *= operator to replace an existing quaternion
//with the product of it (on the left side) and another quat.
Quaternion& Quaternion::operator*=(const Quaternion &rhs)
{
	w = w*rhs.w - x*rhs.x - y*rhs.y - z*rhs.z;
	x = x*rhs.w + w*rhs.x + y*rhs.z - z*rhs.y;
	y = y*rhs.w + w*rhs.y + z*rhs.x - x*rhs.z;
	z = z*rhs.w + w*rhs.z + x*rhs.y - y*rhs.x;
	return *this;
}

Quaternion Quaternion::Conjugate() const
{
	return Quaternion{ w,-x,-y,-z };
}

//Normalizes the quaternion. Prevents numerical drift.
//The transforms look terrible without doing this.
void Quaternion::Normalize()
{
	float magnitude = w * w + x * x + y * y + z * z;
	if (magnitude < 0.9999f)
	{
		magnitude = sqrt(magnitude);
		w /= magnitude;
		x /= magnitude;
		y /= magnitude;
		z /= magnitude;
	}
}

//Returns q1, q2, and q3 in a Vector3.
Vector3 Quaternion::Direction() const
{
	Vector3 dir_vector(x, y, z);
	return dir_vector;
}

//This scales each value in the quaternion by a scalar.
Quaternion operator*(float lhs, const Quaternion &rhs)
{
	return Quaternion{ lhs*rhs.w
		,lhs*rhs.x
		,lhs*rhs.y
		,lhs*rhs.z };
}

//Converts a 3x3 matrix to a quaternion.
//TODO: Fix so that we can have "w" at the end
Quaternion Matrix2Quat(const Matrix3 &mat)
{
	Quaternion result;
	float trace = mat.v00 + mat.v11 + mat.v22;
	unsigned nxt[3] = { 1,2,0 };
	if (trace > 0)
	{
		float s = sqrt(trace + 1);
		result.w = s / 2.0f;
		s = 0.5f / s;
		result.x = (mat.v21 - mat.v12) * s;
		result.y = (mat.v02 - mat.v20) * s;
		result.z = (mat.v10 - mat.v01) * s;
		return result;
	}
	else
	{
		unsigned i = 0;
		if (mat.v11 > mat.v00)
			i = 1;
		if (mat.v22 > mat.d2[i][i])
			i = 2;
		unsigned j = nxt[i];
		unsigned k = nxt[j];
		float s = sqrt((mat.d2[i][i] - (mat.d2[j][j] + mat.d2[k][k])) + 1);
		result.q[i] = s * 0.5f;
		if (s != 0)
			s = 0.5f / s;
		result.w = (mat.d2[j][k] - mat.d2[k][j]) * s;
		result.q[j] = (mat.d2[i][j] + mat.d2[j][i]) * s;
		result.q[k] = (mat.d2[i][k] + mat.d2[k][i]) * s;
		return result;
	}
}

//Converts a quaternion to a matrix.
Matrix3 Quat2Matrix(const Quaternion &quat)
{
	Matrix3 result;
	//Just calculate each value in the matrix.
	float qx2 = quat.x * quat.x;
	float qy2 = quat.y * quat.y;
	float qz2 = quat.z * quat.z;
	result.v00 = 1 - 2 * qy2 - 2 * qz2;
	result.v10 = 2 * quat.x * quat.y + 2 * quat.w * quat.z;
	result.v20 = 2 * quat.x * quat.z - 2 * quat.w * quat.y;
	result.v01 = 2 * quat.x * quat.y - 2 * quat.w * quat.z;
	result.v11 = 1 - 2 * qx2 - 2 * qz2;
	result.v21 = 2 * quat.y * quat.z + 2 * quat.w * quat.x;
	result.v02 = 2 * quat.x * quat.z + 2 * quat.w * quat.y;
	result.v12 = 2 * quat.y * quat.z - 2 * quat.w * quat.x;
	result.v22 = 1 - 2 * qx2 - 2 * qy2;
	return result;
}

//SLERPs two quaternions. "t" is between 0.0f and 1.0f.
//TODO: Fix so that it behaves better when sin(theta) = 0;
Quaternion SLERP(Quaternion p, Quaternion q, float t)
{
	//Skip the processing if t is out of bounds.
	if (t < 0.0f)
		return p;
	else if (t > 1.0f)
		return q;
	//Normalize both quaternions.
	p.Normalize();
	q.Normalize();
	float theta = acos(p.w * q.w
		+ p.x * q.x
		+ p.y * q.y
		+ p.z * q.z);
	//If theta is really close to zero or pi, give up.
	if (theta < 0.001f && theta > -0.001f)
		return q;
	else if (theta < PI + 0.001f && theta > PI - 0.001f)
		return q; //Give up
	float wp = sin((1 - t)*theta) / sin(theta);
	float wq = sin(t*theta) / sin(theta);

	return wp * p + wq * q;
}

} //End of namespace "Math"
} //End of namespace "GE"
