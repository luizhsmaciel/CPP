#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
    // std::cout << "Default constructor called" << std::endl;
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
    // std::cout << "Constructor with parameters called" << std::endl;
}

Point::Point(const Point& other) : _x(other._x), _y(other._y)
{
    // std::cout << "Copy constructor called" << std::endl;
}

Point& Point::operator=(const Point& other)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    std::cerr << "Copy assignment not allowed (const attributes)" << std::endl;
    (void)other;
    return (*this);
}

Point::~Point()
{
    // std::cout << "Destructor called" << std::endl;
}

float   Point::getX() const
{
    return (this->_x.toFloat());
}

float   Point::getY() const
{
    return (this->_y.toFloat());
}
