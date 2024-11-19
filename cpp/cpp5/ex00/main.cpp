#include "Bureaucrat.hpp"

int main(void) {
	Bureaucrat a(1, "jon");

	try {
		a.increase_grade(160);
	} catch (Bureaucrat::GradeTooHighException const& e) {
		std::cout << e.what() << std::endl;
	} catch (Bureaucrat::GradeTooLowException const& e) {
		std::cout << e.what() << std::endl;
	}
}