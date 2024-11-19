#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <string>

const int min_grade = 150;
const int max_grade = 1;

class Bureaucrat {
public:
	Bureaucrat();
	Bureaucrat(int grade, std::string name);
	Bureaucrat(Bureaucrat const& src);
	~Bureaucrat();

	Bureaucrat& operator=(Bureaucrat const& rhs);

	std::string getName() const;
	int getGrade() const;
	void increase_grade(int number);
	void decrease_grade(int number);

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

private:
	const std::string name_;
	int grade_;
};

std::ostream& operator<<(std::ostream& o, Bureaucrat const& i);

#endif /* ****************************************************** BUREAUCRAT_H */