#include "FragTrap.hpp"

int main(void) {
	// コンストラクタのテスト
	std::cout << "\n=== Constructor Tests ===" << std::endl;
	FragTrap frag1;
	FragTrap frag2("Robot2");
	FragTrap frag3(frag2);	// コピーコンストラクタ

	// 代入演算子のテスト
	std::cout << "\n=== Assignment Operator Test ===" << std::endl;
	frag1 = frag2;

	// 攻撃と被ダメージのテスト
	std::cout << "\n=== Attack and Damage Tests ===" << std::endl;
	frag2.attack("Enemy1");	 // 通常の攻撃（30ダメージ）
	frag2.takeDamage(40);	 // ダメージを受ける
	frag2.beRepaired(20);	 // 回復

	// エネルギーポイント消費のテスト（FragTrapは100ポイント持っている）
	std::cout << "\n=== Energy Points Test ===" << std::endl;
	for (int i = 0; i < 101; ++i) {
		frag2.attack("Enemy2");
	}

	// 大きなダメージでの死亡テスト
	std::cout << "\n=== Death Test ===" << std::endl;
	frag3.takeDamage(150);	 // HP100なので死亡する
	frag3.attack("Enemy3");	 // 死亡後の攻撃は失敗するはず
	frag3.beRepaired(50);	 // 死亡後の回復は失敗するはず
	frag3.highFivesGuys();	 // 死亡後のハイタッチは失敗するはず（もし実装していれば）

	// FragTrap固有の機能テスト
	std::cout << "\n=== FragTrap Specific Function Test ===" << std::endl;
	frag2.highFivesGuys();

	// デストラクタのテスト（スコープ終了時に自動的に呼ばれる）
	std::cout << "\n=== Destructor Test ===" << std::endl;

	return 0;
}