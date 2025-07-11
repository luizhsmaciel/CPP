#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <cstdlib>
#include "Contact.hpp"

const std::string RESET = "\x1B[0m";
const std::string RED = "\x1B[31m";
const std::string GREEN = "\x1B[32m";
const std::string CYAN = "\x1B[36m";

class PhoneBook
{
	private:
		Contact contacts[8];
		int		contactCount;

	public:
		PhoneBook();
		void	addContact();
		void	listContacts();
		void	searchContact();
		void	displayContact(int index);
};

#endif /* PHONEBOOK_HPP */