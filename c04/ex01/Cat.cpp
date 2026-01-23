#include "Cat.hpp"

Cat::Cat() {
	printer("Cat Default Constructor");
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat& obj) : Animal(obj) {
	printer("Cat Copy Constructor");
	brain = new Brain(*obj.brain);
}

Cat&	Cat::operator=(const Cat& right) {
	Animal::operator=(right);
	*this->brain = *right.brain;
	return (*this);
}

void	Cat::makeSound( void ) const {
	printer("meow");
}

Brain*	Cat::getBrain() const {
	return brain;
}

Cat::~Cat() {
	printer("Cat Destructor");
	delete brain;
}

