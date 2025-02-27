#include <exception>
#include <iomanip>
#include "RPN.hpp"

int main(int argc, char* argv[])
{
	std::string input;
	RPN rpn;
	double ret;

	if (argc != 2)
	{
		std::cerr << "Usage: ./RPN \"[RPN expression]\"" << std::endl;
		return 1;
	}

	input = argv[1];

	try {
		ret = rpn.rpn(input);
	}
	catch (std::invalid_argument& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	std::cout << "Result: " << ret << std::endl;

	return 0;
}