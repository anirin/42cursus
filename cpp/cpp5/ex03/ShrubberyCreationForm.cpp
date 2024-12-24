#include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(), target_("") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("shrubbery creation", 145, 137), target_(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : AForm(src), target_(src.target_) {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& rhs) {
	if (this != &rhs) {
		AForm::operator=(rhs);
		this->target_ = rhs.target_;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
	if (!this->getIsSigned()) {
		throw AForm::NotSignedException();
	}
	if (executor.getGrade() > this->getExecuteGrade()) {
		throw AForm::GradeTooLowException();
	}

	std::string filename = target_ + "_shrubbery";
	std::ofstream outputfile(filename.c_str());
	if (!outputfile.is_open()) {
		throw ShrubberyCreationForm::FileOpenErrorException();
	}

	outputfile << "       🌲\n";
	outputfile << "      🌲🌲🌲\n";
	outputfile << "     🌲🌲🌲🌲🌲\n";
	outputfile << "    🌲🌲🌲🌲🌲🌲🌲\n";
	outputfile << "   🌲🌲🌲🌲🌲🌲🌲🌲🌲\n";
	outputfile << "        |||\n";
	outputfile << "        |||\n";

	outputfile.close();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */

//child exception
const char* ShrubberyCreationForm::FileOpenErrorException::what() const throw() {
	return "File open error";
}