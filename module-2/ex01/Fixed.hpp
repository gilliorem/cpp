#pragma once
#include <iostream>

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


std::ostream& operator<<(std::ostream& o, const Fixed &i);
