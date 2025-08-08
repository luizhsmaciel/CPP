#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "WrongAnimal Default Constructor called!\n";
	std::cout << "\033[1;32m" <<"❌ WrongAnimal " << this->type << " created!" << "\033[0m\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type)
{
	std::cout << "WrongAnimal Copy constructor called!\n";
	std::cout << "\033[1;32m" <<"❌ WrongAnimal " << this->type << " created!" << "\033[0m\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "WrongAnimal Copy assignment operator called\n";
	if (this != &other)
		this->type = other.type;
	std::cout << "\033[1;32m" <<"❌ WrongAnimal " << this->type << " copied!" << "\033[0m\n";
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor called\n";
}

void	WrongAnimal::makeSound() const
{
	std::cout << "Default WrongAnimal sound\n";
}

std::string	WrongAnimal::getType() const
{
	return (this->type);
}
