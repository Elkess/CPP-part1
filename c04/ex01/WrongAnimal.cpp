#include "WrongAnimal.hpp"

void	WrongAnimal::makeSound( void ) const {
	std::cout << "cats don't bark" << std::endl;
}

std::string	WrongAnimal::getType( void ) const {
	return (type);
}

WrongAnimal::WrongAnimal() {
	std::cout << "WrongAnimal Default Constructor" << std::endl;
	type = "Unknown type";
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj) {
	std::cout << "WrongAnimal Copy Constructor" << std::endl;
	*this = obj;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& right) {
	if (this == &right)
		return (*this);
	this->type = right.type;
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal Destructor" << std::endl;
}