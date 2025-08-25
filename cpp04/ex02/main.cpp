#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

// int	main(void)
// {
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();

// 	delete j;//should not create a leak
// 	delete i;

// 	return (0);
// }

int	main(void)
{
	int	size = 4;
	Animal*	animals[size];

	for(int i = 0; i < size / 2; i++)
	{
		Dog*	dog = new Dog();
		dog->getBrain()->setIdea(0, "I want to play!");
		dog->getBrain()->setIdea(1, "I want to eat!");
		animals[i] = dog;
	}

	for(int i = size / 2; i < size; i++)
	{
		Cat*	cat = new Cat();
		cat->getBrain()->setIdea(0, "I want to sleep.");
		cat->getBrain()->setIdea(1, "Catch the mouse!");
		animals[i] = cat;
	}

	for(int i = 0; i < size; i++)
	{
		animals[i]->makeSound();
		animals[i]->printIdeas();
	}

	for(int i = 0; i < size; i++)
		delete animals[i];

	std::cout << "\n";
	std::cout << "=== Deep Copy Test ===\n";
	
	Dog	caramel;

	caramel.getBrain()->setIdea(0, "Eat shoes!");
	caramel.getBrain()->setIdea(1, "Chase people!");

	Dog	sleeve_lint(caramel); /* deep copy */

	caramel.getBrain()->setIdea(0, "Eat bone!");
	caramel.getBrain()->setIdea(1, "Chase cats!");

	std::cout << "caramel ";
	caramel.printIdeas();

	std::cout << "sleeve_lint ";
	sleeve_lint.printIdeas();

	// Animal* test = new Animal;
	
	// test->makeSound();
	return (0);
}
