#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "*-+*-+ Creating Animal pointer to Cat *-+*-+" << std::endl;
    Animal* a = new Cat();

    std::cout << "Type: " << a->getType() << std::endl;
    a->makeSound();

    std::cout << "*-+*-+ Deleting through Animal pointer *-+*-+" << std::endl;
    delete a;

    std::cout << "\n*-+*-+ Creating Animal pointer to Dog *-+*-+" << std::endl;
    Animal* b = new Dog();

    std::cout << "Type: " << b->getType() << std::endl;
    b->makeSound();

    std::cout << "*-+*-+ Deleting through Animal pointer *-+*-+" << std::endl;
    delete b;

    return 0;
}

