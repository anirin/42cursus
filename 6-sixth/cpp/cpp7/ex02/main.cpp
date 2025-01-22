#include "Array.hpp"
#include <iostream>

#define MAX_VAL 750
int main(int, char**) {
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++) {
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	// SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++) {
		if (mirror[i] != numbers[i]) {
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try {
		numbers[-2] = 0;
	} catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		numbers[MAX_VAL] = 0;
	} catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++) {
		numbers[i] = rand();
	}

	// access sample
	std::cout << "First value: " << numbers[0] << std::endl;

	// const Array test
	const Array<int> constNumbers(numbers);
	std::cout << "First value: " << constNumbers[0] << std::endl;

	// Array member const test
	Array<const int> constArray(5);
	std::cout << "First value: " << constArray[0] << std::endl;

	delete[] mirror;

	return 0;
}