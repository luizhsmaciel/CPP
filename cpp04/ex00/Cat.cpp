#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	std::cout << "Cat Default Constructor called!\n";
	std::cout << "\033[1;35m" <<"Cat " << this->type << " created!" << "\033[0m\n";
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat Copy constructor called!\n";
	std::cout << "\033[1;35m" <<"Cat " << this->type << " created!" << "\033[0m\n";
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat Copy assignment operator called\n";
	if (this != &other)
		this->type = other.type;
	std::cout << "\033[1;35m" <<"Cat " << this->type << " copied!" << "\033[0m\n";
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called\n";
}

void	Cat::makeSound() const
{
	std::cout << "🐱 Meow meow\n";
}
