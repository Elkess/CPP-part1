#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Nameless_clap_name") {
	std::cout << "DiamondTrap default constructor called" << std::endl;
	this->name = "Nameless DiamondTrap";
	this->hit_points = FragTrap::hit_points;
	this->energy_points = this->energy_points_holder;
	this->attack_damage = FragTrap::attack_damage;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name") {
	std::cout << "DiamondTrap parameterized constructor called" << std::endl;
	this->name = name;
	this->hit_points = FragTrap::hit_points;
	this->energy_points = this->energy_points_holder;
	this->attack_damage = FragTrap::attack_damage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj) : ClapTrap(obj), ScavTrap(obj), FragTrap(obj) {
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	this->name = obj.name;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& right) {
	ScavTrap::operator=(right);
	this->name = right.name;
	return (*this);
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap name: " << this->name << ", ClapTrap name: " << ClapTrap::name << std::endl;
}