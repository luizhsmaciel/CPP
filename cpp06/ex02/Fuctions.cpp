#include <iostream>
#include <stdlib.h> /* srand, rand */
#include <time.h> /* time */
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void)
{
	int n = rand() % 3;
	// std::cout << "Numero: " << n << std::endl;

	if (n == 0)
		return (new A());
	else if (n == 1)
		return (new B());
	else if (n == 2)
		return (new C());

	return (NULL);
}

/* If the conversion fails -> returns NULL */
void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "C\n";
}

/* If the conversion fails -> throw an exception. */
void	identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A\n";
		return ;
	}
	catch(const std::exception& e) {}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B\n";
		return ;
	}
	catch(const std::exception& e) {}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C\n";
		return ;
	}
	catch(const std::exception& e) {}
}
