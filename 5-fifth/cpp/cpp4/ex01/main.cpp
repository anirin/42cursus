#include "Cat.hpp"
#include <iostream>

int main() {
	const Animal* i = new Cat();
	const Animal* j = new Dog();
	delete i;
	delete j;

	return 0;
}