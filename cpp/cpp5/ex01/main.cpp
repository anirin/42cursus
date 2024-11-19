#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void) {
	Bureaucrat b(20, "jon");
	Form f("form", 10, 10);

	try {
		b.increaseGrade(15);
	} catch (Bureaucrat::GradeTooHighException const& e) {
		std::cout << e.what() << std::endl;
	} catch (Bureaucrat::GradeTooLowException const& e) {
		std::cout << e.what() << std::endl;
	}

	b.signForm(f);
	b.signForm(f);
}