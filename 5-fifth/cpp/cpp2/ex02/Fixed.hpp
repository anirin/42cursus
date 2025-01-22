#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath> 

class Fixed {
public:
	Fixed();
	Fixed(int number);
	Fixed(float number);
	Fixed(Fixed const& src);
	~Fixed();
	Fixed& operator=(Fixed const& rhs);
	int getRawBits() const;
	void setRawBits(int const raw);
	float toFloat( void ) const;
	int toInt( void ) const;

	bool operator<(const Fixed& rhs) const;
	bool operator>(const Fixed& rhs) const;
	bool operator==(const Fixed& rhs) const;
	bool operator!=(const Fixed& rhs) const;
	bool operator<=(const Fixed& rhs) const;
	bool operator>=(const Fixed& rhs) const;
	const Fixed operator+(const Fixed& rhs) const;
	const Fixed operator-(const Fixed& rhs) const;
	const Fixed operator*(const Fixed& rhs) const;
	const Fixed operator/(const Fixed& rhs) const;
	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);
	static Fixed& min(Fixed& v1, Fixed& v2);
	static const Fixed& min(const Fixed& v1, const Fixed& v2);
	static Fixed& max(Fixed& v1, Fixed& v2);
	static const Fixed& max(const Fixed& v1, const Fixed& v2);

private:
	int fixed_point_number_;
	static const int fractional_bit_ = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& rhs);

#endif /* *********************************************************** FIXED_H */