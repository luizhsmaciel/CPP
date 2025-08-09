#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

/* makeSound is not virtual, so it always calls the base version.
Destructor is not virtual, so it does not call the child destructor.
This can cause resource leaks if the derived class allocates memory. */
class WrongAnimal
{
	protected:
		std::string	type;

	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal& operator=(const WrongAnimal& other);
		~WrongAnimal();

	void	makeSound() const;
	std::string	getType() const;

};

#endif /* WRONGANIMAL_HPP */