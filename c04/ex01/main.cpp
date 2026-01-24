#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    std::cout << "*-+*-+*-+ Cat a *-+*-+*-+" << std::endl;
    Cat a;
    a.setBrainIdea("I wanna fish", 0);

    std::cout << "a's idea[0]: " << a.getBrainIdea(0) << std::endl;

    std::cout << "\n*-+*-+*-+ Deep Copy Cat *-+*-+*-+" << std::endl;
    Cat b = a;
    std::cout << "b's idea[0]: " << b.getBrainIdea(0) << std::endl;

    std::cout << "\n*-+*-+*-+ Change b's brain idea *-+*-+*-+" << std::endl;
    b.setBrainIdea("I wanna milk", 0);

    std::cout << "a's idea[0]: " << a.getBrainIdea(0) << std::endl;
    std::cout << "b's idea[0]: " << b.getBrainIdea(0) << std::endl;

    std::cout << "\n*-+*-+*-+ Assignment Operator Test *-+*-+*-+" << std::endl;
    Cat c;
    c = a;
    std::cout << "c's idea[0]: " << c.getBrainIdea(0) << std::endl;

    c.setBrainIdea("I wanna sleep", 0);
    std::cout << "a's idea[0]: " << a.getBrainIdea(0) << std::endl;
    std::cout << "c's idea[0]: " << c.getBrainIdea(0) << std::endl;

    std::cout << "\n*-+*-+*-+ Dog Deep Copy Test *-+*-+*-+" << std::endl;
    Dog d;
    d.setBrainIdea("I wanna bone", 0);
    Dog e = d;
    e.setBrainIdea("I wanna nap", 0);

    std::cout << "d's idea[0]: " << d.getBrainIdea(0) << std::endl;
    std::cout << "e's idea[0]: " << e.getBrainIdea(0) << std::endl;

   std::cout << "\n*-+*-+*-+ Animal Array *-+*-+*-+" << std::endl;

    const int size = 4;
    Animal* animals[size];

    for (int i = 0; i < size / 2; i++)
        animals[i] = new Dog();

    for (int i = size / 2; i < size; i++)
        animals[i] = new Cat();

    std::cout << "\n*-+*-+ Deleting Animals *-+*-+" << std::endl;
    for (int i = 0; i < size; i++)
        delete animals[i];

    return 0;
}
