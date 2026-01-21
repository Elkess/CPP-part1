#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
	printer("DiamondTrap Default constructor");
	this->name = "Diamond Default name";
	this->attack_damage = FragTrap::attack_damage;
	this->energy_points = ScavTrap::energy_points;
	this->hit_points = FragTrap::hit_points;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name") {
	printer("DiamondTrap Parametrized constructor");
	this->name = name;
	this->attack_damage = FragTrap::attack_damage;
	this->energy_points = ScavTrap::energy_points;
	this->hit_points = FragTrap::hit_points;
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj) : ClapTrap(obj), FragTrap(obj), ScavTrap(obj) {
	printer("DiamondTrap Copy constructor called");
	*this = obj;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& right){
	ClapTrap::operator=(right);
	return *this;
}

void	DiamondTrap::whoAmI( void ){
	printer("Diamond name: " + name + "; ClapTrap name: "+ ClapTrap::name);
}

DiamondTrap::~DiamondTrap() {
	printer("DiamondTrap Destructor");
}
