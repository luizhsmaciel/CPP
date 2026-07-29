#include "RPN.hpp"

int	main(int ac, char** av)
{
	if (ac != 2)
		return (std::cout << "Usage: ./RPN <\"Reverse Polish Notation\"> " << std::endl, 1);

	try
	{
		RPN	rpn;
		rpn.parserInput(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
