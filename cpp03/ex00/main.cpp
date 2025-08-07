#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap jose;
	ClapTrap joao("joao");
	ClapTrap maria(jose);
	ClapTrap marta;

	marta = joao;

	jose.attack("joao");
	joao.attack("maria");
	/* No special ability */

	joao.takeDamage(9);
	joao.beRepaired(1);
	joao.takeDamage(2);

	joao.takeDamage(1);
	joao.attack("jose");
	joao.beRepaired(10);

	/* No special ability */
	return (0);
}
