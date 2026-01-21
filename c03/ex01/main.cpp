#include "ScavTrap.hpp"

int main() {
	ScavTrap scav("Scav1");

	scav.attack("Bandit");
	scav.takeDamage(30);
	scav.beRepaired(20);
	scav.guardGate();
	return 0;
}
