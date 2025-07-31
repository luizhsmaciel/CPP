#include "Fixed.hpp"

int	main(void)
{
	Fixed	a(10);
	Fixed	b(2.44f);

	int	val = a.getRawBits();
	int	val2 = b.getRawBits();

	std::cout << "valor de a: " << val << std::endl;
	std::cout << "valor de b: " << val2 << std::endl;

	return (0);
}
