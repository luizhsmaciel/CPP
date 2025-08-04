#include "Point.hpp"

bool    bsp(Point const a, Point const b, Point const c, Point const point);

int	main(void)
{
	Point	a(0, 3);
	Point	b(2, 1);
	Point	c(3, 2);
	Point	point(2, 2);

	bool	triangle = bsp(a, b, c, point);

	if (triangle)
		std::cout << "Dentro" << std::endl;
	else
		std::cout << "Fora" << std::endl;
	return (0);
}
