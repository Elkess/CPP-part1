#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << ": " ;
	j->makeSound();
	std::cout << i->getType() << ": " ;
	i->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;

	printer("When we don't use virtual");
	const WrongAnimal* wranimal = new WrongCat();
	std::cout << wranimal->getType() << ": " ;
	wranimal->makeSound();
	delete wranimal;
	return (0);
}
