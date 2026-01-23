#include "WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << "WrongCat Default Constructor" << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& obj) : WrongAnimal(obj) {
	std::cout << "WrongCat Copy Constructor" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& right) {
	WrongAnimal::operator=(right);
	return (*this);
}

void	WrongCat::makeSound( void ) const {
	std::cout << "meow" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat Destructor" << std::endl;
}
