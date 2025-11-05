#include "Form.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	luiz("luiz", 3);
		Form		a("ficha", 2, 3);
		Form		b("b", 2, 3);
		Form		c;

		c = a;

		luiz.signForm(a);
		std::cout << luiz << "\n";
		std::cout << a << "\n";
		std::cout << c;
		luiz.increment();
		std::cout << luiz << "\n";
		luiz.signForm(a);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}
