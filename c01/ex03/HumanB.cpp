#include "HumanB.hpp"

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
	else {
		std::cout << name 
				<< " doesn't have a weapon"
				<< std::endl;
	}
}
