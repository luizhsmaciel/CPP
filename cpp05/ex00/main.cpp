#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat a("a", 150);
		std::cout << a << "\n";
		a.decrement();
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception caught: " << RESET << e.what() << '\n';
	}
	
	Bureaucrat b("b", 1);
	Bureaucrat c(b);
	Bureaucrat d;

	d = b;
	b.increment();

	std::cout << b << "\n";
	std::cout << c << "\n";
	return (0);
}
