#include "MutantStack.hpp"
#include <iostream>
#include <list>

#define RESET "\033[0m"
#define YELLOW "\033[1;33m"

int	main(void)
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	std::cout << YELLOW << "┌──────────┐" << RESET << std::endl;
	std::cout << YELLOW << "│ iterator │" << RESET << std::endl;
	std::cout << YELLOW << "└──────────┘" << RESET << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << "std::stack size: " << s.size() << std::endl;

	std::cout << YELLOW << "┌──────────────────┐" << RESET << std::endl;
	std::cout << YELLOW << "│ reverse_iterator │" << RESET << std::endl;
	std::cout << YELLOW << "└──────────────────┘" << RESET << std::endl;
	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();
	for (; rit != rite; ++rit)
		std::cout << *rit << std::endl;

	std::cout << YELLOW << "┌────────────────┐" << RESET << std::endl;
	std::cout << YELLOW << "│ const_iterator │" << RESET << std::endl;
	std::cout << YELLOW << "└────────────────┘" << RESET << std::endl;
	const MutantStack<int> mstackConst(mstack);
	MutantStack<int>::const_iterator cit = mstackConst.begin();
	MutantStack<int>::const_iterator cite = mstackConst.end();
	for (; cit != cite; ++cit)
		std::cout << *cit << std::endl;

	std::cout << YELLOW << "┌────────────────────────┐" << RESET << std::endl;
	std::cout << YELLOW << "│ const_reverse_iterator │" << RESET << std::endl;
	std::cout << YELLOW << "└────────────────────────┘" << RESET << std::endl;
	MutantStack<int>::const_reverse_iterator crit = mstackConst.rbegin();
	MutantStack<int>::const_reverse_iterator crite = mstackConst.rend();
	for (; crit != crite; ++crit)
		std::cout << *crit << std::endl;

	std::cout << YELLOW << "┌────────────────────────┐" << RESET << std::endl;
	std::cout << YELLOW << "│ std::list<int> [tests] │" << RESET << std::endl;
	std::cout << YELLOW << "└────────────────────────┘" << RESET << std::endl;
	std::list<int> mlist;
	mlist.push_back(5);
	mlist.push_back(17);

	std::cout << mlist.back() << std::endl;

	mlist.pop_back();

	std::cout << mlist.size() << std::endl;

	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	//[...]
	mlist.push_back(0);

	std::list<int>::iterator lit = mlist.begin();
	std::list<int>::iterator lite = mlist.end();

	++lit;
	--lit;
	for (; lit != lite; ++lit)
		std::cout << *lit << std::endl;

	return (0);
}
