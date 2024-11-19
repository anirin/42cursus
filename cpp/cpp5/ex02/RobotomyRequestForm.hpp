#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <string>

class RobotomyRequestForm : public AForm {
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const& src);
	~RobotomyRequestForm();

	RobotomyRequestForm& operator=(RobotomyRequestForm const& rhs);

	void execute(Bureaucrat const& executor) const;

	class FailDrilException : public AForm::ChildException {
	public:
		virtual const char* what() const throw() {
			return "Error dril";
		}
	};

private:
	std::string target_;
};

#endif /* ********************************************* ROBOTOMYREQUESTFORM_H */