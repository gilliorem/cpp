#include "Span.hpp"
#include <exception>
#include <stdexcept>

Span::Span(): _capacity(2), _size(0), _data(NULL), _N(_capacity){}

Span::Span(unsigned long n):_capacity(n), _size(1), _data(new int[_capacity]), _N(n){
	if ((unsigned long)_capacity >= HEAP_LIMIT)
	       throw std::bad_alloc();
}

Span& Span::operator=(const Span& other)
{
	this->_data = other._data;
	this->_capacity = other._capacity;
	this->_size = other._size;
	this->_N = other._N;

	return *this;
}

Span::~Span()
{
	delete []_data;
}

Span::It::It(){}
Span::It::It(int* x): _p(x) {}
Span::It::It(const It& it): _p(it._p) {}

Span::It& Span::It::operator++()
{
	++_p;
	return *this;
}

Span::It Span::It::operator++(int)
{
	It tmp(*this);
	operator++();
	return tmp;
}

bool Span::It::operator==(const It& other) const
{
	return _p == other._p; 
}

bool Span::It::operator!=(const It& other) const
{
	return _p != other._p;
}

int& Span::It::operator*() 
{
	return *_p;
}

void Span::addNumbers(int *list, int start, int end)
{
	for (int i = start; i <= end; i++)
	{
		addNumber(list[i]);
	}
}

Span::It Span::begin(void)
{
	It it(this->_data);
	return it;
}

Span::It Span::end(void)
{
	It it(this->_data + (this->_size));
	return it;
}

void Span::addNumber(int n)
{
	if (this->_size >= this->_capacity)
	{
		if ((this->_capacity) >= HEAP_LIMIT)
			throw std::bad_alloc();
		this->_capacity *= 2;
		int* tmp = new int[this->_capacity];
		for (unsigned int i = 0; i < this->_size; i++)
		{
			tmp[i] = this->_data[i];
		}
		delete []_data;
		this->_data = tmp;
	}
	this->_data[this->_size] = n;
	this->_size++;
}

int Span::shortestSpan()
{
	{
		if (this->_size <= 1)
			throw std::logic_error("Missing at least one element in the Span.");
		unsigned int j = 0;
		while (j < this->_size)
		{
			for (unsigned int i = 0; i < (this->_size - 1); i++)
			{
				if (this->_data[i + 1] < this->_data[i])
				{
					int tmp = this->_data[i];
					this->_data[i] = this->_data[i+1];
					this->_data[i + 1] = tmp;
				}
			}
			j++;
		}

		int shortestSpan = this->_data[this->_size - 1];
		for (unsigned int i = 0; i < this->_size - 1; i++)
		{
			if (this->_data[i + 1] - this->_data[i] < shortestSpan)
				shortestSpan = this->_data[i + 1] - this->_data[i];
		}
		return shortestSpan;
	}
}

int Span::longestSpan()
{
	if (this->_size <= 1)
		throw std::logic_error("Missing at least one element in the Span.");
	int smallestN = _data[0];
	int biggestN = _data[0];

	for (unsigned int i = 0; i < this->_size; i++)
	{
		if (_data[i] < smallestN)
		{
			smallestN = this->_data[i];
		}
	}
	for (unsigned int i = 0; i < this->_size;  i++)
	{
		if (_data[i] > biggestN)
		{
			biggestN = this->_data[i];
		}
	}
	return biggestN - smallestN;
}

