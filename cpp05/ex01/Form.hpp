#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

#define RESET		"\033[0m"
#define RED			"\033[1;31m"
#define GREEN		"\033[1;32m"
#define YELLOW		"\033[1;33m"
#define MAGENTA		"\033[1;35m"
#define CYAN_BOLD	"\033[1;36m"
#define LIGHT_BLUE	"\033[1;94m"

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		int					_gradeToSign;
		int					_gradeToExec;

	public:
		Form();
		Form(const std::string name, int gradeToSign, int gradeToExec);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw(); 
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		std::string	getName() const;
		bool		getSigned() const;
		int			getSign() const;
		int			getExec() const;
		void		beSigned(const Bureaucrat& bureaucrat);


};

std::ostream& operator<<(std::ostream &os, const Form& obj);

#endif /* FORM_HPP */