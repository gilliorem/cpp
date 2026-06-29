#pragma once
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
