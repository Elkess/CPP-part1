#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <ostream>

class Fixed {
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
		~Fixed();
};

std::ostream &operator<<(std::ostream &stream, const Fixed& n);

#endif