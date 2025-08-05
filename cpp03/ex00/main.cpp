#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap luiz("Luiz");
	ClapTrap henrique(luiz);

	henrique.attack("Luiz");

	luiz.takeDamage(9);
	luiz.beRepaired(1);
	luiz.takeDamage(2);

	luiz.takeDamage(1);

	return (0);
}
