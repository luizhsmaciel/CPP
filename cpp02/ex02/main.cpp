#include "Fixed.hpp"

int	main(void)
{
	Fixed	a(10);
	Fixed	b(6);
	const Fixed	c(30);
	const Fixed	d(7);

	Fixed 	menor = (a / b);
	const Fixed 	maior = Fixed::max(c, d);

	std::cout << "Resultado menor: " << Fixed::min(a, b) << std::endl;
	std::cout << "Resultado maior: " << maior << std::endl;
	
	return (0);
}
