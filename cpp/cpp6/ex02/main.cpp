#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <iostream>

int main() {
	std::srand(std::time(nullptr));
	// generate()のテスト
	std::cout << "=== generate()のテスト ===" << std::endl;
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
	Base::identify(nullptr);

	// メモリリーク防止のためのクリーンアップ
	delete ptr1;
	delete ptr2;
	delete ptr3;

	// 具体的な型のテスト
	std::cout << "\n=== 具体的な型のテスト ===" << std::endl;
	A a;
	B b;
	C c;

	std::cout << "A object is: ";
	Base::identify(a);
	std::cout << "B object is: ";
	Base::identify(b);
	std::cout << "C object is: ";
	Base::identify(c);

	return 0;
}
