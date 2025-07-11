#include "Phonebook.hpp"

int main(void)
{
	std::string command;
	PhoneBook phonebook;

	while(true)
	{
		std::cout << CYAN << "Enter command (ADD, SEARCH or EXIT): " << RESET;
		std::getline(std::cin, command);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			break ;
		}
		else if (command.empty())
			continue ;
		else if (command == "ADD")
			phonebook.addContact();
		else if (command == "SEARCH")
			phonebook.listContacts();
		else if (command == "EXIT")
			break ;
	}
	return (0);
}
