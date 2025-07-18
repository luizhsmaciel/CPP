#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl		harl;
	std::string	inputLevel;
	std::string	levels = " DEBUG INFO WARNING ERROR ";

	if (ac != 2)
		return (std::cout << "Usage: ./harl <level>" << std::endl 
			<< "level: DEBUG, INFO, WARNING, ERROR" << std::endl, 1);
	inputLevel = av[1];
	if (levels.find(" " + inputLevel + " ") != std::string::npos)
		harl.complain(inputLevel);
	else
		std::cout << "Unknown level: " << inputLevel << std::endl; 
	return (0);
}
