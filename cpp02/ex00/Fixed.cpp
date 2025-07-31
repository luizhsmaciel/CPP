#include "Fixed.hpp"

/* default constructor that initializes the value to zero */
Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}
/* The copy constructor is used to create a new object based on another. */
Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->value = other.getRawBits();
}
/* The copy assignment operator is used to assign the value of one object to an existing one. */
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->value = other.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}
