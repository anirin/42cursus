#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
	srand(static_cast<unsigned int>(time(NULL)));

	try {
		// 官僚を作成
		Bureaucrat president(5, "President");  // 高位
		Bureaucrat manager(45, "Manager");	   // 中位
		Bureaucrat intern(150, "Intern");	   // 低位

		std::cout << "\n=== Testing ShrubberyCreationForm ===" << std::endl;
		{
			ShrubberyCreationForm shrub("home");
			// 署名権限テスト
			intern.signForm(shrub);	  // 失敗するはず (grade 145必要)
			manager.signForm(shrub);  // 成功するはず
			manager.signForm(shrub);  // 既に署名済みのテスト

			// 実行権限テスト
			intern.executeForm(shrub);	 // 失敗するはず (grade 137必要)
			manager.executeForm(shrub);	 // 成功するはず
		}

		std::cout << "\n=== Testing RobotomyRequestForm ===" << std::endl;
		{
			RobotomyRequestForm robot("Bender");
			// 署名権限テスト
			intern.signForm(robot);	  // 失敗するはず (grade 72必要)
			manager.signForm(robot);  // 成功するはず

			// 実行権限テスト
			manager.executeForm(robot);	 // 成功するはず (grade 45必要)
			// 複数回実行して50%の成功率をテスト
			manager.executeForm(robot);
			manager.executeForm(robot);
		}

		std::cout << "\n=== Testing PresidentialPardonForm ===" << std::endl;
		{
			PresidentialPardonForm pardon("Criminal");
			// 署名権限テスト
			manager.signForm(pardon);	 // 失敗するはず (grade 25必要)
			president.signForm(pardon);	 // 成功するはず

			// 実行権限テスト
			manager.executeForm(pardon);	// 失敗するはず (grade 5必要)
			president.executeForm(pardon);	// 成功するはず
		}

		std::cout << "\n=== Testing Unsigned Form Execution ===" << std::endl;
		{
			PresidentialPardonForm pardon("Criminal");
			// 署名なしでの実行テスト
			president.executeForm(pardon);	// 署名されていないので失敗するはず
		}

	} catch (std::exception& e) {
		std::cout << "Unexpected error: " << e.what() << std::endl;
	}

	return 0;
}