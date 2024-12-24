#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat() : name_("no"), grade_(1) {}

Bureaucrat::Bureaucrat(int grade, std::string name) : name_(name) {
	if (grade < max_grade) {
		throw Bureaucrat::GradeTooHighException();
	}
	if (grade > min_grade) {
		throw Bureaucrat::GradeTooLowException();
	}
	grade_ = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : name_(src.name_), grade_(src.grade_) {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& rhs) {
	if (this != &rhs) {
		grade_ = rhs.grade_;
		std::cout << "[Warn] name cant copy" << std::endl;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& o, Bureaucrat const& i) {
	o << i.getName() << ", bureaucrat grade " << i.getGrade() << "." << std::endl;
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Bureaucrat::increaseGrade(int number) {
	if (number < 0) {
		std::cout << "number must be positive" << std::endl;
		return;
	}
	if (grade_ - number < max_grade) {
		throw Bureaucrat::GradeTooHighException();
	}

	grade_ -= number;
}

void Bureaucrat::decreaseGrade(int number) {
	if (number < 0) {
		std::cout << "number must be positive" << std::endl;
		return;
	}
	if (grade_ + number > min_grade) {
		throw Bureaucrat::GradeTooLowException();
	}

	grade_ += number;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Bureaucrat::getName() const {
	return name_;
}

int Bureaucrat::getGrade() const {
	return grade_;
}

/* ************************************************************************** */

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low";
}