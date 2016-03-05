#ifndef GE_VECTOR_CPP_
#define GE_VECTOR_CPP_

#include <containers/vector.h>


namespace GE 
{
	namespace Containers
	{
		/*	
			effects: creates empty vector
		*/
		template<typename T> Vector<T>::Vector()
		{
			m_size = 0;
			m_capacity = 0;
			m_data = 0;
		}
		/*
			parameters:
				capacity - not negative 
			modifies:
				m_size
				m_capacity
				m_data
			effects: 
				creates vector with a capacity of "capacity"
		*/
		template<typename T> Vector<T>::Vector(int capacity)
		{
			m_size = 0;
			m_capacity = capacity;
			m_data = new T[capacity];
		}
		
		/*	
			requires: an existing vector
			parameters:
				a vector with stuff 
			modifies:
				m_size
				m_capacity
				m_data
			effects:
				copy constructor and sets new vector equal to given vector
		*/
		template<typename T> Vector<T>::Vector(const Vector<T> &v)
		{
			m_size = v.m_size;
			m_capacity = v.m_size;
			m_data = new T[m_size];
			for (int i = 0; i < m_size; i++)
			{
				m_data[i] = v.m_data[i];
			}
		}
		
		/*
			returns:
				size of vector
		*/
		template<typename T> int Vector<T>::Size()
		{
			return m_size;
		}
		
		/*	
			requires:
				a vector
			parameters:
				a vector
			modifies:
				m_size
				m_capacity
				m_data
			effects:
				sets one vector equal to the other
		*/
		template<typename T> Vector<T> &Vector<T>::operator=(const Vector<T> &v)
		{
			//only works for vectors of definitive size (can be different size) and doesn't copy the last index correctly
			m_size = v.m_size;
			m_capacity = v.m_size;
			T *new_data = new T[m_size]; //might need to figure out how to do this with malloc
			for (int i = 0; i <  m_size; i++) //ask david about why this works
				new_data[i] = v.m_data[i];
			delete[] m_data;
			m_data = new_data;
			return *this;
		}
		
		/*	
			requires: 
				a vector
			parameters:
				index 
			returns:
				value stored at index
		*/
		template<typename T> T &Vector<T>::operator[](int index)
		{
			return m_data[index];
		}
		
		/*	
			requires: 
				a value and a vector
			parameters:
				value 
			modifies:
				index at end of vector
				possibly increases capacity
			effects:
				adds a value at the end of the vector
		*/
		template<typename T> void Vector<T>::push_back(const T &value)
		{
			if (m_size >= m_capacity)
			{
				increase_cap(m_capacity + 1);
			}
			m_data[m_size++] = value;
		}
		
		/*
			requires: 
				vector
			parameters:
				capacity 
			modifies:
				m_data
				m_capacity
				m_data
				possibly:
					m_size
			effects:
				increases capacity of vector
		*/
		template<typename T> void Vector<T>::increase_cap(int capacity)
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
		
		/*
			requires:
				vector
			modifies:
				m_size
			effects:
				gets rid of last index
		*/
		template<typename T> void Vector<T>::pop_back()
		{
			m_size--; //is this efficient? 
		}
		
		template<typename T> void Vector<T>::insert()
		{
			
		}
		
		template<typename T> Vector<T>::~Vector()
		{
			delete[] m_data;
		}
		
		/* TODO:
			Pushback ✔
			Popback ✔
			Destructor ✔
			Copy ✔
			Insert
			Assignment/ Equals?? ✔
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
			use size_type vs int -> more robust code
		*/
		
	}
}



#endif /* GE_VECTOR_CPP_ */