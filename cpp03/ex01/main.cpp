#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap maciel;
	ScavTrap luiz("Luiz");
	ScavTrap henrique(luiz);

	maciel.attack("Luiz");
	luiz.attack("Henrique");

	luiz.takeDamage(90);
	luiz.beRepaired(10);
	luiz.takeDamage(20);

	luiz.takeDamage(10);

	return (0);
}
