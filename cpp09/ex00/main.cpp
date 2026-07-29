#include "BitcoinExchange.hpp"
#include <iomanip>

/* Delete the data.csv and input.txt files before submitting */
int	main(int ac, char** av)
{
	if (ac != 2)
		return (std::cout << "Error: could not open file." << std::endl, 1);

	try
	{
		BitcoinExchange btc;
		std::cout << std::setprecision(10);
		btc.loadDatabase();
		btc.processInputFile(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}
