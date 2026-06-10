#include <iostream>
#include <cmath>

class Fixed 
{
	private:
		int _value;
		static const int fractionalBits = 8;

	public:
		Fixed();
		Fixed(const Fixed &fixed );
		Fixed& operator=(const Fixed &fixed);
		~Fixed();

		Fixed(float f);
		Fixed(int i);

		int getRawBits() const;
		void setBits(int value);

		float toFloat() const;
		int toInt() const;

		bool operator>(const Fixed &fixed) const;
		bool operator<(const Fixed &fixed) const;
		bool operator>=(const Fixed &fixed) const;
		bool operator<=(const Fixed &fixed) const;

		bool operator==(const Fixed &fixed) const;
		bool operator!=(const Fixed &fixed) const;

		Fixed operator+(const Fixed &fixed) ;
		Fixed operator-(const Fixed &fixed) ;
		Fixed operator*(const Fixed &fixed) ;
		Fixed operator/(const Fixed &fixed) ;

		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);

		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);

		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream &o, const Fixed &fixed)
{
	o << fixed.toFloat();
	return o;
}
/* A static member function min that takes two references to fixed-point numbers as
parameters, and returns a reference to the smallest one */
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

int main()
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	//Fixed const b( Fixed( 2.05f ));// * Fixed( 2 ) );
	std::cout << b<< std::endl;
	//std::cout << a.getRawBits() << std::endl;

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << "b:" << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}
