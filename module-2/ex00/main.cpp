/*Create a class in Orthodox Canonical Form that represents a fixed-point number:
• Private members:
◦ An integer to store the fixed-point number value.
◦ A static constant integer to store the number of fractional bits. Its value
will always be the integer literal 8.
• Public members:
◦ A default constructor that initializes the fixed-point number value to 0.
◦ A copy constructor.
◦ A copy assignment operator overload.
◦ A destructor.
◦ A member function int getRawBits( void ) const;
that returns the raw value of the fixed-point value.
◦ A member function void setRawBits( int const raw );
that sets the raw value of the fixed-point number.*/

#include <iostream>

class Fixed
{
	private:
		int _fixedPoint;
		static const int fractionalBits = 8;

	public:
		Fixed();
		Fixed(const Fixed &fixed);
		Fixed& operator=(const Fixed &fixed);
		~Fixed();
		int getRawBits() const ;
		void setRawBits(int const raw);
};


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

int main()
{
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
}
