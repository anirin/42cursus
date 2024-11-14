#include "ScavTrap.hpp"

int main(void) {
    // 基本的なコンストラクタのテスト
    std::cout << "\n=== Constructor Tests ===" << std::endl;
    ScavTrap scav1;
    ScavTrap scav2("Robot2");
    ScavTrap scav3(scav2);  // コピーコンストラクタ

    // 代入演算子のテスト
    std::cout << "\n=== Assignment Operator Test ===" << std::endl;
    scav1 = scav2;

    // 攻撃と被ダメージのテスト
    std::cout << "\n=== Attack and Damage Tests ===" << std::endl;
    scav2.attack("Enemy1");
    scav2.takeDamage(30);
    scav2.beRepaired(20);

    // エネルギーポイント消費のテスト
    std::cout << "\n=== Energy Points Test ===" << std::endl;
    for (int i = 0; i < 51; ++i) {  // energy_points_が50なので、51回目で空になる
        scav2.attack("Enemy2");
    }

    // 大きなダメージでの死亡テスト
    std::cout << "\n=== Death Test ===" << std::endl;
    scav3.takeDamage(150);  // hit_points_が100なので死亡する
    scav3.attack("Enemy3");  // 死亡後の攻撃は失敗するはず
    scav3.beRepaired(50);   // 死亡後の回復は失敗するはず

    // ScavTrap固有の機能テスト
    std::cout << "\n=== ScavTrap Specific Function Test ===" << std::endl;
    scav2.guardGate();

    // デストラクタのテスト（スコープ終了時に自動的に呼ばれる）
    std::cout << "\n=== Destructor Test ===" << std::endl;

    return 0;
}