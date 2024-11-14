#include "WrongCat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongCat::WrongCat() : WrongAnimal() {
	type_ = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& src) : WrongAnimal(src) {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongCat::~WrongCat() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongCat& WrongCat::operator=(WrongCat const& rhs) {
	if (this != &rhs) {
		WrongAnimal::operator=(rhs);
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void WrongCat::makeSound() {
	std::cout << "Wrong Meow meow!" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */