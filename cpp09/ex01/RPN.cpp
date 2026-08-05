#include "RPN.hpp"

/* OCF */
RPN::RPN() {}

RPN::RPN(const RPN& other) : _stack(other._stack) {}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
		this->_stack = other._stack;
	return (*this);
}

RPN::~RPN() {}

/* static functions */
static bool	stringToDouble(const std::string& s, double& value)
{
	std::stringstream ss(s);
	ss >> value;
	return (!ss.fail() && ss.eof());
}

static bool	isOp(const char& token)
{
	return (token == '+' || token == '-' || token == '*' || token == '/');
}

/* members functions */
bool	RPN::checkInput(const std::string& input)
{
	std::string validChars = "0123456789+-/* ";

	if (input.empty())
		return (false);
	for (size_t i = 0; i < input.size(); i++)
	{
		if (validChars.find(input[i]) == std::string::npos)
			return (false);
	}

	return (true);
}

void	RPN::calculate(const char& token)
{
	double	second = _stack.top();
	_stack.pop();

	double	first = _stack.top();
	_stack.pop();

	switch (token)
	{
		case '+':
			_stack.push(first + second);
			break;
		case '-':
			_stack.push(first - second);
			break;
		case '*':
			_stack.push(first * second);
			break;
		case '/':
			if (second == 0)
				throw (std::runtime_error("Error: division by zero"));
			_stack.push(first / second);
			break;
	}
}

void	RPN::parserInput(const std::string& input)
{
	std::stringstream	ss(input);
	std::string			token;

	if (!checkInput(input))
		throw (std::runtime_error("Error: invalid input"));

	while (ss >> token)
	{
		if (token.size() != 1)
			throw (std::runtime_error("Error: invalid input"));
		else if (isdigit(token[0]))
		{
			double	value;
			if (!stringToDouble(token, value))
				throw (std::runtime_error("Error: conversion error"));
			_stack.push(value);
		}
		else if (isOp(token[0]) && _stack.size() >= 2)
			this->calculate(token[0]);
		else
			throw (std::runtime_error("Error: too few numbers to execute the operation"));
	}

	if (_stack.size() != 1)
		throw (std::runtime_error("Error: invalid input"));

	std::cout << _stack.top() << std::endl;
}

