#include "ClapTrap.hpp"

void	printer(std::string msg) {
	std::cout << msg << std::endl;
}

ClapTrap::ClapTrap() {
	printer("ClapTrap default constructor called");
	this->name = "Nameless";
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
}

ClapTrap::ClapTrap(const std::string& name) {
	printer("ClapTrap parameterized constructor called");
	this->name = name;
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& obj) {
	printer("ClapTrap copy constructor called");
	*this = obj;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& right) {
	this->name = right.name;
	this->hit_points = right.hit_points;
	this->energy_points = right.energy_points;
	this->attack_damage = right.attack_damage;
	return (*this);
}

void ClapTrap::attack(const std::string& target) {
	if (!energy_points || !hit_points) {
		printer("ClapTrap " + name + " has no energy or hit points to attack.");
		return;
	}
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
	energy_points--;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (!hit_points) {
		printer("ClapTrap " + name + " has no hit points left.");
		return;
	}
	if (hit_points <= amount)
		hit_points = 0;
	else
		hit_points -= amount;
	std::cout << "ClapTrap " << name << " takes " << amount << " points of damage! Remaining hit points: " << hit_points << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (!energy_points || !hit_points) {
		printer("ClapTrap " + name + " has no energy or hit points to repair.");
		return;
	}
	long overflow_var = hit_points + amount;
	if (overflow_var - amount == hit_points)
		hit_points += amount;
	else
	 	hit_points = 4294967295;
	std::cout << "ClapTrap " << name << " is repaired by " << amount << " points! Current hit points: " << hit_points << std::endl;
	energy_points--;
}

ClapTrap::~ClapTrap() {
	printer("ClapTrap " + name + " is being destroyed.");
}