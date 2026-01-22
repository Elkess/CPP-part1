#include "ScavTrap.hpp"

int main() {
	ScavTrap scav("Scav1");
	ScavTrap a;
	a = scav;
	scav.attack("Target");
	scav.takeDamage(30);
	scav.beRepaired(20);
	scav.guardGate();
	return 0;
}
