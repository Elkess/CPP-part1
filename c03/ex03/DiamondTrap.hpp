#ifndef DIAMONDTRAP_CPP
#define DIAMONDTRAP_CPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
	std::string name;
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& obj);
		DiamondTrap& operator=(const DiamondTrap& right);
		void whoAmI();
		~DiamondTrap();
};

#endif