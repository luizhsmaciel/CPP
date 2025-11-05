#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): _name("default"), _signed(false), _gradeToSign(150), _gradeToExec(150)
{
	std::cout << MAGENTA << "Form: " << CYAN_BOLD << "Default constructor: " << RESET;
	std::cout << "Form " << this->_name << " created!" << "\n";
}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExec) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
	std::cout << MAGENTA << "Form: " << CYAN_BOLD << "Constructor with parameters: " << RESET;
	std::cout << "Form " << this->_name << " created!" << "\n";
}

Form::Form(const Form& other) : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec)
{
	std::cout << MAGENTA << "Form: " << CYAN_BOLD << "Copy constructor: " << RESET;
	std::cout << "Form " << this->_name << " created!" << "\n";
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		this->_signed = other._signed;
	std::cout << MAGENTA << "Form: " << CYAN_BOLD << "Copy Assignment Operator: " << RESET;
	std::cout << "Form " << this->_name << " created!" << "\n";
	return (*this);
}     

Form::~Form()
{
	std::cout << MAGENTA << "Form: " << CYAN_BOLD << "Destructor called!" << RESET << "\n";
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade too High!");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade too Low!");
}

std::string	Form::getName() const
{
	return (this->_name);
}

bool	Form::getSigned() const
{
	return (this->_signed);
}

int	Form::getSign() const
{
	return (this->_gradeToSign);
}

int	Form::getExec() const
{
	return (this->_gradeToExec);
}

std::ostream& operator<<(std::ostream &os, const Form& obj)
{
	os << "Form name: " << obj.getName() << "\n";
	obj.getSigned() ? os << "Signed: True\n" : os << "Signed: False\n"; 
	os <<  "Grade to sign: " << obj.getSign() << "\n";
	os << "Grade to execute: " << obj.getExec() << "\n";
	return (os);
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (this->_gradeToSign >= bureaucrat.getGrade())
		this->_signed = true;
	else
		throw GradeTooLowException();
}
