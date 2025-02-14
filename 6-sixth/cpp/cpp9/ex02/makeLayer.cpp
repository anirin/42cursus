#include "Chain.hpp"
#include "util.hpp"

size_t c_count = 0;

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

		c_count++;

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

		c_count++;

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