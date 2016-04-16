#ifndef GE_VECTOR_H_
#define GE_VECTOR_H_

#define DEBUG
/*
 * clear
 * shrink_to_fit
 */
namespace GE
{
	namespace Containers
	{
		int test_vectors();

		template <typename T> class Vector
		{
			public:
			//Constructors
			Vector();
			Vector(size_t size);
			Vector(const Vector<T> &v);	//copy constructor
			~Vector(); //Destructor
			
			//Accessors
			size_t Size();
			bool empty();
			
			//Operators
			T & operator[](int index);
			Vector<T> & operator=(const Vector<T> &v);
			
			//Functions
			void push_back(const T &value);
			T pop_back();
			void insert(size_t index, T element);
			void swap(Vector<T> &T1, Vector<T> &T2);
			void clear();
			void erase(size_t index);
			void shrink_to_fit();
#ifdef DEBUG
			void printIntVector();
#endif
			
			private:
				//helper functions
				void increase_cap(int capacity);
				
				//member variables
				T *m_data;		//representation
				size_t m_size;		//number of elements
				size_t m_capacity;	//size in memory (power of 2)
		};
	}
}
#include <containers/vector.hpp>
#endif /* GE_VECTOR_H_ */
