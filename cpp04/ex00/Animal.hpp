#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

/* Just to remember the colors
	RESET		"\033[0m"
	RED			"\033[1;31m"
	GREEN		"\033[1;32m"
	YELLOW		"\033[1;33m"
	MAGENTA		"\033[1;35m"
	CYAN_BOLD	"\033[1;36m"
	LIGHT BLUE	"\033[1;94m"
*/

/* makeSound is virtual to allow polymorphism: it calls the right function in derived classes.
Destructor is virtual to delete derived objects correctly. */
class Animal
{
	protected:
		std::string	type;

	public:
		Animal();
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		virtual	~Animal();

	virtual void	makeSound() const;
	std::string	getType() const;

};

#endif /* ANIMAL_HPP */