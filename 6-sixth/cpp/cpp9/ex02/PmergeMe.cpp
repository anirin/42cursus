#include "PmergeMe.hpp"

int list_count = 0;
int vector_count = 0;
int max_count = 0;

// ======================================= Print =======================================

void printChain(Chain* chain, size_t indent) {
	if (chain == NULL)
		return;

	for (size_t i = 0; i < indent; i++)
		std::cout << "         ";
	std::cout << " [" << chain->getNum() << "]" << std::endl;

	if (chain->getHead().size() > 0) {
		for (size_t i = 0; i < chain->getHead().size(); i++) {
			printChain(chain->getPair(i), indent + 1);
		}
	}
}

void printChainArray(std::vector<Chain*> array) {
	// std::cout << "Chain Array: ";
	for (std::vector<Chain*>::iterator i = array.begin(); i != array.end(); i++) {
		std::cout << (*i)->getNum() << " ";
	}
	std::cout << std::endl;
}

void printChainList(std::list<Chain*> array) {
	// std::cout << "Chain List: ";
	for (std::list<Chain*>::iterator i = array.begin(); i != array.end(); i++) {
		std::cout << (*i)->getNum() << " ";
	}
	std::cout << std::endl;
}

void printNums(std::vector<int> array) {
	for (std::vector<int>::iterator i = array.begin(); i != array.end(); i++) {
		std::cout << *i << " ";
	}
	std::cout << std::endl;
}

void printLayer(std::vector<Layer> layers) {
	for (size_t i = 0; i < layers.size(); i++) {
		std::cout << " ======== Layer: " << i << std::endl;
		if (layers[i].hasTop) {
			std::cout << "Top: " << layers[i].top->getNum() << std::endl;
		}
		if (layers[i].hasRest) {
			std::cout << "Rest: " << layers[i].rest->getNum() << std::endl;
		}
	}
}

// ======================================= Chain =======================================

// constructor

Chain::Chain() : _num(-1) {
	_pairs.clear();	 // pairsにnull入れたい
}

Chain::Chain(size_t _num, Chain* chain) : _num(_num) {
	_pairs.push_back(chain);
}

Chain::Chain(const Chain& other) {
	if (this == &other)
		return;
	_num = other._num;
	_pairs = other._pairs;
}

Chain::~Chain() {
	_pairs.clear();	 // new したものを delete する必要あり
}

// operator

Chain& Chain::operator=(const Chain& other) {
	if (this == &other)
		return *this;
	_num = other._num;
	_pairs = other._pairs;
	return *this;
}

bool Chain::operator>(Chain& other) const {
	return _num > other.getNum();
}
bool Chain::operator<(Chain& other) const {
	return _num < other.getNum();
}
bool Chain::operator==(Chain& other) const {
	return _num == other.getNum();
}
bool Chain::operator!=(Chain& other) const {
	return _num != other.getNum();
}

// getter

size_t Chain::getNum() {
	return _num;
}

std::vector<Chain*>& Chain::getHead() {
	return _pairs;
}

Chain*& Chain::getPair(size_t layer_index) {
	return _pairs[layer_index];
}

// ======================================= insertPart =======================================

size_t binarySearch(std::vector<Chain*> array, size_t start_index, size_t end_index, Chain* node) {
	size_t size = end_index - start_index + 1;
	size_t center_index;
	center_index = size / 2 + start_index;

	vector_count++;

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

	list_count++;

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

// ======================================= mergePart =======================================

size_t doubleJacobsthal(size_t n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 2 * 1;
	return 2 * doubleJacobsthal(n - 1) + doubleJacobsthal(n - 2);
}

size_t powerOfTwoMinusOne(size_t n) {
	return (static_cast<size_t>(1) << n) - 1;
}
// node_num の index がそのまま最大の比較回数となる

void getSmallArrays(std::vector<Chain*> array, std::vector<Chain*>& small_chains, std::vector<Layer> layers,
					size_t layer_index) {
	for (std::vector<Chain*>::iterator it = array.begin(); it != array.end(); ++it) {
		Chain* pair;
		pair = (*it)->getPair(layer_index);
		small_chains.push_back(pair);
	}
	if (layers[layer_index - 1].hasRest) {
		small_chains.push_back(layers[layer_index - 1].rest);
	}
}

void getSmallLists(std::list<Chain*> array, std::list<Chain*>& small_chains, std::vector<Layer> layers,
					size_t layer_index) {
	for (std::list<Chain*>::iterator it = array.begin(); it != array.end(); ++it) {
		Chain* pair;
		pair = (*it)->getPair(layer_index);
		small_chains.push_back(pair);
	}
	if (layers[layer_index - 1].hasRest) {
		small_chains.push_back(layers[layer_index - 1].rest);
	}
}

size_t getEnd(size_t count, size_t array_size) {
	size_t end;

	if (powerOfTwoMinusOne(count + 2) < array_size)	 // node_num[1] = 3, 7 ....
		end = powerOfTwoMinusOne(count + 2) - 1;
	else
		end = array_size - 1;

	return end;
}

size_t getInsertSize(size_t s_size, size_t count) {
	size_t insert_size;

	if (doubleJacobsthal(count + 1) < s_size)  // d_jacob[1] = 2, 2, 6 ....
		insert_size = doubleJacobsthal(count + 1);
	else
		insert_size = s_size;

	return insert_size;
}

void mergePart(std::vector<Chain*>& array, std::vector<Layer> layers, size_t layer_index) {
	if (layer_index == 0)
		return;

	std::vector<Chain*> small_array;
	size_t s_size;
	size_t count = 0;
	size_t base = 0;

	getSmallArrays(array, small_array, layers, layer_index);
	s_size = small_array.size();

	// std::cout << "[big array] : "; // debug
	// printChainArray(array); // debug
	// std::cout << "[small array] : "; // debug
	// printChainArray(small_array); // debug

	array.insert(array.begin(), small_array[0]);
	s_size--;

	for (;;) {
		if (s_size == 0)
			break;

		size_t end = getEnd(count, array.size());
		size_t insert_size = getInsertSize(s_size, count);

		max_count += insert_size * (count + 2);

		insertPart(small_array, insert_size, base, array, end);

		s_size -= insert_size;
		base += insert_size;
		count++;
	}
}

void mergePart(std::list<Chain*>& array, std::vector<Layer> layers, size_t layer_index) {
	if (layer_index == 0)
		return;

	std::list<Chain*> small_array;
	size_t s_size;
	size_t count = 0;
	size_t base = 0;

	getSmallLists(array, small_array, layers, layer_index);
	s_size = small_array.size();

	// std::cout << "[big array] : "; // debug
	// printChainList(array); // debug
	// std::cout << "[small array] : "; // debug
	// printChainList(small_array); // debug

	array.push_front(getListNode(small_array, 0));
	s_size--;

	for (;;) {
		if (s_size == 0)
			break;

		size_t end = getEnd(count, array.size());
		size_t insert_size = getInsertSize(s_size, count);

		insertPart(small_array, insert_size, base, array, end);

		s_size -= insert_size;
		base += insert_size;
		count++;
	}
}

// ======================================= makeLayer =======================================

void makeLayer(std::vector<Chain*>& array, std::vector<Layer>& layers) {
	// printChainArray(array); // debug

	size_t i = 0;
	size_t size = array.size();
	std::vector<Chain*> new_array;
	Layer layer;

	layer.hasRest = false;
	layer.hasTop = false;
	if (size == 1) {
		layer.hasTop = true;
		layer.top = array[0];
		layers.push_back(layer);
		return;
	} else if (size % 2 == 1) {
		layer.hasRest = true;
		layer.rest = array[size - 1];
	}
	layers.push_back(layer);

	while (1) {
		if (i + 1 > size - 1)
			break;

		Chain* big_chain;

		vector_count++;
		max_count++;

		if (*array[i] > *array[i + 1]) {
			array[i]->getHead().push_back(array[i + 1]);
			big_chain = array[i];
		} else {
			array[i + 1]->getHead().push_back(array[i]);
			big_chain = array[i + 1];
		}
		new_array.push_back(big_chain);
		i += 2;
	}
	makeLayer(new_array, layers);

	// std::cout << "c_count: " << c_count << std::endl; // debug
}

Chain* &getListNode(std::list<Chain*>& array, int n) {
	std::list<Chain*>::iterator it = array.begin();

	for (int i = 0; i < n; i++) {
		it++;
	}

	return *it;
}

void makeLayer(std::list<Chain*>& array, std::vector<Layer>& layers) {
	// printChainArray(array); // debug

	size_t i = 0;
	size_t size = array.size();
	std::list<Chain*> new_array;
	Layer layer;

	layer.hasRest = false;
	layer.hasTop = false;
	if (size == 1) {
		layer.hasTop = true;
		layer.top = array.front();
		layers.push_back(layer);
		return;
	} else if (size % 2 == 1) {
		layer.hasRest = true;
		layer.rest = array.back();
	}
	layers.push_back(layer);

	while (1) {
		if (i + 1 > size - 1)
			break;

		Chain* big_chain;

		list_count++;

		Chain* chain1 = getListNode(array, i);
		Chain* chain2 = getListNode(array, i + 1);

		if (*chain1 > *chain2) {
			chain1->getHead().push_back(chain2);
			big_chain = chain1;
		} else {
			chain2->getHead().push_back(chain1);
			big_chain = chain2;
		}
		new_array.push_back(big_chain);
		i += 2;
	}
	makeLayer(new_array, layers);

	// std::cout << "c_count: " << c_count << std::endl; // debug
}

// ======================================= sort =======================================

Chain* getTop(std::vector<Layer> layers) {
	for (size_t i = 0; i < layers.size(); i++) {
		if (layers[i].hasTop)
			return layers[i].top;
	}
	return NULL;
}

void sort(std::vector<Chain*> array, std::vector<Chain*>& sorted) {
	std::vector<Layer> layers;

	makeLayer(array, layers);

	Chain* top = getTop(layers);
	sorted.push_back(top);

	size_t layer_size = layers.size();

	for (size_t i = layer_size - 1; i >= 0; --i) {
		// std::cout << "===== Layer Index: " << i << " =====" << std::endl; // debug
		mergePart(sorted, layers, i);
		if (i == 0)
			break;
	}

	// std::cout << "Max    Count : " << max_count << std::endl;
	// std::cout << "Vector Count : " << vector_count << std::endl << std::endl;
}

void sort(std::list<Chain*> array, std::list<Chain*>& sorted) {
	std::vector<Layer> layers;

	makeLayer(array, layers);

	Chain* top = getTop(layers);
	sorted.push_back(top);

	size_t layer_size = layers.size();

	for (size_t i = layer_size - 1; i >= 0; --i) {
		// std::cout << "===== Layer Index: " << i << " =====" << std::endl; // debug
		mergePart(sorted, layers, i);
		if (i == 0)
			break;
	}

	std::cout << "Max    Count : " << max_count << std::endl;
	std::cout << "List   Count : " << list_count << std::endl << std::endl;
}