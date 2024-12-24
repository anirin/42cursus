#ifndef EASYFIND_H
#define EASYFIND_H

#include <iostream>
#include <string>


template <typename T> void easyfind(T input, int num) {
	typename T::iterator p = std::find(input.begin(), input.end(), num);

	if (p == input.end()) {
		std::cout << "Target not found" << std::endl;
	} else {
		std::cout << "Target found" << std::endl;
	}

	return;
}

#endif