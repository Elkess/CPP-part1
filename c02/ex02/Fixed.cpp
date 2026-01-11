#include "Fixed.hpp"

const int	Fixed::fractional_bits = 256;

Fixed::Fixed()
{
	fixed_point = 0;
}

Fixed::Fixed(const Fixed& other)
{
	fixed_point = other.getRawBits();
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	fixed_point = other.getRawBits();
	return *this;
}

int	Fixed::getRawBits( void ) const
{
	return (fixed_point);
}

void	Fixed::setRawBits( int const raw )
{
	fixed_point = raw;
}

Fixed::~Fixed()
{
	fixed_point = 0;
}

Fixed::Fixed(const int& n)
{
	fixed_point = n * fractional_bits;
}
Fixed::Fixed(const float& n)
{
	fixed_point = roundf(n * fractional_bits);
}

int Fixed::toInt( void ) const{
	return fixed_point / fractional_bits;
}

float Fixed::toFloat( void ) const
{
	return fixed_point / (fractional_bits * 1.0f);
}

std::ostream &operator<<(std::ostream &stream,const Fixed& n)
{
	stream << n.toFloat();
	return (stream);
}

Fixed& Fixed::operator++()
{
	++fixed_point;
	return *this;
}

Fixed& Fixed::operator--()
{
	--fixed_point;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed old = *this;				
	++fixed_point;
	return old;
}

Fixed Fixed::operator--(int)
{
	Fixed old = *this;
	--fixed_point;
	return old;
}

bool Fixed::operator<(const Fixed& n)
{
	return (this->fixed_point < n.getRawBits());
}

bool Fixed::operator>(const Fixed& n)
{
	return (this->fixed_point > n.getRawBits());
}

bool Fixed::operator<=(const Fixed& n)
{
	return (this->fixed_point <= n.getRawBits());
}

bool Fixed::operator>=(const Fixed& n)
{
	return (this->fixed_point >= n.getRawBits());
}

Fixed Fixed::operator+(const Fixed& n)
{
	Fixed	new_obj;
	new_obj.setRawBits((this->fixed_point + n.fixed_point)/fractional_bits);
	return (new_obj);
}

Fixed Fixed::operator-(const Fixed& n)
{
	Fixed	new_obj;
	new_obj.setRawBits((this->fixed_point - n.fixed_point)/fractional_bits);
	return (new_obj);
}

Fixed Fixed::operator*(const Fixed& n)
{
	Fixed	new_obj;
	new_obj.setRawBits((this->fixed_point * n.fixed_point)/fractional_bits);
	return (new_obj);
}

Fixed Fixed::operator/(const Fixed& n)
{
	Fixed	new_obj;
	new_obj.setRawBits((this->fixed_point / n.fixed_point)/fractional_bits);
	return (new_obj);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a.fixed_point > b.fixed_point)
		return (a);
	return (b);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a.fixed_point < b.fixed_point)
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.fixed_point > b.fixed_point)
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.fixed_point < b.fixed_point)
		return (a);
	return (b);
}
