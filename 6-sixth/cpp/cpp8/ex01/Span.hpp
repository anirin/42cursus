#pragma once

#include <iostream>
#include <string>
#include <ranges>

class Span {
public:
	Span();
	Span(unsigned int max);
	Span(Span const& src);
	~Span();

	Span& operator=(Span const& rhs);

	void addNumber(unsigned int num);
	void shortestSpan();
	void longestSpan();
	void randomFill();

private:
	std::vector<unsigned int> _numbers;
	unsigned int _max;
};

std::ostream& operator<<(std::ostream& o, Span const& i);