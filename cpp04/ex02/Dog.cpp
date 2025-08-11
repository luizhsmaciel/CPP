#include "Dog.hpp"

/* I added deep copying of 'brain' to the constructors and the copy assignment operator.
And of course, I deleted 'brain' in the destructor. */
Dog::Dog() : Animal()
{
	std::cout << "Dog Default Constructor called!\n";
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "\033[1;33m" <<"Dog " << this->type << " created!" << "\033[0m\n";
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog Copy constructor called!\n";
	this->brain = new Brain(*other.brain);
	std::cout << "\033[1;33m" <<"Dog " << this->type << " created!" << "\033[0m\n";
}

/* I use the base class constructor to build with all the attributes of the base class
I delete the previous 'brain' and allocate a new 'brain' equal to 'other' */
Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog Copy assignment operator called\n";
	if (this != &other)
	{
		Animal::operator=(other);
		delete this->brain;
		this->brain = new Brain(*other.brain);
		std::cout << "\033[1;33m" <<"Dog " << this->type << " copied!" << "\033[0m\n";
	}
	return (*this);
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog Destructor called\n";
}

void	Dog::makeSound() const
{
	std::cout << "🐶 Woof woof\n";
}

Brain*	Dog::getBrain() const
{
	return (this->brain);
}

void	Dog::printIdeas() const
{
	std::cout << "Dog ideas:\n";
    std::cout << " - " << this->brain->getIdea(0) << "\n";
    std::cout << " - " << this->brain->getIdea(1) << "\n";
}
