#include <cmath>
#include <iostream>

class Fixed
{
	private:
		int	_value;
		static const int fractionalBits = 8;
	
	public:
		Fixed();
		Fixed(const Fixed& fixed);
		Fixed(float f);
		Fixed(int i);
		~Fixed();

		Fixed &operator=(const Fixed& fixed);
		bool operator==(const Fixed& fixed) const;
		bool operator!=(const Fixed& fixed) const;
		bool operator>(const Fixed& fixed) const;
		bool operator<(const Fixed& fixed) const;
		bool operator>=(const Fixed& fixed) const;
		bool operator<=(const Fixed& fixed) const;

		Fixed operator+(const Fixed &fixed);
		Fixed operator-(const Fixed &fixed);
		Fixed operator*(const Fixed &fixed);
		Fixed operator/(const Fixed &fixed);

		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);

		int getRawBit() const ;
		void setRawBit(const int _value);
		float toFloat() const;
		int toInt() const;

		static Fixed& min(Fixed &a, Fixed &b);
		static const Fixed& min(const Fixed &a, const Fixed &b);
		static Fixed& max(Fixed &a, Fixed &b);
		static const Fixed& max(const Fixed &a, const Fixed &b);
};

class Point
{
	private:
		const Fixed x;
		const Fixed y;

	public:
		Point();
		Point(const Point& p);
		Point(const float x, const float y);
		Point& operator=(const Point& p);
		~Point();
		Fixed getX() const;
		Fixed getY() const;
};

Point::Point():x(0), y(0){}
Point::Point(const Point& p):x(p.x), y(p.y){}
Point::Point(const float x, const float y):x(x), y(y){}
Point::~Point(){}
Point& Point::operator=(const Point&p)
{
	return *this;
}

Fixed Point::getX() const
{
	return x;
}

Fixed Point::getY() const
{
	return y;
}

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


bool bsp(const Point a, const Point b, const Point c, const Point point);

Fixed parea(const Point& p1, const Point& p2, const Point& p3)
{
	Fixed parea;

	parea = p1.getX() * (p2.getY() - p3.getY()) 
		  + p2.getX() * (p3.getY() - p1.getY())
		  + p3.getX() * (p1.getY() - p2.getY());

	int pareaRawValue = std::abs(parea.getRawBit());
	parea.setRawBit(pareaRawValue);
	
	return parea;
}

bool bsp(const Point a, const Point b, const Point c, const Point point)
{
	Fixed pabc = parea(a,b,c);
	
	Fixed pabp = parea(a,b,point);
	Fixed pacp = parea(a,c,point);
	Fixed pbcp = parea(b,c,point);

	if (pabp == 0 || pacp == 0 || pbcp == 0)
	{
		std::cout << "The point is on the edge\n";
		return false;
	}
	else if (pabc == (pabp + pacp + pbcp))
	{
		std::cout << "The point is in the triangle !\n";
		return true;
	}
	else
	{
		std::cout << "The point is outside the triangle !\n";
		return false;
	}
}

int main( void )
{
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);
    Point inside(2, 2);
    Point outside(20, 20);
    Point edgeAB(5, 0);
    Point edgeAC(0, 5);
    Point edgeBC(5, 5);
    Point insideCloseEdge(5, 0.01f);
    Point outsideCloseEdge(5, -0.01f);

    std::cout << "Inside: "<< bsp(a, b, c, inside) << std::endl;
    std::cout << "Outside: " << bsp(a, b, c, outside) << std::endl;
    std::cout << "EdgeAB: " << bsp(a, b, c, edgeAB) << std::endl;
    std::cout << "EdgeAC: " << bsp(a, b, c, edgeAC) << std::endl;
    std::cout << "EdgeBC: " << bsp(a, b, c, edgeBC) << std::endl;
    std::cout << "VertexA: " << bsp(a, b, c, a) << std::endl;
    std::cout << "VertexB: " << bsp(a, b, c, b) << std::endl;
    std::cout << "VertexC: " << bsp(a, b, c, c) << std::endl;
    std::cout << "InsideCloseEdge: "<< bsp(a, b, c, insideCloseEdge) << std::endl;
    std::cout << "OutsideCloseEdge: " << bsp(a, b, c, outsideCloseEdge) << std::endl;

    return 0;
}
