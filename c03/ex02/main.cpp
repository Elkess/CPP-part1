#include "FragTrap.hpp"

int main() {
	FragTrap frag("Frag1");
	FragTrap a;
	a = frag;
	frag.attack("Target");
	frag.takeDamage(30);
	frag.beRepaired(20);
	frag.highFivesGuys();
	return 0;
}