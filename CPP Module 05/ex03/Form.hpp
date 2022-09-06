#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form{
	private:
		const std::string _name;
		const int _gradeToSign;
		const int _gradeToExec;
		bool _beSigned;
	public:
		Form();
		virtual ~Form();
		Form(std::string name, int gradeToSign, int gradeToExec);
		Form(const Form &f);

		const std::string &getName() const;
		const int &getGradeToSign() const;
		const int &getGradeToExec() const;
		bool getBeSigned() const;
		void beSigned(const Bureaucrat &bc);

		virtual void executeForm(Bureaucrat const &executor) const = 0;

		Form &operator=(const Form &f);
		class GradeTooHighException : public std::exception {
			virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			virtual const char *what() const throw();
		};
		class NoSignException : public std::exception{
			virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, Form const &f);

#endif
