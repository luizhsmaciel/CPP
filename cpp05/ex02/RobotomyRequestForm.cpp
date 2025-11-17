#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
	std::cout << YELLOW << "RobotomyRequestForm: " << CYAN_BOLD << "Default constructor: " << RESET;
	std::cout << "RobotomyRequestForm " << this->_target << " created!" << "\n";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << YELLOW << "RobotomyRequestForm: " << CYAN_BOLD << "Constructor with parameters: " << RESET;
	std::cout << "RobotomyRequestForm " << this->_target << " created!" << "\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target)
{
	std::cout << YELLOW << "RobotomyRequestForm: " << CYAN_BOLD << "Copy constructor: " << RESET;
	std::cout << "RobotomyRequestForm " << this->_target << " created!" << "\n";
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << YELLOW << "RobotomyRequestForm: " << CYAN_BOLD << "Destructor called!" << RESET << "\n";
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);

	std::cout << "vrrrr vrrrrrrrrr\n";
	
	if (std::rand() % 2)
		std::cout << this->_target << " was successfully robotomized!\n";
	else
		std::cout << "Robotomy failed on " << _target << "\n";
}
