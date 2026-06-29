#include "Fixed.hpp"
#include <iostream>
#include <cmath>

std::ostream& operator<<(std::ostream& o, const Fixed &i)
{
	o << i.toFloat();
	return o;
}

float Fixed::toFloat() const
{
	return static_cast<float>(_value) / (1 << fractionalBits);
}

int Fixed::toInt() const
{
	return _value / (1 << fractionalBits);
}


Fixed::Fixed(const int i):_value(i * (1 << fractionalBits))
{
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float f):_value(roundf(f * (1 << fractionalBits)))
{
	std::cout << "Float constructor called\n";
}

Fixed::Fixed():_value(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called\n";
	*this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	if (&fixed == this)
		return *this;
	std::cout << "Copy assignment operator called\n";
 	this->_value = fixed.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits() const
{
	//std::cout << "getRawBits member function called\n";
	return _value;
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}
