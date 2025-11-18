#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{

}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return (*this);
}

Intern::~Intern()
{

}
/* Free functions (do not require objects) to use in the pointer array. */
static	AForm*	createShrubbery(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

static	AForm*	createRobotomy(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}

static	AForm*	createPresidential(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::makeForm(std:: string formName, std::string target) const
{
	const std::string	names[] = {"shrubbery creation", "robotomy request", "presidencial pardon"};
	AForm*				(*creators[])(const std::string&) = {&createShrubbery, &createRobotomy, &createPresidential};
	const size_t		n = sizeof(names) / sizeof(names[0]);

	for (size_t i = 0; i < n; i++)
	{
		if (formName == names[i])
		{
			AForm* form = creators[i](target);
			std::cout << "Intern creates " << names[i] << "\n";
			return (form);
		}
	}
	std::cerr << "ERROR: " << formName << ": Form not found.\n";
	return (NULL);
}
