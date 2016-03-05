#ifndef GE_FIXED_VECTOR_HPP_
#define GE_FIXED_VECTOR_HPP_

namespace GE
{
	namespace Containers
	{
		template<typename T, unsigned int SIZE>
		FixedVector<T,SIZE>::FixedVector()
		{
			m_occupancy = 0;
		}

		template<typename T, unsigned int SIZE>
		T& FixedVector<T, SIZE>::operator[](unsigned int index)
		{
			if (index < m_occupancy)
			{
				return m_data[index];
			}
			else
			{
				/// TODO (DUNETZ): HANDLE OUT OF BOUNDS ERROR.
				return 0;
			}
		}
	}
}
#endif