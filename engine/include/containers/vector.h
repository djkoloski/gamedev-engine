#ifndef GE_VECTOR_H_
#define GE_VECTOR_H_

namespace GE
{
	namespace Containers
	{
		template <typename T> class Vector
		{
			private:
				T *data;		//representation
				int size;		//number of elements
				int capacity;	//size in memory (power of 2)
			
			public:
			
			
			//Constructor
			Vector();
			
			//Accessors
			int Size();
			
		};
	}
}
#include <containers/vector.hpp>
#endif /* GE_VECTOR_H_ */