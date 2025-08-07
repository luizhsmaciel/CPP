#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap Default constructor called\n";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_maxHitPoints = 100;
	std::cout << "\033[1;33m" <<"ScavTrap " << _name << " created!" << "\033[0m\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap Constructor with parameters called\n";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_maxHitPoints = 100;
	std::cout << "\033[1;33m" <<"ScavTrap " << _name << " created!" << "\033[0m\n";
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap Copy constructor called\n";
	std::cout << "\033[1;33m" <<"ScavTrap " << _name << " created!" << "\033[0m\n";
}

/* I call the base class assignment operator */
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap Copy assignment operator called\n";
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called\n";
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << "\033[1;36m" << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << "\033[0m\n";
		this->_energyPoints--;
	}
	else
		std::cout << "\033[1;31m" << "ScavTrap " << this->_name << " has no energy or hit points to attack!" << "\033[0m\n";

}

void	ScavTrap::guardGate()
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
		std::cout << "ScavTrap " << this->_name << " is in Gate keeper mode\n";
	else
		std::cout << "ScavTrap " << this->_name << " cannot enter Gate keeper mode due to lack of energy or hit points!\n";
}
