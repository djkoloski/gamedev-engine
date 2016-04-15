#include <math/Vector.hpp>

using namespace GE::Math;

Vector2 GE::Math::operator*(const float &a, const Vector2& b)
{
	return Vector2(a*b.x, a*b.y);
}

std::ostream& operator<<(std::ostream& os, const Vector2& out)
{
	os << "(" << out.x << "," << out.y << ")";
	return os;
}

Vector3 GE::Math::operator*(const float &a, const Vector3& b)
{
	return Vector3(a*b.x, a*b.y, a*b.z);
}

std::ostream& operator<<(std::ostream& os, const Vector3& out)
{
	os << "(" << out.x << "," << out.y << "," << out.z << ")";
	return os;
}

Vector4 GE::Math::operator*(const float &a, const Vector4& b)
{
	return Vector4(a*b.x, a*b.y, a*b.z, a*b.w);
}

std::ostream& operator<<(std::ostream& os, const Vector4& out)
{
	os << "(" << out.x << "," << out.y << "," << out.z << "," << out.w << ")";
	return os;
}
