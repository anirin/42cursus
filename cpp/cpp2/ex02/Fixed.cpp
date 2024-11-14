#include "Fixed.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed() : fixed_point_number_(0) {
}

Fixed::Fixed(const Fixed& src) {
	fixed_point_number_ = src.getRawBits();
}

Fixed::Fixed(int number) {
	fixed_point_number_ = number * (1 << fractional_bit_);
}

Fixed::Fixed(float number) {
	fixed_point_number_ = roundf(number * (1 << fractional_bit_));
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed() {
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Fixed& Fixed::operator=(Fixed const& rhs) {
	fixed_point_number_ = rhs.getRawBits();

	return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed& rhs) {
	os << rhs.toFloat();
	return os;
}

bool Fixed::operator<(const Fixed& rhs) const {
	return fixed_point_number_ < rhs.fixed_point_number_;
}

bool Fixed::operator>(const Fixed& rhs) const {
	return fixed_point_number_ > rhs.fixed_point_number_;
}

bool Fixed::operator<=(const Fixed& rhs) const {
	return fixed_point_number_ <= rhs.fixed_point_number_;
}

bool Fixed::operator>=(const Fixed& rhs) const {
	return fixed_point_number_ >= rhs.fixed_point_number_;
}

bool Fixed::operator==(const Fixed& rhs) const {
	return fixed_point_number_ == rhs.fixed_point_number_;
}

bool Fixed::operator!=(const Fixed& rhs) const {
	return fixed_point_number_ != rhs.fixed_point_number_;
}

const Fixed Fixed::operator+(const Fixed& rhs) const {
	Fixed tmp;
	tmp.fixed_point_number_ = fixed_point_number_ + rhs.fixed_point_number_;
	return tmp;
}

const Fixed Fixed::operator-(const Fixed& rhs) const {
	Fixed tmp;
	tmp.fixed_point_number_ = fixed_point_number_ - rhs.fixed_point_number_;
	return tmp;
}

const Fixed Fixed::operator*(const Fixed& rhs) const {
	Fixed tmp;
	tmp.fixed_point_number_ = fixed_point_number_ * (rhs.fixed_point_number_ >> fractional_bit_);
	return tmp;
}

const Fixed Fixed::operator/(const Fixed& rhs) const {
	Fixed tmp;
	tmp.fixed_point_number_ = fixed_point_number_ / (rhs.fixed_point_number_ >> fractional_bit_);
	return tmp;
}

Fixed& Fixed::operator++() {
	fixed_point_number_ += 1;
	return *this;
}

Fixed Fixed::operator++(int) {
	const Fixed tmp = *this;
	++(*this);
	return tmp;
}

Fixed& Fixed::operator--() {
	fixed_point_number_ -= 1;
	return *this;
}

Fixed Fixed::operator--(int) {
	const Fixed tmp = *this;
	--(*this);
	return tmp;
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

Fixed& Fixed::min(Fixed& v1, Fixed& v2) {
	if (v1 < v2) {
		return v1;
	}
	return v2;
}

const Fixed& Fixed::min(const Fixed& v1, const Fixed& v2) {
	if (v1 < v2) {
		return v1;
	}
	return v2;
}

Fixed& Fixed::max(Fixed& v1, Fixed& v2) {
	if (v1 > v2) {
		return v1;
	}
	return v2;
}

const Fixed& Fixed::max(const Fixed& v1, const Fixed& v2) {
	if (v1 > v2) {
		return v1;
	}
	return v2;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */