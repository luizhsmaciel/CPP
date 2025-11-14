#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
	std::cout << YELLOW << "RobotomyRequestForm: " << CYAN_BOLD << "Default constructor: " << RESET;
	std::cout << "RobotomyRequestForm " << this->_target << " created!" << "\n";
}

RobotomyRequestForm::RobotomyRequestForm()
{
	std::cout << YELLOW << "RobotomyRequestForm: " << CYAN_BOLD << "Default constructor: " << RESET;
	std::cout << "RobotomyRequestForm " << this->_target << " created!" << "\n";
}

RobotomyRequestForm::RobotomyRequestForm()
{

}