#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


int main(void)
{
	try
	{
		Bureaucrat	luiz("Luiz", 42);
		Intern		someRandomIntern;
		AForm*		rrf = someRandomIntern.makeForm("robotomy request", "Bender");

		luiz.signForm(*rrf);
		luiz.executeForm(*rrf);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}
