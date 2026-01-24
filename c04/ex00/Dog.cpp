#include "Dog.hpp"

Dog::Dog() {
	printer("Dog Default Constructor");
	type = "Dog";
}

Dog::Dog(const Dog& obj) : Animal(obj) {
	printer("Dog Copy Constructor");
}

Dog&	Dog::operator=(const Dog& right) {
	if (this == &right)
		return (*this);
	Animal::operator=(right);
	return (*this);
}

void	Dog::makeSound( void ) const {
	printer("Bark");
}

Dog::~Dog() {
	printer("Dog Destructor");
}
