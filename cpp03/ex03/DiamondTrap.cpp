#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name"), FragTrap("default"), ScavTrap("default"), _name("default")
{
	std::cout << "DiamondTrap Default constructor called\n";
	std::cout << "💎 \033[1;94m" <<"DiamondTrap " << _name << " created!" << "\033[0m\n";
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name)
{
	std::cout << "DiamondTrap Constructor with parameters called\n";
	std::cout << "💎 \033[1;94m" <<"DiamondTrap " << _name << " created!" << "\033[0m\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), FragTrap(other), ScavTrap(other), _name(other._name)
{
	std::cout << "DiamondTrap Copy constructor called\n";
	std::cout << "💎 \033[1;94m" <<"DiamondTrap " << _name << " created!" << "\033[0m\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "DiamondTrap Copy assignment operator called\n";
	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->_name = other._name;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called\n";
}

void	DiamondTrap::whoAmI()
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << "DiamondTrap name: " << this->_name << "\n";
		std::cout << "ClapTrap name: " << ClapTrap::_name << "\n";
	}
	else
		std::cout << "\033[1;31m" << "DiamondTrap " << this->_name << " can't say who he is due to lack of energy or hit points!" << "\033[0m\n";
}
