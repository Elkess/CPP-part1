#include "Fixed.hpp"

const int	Fixed::fractional_bits = 8;

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
	fixed_point = n * (1 << fractional_bits);
}
Fixed::Fixed(const float& n)
{
	fixed_point = roundf(n * (1 << fractional_bits));
}

int Fixed::toInt( void ) const{
	return fixed_point / (1 << fractional_bits);
}

float Fixed::toFloat( void ) const
{
	return fixed_point / (1.0f * (1 << fractional_bits));
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

bool Fixed::operator<(const Fixed& n) const
{
	return (this->fixed_point < n.getRawBits());
}

bool Fixed::operator>(const Fixed& n) const
{
	return (this->fixed_point > n.getRawBits());
}

bool Fixed::operator<=(const Fixed& n) const
{
	return (this->fixed_point <= n.getRawBits());
}

bool Fixed::operator>=(const Fixed& n) const
{
	return (this->fixed_point >= n.getRawBits());
}

bool Fixed::operator==(const Fixed& n) const
{
	return (this->fixed_point == n.getRawBits());
}

bool Fixed::operator!=(const Fixed& n) const
{
	return (this->fixed_point != n.getRawBits());
}

Fixed Fixed::operator+(const Fixed& n) const
{
	Fixed new_obj;
	new_obj.setRawBits(this->fixed_point + n.fixed_point);
	return new_obj;
}

Fixed Fixed::operator-(const Fixed& n) const
{
	Fixed new_obj;
	new_obj.setRawBits(this->fixed_point - n.fixed_point);
	return new_obj;
}

Fixed Fixed::operator*(const Fixed& n) const
{
	Fixed new_obj;
	long long prod = (long long)this->fixed_point * (long long)n.fixed_point;
	new_obj.setRawBits((int)(prod >> fractional_bits));
	return new_obj;
}

Fixed Fixed::operator/(const Fixed& n) const
{
	Fixed new_obj;
	long long num = ((long long)this->fixed_point << fractional_bits);
	new_obj.setRawBits((int)(num / n.fixed_point));
	return new_obj;
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
