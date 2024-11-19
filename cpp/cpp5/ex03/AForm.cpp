#include "AForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AForm::AForm() : name_("init"), sign_grade_(0), execute_grade_(0), is_signed_(false) {}

AForm::AForm(std::string name, int sign_grade, int execute_grade)
	: name_(name), sign_grade_(sign_grade), execute_grade_(execute_grade), is_signed_(false) {
	if (sign_grade < max_grade || execute_grade < max_grade) {
		throw AForm::GradeTooHighException();
	}
	if (sign_grade > min_grade || execute_grade > min_grade) {
		throw AForm::GradeTooLowException();
	}
}

AForm::AForm(const AForm& src)
	: name_(src.name_), sign_grade_(src.sign_grade_), execute_grade_(src.execute_grade_), is_signed_(false) {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AForm::~AForm() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AForm& AForm::operator=(AForm const& rhs) {
	if (this != &rhs) {
		this->is_signed_ = rhs.is_signed_;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& o, AForm const& i) {
	o << "Name : " << i.getName() << " Sign grade : " << i.getSignGrade() << "Execute grade : " << i.getExecuteGrade()
	  << " Is signed : " << i.getIsSigned() << std::endl;
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void AForm::beSigned(Bureaucrat const& b) {
	if (b.getGrade() > sign_grade_) {
		throw AForm::GradeTooLowException();
	}
	is_signed_ = true;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int AForm::getExecuteGrade() const {
	return execute_grade_;
}
int AForm::getSignGrade() const {
	return sign_grade_;
}
std::string AForm::getName() const {
	return name_;
}
bool AForm::getIsSigned() const {
	return is_signed_;
}

/* ************************************************************************** */