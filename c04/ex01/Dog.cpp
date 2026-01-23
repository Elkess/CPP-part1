#include "Dog.hpp"

Dog::Dog() {
	printer("Dog Default Constructor");
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog& obj) : Animal(obj) {
	printer("Dog Copy Constructor");
	*this = obj;
}

Dog&	Dog::operator=(const Dog& right) {
	Animal::operator=(right);
	return (*this);
}

void	Dog::makeSound( void ) const {
	printer("Bark");
}

Dog::~Dog() {
	printer("Dog Destructor");
	delete brain;
}
