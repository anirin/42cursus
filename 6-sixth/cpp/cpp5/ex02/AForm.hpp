#ifndef AForm_HPP
#define AForm_HPP

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
public:
	AForm();
	AForm(std::string name, int sign_grade, int execute_grade);
	AForm(AForm const& src);
	virtual ~AForm();

	AForm& operator=(AForm const& rhs);

	void beSigned(Bureaucrat const& b);

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	class NotSignedException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class ChildException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	int getSignGrade() const;
	int getExecuteGrade() const;
	std::string getName() const;
	bool getIsSigned() const;

	virtual void execute(Bureaucrat const& executor) const = 0;

private:
	const std::string name_;
	const int sign_grade_;
	const int execute_grade_;
	bool is_signed_;
};

std::ostream& operator<<(std::ostream& o, AForm const& i);

#endif /* ************************************************************ AForm_H */