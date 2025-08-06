#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap maciel;
	ClapTrap luiz("Luiz");
	ClapTrap henrique(luiz);

	maciel.attack("Luiz");
	luiz.attack("Henrique");

	luiz.takeDamage(9);
	luiz.beRepaired(1);
	luiz.takeDamage(2);

	luiz.takeDamage(1);

	return (0);
}
