#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <stdexcept>

class RPN
{
	private:
		std::stack<double>	_stack;

	public:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();

		void	parserInput(const std::string& input);
		bool	checkInput(const std::string& input);
		void	calculate(const char& token);
	
};

#endif /* RPN */