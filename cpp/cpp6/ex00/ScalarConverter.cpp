#include "ScalarConverter.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter( const ScalarConverter & src )
{
	(void)src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScalarConverter::~ScalarConverter()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScalarConverter &				ScalarConverter::operator=( ScalarConverter const & rhs )
{
	(void)rhs;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

bool is_invalid_format(std::string input) {
	if (!input.empty() && input[input.length() - 1] == '.') {
		return true;
	}
	return false;
}

void convert_char(double value) {
	char c = static_cast<unsigned char>(static_cast<int>(value));
	std::cout << "char: ";
	if (std::isprint(c)) {
		std::cout << c;
	} else if (std::iscntrl(c)) {
		std::cout << "Non displayable";
	} else {
		std::cout << "'*'";
	}
	std::cout << std::endl;
}

void convert_int(double value) {
	if (value <= std::numeric_limits<int>::max() && value >= std::numeric_limits<int>::min()) {
		int i = static_cast<int>(value);
		std::cout << "int: " << i << std::endl;
	} else {
		std::cout << "int: out of range" << std::endl;
	}
}

void convert_float(double value) {
	float f = static_cast<float>(value);
	if (f <= std::numeric_limits<float>::max() && f >= std::numeric_limits<float>::lowest()) {
		std::cout << "float: ";
		if (std::floor(f) == f) {
			std::cout << std::fixed << std::setprecision(1);
		}
		if (static_cast<double>(f) != value) {
			std::cout << f << "f (precision loss)" << std::endl;
		} else {
			std::cout << f << "f" << std::endl;
		}
	} else {
		std::cout << "float: out of range" << std::endl;
	}
}

void convert_double(double value) {
	std::cout << "double: ";
	if (std::floor(value) == value) {
		std::cout << std::fixed << std::setprecision(1);
	}
	std::cout << value << std::endl;
}

void ScalarConverter::convert(std::string input) {
	if (!input.empty() && input[input.length() - 1] == 'f' && input != "-inf" && input != "+inf" && input != "f") {
		input = input.substr(0, input.length() - 1);
	}

	if (is_invalid_format(input)) {
		std::cout << "invalid format" << std::endl;
		return;
	}

	if (input == "+inf" || input == "-inf" || input == "nan") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << input << "f" << std::endl;
		std::cout << "double: " << input << std::endl;
		return ;
	}


	if (input.length() == 1 && std::isalpha(input[0])) {
		char c = input[0];
		convert_char(c);
		convert_int(c);
		convert_float(c);
		convert_double(c);
		return ;
	}

	std::stringstream ss(input);
	double value = 0.0;
	if (ss >> value && ss.peek() == EOF) {
		convert_char(value);
		convert_int(value);
		convert_float(value);
		convert_double(value);
	} else {
		std::cout << "invalid format" << std::endl;
	}
	return ;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */