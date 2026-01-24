#include "Cat.hpp"

Cat::Cat() : Animal() {
	printer("Cat Default Constructor");
	type = "Cat";
}

Cat::Cat(const Cat& obj) : Animal(obj) {
	printer("Cat Copy Constructor");
}

Cat&	Cat::operator=(const Cat& right) {
	if (this == &right)
		return (*this);
	Animal::operator=(right);
	return (*this);
}

void	Cat::makeSound( void ) const {
	printer("meow");
}

Cat::~Cat() {
	printer("Cat Destructor");
}
