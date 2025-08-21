#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name"), FragTrap(), ScavTrap(), _name("default")
{
	std::cout << "DiamondTrap Default constructor called\n";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;
	this->_maxHitPoints = 100;
	std::cout << "💎 \033[1;94m" <<"DiamondTrap " << _name << " created!" << "\033[0m\n";
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name)
{
	std::cout << "DiamondTrap Constructor with parameters called\n";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;
	this->_maxHitPoints = 100;
	std::cout << "💎 \033[1;94m" <<"DiamondTrap " << _name << " created!" << "\033[0m\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), FragTrap(other), ScavTrap(other), _name(other._name)
{
	std::cout << "DiamondTrap Copy constructor called\n";
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	this->_maxHitPoints = other._maxHitPoints;
	std::cout << "💎 \033[1;94m" <<"DiamondTrap " << _name << " created!" << "\033[0m\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "DiamondTrap Copy assignment operator called\n";
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called\n";
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << "💎 DiamondTrap name: " << this->_name << "\n";
		std::cout << "ClapTrap name: " << ClapTrap::_name << "\n";
	}
	else
		std::cout << "\033[1;31m" << "DiamondTrap " << this->_name << " can't say who he is due to lack of energy or hit points!" << "\033[0m\n";
}
void	DiamondTrap::showStatus()
{
	std::cout << "DiamondTrap " << this->_name << " hitPoints: " << this->_hitPoints << "\n";
	std::cout << "DiamondTrap " << this->_name << " energyPoints: " << this->_energyPoints << "\n";
	std::cout << "DiamondTrap " << this->_name << " attackDamage: " << this->_attackDamage << "\n";
	std::cout << "DiamondTrap " << this->_name << " maxHitPoints: " << this->_maxHitPoints << "\n";
}
