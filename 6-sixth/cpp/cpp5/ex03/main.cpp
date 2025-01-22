#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
	Intern someRandomIntern;
	Bureaucrat boss(1, "Boss");

	std::cout << "\n=== Testing Valid Forms Creation ===" << std::endl;

	// Robotomy Request Form のテスト
	std::cout << "\n--- Testing Robotomy Request Form ---" << std::endl;
	AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	if (rrf) {
		boss.signForm(*rrf);
		boss.executeForm(*rrf);
		delete rrf;
	}

	// Presidential Pardon Form のテスト
	std::cout << "\n--- Testing Presidential Pardon Form ---" << std::endl;
	AForm* ppf = someRandomIntern.makeForm("presidential pardon", "Criminal");
	if (ppf) {
		boss.signForm(*ppf);
		boss.executeForm(*ppf);
		delete ppf;
	}

	// Shrubbery Creation Form のテスト
	std::cout << "\n--- Testing Shrubbery Creation Form ---" << std::endl;
	AForm* scf = someRandomIntern.makeForm("shrubbery creation", "Garden");
	if (scf) {
		boss.signForm(*scf);
		boss.executeForm(*scf);
		delete scf;
	}

	// 存在しないフォームのテスト
	std::cout << "\n=== Testing Invalid Form Creation ===" << std::endl;
	AForm* invalid = someRandomIntern.makeForm("invalid form", "Target");
	if (invalid) {
		boss.signForm(*invalid);
		delete invalid;
	}

	return 0;
}