#pragma once

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
