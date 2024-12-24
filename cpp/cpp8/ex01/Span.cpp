#include "Span.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span() : _max(0)
{
	_numbers.reserve(0);
}

Span::Span(unsigned int max) : _max(max)
{
	_numbers.reserve(max);
}

Span::Span( const Span & src )
{
	if (this != &src) {
		_max = src._max;
		_numbers = src._numbers;
	}
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Span::~Span()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Span &				Span::operator=( Span const & rhs )
{
	if ( this != &rhs )
	{
		this->_max = rhs._max;
		this->_numbers = rhs._numbers;
	}
	return *this;
}



/*
** --------------------------------- METHODS ----------------------------------
*/

void Span::addNumber(unsigned int num) {
	if (_numbers.size() > _max) {
		throw "size out of range";
	}

	_numbers.push_back(num);
	return ;
}

void Span::shortestSpan() {
	if (_numbers.size() < 2) {
		throw "size is less than 2";
	}

	unsigned int ret = 0;
	sort(_numbers.begin(), _numbers.end());
	for (unsigned int i = 0; i < _max - 1; i++) {
		unsigned int span = _numbers[i + 1]- _numbers[i];
		if (ret < span) {
			ret = span;
		}
	}
	std::cout << "min span : " << ret << std::endl;
	return ;
}

void Span::longestSpan() {
	if (_numbers.size() < 2) {
		throw "size is less than 2";
	}

	unsigned int ret = 0;
	sort(_numbers.begin(), _numbers.end());
	ret = _numbers[_max - 1] - _numbers[0];
	std::cout << "max span : " << ret << std::endl;
	return ;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */