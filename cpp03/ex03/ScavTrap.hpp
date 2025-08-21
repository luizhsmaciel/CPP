#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

/* Using virtual inheritance to avoid the diamond problem.
Virtual inheritance ensures that there is only one ClapTrap base in DiamondTrap. */

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