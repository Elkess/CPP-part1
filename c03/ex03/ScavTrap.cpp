#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	printer("ScavTrap default constructor called");
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	printer("ScavTrap parameterized constructor called");
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& obj) : ClapTrap(obj)
{
	printer("ScavTrap copy constructor called");
	*this = obj;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& right) {
	ClapTrap::operator=(right);
	return (*this);
}

void ScavTrap::attack(const std::string& target) {
	if (!energy_points || !hit_points) {
		printer("ScavTrap " + name + " has no energy or hit points to attack.");
		return;
	}
	std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
	energy_points--;
}

void ScavTrap::guardGate()
{
	printer("ScavTrap " + name + " is now in Gate keeper mode.");
}

ScavTrap::~ScavTrap()
{
	printer("ScavTrap destructor called");
}
