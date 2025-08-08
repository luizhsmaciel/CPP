#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// int	main(void)
// {
// 	const Animal* meta = new Animal();
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
// 	std::cout << j->getType() << " " << "\n";
// 	std::cout << i->getType() << " " << "\n";
// 	i->makeSound(); //will output the cat sound!
// 	j->makeSound();
// 	meta->makeSound();

// 	delete meta;
// 	delete i;
// 	delete j;
// 	return (0);
// }

int	main(void)
{
	const	Animal*	generic = new Animal();
	const	Animal*	dog = new Dog();
	const	Animal*	cat = new Cat();

	std::cout << "\033[1;36m" << "=== Testing getType() ===" << "\033[0m\n";
    std::cout << "generic type: " << generic->getType() << "\n";
    std::cout << "dog type: " << dog->getType() << "\n";
    std::cout << "cat type: " << cat->getType() << "\n";

	std::cout << "\033[1;36m" << "=== Testing makeSound() (Polymorphism) ===" << "\033[0m\n";
	generic->makeSound();
    dog->makeSound();
    cat->makeSound();

	std::cout << "\033[1;36m" << "=== Cleaning up Animals ===" << "\033[0m\n";
	delete generic;
    delete dog;
	delete cat;

	std::cout << "\n";

	const	WrongAnimal*	wrongGeneric = new WrongAnimal();
	const	WrongAnimal*	wrongCat = new WrongCat();

	std::cout << "\033[1;36m" << "=== Testing getType() ===" << "\033[0m\n";
	std::cout << "wrongGeneric type: " << wrongGeneric->getType() << "\n";
    std::cout << "wrongCat type: " << wrongCat->getType() << "\n";

	std::cout << "\033[1;36m" << "=== Testing makeSound() without polymorphism ===" << "\033[0m\n";
	wrongGeneric->makeSound();
	wrongCat->makeSound();

	std::cout << "\033[1;36m" << "=== Cleaning up WrongAnimals ===" << "\033[0m\n";
	delete wrongGeneric;
	delete wrongCat;
	return (0);
}
