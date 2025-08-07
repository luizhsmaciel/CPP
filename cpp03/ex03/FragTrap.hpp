#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ScavTrap.hpp"

/* Virtual inheritance to avoid problem in DiamondTrap.
This ensures only one shared ClapTrap base is created, 
even when both FragTrap and ScavTrap are inherited together. */

class FragTrap : public virtual ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap& other);
		FragTrap& operator=(const FragTrap& other);
		~FragTrap();

		void	highFivesGuys(void);
};

#endif /* FRAGTRAP_HPP */