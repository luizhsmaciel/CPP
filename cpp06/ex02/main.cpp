#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Base.hpp"

int	main(void)
{
	std::srand(std::time(NULL));
	Base* a = generate();
	Base* b = generate();
	Base* c = generate();
	Base* d = generate();
	Base* e = generate();

	identify(a);
	identify(b);
	identify(c);
	identify(d);
	identify(e);

	std::cout << std::endl;
	identify(*a);
	identify(*b);
	identify(*c);
	identify(*d);
	identify(*e);

	delete a;
	delete b;
	delete c;
	delete d;
	delete e;
	return (0);
}
