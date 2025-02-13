#include "Chain.hpp"
#include "util.hpp"

std::vector<Chain*> initChain(size_t size, size_t range) {
	std::vector<Chain*> chains;

	srand((unsigned)time(NULL));

	for (size_t i = 0; i < size; i++) {
		Chain* chain = new Chain(rand() % range + 1, NULL);
		chains.push_back(chain);
	}
	return chains;
}

bool isSorted(std::vector<Chain*> array) {
	for (size_t i = 0; i < array.size() - 1; i++) {
		if (*array[i] > *array[i + 1])
			return false;
	}
	return true;
}

int main() {
	size_t size = 1;
	size_t length = 5000;
	size_t range = 10000;

	for (size_t i = 0; i < size; i++) {
		std::vector<Chain*> chains;
		std::vector<Chain*> sorted_array;

		chains = initChain(length - i, range);

		sort(chains, sorted_array);

		if (!isSorted(sorted_array)) {
			std::cout << "Not Sorted!" << std::endl;
			break;
		}
		if (i == size - 1) {
			std::cout << "All Sorted!" << std::endl;
		}
	}
	return 0;
}
