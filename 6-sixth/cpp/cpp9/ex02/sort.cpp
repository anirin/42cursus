#include "Chain.hpp"
#include "util.hpp"

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
}