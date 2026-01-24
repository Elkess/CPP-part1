#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal{
	Brain* brain;
	public:
		Cat();
		Cat(const Cat& obj);
		Cat& operator=(const Cat& right);
		void	makeSound( void ) const ;
		std::string	getBrainIdea(size_t index) const;
		void	setBrainIdea(std::string idea, size_t index);
		~Cat();
};

#endif