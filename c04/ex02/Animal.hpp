#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class Animal {
	protected:
		std::string	type;
	public:
		Animal();
		Animal(const Animal& obj);
		Animal& operator=(const Animal& right);
		virtual void	makeSound( void ) const = 0;
		std::string	getType( void ) const;
		virtual ~Animal();
};

void	printer(std::string msg);

#endif