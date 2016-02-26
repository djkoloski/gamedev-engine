#ifndef GE_VEC2_CPP_
#define GE_VEC2_CPP_

#include <math/vec2.h>

namespace GE
{
	namespace Math
	{
		Vec2::Vec2() :
			x(0.0f),
			y(0.0f)
		{}
		Vec2::Vec2(float xVal, float yVal) :
			x(xVal),
			y(yVal)
		{}
	}
}

#endif /* GE_VEC2_CPP_ */