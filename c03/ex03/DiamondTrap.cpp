#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Nameless_clap_name"), FragTrap(), ScavTrap() {
    this->name = "Nameless";
    this->hit_points = FragTrap::hit_points;
    this->energy_points = ScavTrap::energy_points;
    this->attack_damage = FragTrap::attack_damage;
    std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap() {
    this->name = name;
    this->hit_points = FragTrap::hit_points;
    this->energy_points = ScavTrap::energy_points;
    this->attack_damage = FragTrap::attack_damage;
    std::cout << "DiamondTrap parameterized constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj) : ClapTrap(obj), FragTrap(obj), ScavTrap(obj) {
    std::cout << "DiamondTrap copy constructor called" << std::endl;
    *this = obj;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& right) {
    ClapTrap::operator=(right);
    return (*this);
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap destructor called" << std::endl;
}
void DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap name: " << this->name << ", ClapTrap name: " << ClapTrap::name << std::endl;
}