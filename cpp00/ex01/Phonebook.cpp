#include "Phonebook.hpp"
#include <iomanip>
#include <sstream>

PhoneBook::PhoneBook()
{
	contactCount = 0;
}

std::string formatField(const std::string &str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

std::string getNonEmptyInput(const std::string &prompt)
{
	std::string input;

	while (true)
	{
		std::cout << prompt;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			exit (0);
		}
		if (input.empty())
		{
			std::cout << RED << "Field cannot be empty. Try again.\n" << RESET;
			continue ;
		}
		if (input.length() > 255)
		{
			std::cout << RED << "Input too long (max " << 255 << " characters). Try again.\n" << RESET;
			continue;
		}
		break ;
	}
	return (input);
}

void	PhoneBook::addContact()
{
	Contact newContact;
	int		index;

	newContact.setFirstName(getNonEmptyInput("First Name: "));
	newContact.setLastName(getNonEmptyInput("Last Name: "));
	newContact.setNickName(getNonEmptyInput("Nickame: "));
	newContact.setPhoneNumber(getNonEmptyInput("Phone Number: "));
	newContact.setDarkestSecret(getNonEmptyInput("Darkest Secret: "));

	index = contactCount % 8;
	contacts[index] = newContact;
	contactCount++;
	std::cout << GREEN << "Contact added successfully!\n" << RESET;
}

void	PhoneBook::displayContact(int index)
{
	std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << contacts[index].getNickName() << std::endl;
	std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}

void	PhoneBook::searchContact()
{
	std::string	input;
	int	index;
	int	maxIndex;

	while (true)
	{
		std::cout << CYAN << "Enter index to display contact details: " << RESET;
		std::getline(std::cin, input);
		maxIndex = contactCount;
		if (contactCount > 8)
			maxIndex = 8;
		if (std::cin.eof())
		{
			std::cout << std::endl;
			exit (0);
		}
		if (input.empty())
			continue ;
		std::stringstream ss(input);
		if (!(ss >> index) || !(ss.eof()) || index < 0 || index >= maxIndex)
		{
			std::cout << RED << "Invalid index." << RESET << std::endl;
			std::cin.clear();
			continue ;
		}
		break ;
	}
	PhoneBook::displayContact(index);
}

void	PhoneBook::listContacts()
{
	int	numberContactsList;

	if (contactCount == 0)
	{
		std::cout << RED << "PhoneBook is empty. Add some contacts first." << RESET << std::endl;
		return ;
	}
	std::cout << "|" << std::setw(10) << "Index"
			<< "|" << std::setw(10) << "First Name"
			<< "|" << std::setw(10) << "Last Name"
			<< "|" << std::setw(10) << "Nickname"
			<< "|" << std::endl;
	numberContactsList = contactCount;
	if (contactCount > 8)
		numberContactsList = 8;
	for (int i = 0; i < numberContactsList; i++)
	{
		std::cout << "|" << std::setw(10) << i
				<< "|" << std::setw(10) << formatField(contacts[i].getFirstName())
				<< "|" << std::setw(10) << formatField(contacts[i].getLastName())
				<< "|" << std::setw(10) << formatField(contacts[i].getNickName())
				<< "|" << std::endl;
	}
	PhoneBook::searchContact();
}
