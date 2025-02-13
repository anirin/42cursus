#include "Chain.hpp"
#include "util.hpp"

size_t b_count = 0;

void insertChain(std::vector<Chain*>& array, Chain* chain, size_t index)	 // copyによって省力化を図ることはできる
{
	// std::cout << "Insert " << chain->getNum() << " at " << index << std::endl; // debug

	std::vector<Chain*> new_array;

	for (size_t i = 0; i < array.size(); i++) {
		if (i == index)
			new_array.push_back(chain);
		new_array.push_back(array[i]);
	}
	if (index == array.size()) {
		new_array.push_back(chain);
	}

	array.clear();
	array = new_array;
}

size_t binarySearch(std::vector<Chain*> array, size_t start_index, size_t end_index, Chain* node) {
	size_t size = end_index - start_index + 1;
	size_t center_index;
	center_index = size / 2 + start_index;

	b_count++;

	if (*array[center_index] < *node) {
		if (center_index == end_index)
			return center_index + 1;
		return binarySearch(array, center_index + 1, end_index, node);
	} else {
		if (center_index == start_index)
			return center_index;
		return binarySearch(array, start_index, center_index - 1, node);
	}
}

void insertPart(std::vector<Chain*>& small_array, size_t insert_size, size_t base, std::vector<Chain*>& array, size_t end)
{
	for (size_t i = 0; i < insert_size; i++) {
		Chain* node = small_array[insert_size - i + base];
		size_t insert_index = binarySearch(array, 0, end, node);

		insertChain(array, node, insert_index);
	}

	// std::cout << "b_count: " << b_count << std::endl; // debug
}
