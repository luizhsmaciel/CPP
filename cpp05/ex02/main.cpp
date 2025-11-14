#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	try
	{
		Bureaucrat	luiz("Luiz", 138);
		ShrubberyCreationForm	ficha("Ficha");

		luiz.signForm(ficha);
		ficha.execute(luiz);
		luiz.increment();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}
