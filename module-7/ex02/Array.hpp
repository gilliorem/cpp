#pragma once
#include <iostream>

template <typename T>
class Array
{
	private:
		T* _element;
		unsigned int _size;
	
	public:
		Array();
		Array(unsigned int n); // creates an array of n elements init by default () calloc style
		Array(const Array& other);
		Array& operator=(const Array& other);
		~Array();
		const T& operator[](unsigned int index) const;
		T& operator[](unsigned int index);
		unsigned int size() const;
		T* element();
		class ArrayException : public std::exception
		{
			private:
				const std::string _msg;
			public:
				ArrayException(const std::string& msg) : _msg(msg) {}
				virtual const char* what() const throw()
				{
					return _msg.c_str();
				}
				~ArrayException() throw() {}
		};
};

template <typename T>
Array<T>::Array(const Array& other):_size(other.size())
{
	this->_element = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; i++)
	{
		this->_element[i] = other._element[i];
	}
}


template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= this->_size)
		throw ArrayException("Index out of bounds");
	return _element[index];
}

template <typename T>
T& Array<T>::operator[](unsigned int index) 
{
	if (index >= this->_size)
		throw ArrayException("Index out of bounds");
	return _element[index];
}

template <typename T>
T* Array<T>::element()
{
	return this->_element;
}

template <typename T>
unsigned int Array<T>::size() const
{
	return this->_size;
}


template <typename T>
Array<T>::Array(): _element(NULL), _size(0)
{}

template <typename T>
Array<T>::Array(unsigned int n)
{
	this->_size = n;
	this->_element = new T[this->_size]();
}

template <typename T>
Array<T>::~Array()
{
	delete []this->_element;
}
