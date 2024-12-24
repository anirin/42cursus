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
	easyfind(a, 1);
	easyfind(a, 2);

	std::cout << "vector" << std::endl;
	easyfind(v, 1);
	easyfind(v, 2);

	std::cout << "list" << std::endl;
	easyfind(ls, 1);
	easyfind(ls, 2);

	return 0;
}