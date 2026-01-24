#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal{
	Brain*	brain;
	public:
		Dog();
		Dog(const Dog& obj);
		Dog& operator=(const Dog& right);
		void	makeSound( void ) const;
		std::string	getBrainIdea(size_t index) const;
		void	setBrainIdea(std::string idea, size_t index);
		~Dog();
};

#endif