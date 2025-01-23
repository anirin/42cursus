#pragma once

#include <iostream>
#include <string>

template <typename T> void easyfind(T input, int num) {
	if (std::find(input.begin(), input.end(), num) == input.end()) {
		throw std::runtime_error("Target not found");
	} else {
		std::cout << "Target found" << std::endl;
	}

	return;
}