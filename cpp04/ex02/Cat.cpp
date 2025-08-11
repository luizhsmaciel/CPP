#include "Cat.hpp"

/* I added deep copying of 'brain' to the constructors and the copy assignment operator.
And of course, I deleted 'brain' in the destructor. */
Cat::Cat() : Animal()
{
	std::cout << "Cat Default Constructor called!\n";
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "\033[1;35m" <<"Cat " << this->type << " created!" << "\033[0m\n";
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat Copy constructor called!\n";
	this->brain = new Brain(*other.brain);
	std::cout << "\033[1;35m" <<"Cat " << this->type << " created!" << "\033[0m\n";
}

/* I use the base class constructor to build with all the attributes of the base class
I delete the previous 'brain' and allocate a new 'brain' equal to 'other' */
Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat Copy assignment operator called\n";
	if (this != &other)
	{
		Animal::operator=(other);
		delete this->brain;
		this->brain = new Brain(*other.brain);
		std::cout << "\033[1;35m" <<"Cat " << this->type << " copied!" << "\033[0m\n";
	}
	return (*this);
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat Destructor called\n";
}

void	Cat::makeSound() const
{
	std::cout << "🐱 Meow meow\n";
}

Brain*	Cat::getBrain() const
{
	return (this->brain);
}

void	Cat::printIdeas() const
{
	std::cout << "Cat ideas:\n";
    std::cout << " - " << this->brain->getIdea(0) << "\n";
    std::cout << " - " << this->brain->getIdea(1) << "\n";
}
