#ifndef GE_VECTOR_CPP_
#define GE_VECTOR_CPP_

#include <containers/vector.h>


namespace GE 
{
	namespace Containers
	{
		template<typename T> Vector<T>::Vector()
		{
			m_size = 0;
			m_capacity = 0;
			m_data = 0;
		}
		
		template<typename T> Vector<T>::Vector(int size)
		{
			m_size = 0;
			m_capacity = size;
			m_data = new T[size];
		}
		
		template<typename T> Vector<T>::Vector(const Vector<T> &v)
		{
			m_size = v.m_size;
			m_capacity = v.m_capacity;
			m_data = new T[m_size];
			for (int i = 0; i < m_size; i++)
			{
				m_data[i] = v.m_data[i];
			}
		}
		
		template<typename T> int Vector<T>::Size()
		{
			return m_size + 1;
		}
		
		template<typename T> Vector<T> &Vector<T>::operator=(const Vector<T> &v)
		{
			//only works for vectors of definitive size (can be different size) and doesn't copy the last index correctly
			delete[] m_data;
			m_size = v.m_size;
			m_capacity = v.m_capacity;
			m_data = new T[m_size];
			for (int i = 0; i < m_size; i++)
				m_data[i] = v.m_data[i];
			return *this;
		}
		
		template<typename T> T &Vector<T>::operator[](int index)
		{
			return m_data[index];
		}
		
		template<typename T> void Vector<T>::push_back(const T &value)
		{
			if (m_size >= m_capacity)
			{
				increase_cap(m_capacity + 1);
				std::cout << "size > cap" << std::endl;
			}
			m_data[m_size + 1] = value;
			m_size++;
		}
		
		template<typename T> void Vector<T> :: increase_cap(int capacity)
		{
			if (m_data = 0){
				m_size = 0;
				m_capacity = 0;
			}
			T *newData = new T[capacity];
			//assert (newData)
			for (int i = 0; i < m_size; i++)
				newData[i] = m_data[i];
			m_capacity = capacity;
			delete[] m_data;
			m_data = newData;
			delete[] newData;
		}
		
		template<typename T> Vector<T>::~Vector()
		{
			delete[] m_data;
		}
		
		/* TODO:
			Pushback✔
			Popback
			Destructor ✔
			Copy IN PROGRESS
			Insert
			Assignment/ Equals??
			Concatenation/Addall
			Pushfront/Popfront
			Indexing ✔
			Iterators?? (pointers based) (typedef of pointers)
			size/max_size ✔
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