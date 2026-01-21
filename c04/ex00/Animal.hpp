#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class Animal {
	protected:
		std::string	type;
		void	makeSound( void );
	public:
		Animal();
		Animal(const Animal& obj);
		Animal& operator=(const Animal& right);
		~Animal();
};

void	printer(std::string msg);

#endif