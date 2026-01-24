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
	if (this == &right)
		return (*this);
	Animal::operator=(right);
	delete this->brain;
	this->brain = new Brain(*right.brain);
	return (*this);
}

void	Cat::makeSound( void ) const {
	printer("meow");
}

std::string	Cat::getBrainIdea(size_t index) const {
	return (this->brain->getIdea(index));
}

void	Cat::setBrainIdea(std::string idea, size_t index) {
	this->brain->setIdea(idea, index);
}

Cat::~Cat() {
	printer("Cat Destructor");
	delete brain;
}
