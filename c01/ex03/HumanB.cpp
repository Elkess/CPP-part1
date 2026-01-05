#include "HumanB.hpp"
#include <cstddef>

HumanB::HumanB(std::string name, Weapon& weapon)
	: name(name), weapon(&weapon) {}

HumanB::HumanB(std::string	name)
{
	this->name = name;
	this->weapon = NULL;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}

void	HumanB::attack() {
	if (weapon)
	{
		std::cout << name 
				<< " attacks with their "
				<< weapon->getType()
				<< std::endl;
	}
}
