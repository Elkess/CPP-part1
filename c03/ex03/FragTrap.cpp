#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	printer("FragTrap default constructor called");
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	printer("FragTrap parameterized constructor called");
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap& obj) : ClapTrap(obj)
{
	printer("FragTrap copy constructor called");
}

FragTrap&	FragTrap::operator=(const FragTrap& right) {
	ClapTrap::operator=(right);
	return (*this);
}

void	FragTrap::highFivesGuys() {
	printer("FragTrap " + name + " is requesting a high five!");
}

FragTrap::~FragTrap()
{
	printer("FragTrap destructor called");
}
