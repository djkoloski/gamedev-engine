#ifndef GE_VECTOR_HPP_
#define GE_VECTOR_HPP_

#include <containers/vector.h>
#define GE_VECTOR_INITIAL_CAPACITY 1
#define VERBOSE
#define DEBUG

//#ifndef IOSTREAM
//#define IOSTREAM
#include <iostream>
//#endif

// TODO (dunetz) : get rid of cmath when we implement our own math lib.

//#ifndef CMATH
//#define CMATH
#include <cmath>
#include <math.h>
//#endif 

namespace GE 
{
	namespace Containers
	{
		//TEST CASES:
		int test_vectors()
		{
#ifdef VERBOSE
			//PUSHBACK TESTS
			std::cout << "Test Vector\n";
			Vector<int> v = Vector<int>();
			std::cout << "Pushback Vector v with:" << std::endl;
			/* concatenate test */
			for (size_t intIndex = 0; intIndex < 20; intIndex++)
			{
				v.push_back(intIndex);
				std::cout << "\tMember "<<intIndex<<": " << v[intIndex] 
					<< "\n";
			}
			Vector<int> v1 = Vector<int>();
			std::cout << "Pushback Vector v1 with:" << std::endl;
			for (size_t intIndex = 0; intIndex < 20; intIndex++)
			{
				v1.push_back(intIndex+20);
				std::cout << "\tMember "<<intIndex<<": " << v1[intIndex] 
					<< "\n";
			}
			std::cout << "Concatenate v1 onto v" << std::endl;
			v.concatenate(v1);
			for (size_t intIndex = 0; intIndex < v.Size(); intIndex++)
			{
				std::cout << "\tMember "<<intIndex<<": " << v[intIndex] 
					<< "\n";
			}
			std::cout << "\n";
			
			//SHRINK TO FIT TESTS
			std::cout << "Shrink v to fit\n";
			v.shrink_to_fit();
			
			for (size_t intIndex = 0; intIndex < v.Size(); intIndex++)
			{
				std::cout << v[intIndex] << " ";
			}
			std::cout << "\n";
			//CLEAR TESTS
			v.clear();
			std::cout << "Clear vector v\n";

			for (size_t intIndex = 0; intIndex < v.Size(); intIndex++)
			{
				std::cout << v[intIndex] << " ";
			}
			std::cout << "\n";
			
			std::cout << "printIntVector Test: \n";
			v.printIntVector();
			v.push_back(5);
			v.push_back(10);
			v.push_back(15);
			v.printIntVector();
			
			Vector<int> v2 = Vector<int>();
			for (int i = 0; i < 20; i++) {
				v2.push_back(i*23%17);
			}
			v2.printIntVector();
			v2.erase(0);
			v2.printIntVector();
			v2.erase(0);
			v2.printIntVector();
			v2.erase(17);
			v2.printIntVector();
			v2.erase(5);
			v2.printIntVector();
			
			int c[] = {1,2,3,4,5};
			Vector<int> v3 = Vector<int>(c,5);
			std::cout << v3.Size() << std::endl;
			std::cout << v3.Capacity() << std::endl;
			v3.printIntVector();
			
			int d[] = {};
			Vector<int> v4 = Vector<int>(d,0);
			std::cout << v4.Size() << " " << v4.Capacity() << " " << std::endl;
			v4.printIntVector();
#endif
			return 0;
		}
		/*	
			effects: creates empty vector
		*/
		template<typename T> Vector<T>::Vector()
		{
			m_size = 0;
			m_capacity = GE_VECTOR_INITIAL_CAPACITY;
			m_data = new T[GE_VECTOR_INITIAL_CAPACITY];
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
		template<typename T> Vector<T>::Vector(size_t capacity)
		{
			m_size = 0;
			m_capacity = capacity;
			m_data = new T[capacity];
		}
		
		//requires size = a.size
		template<typename T> Vector<T>::Vector(T a[], size_t size)
		{
			m_size = size;
			m_capacity = std::pow(2,std::ceil(log2( size )));
			m_data = new T[m_capacity];
			for (int i = 0; i < size; i++)
			{
				m_data[i] = a[i];
			}
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
			for (size_t i = 0; i < m_size; i++)
			{
				m_data[i] = v.m_data[i];
			}
		}
		
		/*
			returns:
				size of vector
		*/
		template<typename T> size_t Vector<T>::Size()
		{
			return m_size;
		}
		
		template<typename T> size_t Vector<T>::Capacity()
		{
			return m_capacity;
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
			for (size_t i = 0; i <  m_size; i++) //ask david about why this works
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
		template<typename T> void Vector<T>::increase_cap(int desiredCapacity)
		{
			/// Calculate the new capacity
			double capItr = log2( desiredCapacity );
			int newCapacity = std::pow(2,std::ceil(capItr));
#ifdef VERBOSE
			std::cout << "Increase vector capacity from " << m_capacity << " to " << newCapacity
				<< " with desired new cap of " << desiredCapacity << "\n";
#endif
			m_capacity = newCapacity;

			/// Copy the data to a new buffer
			{
				T *newData = new T[m_capacity];
				//assert (newData)
				for (size_t i = 0; i < m_size; i++)
					newData[i] = m_data[i];
				delete[] m_data;
				m_data = newData;
			}
		}
		
		/*
			requires:
				vector
			modifies:
				m_size
			effects:
				gets rid of last index
		*/
		template<typename T> T Vector<T>::pop_back()
		{
			/// Unsafe: does not perform bounds checking.
			
			// TODO: We may want to do an automatic shrink to fit here,
			//   or something similar.
			return m_data[--m_size];
		}
		
		template<typename T> void Vector<T>::insert(size_t index, T element)
		{
			if (m_size >= m_capacity)
			{
				increase_cap(m_capacity + 1);
			}

			m_size++;

			T newElement = element;
			for (size_t dataIndex = index; dataIndex < m_size; dataIndex++)
			{
				T tmp = m_data[dataIndex];
				m_data[dataIndex] = newElement;
				newElement = tmp;
			}

		}
		
		
		//Requires index in bound (0 <= index < m_size)
		//Must manually decrease capacity, capacity checks are possibly expensive
		template<typename T> void Vector<T>::erase(size_t index)
		{
			for (int i = index; i < m_size-1; i++)
			{
				m_data[i] = m_data[i+1];
			}
			m_size--;
			
		}
		
		template<typename T> bool Vector<T>::empty()
		{
			return (m_size == 0);
		}
		
		template<typename T> void Vector<T>::swap(Vector<T> &t1, Vector<T> &t2){
			Vector<T> tmp = t1;
			t1 = t2;
			t2 = tmp;
		}
		
		template<typename T> Vector<T>::~Vector()
		{
			delete[] m_data;
		}

		template<typename T> void Vector<T>::clear()
		{
			// TODO: We may not actually want to deallocate this memory
			//  when we clear the vector.
			delete[] m_data;
			m_size = 0;
			m_capacity = GE_VECTOR_INITIAL_CAPACITY;
			m_data = new T[GE_VECTOR_INITIAL_CAPACITY];
		}

		template<typename T> void Vector<T>::shrink_to_fit()
		{
			T *tempData = new T[m_size];
			for (size_t mIndex = 0; mIndex < m_size; mIndex++)
			{
				tempData[mIndex] = m_data[mIndex];
			}
			delete[] m_data;
			m_data = tempData;
			size_t cap = m_capacity;
			m_capacity = m_size;
		}

		template<typename T> void Vector<T>::concatenate(Vector<T> &v)
		{
			int destIndex = m_size;
			int newSize = m_size + v.Size();
			increase_cap(newSize);
			int otherSize = v.Size();
			for (int copyIndex = 0; copyIndex < otherSize; copyIndex++)
			{
				m_data[destIndex + copyIndex] = v[copyIndex];
			}
			m_size = newSize;
		}
		
#ifdef DEBUG
		//Debugging help
		//Assumes printable
		template<typename T> void Vector<T>::printIntVector() {
			for (std::size_t i = 0; i < Size(); i++) {
				std::cout << m_data[i] << " ";
			}
			std::cout << "got here" << std::endl;
			std::cout << "\n";
			std::cout << "got here" << std::endl;
		}
#endif

		/* TODO:
			Pushback ✔
			Popback ✔
			Destructor ✔
			Copy ✔
			Insert ✔
			Assignment/ Equals?? ✔
			Concatenation/Addall ✔
			Indexing ✔
			Iterators?? (pointers based) (typedef of pointers) 
			size/max_size ✔
			shrink-to-fit ✔
			erase ✔
			empty ✔
			clear ✔
			swap ✔
			emplace
			use size_type vs int -> more robust code ✔
		*/
		
		
	}
}

#endif /* GE_VECTOR_HPP_ */
