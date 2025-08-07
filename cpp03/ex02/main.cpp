#include "FragTrap.hpp"

int main(void)
{
	FragTrap jose;
	FragTrap joao("joao");
	FragTrap maria(jose);
	FragTrap marta;

	marta = joao;

	jose.attack("joao");
	joao.attack("maria");
	joao.highFivesGuys();

	joao.takeDamage(90);
	joao.beRepaired(10);
	joao.takeDamage(20);

	joao.takeDamage(10);
	joao.attack("jose");
	joao.beRepaired(10);

	joao.highFivesGuys();
	return (0);
}
