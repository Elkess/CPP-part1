#include "Brain.hpp"

Brain::Brain() {
	printer("Brain Default Constructor");
}

Brain::Brain(const Brain& obj) {
	printer("Brain Copy Constructor");
	*this = obj;
}

Brain&	Brain::operator=(const Brain& right) {
	if (this == &right)
		return (*this);
	for (size_t	i = 0; i < 100; i++)
		this->ideas[i] = right.ideas[i];
	return (*this);
}

void	Brain::setIdea(std::string idea, size_t index){
	if (index < 100)
		ideas[index] = idea;
}

std::string	Brain::getIdea(size_t index) {
	if (index < 100)
		return ideas[index];
	return "";
}

Brain::~Brain() {
	printer("Brain Destructor");
}
