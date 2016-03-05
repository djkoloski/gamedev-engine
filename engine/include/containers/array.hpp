#ifndef GE_ARRAY_HPP_
#define GE_ARRAY_HPP_

#include <containers/array.h>

namespace GE 
{
	namespace Containers
	{
		template<typename T> Array<T>::Array()
		{
			m_memory = (T *) calloc(GE_ARRAY_FIXED_SIZE, sizeof(T));
			if (!m_memory)
			{
				/// TODO (DUNETZ) : Add an assert or error handling to ensure that
				/// The memory was actually aquired.
				return;
			}
			return;
		};

		template<typename T> T& Array<T>::operator[] (unsigned int m_index)
		{
			if (m_index < GE_ARRAY_FIXED_SIZE)
			{
				return m_memory[m_index];
			}
		}
	}
}

#endif /* GE_ARRAY_HPP_ */