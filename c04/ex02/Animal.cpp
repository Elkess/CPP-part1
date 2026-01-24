#include "Animal.hpp"

void	printer(std::string msg)
{
	std::cout << msg << "\n";
}

std::string	Animal::getType( void ) const {
	return (type);
}

Animal::Animal() {
	printer("Animal Default Constructor");
	type = "Unknown type";
}

Animal::Animal(const Animal& obj) {
	printer("Animal Copy Constructor");
	*this = obj;
}

Animal&	Animal::operator=(const Animal& right) {
	if (this == &right)
		return (*this);
	this->type = right.type;
	return (*this);
}

Animal::~Animal() {
	printer("Animal Destructor");
}