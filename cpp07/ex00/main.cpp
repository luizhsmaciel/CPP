#include <iostream>

#include "whatever.hpp"

#define RESET "\033[0m"
#define YELLOW "\033[1;33m"
#define CYAN_BOLD "\033[1;36m"
#define BOX_DRAWING "┌└│┘┐─"

/*	Force the compiler to use my global template functions (::swap, ::min, ::max) 
	and prevent any name conflicts with the standard library (std::) */
int	main(void)
{
	int			a = 2;
	int			b = 3;
	std::string	c = "chaine1";
	std::string	d = "chaine2";

	std::cout << YELLOW <<"┌──────────────────┐" << RESET << std::endl;
	std::cout << YELLOW <<"│ swap | min | max │ [int] " << RESET << std::endl;
	std::cout << YELLOW <<"└──────────────────┘" << RESET << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << " (swaped)" << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

	std::cout << CYAN_BOLD <<"┌──────────────────┐" << RESET << std::endl;
	std::cout << CYAN_BOLD <<"│ swap | min | max │ [string] " << RESET << std::endl;
	std::cout << CYAN_BOLD <<"└──────────────────┘" << RESET << std::endl;
	std::cout << "c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << " (swaped)" << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
	return (0);
}
