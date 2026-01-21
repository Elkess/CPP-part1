#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"

class Cat : public Animal{
	public:
		Cat();
		Cat(const Cat& obj);
		Cat& operator=(const Cat& right);
		~Cat();
};

#endif