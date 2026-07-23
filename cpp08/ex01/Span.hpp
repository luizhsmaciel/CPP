#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <cstdlib>


class Span
{
	private:
		unsigned int		_maxSize;
		std::vector<int>	_container;

	public:
		Span();
		Span(unsigned int maxSize);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void				addNumber(int n);
		int					shortestSpan();
		int					longestSpan();
		void				fillSpan();

		template <typename Iterator>
		void	addRange(Iterator first, Iterator last)
		{
			if ((std::distance(first, last) + static_cast<long>(_container.size())) > static_cast<long>(_maxSize))
				throw (std::runtime_error("Range exceeds Span capacity"));
			_container.insert(_container.end(), first, last);
		}
};

#endif /* SPAN_HPP */