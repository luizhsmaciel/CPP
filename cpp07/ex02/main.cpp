#include <iostream>
#include "Array.hpp"

#define RESET "\033[0m"
#define YELLOW "\033[1;33m"
#define CYAN_BOLD "\033[1;36m"

int	main(void)
{
	std::cout << YELLOW << "┌───────────────────┐" << RESET << std::endl;
	std::cout << YELLOW << "│ empty constructor │" << RESET << std::endl;
	std::cout << YELLOW << "└───────────────────┘" << RESET << std::endl;
	Array<int> empty;
	std::cout << "size: " << empty.size() << std::endl;

	std::cout << YELLOW << "┌────────────────┐" << RESET << std::endl;
	std::cout << YELLOW << "│ constructor(n) │" << RESET << std::endl;
	std::cout << YELLOW << "└────────────────┘" << RESET << std::endl;
	Array<int> arrInt(5);
	std::cout << CYAN_BOLD << "Default init: " << std::endl;
	for (unsigned int i = 0; i < arrInt.size(); i++)
		std::cout << "arrInt[" << i << "] = " << arrInt[i] << std::endl;
	std::cout << RESET << std::endl;
	for (unsigned int i = 0; i < arrInt.size(); i++)
		arrInt[i] = i;
	for (unsigned int i = 0; i < arrInt.size(); i++)
		std::cout << "arrInt[" << i << "] = " << arrInt[i] << std::endl;

	std::cout << YELLOW << "┌──────────────────┐" << RESET << std::endl;
	std::cout << YELLOW << "│ copy constructor │" << RESET << std::endl;
	std::cout << YELLOW << "└──────────────────┘" << RESET << std::endl;
	Array<int> arrCopy(arrInt);
	arrCopy[0] = 999;
	std::cout << "arrInt[0] = " << arrInt[0] << " (deve ser 0)" << std::endl;
	std::cout << "arrCopy[0] = " << arrCopy[0] << " (deve ser 999)" << std::endl;

	std::cout << YELLOW << "┌─────────────────────┐" << RESET << std::endl;
	std::cout << YELLOW << "│ assignment operator │" << RESET << std::endl;
	std::cout << YELLOW << "└─────────────────────┘" << RESET << std::endl;
	Array<int> arrAssign(3);
	arrAssign = arrInt;
	std::cout << "arrInt[1] = " << arrInt[1] << " (deve ser 1)" << std::endl;
	std::cout << "arrAssign[1] = " << arrAssign[1] << " (deve ser 1)" << std::endl;
	arrAssign[1] = 888;
	std::cout << "arrAssign[1] = " << arrAssign[1] << " (deve ser 888)" << std::endl;

	std::cout << YELLOW << "┌───────────────┐" << RESET << std::endl;
	std::cout << YELLOW << "│ Array<string> │" << RESET << std::endl;
	std::cout << YELLOW << "└───────────────┘" << RESET << std::endl;
	Array<std::string> arrStr(3);
	std::cout << CYAN_BOLD << "Default init: " << std::endl;
	for (unsigned int i = 0; i < arrStr.size(); i++)
	{
		if (arrStr[i].empty())
			std::cout << "arrStr[" << i << "] = \"" << arrStr[i] << "\" (empty string)" << std::endl;
		else
			std::cout << "arrStr[" << i << "] = " << arrStr[i] << std::endl;
	}
	std::cout << RESET << std::endl;
	arrStr[0] = "aviao";
	arrStr[1] = "bola";
	arrStr[2] = "casa";
	for (unsigned int i = 0; i < arrStr.size(); i++)
		std::cout << "arrStr[" << i << "] = " << arrStr[i] << std::endl;
	arrStr[2] = "carro";
	std::cout << "arrStr[2] = " << arrStr[2] << std::endl;

	std::cout << YELLOW << "┌───────────────┐" << RESET << std::endl;
	std::cout << YELLOW << "│ out of bounds │" << RESET << std::endl;
	std::cout << YELLOW << "└───────────────┘" << RESET << std::endl;
	try
	{
		std::cout << arrInt[10] << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "exception: " << e.what() << std::endl;
	}
	try
	{
		empty[0];
	}
	catch (std::exception& e)
	{
		std::cout << "exception (empty array): " << e.what() << std::endl;
	}

	/* extra tests */
	/* std::cout << YELLOW << "┌───────────────┐" << RESET << std::endl;
	std::cout << YELLOW << "│   push_back   │" << RESET << std::endl;
	std::cout << YELLOW << "└───────────────┘" << RESET << std::endl;
	Array<int> arrPush(3);
	arrPush[0] = 1;
	arrPush[1] = 2;
	arrPush[2] = 3;
	std::cout << CYAN_BOLD << "Before (size=" << arrPush.size() << "): " << std::endl;
	for (unsigned int i = 0; i < arrPush.size(); i++)
		std::cout << "arrPush[" << i << "] = " << arrPush[i] << std::endl;
	std::cout << RESET << std::endl;
	arrPush.push_back(99);
	std::cout << CYAN_BOLD << "After (size=" << arrPush.size() << "): " << std::endl;
	for (unsigned int i = 0; i < arrPush.size(); i++)
		std::cout << "arrPush[" << i << "] = " << arrPush[i] << std::endl;
	std::cout << RESET << std::endl;

	std::cout << YELLOW << "┌───────────────┐" << RESET << std::endl;
	std::cout << YELLOW << "│   pop_back    │" << RESET << std::endl;
	std::cout << YELLOW << "└───────────────┘" << RESET << std::endl;
	arrPush.pop_back();
	std::cout << "pop_back..." << std::endl;
	std::cout << CYAN_BOLD << "After pop (size=" << arrPush.size() << "): " << std::endl;
	for (unsigned int i = 0; i < arrPush.size(); i++)
		std::cout << "arrPush[" << i << "] = " << arrPush[i] << std::endl;
	std::cout << RESET << std::endl;
	try
	{
		Array<int> arrEmpty;
		arrEmpty.pop_back();
	}
	catch (std::exception& e)
	{
		std::cout << "exception: " << e.what() << std::endl;
	}

	std::cout << YELLOW << "┌───────────────┐" << RESET << std::endl;
	std::cout << YELLOW << "│   remove_at   │" << RESET << std::endl;
	std::cout << YELLOW << "└───────────────┘" << RESET << std::endl;
	Array<int> arrRemove(5);
	for (unsigned int i = 0; i < arrRemove.size(); i++)
		arrRemove[i] = i + 5;
	std::cout << CYAN_BOLD << "Before (size=" << arrRemove.size() << "): " << std::endl;
	for (unsigned int i = 0; i < arrRemove.size(); i++)
		std::cout << "arrRemove[" << i << "] = " << arrRemove[i] << std::endl;
	std::cout << RESET << std::endl;
	arrRemove.remove_at(2);
	std::cout << CYAN_BOLD << "After (size=" << arrRemove.size() << "): " << std::endl;
	for (unsigned int i = 0; i < arrRemove.size(); i++)
		std::cout << "arrRemove[" << i << "] = " << arrRemove[i] << std::endl;
	std::cout << RESET << std::endl;
	try
	{
		arrRemove.remove_at(99);
	}
	catch (std::exception& e)
	{
		std::cout << "exception: " << e.what() << std::endl;
	}
	std::cout << RESET;*/
	return (0);
}
