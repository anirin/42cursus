#include "Array.hpp"
#include "Array.tpp"
#include <iostream>
#include <string>

int main()
{
    std::cout << "\n=== Int Array Test ===" << std::endl;
    Array<int> intArray(5);
    std::cout << "Size: " << intArray.size() << std::endl;
    
    // 値を設定
    for (size_t i = 0; i < intArray.size(); i++) {
        intArray[i] = i * 100;
    }
    
    // 値を表示
    std::cout << "Values: ";
    for (size_t i = 0; i < intArray.size() + 1; i++) {
		try {
			std::cout << intArray[i] << " ";
		} catch (const char* e) {
			std::cout << e << std::endl;
		}
    }
    std::cout << "\n\n";

    std::cout << "=== Double Array Test ===" << std::endl;
    Array<double> doubleArray(4);
    std::cout << "Size: " << doubleArray.size() << std::endl;
    
    // 値を設定
    for (size_t i = 0; i < doubleArray.size(); i++) {
        doubleArray[i] = i * 1.5;
    }
    
    // 値を表示
    std::cout << "Values: ";
    for (size_t i = 0; i < doubleArray.size(); i++) {
        std::cout << doubleArray[i] << " ";
    }
    std::cout << "\n\n";

    std::cout << "=== String Array Test ===" << std::endl;
    Array<std::string> stringArray(3);
    std::cout << "Size: " << stringArray.size() << std::endl;
    
    // 値を設定
    stringArray[0] = "Hello";
    stringArray[1] = "World";
    stringArray[2] = "!";
    
    // 値を表示
    std::cout << "Values: ";
    for (size_t i = 0; i < stringArray.size(); i++) {
        std::cout << stringArray[i] << " ";
    }
    std::cout << "\n\n";

    // 範囲外アクセスのテスト
    std::cout << "=== Exception Test ===" << std::endl;
    try {
        std::cout << "Attempting to access index 5 of intArray..." << std::endl;
        std::cout << intArray[5] << std::endl;
    }
    catch (const char* e) {
        std::cout << "Exception caught: " << e << std::endl;
    }

    return 0;
}
