#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ScavTrap.hpp"

/* Using virtual inheritance to avoid the diamond problem.
Virtual inheritance ensures that there is only one ClapTrap base in DiamondTrap. */

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