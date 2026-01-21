#include "FragTrap.hpp"

int main() {
	FragTrap frag("Frag1");
	frag.attack("TARGET");
	frag.takeDamage(40);
	frag.beRepaired(30);	
	return 0;
}
