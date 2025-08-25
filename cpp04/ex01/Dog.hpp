#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

/* Includes the 'Brain' pointer */
class Dog : public Animal
{
	private:
		Brain* brain;
	public:
		Dog();
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		~Dog();

		void	makeSound() const;
		Brain*	getBrain() const;
		void	printIdeas() const;
};

#endif /* DOG_HPP */