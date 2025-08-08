#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Animal Default Constructor called!\n";
	std::cout << "\033[1;32m" <<"Animal " << this->type << " created!" << "\033[0m\n";
}

Animal::Animal(const Animal& other) : type(other.type)
{
	std::cout << "Animal Copy constructor called!\n";
	std::cout << "\033[1;32m" <<"Animal " << this->type << " created!" << "\033[0m\n";
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "Animal Copy assignment operator called\n";
	if (this != &other)
		this->type = other.type;
	std::cout << "\033[1;32m" <<"Animal " << this->type << " copied!" << "\033[0m\n";
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called\n";
}

void	Animal::makeSound() const
{
	std::cout << "Default Animal sound\n";
}

std::string	Animal::getType() const
{
	return (this->type);
}
