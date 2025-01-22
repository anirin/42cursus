#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm {
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const& src);
	~PresidentialPardonForm();

	PresidentialPardonForm& operator=(PresidentialPardonForm const& rhs);

	void execute(Bureaucrat const& executor) const;

	class ChildException : public AForm::ChildException {
	public:
		virtual const char* what() const throw();
	};

private:
	std::string target_;
};

#endif /* ****************************************** PRESIDENTIALPARDONFORM_H */