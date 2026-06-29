#include "Fixed.hpp"
#include <iostream>
#include <cmath>

std::ostream& operator<<(std::ostream &o, const Fixed &fixed)
{
	o << fixed.toFloat();
	return o;
}

Fixed&Fixed::min(Fixed& a, Fixed& b)
{
	if (a <= b)
		return a;
	else
		return b;
}

const Fixed&Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a <= b)
		return a;
	else
		return b;
}

Fixed&Fixed::max(Fixed& a, Fixed& b)
{
	if (a >= b)
		return a;
	else
		return b;
}

const Fixed&Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a >= b)
		return a;
	else
		return b;
}

bool Fixed::operator>(const Fixed &fixed) const
{
	if (_value > fixed._value)
		return true;
	return false;
}

bool Fixed::operator<(const Fixed &fixed) const
{
	if (_value < fixed._value)
		return true;
	return false;
}

bool Fixed::operator>=(const Fixed &fixed) const
{
	if (_value >= fixed._value)
		return true;
	return false;
}

bool Fixed::operator<=(const Fixed &fixed) const
{
	if (_value <= fixed._value)
		return true;
	return false;
}

bool Fixed::operator==(const Fixed &fixed) const
{
	if (_value == fixed._value)
		return true;
	return false;
}

bool Fixed::operator!=(const Fixed &fixed) const
{
	return !(_value == fixed._value);
}

float Fixed::toFloat() const
{
	return static_cast<float>(_value) / (1 << fractionalBits);
}

int Fixed::toInt() const
{
	return (_value / (1 << fractionalBits));
}

Fixed::Fixed(float f):_value(roundf(f * (1 << fractionalBits)))
{
	//std:: cout << "Float constructor called\n";
}

Fixed::Fixed(int i):_value(i * (1 << fractionalBits))
{
	//std::cout << "Int constructor called\n";
}

Fixed::Fixed():_value(0)
{
	//std::cout << "default constructor called\n";
}

Fixed::Fixed(const Fixed &fixed)
{
	*this = fixed;
}

Fixed& Fixed::operator=(const Fixed &fixed)
{
	if (this == &fixed)
		return *this;
	this->_value = fixed.getRawBits();
	return *this;
}

Fixed Fixed::operator+(const Fixed &fixed) 
{
	return Fixed (this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed &fixed) 
{
	return Fixed (this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed &fixed) 
{
	return Fixed (this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed) 
{
	return Fixed (this->toFloat() / fixed.toFloat());
}

Fixed& Fixed::operator++()
{
	_value++;
	return *this;
}


Fixed Fixed::operator++(int)
{
	Fixed temp(_value);
	_value++;

	return temp;
}

Fixed& Fixed::operator--()
{
	_value--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(_value);
	_value--;

	return temp;
}

Fixed::~Fixed()
{
	//std::cout << "Default destructor called\n";
}

int Fixed::getRawBits() const
{
	return _value;
}

void Fixed::setBits(int value)
{
	_value = value;
}
