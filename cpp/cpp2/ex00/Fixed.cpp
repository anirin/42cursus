#include "Fixed.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed() : fixed_point_number_(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& src) {
	fixed_point_number_ = src.getRawBits();
	std::cout << "Copy constructor called" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Fixed& Fixed::operator=(Fixed const& rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixed_point_number_ = rhs.getRawBits();

	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return fixed_point_number_;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	fixed_point_number_ = raw;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */