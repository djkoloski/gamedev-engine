#ifndef GE_FIXED_VECTOR_H_
#define GE_FIXED_VECTOR_H_

namespace GE
{
	namespace Containers
	{
		template<typename T, unsigned int SIZE>
		class FixedVector
		{
			private:
				T m_data[SIZE];
				unsigned int m_occupancy;
			public:
				FixedVector();
				T& operator[](unsigned int index);

				/// Accessors
				unsigned int get_size() { return m_occupancy; }
				unsigned int get_capacity() { return SIZE; }
		};
	}
}

#include <containers/fixedVector.hpp>

#endif