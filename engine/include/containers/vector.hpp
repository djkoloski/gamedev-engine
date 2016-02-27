#ifndef GE_VECTOR_CPP_
#define GE_VECTOR_CPP_

#include <containers/vector.h>


namespace GE 
{
	namespace Containers
	{
		template<typename T> Vector<T>::Vector()
		{
			size = 0;
			capacity = 0;
			data = 0;
		}
		
		template<typename T> int Vector<T>::Size()
		{
			return size;
		}
		
		/* TODO:
			Pushback
			Popback
			Destructor
			Copy
			Insert
			Assignment/ Equals??
			Concatenation/Addall
			Pushfront/Popfront
			Indexing
			Iterators?? (pointers based) (typedef of pointers)
			size/max_size
			shrink-to-fit
			erase
			empty
			clear
			swap
			emplace
		*/
		
	}
}



#endif /* GE_VECTOR_CPP_ */