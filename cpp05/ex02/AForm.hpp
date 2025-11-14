#ifndef AFORM_HPP
#define AFORM_HPP

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

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExec;

	public:
		AForm();
		AForm(const std::string name, int gradeToSign, int gradeToExec);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		~AForm();

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

		class FormNotSignedException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		std::string		getName() const;
		bool			getSigned() const;
		int				getSign() const;
		int				getExec() const;
		void			beSigned(const Bureaucrat& bureaucrat);
		virtual void	execute(Bureaucrat const & bureaucrat) const = 0;

};

std::ostream& operator<<(std::ostream &os, const AForm& obj);

#endif /* AFORM_HPP */