#include "Dog.hpp"

Dog::Dog() {
	printer("Dog Default Constructor");
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog& obj) : Animal(obj) {
	printer("Dog Copy Constructor");
	brain = new Brain(*obj.brain);
}

Dog&	Dog::operator=(const Dog& right) {
	if (this == &right)
		return (*this);
	Animal::operator=(right);
	delete this->brain;
	this->brain = new Brain(*right.brain);
	return (*this);
}

void	Dog::makeSound( void ) const {
	printer("Bark");
}

std::string	Dog::getBrainIdea(size_t index) const {
	return (this->brain->getIdea(index));
}

void	Dog::setBrainIdea(std::string idea, size_t index) {
	this->brain->setIdea(idea, index);
}

Dog::~Dog() {
	printer("Dog Destructor");
	delete brain;
}
