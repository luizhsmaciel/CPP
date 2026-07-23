#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

#define RESET "\033[0m"
#define YELLOW "\033[1;33m"

int	main(void)
{
	std::vector<int> v1;
	std::list<int> l1;

	v1.push_back(2);
	v1.push_back(5);
	v1.push_back(12);
	v1.push_back(5);
	v1.push_back(9);

	l1.push_back(2);
	l1.push_back(5);
	l1.push_back(12);
	l1.push_back(5);
	l1.push_back(9);

	try
	{
		std::cout << YELLOW << "┌───────────────┐" << RESET << std::endl;
		std::cout << YELLOW << "│  vector<int>  │" << RESET << std::endl;
		std::cout << YELLOW << "└───────────────┘" << RESET << std::endl;
		std::vector<int>::iterator it = ::easyfind(v1, 2);
		std::cout << "Value found: " << *it << " at position " << std::distance(v1.begin(), it) << '\n';

		std::vector<int>::iterator it1 = ::easyfind(v1, 9);
		std::cout << "Value found: " << *it1 << " at position " << std::distance(v1.begin(), it1) << '\n';
		
		std::vector<int>::iterator it2 = ::easyfind(v1, 5);
		std::cout << "Value found: " << *it2 << " at position " << std::distance(v1.begin(), it2) << '\n';

		std::vector<int>::iterator it3 = ::easyfind(v1, 20);
		std::cout << "Value found: " << *it3 << " at position " << std::distance(v1.begin(), it3) << '\n';
	
	}
	catch(const std::exception& e)
	{
		std::cerr << "exception: " << e.what() << '\n';
	}

	try
	{
		std::cout << YELLOW << "┌───────────────┐" << RESET << std::endl;
		std::cout << YELLOW << "│   list<int>   │" << RESET << std::endl;
		std::cout << YELLOW << "└───────────────┘" << RESET << std::endl;
		std::list<int>::iterator it4 = ::easyfind(l1, 2);
		std::cout << "Value found: " << *it4 << " at position " << std::distance(l1.begin(), it4) << '\n';

		std::list<int>::iterator it5 = ::easyfind(l1, 9);
		std::cout << "Value found: " << *it5 << " at position " << std::distance(l1.begin(), it5) << '\n';
		
		std::list<int>::iterator it6 = ::easyfind(l1, 5);
		std::cout << "Value found: " << *it6 << " at position " << std::distance(l1.begin(), it6) << '\n';

		std::list<int>::iterator it7 = ::easyfind(l1, 20);
		std::cout << "Value found: " << *it7 << " at position " << std::distance(l1.begin(), it7) << '\n';
	
	}
	catch(const std::exception& e)
	{
		std::cerr << "exception: " << e.what() << '\n';
	}
	std::vector<int> v2;
	try
	{
		std::cout << YELLOW << "┌───────────────────────┐" << RESET << std::endl;
		std::cout << YELLOW << "│   vector<int> empty   │" << RESET << std::endl;
		std::cout << YELLOW << "└───────────────────────┘" << RESET << std::endl;
		std::vector<int>::iterator it8 = ::easyfind(v2, 2);
		std::cout << "Value found: " << *it8 << " at position " << std::distance(v2.begin(), it8) << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << "exception: " << e.what() << '\n';
	}

	const std::list<int> l2(l1);
	try
	{
		std::cout << YELLOW << "┌─────────────────────┐" << RESET << std::endl;
		std::cout << YELLOW << "│   const list<int>   │" << RESET << std::endl;
		std::cout << YELLOW << "└─────────────────────┘" << RESET << std::endl;
		std::list<int>::const_iterator it9 = ::easyfind(l2, 2);
		std::cout << "Value found: " << *it9 << " at position " << std::distance(l2.begin(), it9) << '\n';

		std::list<int>::const_iterator it10 = ::easyfind(l2, 9);
		std::cout << "Value found: " << *it10 << " at position " << std::distance(l2.begin(), it10) << '\n';
		
		std::list<int>::const_iterator it11 = ::easyfind(l2, 5);
		std::cout << "Value found: " << *it11 << " at position " << std::distance(l2.begin(), it11) << '\n';

		std::list<int>::const_iterator it12 = ::easyfind(l2, 20);
		std::cout << "Value found: " << *it12 << " at position " << std::distance(l2.begin(), it12) << '\n';
	
	}
	catch(const std::exception& e)
	{
		std::cerr << "exception: " << e.what() << '\n';
	}

	return (0);
}
