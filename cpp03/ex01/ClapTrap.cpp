#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap Default constructor called\n";
	std::cout << "\033[1;32m" <<"ClapTrap " << _name << " created!" << "\033[0m\n";
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap Constructor with parameters called\n";
	std::cout << "\033[1;32m" <<"ClapTrap " << _name << " created!" << "\033[0m\n";

}

ClapTrap::ClapTrap(const ClapTrap& other)
	: _name(other._name), _hitPoints(other._hitPoints),
	_energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap Copy constructor called\n";
	std::cout << "\033[1;32m" <<"ClapTrap " << _name << " created!" << "\033[0m\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap Copy assignment operator called\n";
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
		std::cout << "\033[1;32m" <<"ClapTrap " << _name << " created!" << "\033[0m\n";
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called\n";
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << "\033[1;36m" << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << "\033[0m\n";
		this->_energyPoints--;
	}
	else
		std::cout << "\033[1;31m" << "ClapTrap " << this->_name << " has no energy or hit points to attack!" << "\033[0m\n";
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints > 0)
	{
		std::cout << "\033[1;36m" << "ClapTrap " << this->_name << " received " << amount << " points of damage!" << "\033[0m\n";
		this->_hitPoints -= amount;
		if (this->_hitPoints < 0)
			this->_hitPoints = 0;
		// std::cout << "Vida atual: " << this->_hitPoints << std::endl;
	}
	else
		std::cout << "\033[1;31m" << "ClapTrap " << this->_name << " cannot take damage because he is dead!" << "\033[0m\n";
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << "\033[1;36m" << "ClapTrap " << this->_name << " recovered " << amount << " hit points!" << "\033[0m\n";
		this->_hitPoints += amount;
		if (this->_hitPoints > 10)
			this->_hitPoints = 10;
		this->_energyPoints--;
		// std::cout << "Vida atual: " << this->_hitPoints << std::endl;
	}
	else
		std::cout << "\033[1;31m" << "ClapTrap " << this->_name << " cannot recover due to lack of energy or hit points!" << "\033[0m\n";
}
