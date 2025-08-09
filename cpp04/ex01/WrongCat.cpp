#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	// char* teste = new char[100];
	// (void)teste;
	this->type = "WrongCat";
	std::cout << "WrongCat Default Constructor called!\n";
	std::cout << "\033[1;35m" <<"WrongCat " << this->type << " created!" << "\033[0m\n";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout << "WrongCat Copy constructor called!\n";
	std::cout << "\033[1;35m" <<"WrongCat " << this->type << " created!" << "\033[0m\n";
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << "WrongCat Copy assignment operator called\n";
	if (this != &other)
		this->type = other.type;
	std::cout << "\033[1;35m" <<"WrongCat " << this->type << " copied!" << "\033[0m\n";
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called\n";
}

void	WrongCat::makeSound() const
{
	std::cout << "❌ 🐱 Meow meow\n";
}
