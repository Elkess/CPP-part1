#include "Animal.hpp"

void	printer(std::string msg)
{
	std::cout << msg << std::endl;
}

void	Animal::makeSound( void ) {
	printer("cats don’t bark");
}

Animal::Animal() {
	type = "Animal type";
}

Animal::Animal(const Animal& obj) {
	*this = obj;
}

Animal&	Animal::operator=(const Animal& right) {
	this->type = right.type;
	return (*this);
}

Animal::~Animal() {

}