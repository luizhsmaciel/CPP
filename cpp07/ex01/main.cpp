#include <iostream>
#include <algorithm>

#include "iter.hpp"

#define RESET "\033[0m"
#define YELLOW "\033[1;33m"
#define CYAN_BOLD "\033[1;36m"

template <typename T>
void	print(const T& element)
{
	std::cout << element << " ";
}

template <typename T>
void	doubleValue(T& element)
{
	element *= 2;
}

void	stringInverter(std::string& str)
{
	std::reverse(str.begin(), str.end());
}

int	main(void)
{
	int				arrInt[] = {2,3,1,4};
	std::string		arrString[] = {"aviao", "dado", "bola", "casa"};
	const int		arrConst[] = {5,2,3,6};

	const	size_t 	arrSize = 4;

	std::cout << YELLOW <<"┌────────────┐" << RESET << std::endl;
	std::cout << YELLOW <<"│ iter array │ [int] " << RESET << std::endl;
	std::cout << YELLOW <<"└────────────┘" << RESET << std::endl;
	std::cout << CYAN_BOLD << "Array   : " << RESET;
	::iter(arrInt, arrSize, ::print<int>);
	std::cout << std::endl;
	
	::iter(arrInt, 4, ::doubleValue<int>);
	std::cout << CYAN_BOLD << "Array 2x: " << RESET;
	::iter(arrInt, (sizeof(arrInt) / sizeof(arrInt[0])), ::print<int>);
	std::cout << std::endl;

	std::cout << YELLOW <<"┌────────────┐" << RESET << std::endl;
	std::cout << YELLOW <<"│ iter array │ [string] " << RESET << std::endl;
	std::cout << YELLOW <<"└────────────┘" << RESET << std::endl;
	std::cout << CYAN_BOLD << "Array          : " << RESET;
	::iter(arrString, 4, ::print<std::string>);
	std::cout << std::endl;

	::iter(arrString, arrSize, ::stringInverter);
	std::cout << CYAN_BOLD << "Array Inverted : " << RESET;
	::iter(arrString, arrSize, ::print<std::string>);
	std::cout << std::endl;

	std::cout << YELLOW <<"┌────────────┐" << RESET << std::endl;
	std::cout << YELLOW <<"│ iter array │ [const int] " << RESET << std::endl;
	std::cout << YELLOW <<"└────────────┘" << RESET << std::endl;
	std::cout << CYAN_BOLD << "Array   : " << RESET;
	::iter(arrConst, 4, ::print<int>);
	std::cout << std::endl;

	return (0);
}
