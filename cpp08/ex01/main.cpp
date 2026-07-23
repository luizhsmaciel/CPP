#include "Span.hpp"
#include <list>
#include <ctime>

int	main(void)
{
	std::srand(std::time(NULL));

	Span sp1 = Span(10000);
	
	sp1.addNumber(3);
	sp1.addNumber(120);
	sp1.addNumber(13);
	sp1.addNumber(20);
	sp1.addNumber(8);
	
	try
	{
		sp1.fillSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << "exception: " << e.what() << '\n';
	}

	std::vector<int> vec;

	vec.push_back(12);
	vec.push_back(7);
	vec.push_back(3);
	vec.push_back(18);
	vec.push_back(25);

	std::list<int> lis;

	lis.push_back(34);
	lis.push_back(19);
	lis.push_back(63);
	lis.push_back(30);
	lis.push_back(40);

	Span sp2 = Span(10);

	try
	{
		sp2.addRange(vec.begin(), vec.end());
		sp2.addRange(lis.begin(), lis.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << "exception: " << e.what() << '\n';
	}
	
	std::cout << "sp1 shortestSpan: " << sp1.shortestSpan() << std::endl;
	std::cout << "sp1 longestSpan: " << sp1.longestSpan() << std::endl;
	std::cout << "sp2 shortestSpan: " << sp2.shortestSpan() << std::endl;
	std::cout << "sp2 longestSpan: " << sp2.longestSpan() << std::endl;

	return (0);
}
