#include "Span.hpp"


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
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	Span sp2 = Span(10000);
	sp2.randomFill();
	try {
		sp2.shortestSpan();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		sp2.longestSpan();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	// error case
	Span sp3 = Span(1);
	try {
		sp3.addNumber(1);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		sp3.shortestSpan();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		sp3.longestSpan();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		sp3.addNumber(2);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
