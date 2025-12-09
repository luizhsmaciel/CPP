#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	std::srand(std::time(NULL));
	try
	{
		Bureaucrat				henrique("Henrique", 145);
		Bureaucrat				luiz("Luiz", 72);
		Bureaucrat				maciel("Maciel", 25);
		ShrubberyCreationForm	ficha("FICHA");
		RobotomyRequestForm		ficha1("FICHA 1");
		PresidentialPardonForm	ficha2("FICHA 2");


		std::cout << henrique << "\n";
		henrique.signForm(ficha);
		henrique.executeForm(ficha);
		henrique.signForm(ficha1);
		henrique.executeForm(ficha1);
		henrique.signForm(ficha2);
		henrique.executeForm(ficha2);

		std::cout << luiz << "\n";
		luiz.signForm(ficha);
		luiz.executeForm(ficha);
		luiz.signForm(ficha1);
		luiz.executeForm(ficha1);
		luiz.signForm(ficha2);
		luiz.executeForm(ficha2);

		std::cout << maciel << "\n";
		maciel.signForm(ficha);
		maciel.executeForm(ficha);
		maciel.signForm(ficha1);
		maciel.executeForm(ficha1);
		maciel.signForm(ficha2);
		maciel.executeForm(ficha2);

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}
