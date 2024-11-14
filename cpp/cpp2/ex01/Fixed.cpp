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

Fixed::Fixed(int number) {
	std::cout << "Int constructor called" << std::endl;
	fixed_point_number_ = number * (1 << fractional_bit_);
}

Fixed::Fixed(float number) {
	std::cout << "Float constructor called" << std::endl;
	fixed_point_number_ = roundf(number * (1 << fractional_bit_));
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
	fixed_point_number_ = rhs.getRawBits();

	return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed& rhs) {
	os << rhs.toFloat();
	return os;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

int Fixed::getRawBits() const {
	return fixed_point_number_;
}

void Fixed::setRawBits(int const raw) {
	fixed_point_number_ = raw;
}

int Fixed::toInt() const {
	return fixed_point_number_ >> fractional_bit_;
}

float Fixed::toFloat() const {
	return static_cast<float>(fixed_point_number_) / (1 << fractional_bit_);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */