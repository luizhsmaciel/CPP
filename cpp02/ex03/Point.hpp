#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
    private:
        const Fixed _x;
        const Fixed _y;

    public:
        Point();
        Point(const float x, const float y);
        Point(const Point& other);
        Point&  operator=(const Point& other);
        ~Point();

        float   getX() const;
        float   getY() const;

};

#endif /* POINT_HPP */