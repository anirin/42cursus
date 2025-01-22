#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>

class Span
{

	public:

		Span();
		Span(unsigned int max);
		Span( Span const & src );
		~Span();

		Span &		operator=( Span const & rhs );

		void addNumber(unsigned int num);
		void shortestSpan();
		void longestSpan();

	private:
		std::vector<unsigned int> _numbers;
		unsigned int _max;
};

std::ostream &			operator<<( std::ostream & o, Span const & i );

#endif /* ************************************************************ SPAN_H */