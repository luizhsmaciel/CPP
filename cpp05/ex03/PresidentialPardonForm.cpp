#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default")
{
	std::cout << YELLOW << "PresidentialPardonForm: " << CYAN_BOLD << "Default constructor: " << RESET;
	std::cout << "PresidentialPardonForm " << this->_target << " created!" << "\n";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << YELLOW << "PresidentialPardonForm: " << CYAN_BOLD << "Constructor with parameters: " << RESET;
	std::cout << "PresidentialPardonForm " << this->_target << " created!" << "\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other ) : AForm(other), _target(other._target)
{
	std::cout << YELLOW << "PresidentialPardonForm: " << CYAN_BOLD << "Copy constructor: " << RESET;
	std::cout << "PresidentialPardonForm " << this->_target << " created!" << "\n";
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << YELLOW << "PresidentialPardonForm: " << CYAN_BOLD << "Destructor called!" << RESET << "\n";
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox.\n";
}
