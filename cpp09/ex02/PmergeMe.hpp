#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <climits>
#include <ctime>
#include <algorithm>
#include <utility>

class PmergeMe
{
	private:
		std::vector<int>	_vec;
		std::list<int>		_lis;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void	run(char** av);
		void	parserInput(char** av);
		void	sort();
		void	fordJohnsonSortVector(std::vector<int>& vector);


};


#endif /* PMERGEME_HPP */