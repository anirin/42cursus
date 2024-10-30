#include <iostream>

int main() {
	std::string str = "HI THIS IS BRAIN";
	std::string *strPTR = &str;
	std::string &strREF = str;

	std::cout << "Address" << std::endl;
	std::cout << "Str : " << &str << std::endl;
	std::cout << "Ptr : " << strPTR << std::endl;
	std::cout << "Ref : " << &strREF << std::endl;

	std::cout << "Value" << std::endl;
	std::cout << "Str : " << str << std::endl;
	std::cout << "Ptr : " << *strPTR << std::endl;
	std::cout << "Ref : " << strREF << std::endl;

	return 0;
}