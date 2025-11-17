#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
	std::cout << YELLOW << "ShrubberyCreationForm: " << CYAN_BOLD << "Default constructor: " << RESET;
	std::cout << "ShrubberyCreationForm " << this->_target << " created!" << "\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << YELLOW << "ShrubberyCreationForm: " << CYAN_BOLD << "Constructor with parameters: " << RESET;
	std::cout << "ShrubberyCreationForm " << this->_target << " created!" << "\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target)
{
	std::cout << YELLOW << "ShrubberyCreationForm: " << CYAN_BOLD << "Copy constructor: " << RESET;
	std::cout << "ShrubberyCreationForm " << this->_target << " created!" << "\n";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << YELLOW << "ShrubberyCreationForm: " << CYAN_BOLD << "Destructor called!" << RESET << "\n";
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);

	std::string file = this->_target + "_shrubbery";
	std::ofstream outfile(file.c_str());

	if (!outfile)
		throw std::ios_base::failure("Failed to open file: " + file);
	outfile << "      *      \n";
	outfile << "     ***     \n";
	outfile << "    *****    \n";
	outfile << "   *******   \n";
	outfile << "  *********  \n";
	outfile << "      *      \n";
	outfile << "______*______\n";
	outfile.close();
	std::cout << YELLOW << "ShrubberyCreationForm: " << CYAN_BOLD << "File created!" << RESET << "\n";
}
