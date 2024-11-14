#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed
{

	public:
		Fixed();
		Fixed( Fixed const & src );
		~Fixed();
		Fixed &		operator=( Fixed const & rhs );
		int getRawBits() const;
		void setRawBits( int const raw);

	private:
		int fixed_point_number_;
		static const int fractional_number_ = 8;

};

#endif /* *********************************************************** FIXED_H */