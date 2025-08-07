#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

/* Just to remember the colors
	RESET		"\033[0m"
	RED			"\033[1;31m"
	GREEN		"\033[1;32m"
	YELLOW		"\033[1;33m"
	MAGENTA		"\033[1;35m"
	CYAN_BOLD	"\033[1;36m"
	CYAN 		"\033[0;36m"
*/

class ClapTrap
{
	private:
		std::string _name;
		int	_hitPoints;
		int	_energyPoints;
		int	_attackDamage;
		int	_maxHitPoints;
	
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);
		~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

};

#endif /* CLAPTRAP_HPP */