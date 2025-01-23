#include "easyfind.hpp"
#include <array>
#include <list>
#include <vector>

int main() {
	std::array<int, 5> a = {1, 11, 111, 1111, 11111};

	std::vector<int> v;
	v.push_back(1);
	v.push_back(11);
	v.push_back(111);
	v.push_back(1111);
	v.push_back(11111);

	std::list<int> ls;
	ls.push_front(1);
	ls.push_front(11);
	ls.push_front(111);
	ls.push_front(1111);

	std::cout << " ============ array ============ " << std::endl;
	try {
		easyfind(a, 1111);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		easyfind(a, 12);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << " =========== vector =========== " << std::endl;
	try {
		easyfind(v, 1111);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		easyfind(v, 12);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << " ============ list ============ " << std::endl;
	try {
		easyfind(ls, 1111);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		easyfind(ls, 12);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}