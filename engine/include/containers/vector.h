#ifndef GE_VECTOR_H_
#define GE_VECTOR_H_

namespace GE
{
	namespace Containers
	{
		template <typename T> class Vector
		{
			public:
			//Constructors
			Vector();
			Vector(int size);
			Vector(const Vector<T> &v); //copy constructor
			~Vector(); //Destructor
			
			//Accessors
			int Size();
			
			//Operators
			T & operator[](int index);
			Vector<T> & operator=(const Vector<T> &v);
			
			//Functions
			void push_back(const T &value);
			void pop_back();
			void insert();
			
			
			private:
				//helper functions
				void increase_cap(int capacity);
				
				//member variables
				T *m_data;		//representation
				int m_size;		//number of elements
				int m_capacity;	//size in memory (power of 2)
		};
	}
}
#include <containers/vector.hpp>
#endif /* GE_VECTOR_H_ */