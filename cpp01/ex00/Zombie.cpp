#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
	// std::cout << this->name << " was created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->name << " has been destroyed." << std::endl;
}

void	Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
