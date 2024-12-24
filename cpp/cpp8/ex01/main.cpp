#include "Span.hpp"
#include <ranges>


int main() {
	Span sp1 = Span(5);
	try {
		sp1.addNumber(6);
		sp1.addNumber(3);
		sp1.addNumber(17);
		sp1.addNumber(9);
		sp1.addNumber(11);
		sp1.shortestSpan();
		sp1.longestSpan();
	} catch (const char *e) {
		std::cout << e << std::endl;
	}

	Span sp2 = Span(10000);
	try {
		for (unsigned int i = 0; i < 10000; i++) {
			sp2.addNumber(rand() % 1000);
		}
		sp2.shortestSpan();
		sp2.longestSpan();
	} catch (const char *e) {
		std::cout << e << std::endl;
	}

	// error
	Span sp3 = Span(1);
	try {
		sp3.shortestSpan();
	} catch (const char *e) {
		std::cout << e << std::endl;
	}
}
