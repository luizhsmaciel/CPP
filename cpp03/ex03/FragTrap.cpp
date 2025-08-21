#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap Default constructor called\n";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	this->_maxHitPoints = 100;
	std::cout << "\033[1;35m" <<"FragTrap " << _name << " created!" << "\033[0m\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap Constructor with parameters called\n";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	this->_maxHitPoints = 100;
	std::cout << "\033[1;35m" <<"FragTrap " << _name << " created!" << "\033[0m\n";
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap Copy constructor called\n";
	std::cout << "\033[1;35m" <<"FragTrap " << _name << " created!" << "\033[0m\n";
}

/* I call the base class assignment operator */
FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap Copy assignment operator called\n";
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called\n";
}

void	FragTrap::highFivesGuys(void)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
		std::cout << "FragTrap " << this->_name << " requests a high five!\n";
	else
		std::cout << "\033[1;31m" << "FragTrap " << this->_name << " cannot request a high five due to lack of energy or life points!" << "\033[0m\n";

}
