#include "PmergeMe.hpp"

int	main(int ac, char** av)
{
	if (ac < 3)
		return (std::cerr << "Error: insufficient arguments" << std::endl, 1);

	try
	{
		PmergeMe pmm;
		pmm.run(av);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
