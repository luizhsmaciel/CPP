#include "Point.hpp"

/* Área = |(x₁(y₂ - y₃) + x₂(y₃ - y₁) + x₃(y₁ - y₂)) / 2| */
Fixed   area(Point const &a, Point const &b, Point const &c)
{
    Fixed result = (a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())) / 2;

    return (result >= 0 ? result : result * -1);
}

bool    bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed   triangle = area(a, b, c);
    Fixed   ABP = area(a, b, point);
    Fixed   BCP = area(b, c, point);
    Fixed   CAP = area(c, a, point);

    if (ABP == 0 || BCP == 0 || CAP == 0)
        return (false);
    return (ABP + BCP + CAP == triangle);
}
