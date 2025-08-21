#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0), _maxHitPoints(10)
{
	std::cout << "ClapTrap Default constructor called\n";
	std::cout << "\033[1;32m" <<"ClapTrap " << _name << " created!" << "\033[0m\n";
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0), _maxHitPoints(10)
{
	std::cout << "ClapTrap Constructor with parameters called\n";
	std::cout << "\033[1;32m" <<"ClapTrap " << _name << " created!" << "\033[0m\n";

}

ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name), _hitPoints(other._hitPoints),
	_energyPoints(other._energyPoints), _attackDamage(other._attackDamage), _maxHitPoints(other._maxHitPoints)
{
	std::cout << "ClapTrap Copy constructor called\n";
	std::cout << "\033[1;32m" <<"ClapTrap " << _name << " created!" << "\033[0m\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap Copy assignment operator called\n";
	if (this != &other)
	{
		std::cout << "\033[1;32m" <<"ClapTrap " << other._name << " assigned from " << _name << "\033[0m\n";
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
		this->_maxHitPoints = other._maxHitPoints;
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
		if (amount > static_cast<unsigned int>(this->_hitPoints))
			this->_hitPoints = 0;
		else
			this->_hitPoints -= amount;
		// std::cout << "ClapTrap Vida atual: " << this->_hitPoints << std::endl;
	}
	else
		std::cout << "\033[1;31m" << "ClapTrap " << this->_name << " cannot take damage because he is dead!" << "\033[0m\n";
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << "\033[1;36m" << "ClapTrap " << this->_name << " recovered " << amount << " hit points!" << "\033[0m\n";
		if (amount > static_cast<unsigned int>(this->_maxHitPoints - this->_hitPoints))
			this->_hitPoints = this->_maxHitPoints;
		else
			this->_hitPoints += amount;
		this->_energyPoints--;
		// std::cout << "ClapTrap Vida atual: " << this->_hitPoints << std::endl;
	}
	else
		std::cout << "\033[1;31m" << "ClapTrap " << this->_name << " cannot recover due to lack of energy or hit points!" << "\033[0m\n";
}
