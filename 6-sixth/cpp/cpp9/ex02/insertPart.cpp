#include "Chain.hpp"
#include "util.hpp"

size_t b_count = 0;

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

size_t binarySearch(std::list<Chain*> array, size_t start_index, size_t end_index, Chain* node) {
	size_t size = end_index - start_index + 1;
	size_t center_index;
	center_index = size / 2 + start_index;

	b_count++;

	if (*getListNode(array, center_index) < *node) {
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

		array.insert(array.begin() + insert_index, node);
	}

	// std::cout << "b_count: " << b_count << std::endl; // debug
}

void insertPart(std::list<Chain*>& small_array, size_t insert_size, size_t base, std::list<Chain*>& array, size_t end)
{
	for (size_t i = 0; i < insert_size; i++) {
		Chain* node = getListNode(small_array, insert_size - i + base);
		size_t insert_index = binarySearch(array, 0, end, node);

		std::list<Chain*>::iterator it = array.begin();
		std::advance(it, insert_index);
		array.insert(it, node);
	}

	// std::cout << "b_count: " << b_count << std::endl; // debug
}