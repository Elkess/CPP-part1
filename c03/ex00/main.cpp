#include "ClapTrap.hpp"

int main() {
    ClapTrap clap1("Mr.Clap");
    ClapTrap clap2 = clap1;

    clap1.attack("Target1");
    clap1.takeDamage(5);
    clap1.beRepaired(3);

    clap2.attack("Target2");
    clap2.takeDamage(15);
    clap2.beRepaired(10);
    ClapTrap a;
    return 0;
}