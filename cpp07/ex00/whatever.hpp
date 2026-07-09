#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void	swap(T& first, T& second)
{
	T	tmp = first;
	first = second;
	second = tmp;
}

/* Using const references to avoid copies and accept rvalues */
template <typename T>
T	min(const T& first, const T& second)
{
	return (first < second ? first : second);
}

template <typename T>
T	max(const T& first, const T& second)
{
	return (first > second ? first : second);
}

#endif /* WHATEVER_HPP */