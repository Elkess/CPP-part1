#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <ostream>
#include <cmath>

class Fixed {
	private:
		int					fixed_point;
		static const int	fractional_bits;
	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed(const int& n);
		Fixed(const float& n);
		Fixed& operator=(const Fixed& other);
		int	getRawBits( void ) const;
		void setRawBits( int const raw );
		int toInt( void ) const;
		float toFloat( void ) const;
		bool operator<(const Fixed& n) const;
		bool operator>(const Fixed& n) const;
		bool operator<=(const Fixed& n) const;
		bool operator>=(const Fixed& n) const;
		bool operator==(const Fixed& n) const;
		bool operator!=(const Fixed& n) const;
		Fixed operator+(const Fixed& n) const;
		Fixed operator-(const Fixed& n) const;
		Fixed operator*(const Fixed& n) const;
		Fixed operator/(const Fixed& n) const;
		Fixed &operator++();
		Fixed &operator--();
		Fixed operator++(int);
		Fixed operator--(int);
		static Fixed &max(Fixed& a, Fixed& b);
		static Fixed &min(Fixed& a, Fixed& b);
		static const Fixed &max(const Fixed& a, const Fixed& b);
		static const Fixed &min(const Fixed& a, const Fixed& b);
		~Fixed();
};

std::ostream &operator<<(std::ostream &stream, const Fixed& n);

#endif