#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap jose;
	DiamondTrap joao("joao");
	DiamondTrap maria(jose);
	DiamondTrap marta;

	marta = joao;

	jose.showStatus();
	joao.showStatus();
	maria.showStatus();
	marta.showStatus();

	jose.attack("joao");
	joao.attack("maria");

	jose.whoAmI();
	joao.whoAmI();
	maria.whoAmI();
	marta.whoAmI();
	
	joao.guardGate();
	joao.highFivesGuys();

	joao.takeDamage(90);
	joao.beRepaired(10);
	joao.takeDamage(20);

	jose.showStatus();
	joao.showStatus();
	maria.showStatus();
	marta.showStatus();

	joao.takeDamage(10);
	joao.attack("jose");
	joao.beRepaired(10);

	jose.showStatus();
	joao.showStatus();
	maria.showStatus();
	marta.showStatus();

	joao.whoAmI();
	joao.guardGate();
	joao.highFivesGuys();
	return (0);
}
