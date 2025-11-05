#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <string>
#include <iostream>
#include <exception>

#define RESET		"\033[0m"
#define RED			"\033[1;31m"
#define GREEN		"\033[1;32m"
#define YELLOW		"\033[1;33m"
#define MAGENTA		"\033[1;35m"
#define CYAN_BOLD	"\033[1;36m"
#define LIGHT_BLUE	"\033[1;94m"

class Form;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();

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

		std::string		getName() const;
		int				getGrade() const;
		void			increment();
		void			decrement();
		void			signForm(Form& form);
		
};

std::ostream& operator<<(std::ostream &os, Bureaucrat const &obj);
	
#endif /* BUREAUCRAT_H */