#include "Zombie.hpp"

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

int	main(void)
{
	Zombie	*red_zombie = newZombie("Luiz");
	red_zombie->announce();
	delete(red_zombie);

	randomChump("Maciel");
	return (0);
}
