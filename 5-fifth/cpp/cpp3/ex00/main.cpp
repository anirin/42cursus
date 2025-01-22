#include "ClapTrap.hpp"

int main(void) {
	// 基本的なコンストラクタのテスト
	std::cout << "=== Constructor Tests ===" << std::endl;
	ClapTrap clap1("Clap1");
	ClapTrap clap2("Clap2");
	ClapTrap clap3(clap1);	// コピーコンストラクタ

	std::cout << "\n=== Attack Tests ===" << std::endl;
	// 通常の攻撃テスト
	clap1.attack("Target1");
	clap2.attack("Target2");

	std::cout << "\n=== Damage Tests ===" << std::endl;
	// ダメージテスト
	clap1.takeDamage(5);   // 半分のダメージ
	clap2.takeDamage(15);  // 致命的なダメージ

	std::cout << "\n=== Repair Tests ===" << std::endl;
	// 修理テスト
	clap1.beRepaired(3);  // 通常の修理
	clap2.beRepaired(5);  // 死亡状態での修理試行

	std::cout << "\n=== Energy Tests ===" << std::endl;
	// エネルギー消費テスト
	for (int i = 0; i < 12; ++i) {
		std::cout << "\nAttempt " << i + 1 << ":" << std::endl;
		clap3.attack("Target3");  // エネルギーが尽きるまで攻撃
	}

	std::cout << "\n=== Assignment Test ===" << std::endl;
	// 代入演算子のテスト
	ClapTrap clap4("Clap4");
	clap4 = clap1;

	std::cout << "\n=== Death Test ===" << std::endl;
	// 死亡状態のテスト
	clap4.takeDamage(20);	  // 即死ダメージ
	clap4.attack("Target4");  // 死亡状態での攻撃試行
	clap4.beRepaired(5);	  // 死亡状態での修理試行

	std::cout << "\n=== End of Tests ===" << std::endl;
	return 0;
}