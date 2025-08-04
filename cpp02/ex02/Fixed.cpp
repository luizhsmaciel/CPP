#include "Fixed.hpp"

/* Default constructor that initializes the value to zero */
Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}
/* Int constructor */
Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = n << this->fractionalBits;
}
/* Float constructor */
Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = (int)roundf(n * (1 << this->fractionalBits));
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

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void	Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->value / (1 << this->fractionalBits));
}

int	Fixed::toInt(void) const
{
	return (this->value >> this->fractionalBits);
}
/* This function defines what to do when you try to "insert" a 'Fixed' object into an ostream */
std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();

	return (os);
}
/* Comparison operators */
bool	Fixed::operator>(const Fixed& other) const
{
	return (this->value > other.value);
}

bool	Fixed::operator<(const Fixed& other) const
{
	return (this->value < other.value);
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return (this->value >= other.value);
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return (this->value <= other.value);
}

bool	Fixed::operator==(const Fixed& other) const
{
	return (this->value == other.value);
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return (this->value != other.value);
}
/* Arithmetic operators (conversion to float because the current value is at a fixed point) */
Fixed	Fixed::operator+(const Fixed& other) const
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	if (other.value == 0)
	{
		std::cerr << "Error: division by zero!" << std::endl;
		return (Fixed());
	}
	return (Fixed(this->toFloat() / other.toFloat()));
}
/* Pre-increment */
Fixed&	Fixed::operator++()
{
	this->value++;
	return (*this);
}
/* Post-increment */
Fixed	Fixed::operator++(int)
{
	Fixed	temp = *this;
	this->value++;
	return (temp);
}
/* Pre-decrement */
Fixed&	Fixed::operator--()
{
	this->value--;
	return (*this);
}
/* Post-decrement */
Fixed	Fixed::operator--(int)
{
	Fixed	temp = *this;
	this->value--;
	return (temp);
}

Fixed&	Fixed::min(Fixed& n1, Fixed& n2)
{
	return (n1 <= n2 ? n1 : n2);
}

const Fixed&	Fixed::min(const Fixed& n1, const Fixed& n2)
{
	return (n1 <= n2 ? n1 : n2);
}

Fixed&	Fixed::max(Fixed& n1, Fixed& n2)
{
	return (n1 >= n2 ? n1 : n2);
}

const Fixed&	Fixed::max(const Fixed& n1, const Fixed& n2)
{
	return (n1 >= n2 ? n1 : n2);
}
