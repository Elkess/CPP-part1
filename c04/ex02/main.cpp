#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "*-+*-+ Creating array of Animals *-+*-+" << std::endl;

    Animal* animals[4];

    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Dog();
    animals[3] = new Cat();

    std::cout << "\n*-+*-+ Making sounds *-+*-+" << std::endl;

    for (int i = 0; i < 4; i++)
    {
        std::cout << "Animal " << i << " type: "
                  << animals[i]->getType() << std::endl;
        animals[i]->makeSound();
    }

    std::cout << "\n*-+*-+ Deleting animals through Animal* *-+*-+" << std::endl;

    for (int i = 0; i < 4; i++)
        delete animals[i];

    return 0;
}
