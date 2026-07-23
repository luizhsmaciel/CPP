#include "Span.hpp"

Span::Span() : _maxSize(0)
{}

Span::Span(unsigned int maxSize) : _maxSize(maxSize)
{}

Span::Span(const Span& other) : _maxSize(other._maxSize), _container(other._container)
{}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_container = other._container;
	}
	return (*this);
}

Span::~Span()
{}

void	Span::addNumber(int n)
{
	if (_container.size() >= _maxSize)
		throw (std::runtime_error("Span is full"));
	_container.push_back(n);
}

int	Span::shortestSpan()
{
	if (_container.size() < 2)
		throw (std::runtime_error("Not enough elements"));

	std::vector<int> temp(_container);
	std::sort(temp.begin(), temp.end());

	int	minDiff = temp[1] - temp[0];
	for (size_t i = 2; i < temp.size(); ++i)
	{
		int	diff = temp[i] - temp[i - 1];
		if (diff < minDiff)
			minDiff = diff;
		if (minDiff == 0)
			return (minDiff);
	}

	return (minDiff);
}

int	Span::longestSpan()
{
	if (_container.size() < 2)
		throw (std::runtime_error("Not enough elements"));

	int	maxValue = *std::max_element(_container.begin(), _container.end());
	int	minValue = *std::min_element(_container.begin(), _container.end());

	return (maxValue - minValue);
}

void	Span::fillSpan()
{
	while (_container.size() < _maxSize)
		addNumber(rand());
}
