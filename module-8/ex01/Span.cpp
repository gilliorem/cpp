#include "Span.hpp"
#include <stdexcept>

Span::Span(): N(1), _size(0), _data(NULL){}

Span::Span(unsigned int n):N(n), _size(0), _data(new int[N]){ }

const char* ContainerSizeException::what() const throw()
{
	return "Oversize";
}


Span& Span::operator=(const Span& other)
{
	this->N = other.N;
	this->_size = other._size;
	this->_data = other._data;

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
void Span::addNumber(int n)
{
	if (this->_size >= N)
		throw ContainerSizeException(); 
	this->_data[this->_size] = n;
	this->_size++;
}

void Span::addNumbers(Span::It begin, Span::It end)
{
	while (begin != end)
	{
		addNumber(*begin);
		begin++;
	}
}

Span::It Span::begin(void)
{
	It it(this->_data);
	return it;
}

Span::It Span::end(void)
{
	It it(this->_data + (this->N));
	return it;
}

unsigned int Span::shortestSpan()
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

unsigned int Span::longestSpan()
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

