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

/* Adding "= 0" to at least one virtual function makes it a "pure virtual function".
This makes the class abstract (cannot be instantiated) and forces derived classes 
to provide their own implementation. */
class Animal
{
	protected:
		std::string	type;

	public:
		Animal();
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		virtual	~Animal();

	virtual	void	makeSound() const = 0;
	std::string	getType() const;
	virtual	void	printIdeas() const = 0;

};

#endif /* ANIMAL_HPP */