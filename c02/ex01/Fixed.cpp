#include "Fixed.hpp"
#include <cmath>

const int	Fixed::fractional_bits = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	fixed_point = 0;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	fixed_point = other.getRawBits();
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	fixed_point = other.getRawBits();
	return *this;
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (fixed_point);
}

void	Fixed::setRawBits( int const raw )
{
	fixed_point = raw;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	fixed_point = 0;
}


Fixed::Fixed(const int& n)
{
	std::cout << "Int constructor called" << std::endl;
	fixed_point = n * (1 << fractional_bits);
}
Fixed::Fixed(const float& n)
{
	std::cout << "Float constructor called" << std::endl;
	fixed_point = roundf(n * (1 << fractional_bits));
}

int Fixed::toInt( void ) const{
	return fixed_point / 256;
}

float Fixed::toFloat( void ) const
{
	return fixed_point / 256.0f;
}

std::ostream &operator<<(std::ostream &stream,const Fixed& n)
{
	stream << n.toFloat();
	return (stream);
}