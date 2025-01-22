#include "Bureaucrat.hpp"

int main(void) {
	Bureaucrat a(1, "jon");

	try {
		a.increaseGrade(160);
		std::cout << a;
	} catch (Bureaucrat::GradeTooHighException const& e) {
		std::cout << e.what() << std::endl;
	} catch (Bureaucrat::GradeTooLowException const& e) {
		std::cout << e.what() << std::endl;
	}


	try {
		a.decreaseGrade(160);
		std::cout << a;
	} catch (Bureaucrat::GradeTooHighException const& e) {
		std::cout << e.what() << std::endl;
	} catch (Bureaucrat::GradeTooLowException const& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		a.decreaseGrade(10);
		std::cout << a;
	} catch (Bureaucrat::GradeTooHighException const& e) {
		std::cout << e.what() << std::endl;
	} catch (Bureaucrat::GradeTooLowException const& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
