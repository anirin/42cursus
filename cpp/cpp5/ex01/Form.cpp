#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form() : name_("init"), sign_grade_(0), execute_grade_(0), is_signed_(false) {}

Form::Form(std::string name, int sign_grade, int execute_grade)
	: name_(name), sign_grade_(sign_grade), execute_grade_(execute_grade), is_signed_(false) {
	if (sign_grade < max_grade || execute_grade < max_grade) {
		throw Form::GradeTooHighException();
	}
	if (sign_grade > min_grade || execute_grade > min_grade) {
		throw Form::GradeTooLowException();
	}
}

Form::Form(const Form& src)
	: name_(src.name_), sign_grade_(src.sign_grade_), execute_grade_(src.execute_grade_), is_signed_(false) {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form& Form::operator=(Form const& rhs) {
	if (this != &rhs) {
		this->is_signed_ = rhs.is_signed_;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& o, Form const& i) {
	o << "Name : " << i.getName() << " Sign grade : " << i.getSignGrade() << "Execute grade : " << i.getExecuteGrade()
	  << " Is signed : " << i.getIsSigned() << std::endl;
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Form::beSigned(Bureaucrat const& b) {
	if (b.getGrade() > sign_grade_) {
		throw Form::GradeTooLowException();
	}
	is_signed_ = true;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int Form::getExecuteGrade() const {
	return execute_grade_;
}
int Form::getSignGrade() const {
	return sign_grade_;
}
std::string Form::getName() const {
	return name_;
}
bool Form::getIsSigned() const {
	return is_signed_;
}

/* ************************************************************************** */

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade too low";
}