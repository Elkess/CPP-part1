#ifndef WRONGCAT_H
#define WRONGCAT_H

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
	public:
		WrongCat();
		WrongCat(const WrongCat& obj);
		WrongCat& operator=(const WrongCat& right);
		void	makeSound( void ) const;
		~WrongCat();
};

#endif