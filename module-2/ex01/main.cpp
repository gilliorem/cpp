#include <iostream>
#include <cmath>

class Fixed
{

	private:
		int _value;
		const int static fractionalBits = 8;

	public:
		Fixed();
		Fixed(const Fixed &fixed);
		Fixed &operator=(const Fixed &fixed);

		Fixed(const int i);
		Fixed(const float f);

		float toFloat() const;
		int toInt() const;

		~Fixed();
		int getRawBits() const;
		void setRawBits(int const raw);

};

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



int main()
{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}
