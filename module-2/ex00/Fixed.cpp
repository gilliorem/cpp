#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed():_fixedPoint(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called\n";
	*this = fixed;
}

Fixed& Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called\n";
	this->_fixedPoint = fixed.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n" ;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called\n";
	return _fixedPoint;
}

void Fixed::setRawBits(int const raw)
{
	_fixedPoint = raw;
}
