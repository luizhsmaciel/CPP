#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog Default Constructor called!\n";
	this->type = "Dog";
	std::cout << "\033[1;33m" <<"Dog " << this->type << " created!" << "\033[0m\n";
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog Copy constructor called!\n";
	std::cout << "\033[1;33m" <<"Dog " << this->type << " created!" << "\033[0m\n";
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog Copy assignment operator called\n";
	if (this != &other)
		this->type = other.type;
	std::cout << "\033[1;33m" <<"Dog " << this->type << " copied!" << "\033[0m\n";
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called\n";
}

void	Dog::makeSound() const
{
	std::cout << "🐶 Woof woof\n";
}

