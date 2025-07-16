#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int	main(void)
{
	Weapon we1 = Weapon("Fists");
	HumanA bob("Bob", we1);
	bob.attack();
	we1.setType("Gun");
	bob.attack();

	Weapon we2 = Weapon("Fists");
	HumanB jim("Jim");
	jim.setWeapon(we2);
	jim.attack();
	we2.setType("Gun");
	jim.attack();

	return (0);
}
