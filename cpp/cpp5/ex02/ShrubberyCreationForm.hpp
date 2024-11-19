#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <iostream>
#include <string>

class ShrubberyCreationForm : public AForm {
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm const& src);
	~ShrubberyCreationForm();

	ShrubberyCreationForm& operator=(ShrubberyCreationForm const& rhs);

	void execute(Bureaucrat const& executor) const;

	class FileOpenErrorException : public AForm::ChildException {
	public:
		virtual const char* what() const throw() {
			return "File open error";
		}
	};

private:
	std::string target_;
};

#endif /* ******************************************* SHRUBBERYCREATIONFORM_H */