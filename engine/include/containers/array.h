#ifndef GE_ARRAY_H_
#define GE_ARRAY_H_

#define GE_ARRAY_FIXED_SIZE 128

namespace GE 
{
	namespace Containers
	{
		template<typename T>
		class Array
		{
			private: 
				T *m_memory;
			public:
				Array();
				T& operator[](unsigned int m_index);
		};
	}
}

#include <containers/array.hpp>

#endif /* GE_ARRAY_H_ */