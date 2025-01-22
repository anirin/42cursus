#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat() : Animal(), brain_(new Brain()) {
	type_ = "Cat";
}

Cat::Cat(const Cat& src) : Animal(src), brain_(new Brain()) {
	std::cout << "cat copy" << std::endl;

	*brain_ = *(src.brain_);
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat() {
	delete brain_;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat& Cat::operator=(Cat const& rhs) {
	if (this != &rhs) {
		Animal::operator=(rhs);
		this->brain_ = rhs.brain_;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Cat::makeSound() {
	std::cout << "Meow meow!" << std::endl;
}

Brain* Cat::get_brain() {
	return brain_;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */