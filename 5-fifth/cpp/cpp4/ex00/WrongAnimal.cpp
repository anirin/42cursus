#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {}

WrongAnimal::WrongAnimal(const WrongAnimal& src) : type_(src.type_) {}

WrongAnimal::~WrongAnimal() {}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const& rhs) {
	if (this != &rhs) {
		this->type_ = rhs.type_;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void WrongAnimal::makeSound() {}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */