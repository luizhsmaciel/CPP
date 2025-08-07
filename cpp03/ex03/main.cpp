#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap jose;
	DiamondTrap joao("joao");
	DiamondTrap maria(jose);
	DiamondTrap marta;

	marta = joao;

	jose.attack("joao");
	joao.attack("maria");
	joao.whoAmI();

	joao.takeDamage(90);
	joao.beRepaired(10);
	joao.takeDamage(20);

	joao.takeDamage(10);
	joao.attack("jose");
	joao.beRepaired(10);

	joao.whoAmI();

	joao.guardGate();
	joao.highFivesGuys();
	return (0);
}
