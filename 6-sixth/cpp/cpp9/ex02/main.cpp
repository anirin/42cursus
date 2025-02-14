#include "PmergeMe.hpp"

// ======================================= main =======================================

std::vector<int> initArray(size_t size, size_t range) {
	std::vector<int> array;

	srand((unsigned)time(NULL));

	for (size_t i = 0; i < size; i++) {
		array.push_back(rand() % range + 1);
	}
	return array;
}

std::vector<Chain*> initChainVector(std::vector<int> array) {
	std::vector<Chain*> chains;

	for (size_t i = 0; i < array.size(); i++) {
		Chain* chain = new Chain(array[i], NULL);
		chains.push_back(chain);
	}

	return chains;
}

std::list<Chain*> initChainList(std::vector<int> array) {
	std::list<Chain*> chains;

	for (size_t i = 0; i < array.size(); i++) {
		Chain* chain = new Chain(array[i], NULL);
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

bool isSorted(std::list<Chain*> array) {
	std::list<Chain*>::iterator it = array.begin();
	std::list<Chain*>::iterator it_next = array.begin();
	it_next++;
	for (; it_next != array.end(); it++, it_next++) {
		if (**it > **it_next)
			return false;
	}
	return true;
}

// ======================================= main =======================================
#include <sstream>

std::vector<int> convertToVector(int argc, char* argv[]) {
	std::vector<int> array;

	if (argc < 2) {
		std::cerr << "Error: Please enter integers." << std::endl;
		exit(1);
	}

	for (int i = 1; i < argc; i++) {
		std::stringstream ss;
		ss << argv[i];
		int num;

		if (!(ss >> num)) {
			std::cerr << "Error: Invalid input \"" << argv[i] << "\". Please enter valid integers." << std::endl;
			exit(1);
		}

		if (num < 0) {
			std::cerr << "Error: Negative value \"" << argv[i] << "\" is not allowed." << std::endl;
			exit(1);
		}

		array.push_back(num);
	}

	return array;
}

int main(int argc, char* argv[]) {
	// size_t size = 1;
	// size_t length = 21;
	// size_t range = 1000;

	std::vector<Chain*> chains;
	std::vector<Chain*> sorted_array;

	std::list<Chain*> list_chains;
	std::list<Chain*> list_sorted_array;

	// std::vector<int> array = initArray(length, range);
	std::vector<int> array = convertToVector(argc, argv);

	chains = initChainVector(array);
	list_chains = initChainList(array);

	std::cout << "before :";
	printNums(array);

	clock_t v_start = std::clock();
	sort(chains, sorted_array);	 // vector
	clock_t v_end = std::clock();

	std::cout << "after  :";
	printChainArray(sorted_array);

	// if (!isSorted(sorted_array)) {
	// 	std::cout << "Vector Not Sorted!" << std::endl;
	// 	break;
	// }
	// if (i == size - 1) {
	// 	std::cout << "Vector All Sorted!" << std::endl;
	// }

	clock_t l_start = std::clock();
	sort(list_chains, list_sorted_array);  // list
	clock_t l_end = std::clock();

	// std::cout << "after  :";
	// printChainList(list_sorted_array);

	std::cout << "Vector Time : " << (double)(v_end - v_start) / CLOCKS_PER_SEC << "s" << std::endl;
	std::cout << "List   Time : " << (double)(l_end - l_start) / CLOCKS_PER_SEC << "s" << std::endl;

	// if (!isSorted(list_sorted_array)) {
	// 	std::cout << "List Not Sorted!" << std::endl;
	// 	break;
	// }
	// if (i == size - 1) {
	// 	std::cout << "List All Sorted!" << std::endl;
	// }

	return 0;
}
