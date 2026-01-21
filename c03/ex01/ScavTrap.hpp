#ifndef SCAVETRAP_HPP
#define SCAVETRAP_HPP

#include "ClapTrap.hpp"

class   ScavTrap : public ClapTrap {
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& obj);
	ScavTrap&  operator=(const ScavTrap& right);
	void	attack(const std::string& target);
	void	guardGate();
	~ScavTrap();
};

#endif