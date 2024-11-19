#include "Intern.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern() {}

Intern::Intern(const Intern& src) {
	(void)src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern& Intern::operator=(Intern const& rhs) {
	(void)rhs;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

AForm* Intern::makeForm(std::string form, std::string target) {
	const std::string form_list[] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	int index = 0;

	while (index < 3) {
		if (form == form_list[index]) {
			break;
		}
		index++;
	}

	switch (index) {
		case 0:
			std::cout << "Intern creates RobotomyRequestForm" << std::endl;
			return new RobotomyRequestForm(target);
		case 1:
			std::cout << "Intern creates PresidentialPardonForm" << std::endl;
			return new PresidentialPardonForm(target);
		case 2:
			std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
			return new ShrubberyCreationForm(target);
		default:
			std::cerr << "Error: Form name '" << form << "' does not exist!" << std::endl;
			return NULL;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */