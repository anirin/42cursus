#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
	std::cout << "=== Normal Animal Test ===" << std::endl;
	Animal* animal = new Animal();
	Animal* cat = new Cat();
	Animal* dog = new Dog();

	std::cout << "Animal sound: ";
	animal->makeSound();
	std::cout << "Cat sound: ";
	cat->makeSound();
	std::cout << "Dog sound: ";
	dog->makeSound();

	delete animal;
	delete dog;

	std::cout << "\n=== Wrong Animal Test ===" << std::endl;
	WrongAnimal* wrongAnimal = new WrongCat();
	WrongCat* wrongCat = new WrongCat();

	std::cout << "WrongAnimal(WrongCat) sound: ";
	wrongAnimal->makeSound();
	std::cout << "WrongCat sound: ";
	wrongCat->makeSound();

	delete wrongAnimal;
	delete wrongCat;

	return 0;
}