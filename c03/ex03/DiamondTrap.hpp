#ifndef DIAMONDTRAP_CPP
#define DIAMONDTRAP_CPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& obj);
		DiamondTrap& operator=(const DiamondTrap& right);
		~DiamondTrap();

	void whoAmI();
};

#endif