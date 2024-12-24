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
	o << i.getName() << ", bureaucrat grade " << i.getGrade() << std::endl;
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Bureaucrat::increaseGrade(int number) {
	if (number < 0) {
		std::cout << "tooooo small!" << std::endl;
		return;
	}
	if (grade_ - number < max_grade) {
		throw Bureaucrat::GradeTooHighException();
	}

	grade_ -= number;
}

void Bureaucrat::decreaseGrade(int number) {
	if (number < 0) {
		std::cout << "tooooo small!" << std::endl;
		return;
	}
	if (grade_ + number > min_grade) {
		throw Bureaucrat::GradeTooLowException();
	}

	grade_ += number;
}

void Bureaucrat::signForm(AForm& form) {
	if (form.getIsSigned() == true) {
		std::cout << name_ << " couldn't sign " << form.getName() << " because " << "form is already signed"
				  << std::endl;
		return;
	}
	try {
		form.beSigned(*this);
	} catch (AForm::GradeTooLowException const& e) {
		std::cout << name_ << " couldn't sign " << form.getName() << " because " << "low grade" << std::endl;
		return;
	} catch (AForm::GradeTooHighException const& e) {
		std::cout << e.what() << std::endl;
		return;
	}
	std::cout << name_ << " signed " << form.getName() << std::endl;
}

void Bureaucrat::executeForm(AForm const& form) {
	try {
		form.execute(*this);
	} catch (AForm::GradeTooHighException const& e) {
		std::cout << name_ << " could not execute becase of " << e.what() << std::endl;
		return;
	} catch (AForm::GradeTooLowException const& e) {
		std::cout << name_ << " could not execute becase of " << e.what() << std::endl;
		return;
	} catch (AForm::NotSignedException const& e) {
		std::cout << name_ << " could not execute becase of " << e.what() << std::endl;
		return;
	} catch (AForm::ChildException const& e) {
		std::cout << name_ << " could not execute becase of " << e.what() << std::endl;
		return;
	}

	std::cout << name_ << " executed " << form.getName() << std::endl;
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
