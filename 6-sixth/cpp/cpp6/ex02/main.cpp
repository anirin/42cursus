#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
	std::srand(time(0));
	Base* ptr1 = Base::generate();
	Base* ptr2 = Base::generate();
	Base* ptr3 = Base::generate();

	// ポインタによる識別のテスト
	std::cout << "\n=== identify(Base*)のテスト ===" << std::endl;
	std::cout << "ptr1 is: ";
	Base::identify(ptr1);
	std::cout << "ptr2 is: ";
	Base::identify(ptr2);
	std::cout << "ptr3 is: ";
	Base::identify(ptr3);

	// 参照による識別のテスト
	std::cout << "\n=== identify(Base&)のテスト ===" << std::endl;
	std::cout << "ptr1 is: ";
	Base::identify(*ptr1);
	std::cout << "ptr2 is: ";
	Base::identify(*ptr2);
	std::cout << "ptr3 is: ";
	Base::identify(*ptr3);

	// nullptrのテスト
	std::cout << "\n=== nullptrのテスト ===" << std::endl;
	Base::identify(NULL);

	// メモリリーク防止のためのクリーンアップ
	delete ptr1;
	delete ptr2;
	delete ptr3;

	return 0;
}
