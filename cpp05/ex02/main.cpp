#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
	std::srand(std::time(NULL));
	try
	{
		Bureaucrat				henrique("Henrique", 145);
		Bureaucrat				luiz("Luiz", 72);
		ShrubberyCreationForm	ficha("FICHA");
		RobotomyRequestForm		ficha1("FICHA 1");

		std::cout << henrique << "\n";
		henrique.signForm(ficha);
		henrique.executeForm(ficha);
		henrique.signForm(ficha1);
		henrique.executeForm(ficha1);

		std::cout << luiz << "\n";
		luiz.signForm(ficha);
		luiz.executeForm(ficha);
		luiz.signForm(ficha1);
		luiz.executeForm(ficha1);

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}
