#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP  

#include <iostream>

class ClapTrap {
	protected:
		std::string name;
		unsigned int hit_points;
		unsigned int energy_points;
		unsigned int attack_damage;
	public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& obj);
	ClapTrap&	operator=(const ClapTrap& right);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	~ClapTrap();
};

void printer(std::string msg);

#endif