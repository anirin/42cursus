#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;

class Form {
public:
	Form();
	Form(std::string name, int sign_grade, int execute_grade);
	Form(Form const& src);
	~Form();

	Form& operator=(Form const& rhs);

	void beSigned(Bureaucrat const& b);

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Too High";
		}
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Too Low";
		}
	};

	int getSignGrade() const;
	int getExecuteGrade() const;
	std::string getName() const;
	bool getIsSigned() const;

private:
	const std::string name_;
	const int sign_grade_;
	const int execute_grade_;
	bool is_signed_;
};

std::ostream& operator<<(std::ostream& o, Form const& i);

#endif /* ************************************************************ FORM_H */