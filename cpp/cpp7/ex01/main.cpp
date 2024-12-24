#include "iter.hpp"

void print(int &n) {
	std::cout << n << std::endl;
}

void print(std::string &s) {
	std::cout << s << std::endl;
}

int main(void) {
	int array[] = {1, 2, 3, 4, 5};
	std::string array2[] = {"Hello", "World", "!"};

	iter(array, 5, print);
	iter(array2, 3, print);
	return 0;
}