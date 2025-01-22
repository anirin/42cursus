#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog() : Animal(), brain_(new Brain()) {
	type_ = "Dog";
}

Dog::Dog(const Dog& src) : Animal(src), brain_(new Brain()) {
	*brain_ = *(src.brain_);
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog() {
	delete brain_;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog& Dog::operator=(Dog const& rhs) {
	if (this != &rhs) {
		Animal::operator=(rhs);
		this->brain_ = rhs.brain_;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Dog::makeSound() {
	std::cout << "Woof woof!" << std::endl;
}

Brain* Dog::get_brain() {
	return brain_;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */