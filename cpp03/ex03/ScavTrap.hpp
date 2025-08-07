#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

/* Virtual inheritance to avoid problem in DiamondTrap.
This ensures only one shared ClapTrap base is created, 
even when both FragTrap and ScavTrap are inherited together. */

class ScavTrap : public virtual ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& other);
		ScavTrap& operator=(const ScavTrap& other);
		~ScavTrap();

		void	attack(const std::string& target);
		void	guardGate();
};

#endif /* SCAVTRAP_HPP */