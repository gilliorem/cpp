#include "Fixed.hpp"
#include <iostream>
Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a <= b)
		return a;
	else
		return b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a <= b)
		return a;
	else
		return b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a >= b)
		return a;
	else
		return b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a >= b)
		return a;
	else
		return b;
}


Fixed& Fixed::operator++()
{
	_value++;	
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
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
	Fixed temp;
	*this = temp;
	_value--;
	return temp;
}

Fixed Fixed::operator-(const Fixed &fixed)
{
	return Fixed(this->toFloat() - fixed.toFloat());
}
Fixed Fixed::operator*(const Fixed &fixed)
{
	return Fixed(this->toFloat() * fixed.toFloat());
}
Fixed Fixed::operator/(const Fixed &fixed)
{
	return Fixed(this->toFloat() / fixed.toFloat());
}


Fixed::Fixed():_value(0){}
Fixed::Fixed(const Fixed& fixed){*this = fixed;}
Fixed::Fixed(float f):_value(roundf(f * (1 << fractionalBits))){}
Fixed::Fixed(int i):_value(i * (1 << fractionalBits)){}
Fixed::~Fixed(){}

Fixed Fixed::operator+(const Fixed &fixed)
{
	return Fixed(this->toFloat() + fixed.toFloat());
}
bool Fixed::operator==(const Fixed& fixed) const
{
	return (fixed._value == _value);
}

bool Fixed::operator!=(const Fixed& fixed) const
{
	return (fixed._value != _value);
}

bool Fixed::operator>(const Fixed& fixed) const
{
	return (_value > fixed._value);
}

bool Fixed::operator<(const Fixed& fixed) const
{
	return (_value < fixed._value);
}

bool Fixed::operator>=(const Fixed& fixed) const
{
	return (_value >= fixed._value);
}

bool Fixed::operator<=(const Fixed& fixed) const
{
	return (_value <= fixed._value);
}

std::ostream& operator<<(std::ostream &o, const Fixed &fixed)
{
	o << fixed.toFloat();
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

int Fixed::getRawBit() const
{
	return _value;
}

void Fixed::setRawBit(const int value)
{
	_value = value;
}


Fixed &Fixed::operator=(const Fixed& fixed)
{

	if (fixed._value == _value)
		return *this;
	else
		_value = fixed._value;
	return *this;
}
