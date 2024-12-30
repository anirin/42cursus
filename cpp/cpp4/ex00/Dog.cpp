#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog() : Animal() {
	type_ = "Dog";
}

Dog::Dog(const Dog& src) : Animal(src) {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog& Dog::operator=(Dog const& rhs) {
	if (this != &rhs) {
		Animal::operator=(rhs);
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Dog::makeSound() {
	std::cout << "Woof woof!" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */