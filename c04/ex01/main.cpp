#include "Animal.hpp"
#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

#include "Cat.hpp"
#include <iostream>
#include <string>

int main() {
    std::cout << "\n--- Original Cat ---\n";
    Cat a;
    a.makeSound();
    std::cout << "\n--- Deep Copy Test ---\n";
    Cat b(a); // calls copy constructor (deep copy)

    std::cout << "a brain: " << a.getBrain() << "\n";
    std::cout << "b brain: " << b.getBrain() << "\n";

    std::cout << "\n--- Change a's brain idea ---\n";
    Brain* aBrain = a.getBrain();
    aBrain->setIdea("I am a changed cat!",0);

    // Print to check if b is affected
    std::cout << "a ideas[0]: " << a.getBrain()->getIdea(0) << "\n";
    std::cout << "b ideas[0]: " << b.getBrain()->getIdea(0) << "\n";

    std::cout << "\n--- Assignment operator Test ---\n";
    Cat c;
    c = a; // uses operator=
    std::cout << "c brain: " << c.getBrain() << "\n";

    std::cout << "Changing a's brain again...\n";
    aBrain->setIdea("Another change", 0);

    std::cout << "a ideas[0]: " << a.getBrain()->getIdea(0) << "\n";
    std::cout << "c ideas[0]: " << c.getBrain()->getIdea(0) << "\n";

    return 0;
}
