#include "Brain.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Brain::Brain() {}

Brain::Brain(const Brain& src) {
	for (int i = 0; i < 100; i++) {
		ideas_[i] = src.ideas_[i];
	}
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Brain::~Brain() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Brain& Brain::operator=(Brain const& rhs) {
	std::cout << "<<operater has called>>" << std::endl;
	if (this != &rhs) {
		for (int i = 0; i < 100; i++) {
			this->ideas_[i] = rhs.ideas_[i];
		}
	}

	std::cout << "<<operater has called>> before return" << std::endl;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

const std::string Brain::getter(int i) const {
	if (i < 0 || i >= 100) {
		std::out_of_range("Invalid index return index 0");
		return ideas_[0];
	}
	return ideas_[i];
}

void Brain::setter(int i, std::string str) {
	if (i < 0 || i >= 100) {
		std::out_of_range("Invalid index");
		return;
	}
	ideas_[i] = str;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */