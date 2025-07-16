#include "Zombie.hpp"

Zombie::Zombie()
{
	// std::cout << this->name << "A zombie was created." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->name << " has been destroyed." << std::endl;
}

void	Zombie::setName(std::string &name)
{
	this->name = name;
}

void	Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
