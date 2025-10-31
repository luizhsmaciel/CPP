#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
	std::cout << CYAN_BOLD << "Default constructor: " << RESET;
	std::cout << "Bureaucrat " << _name << " created with grade " << _grade << "\n";
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->_grade = grade;
	std::cout << CYAN_BOLD << "Constructor with parameters: " << RESET;
	std::cout << "Bureaucrat " << _name << " created with grade " << _grade << "\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
	std::cout << CYAN_BOLD << "Copy constructor: " << RESET;
	std::cout << "Bureaucrat " << _name << " created with grade " << _grade << "\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		this->_grade = other._grade;
	std::cout << CYAN_BOLD << "Copy Assignment Operator: " << RESET;
	std::cout << "Bureaucrat " << _name << " created with grade " << _grade << "\n";
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << CYAN_BOLD << "Destructor called!" << RESET << "\n";
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::increment()
{
	if (this->_grade == 1)
		throw GradeTooHighException();
	this->_grade--;
}

void	Bureaucrat::decrement()
{
	if (this->_grade == 150)
		throw GradeTooLowException();
	this->_grade++;
}

std::ostream& operator<<(std::ostream &os, Bureaucrat const &obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return (os);
}
