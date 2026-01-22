#ifndef SCAVETRAP_HPP
#define SCAVETRAP_HPP

#include "ClapTrap.hpp"

class   ScavTrap : virtual public ClapTrap {
	protected:
		unsigned int energy_points_holder;
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