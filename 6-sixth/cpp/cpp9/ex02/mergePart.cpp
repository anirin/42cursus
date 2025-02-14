#include "Chain.hpp"
#include "util.hpp"

size_t d_jacob[] = {0,	  2,	 2,		6,	   10,	  22,	  42,	  86,	  170,	   342,		682,	 1366,	  2730,
					5462, 10922, 21846, 43690, 87382, 174762, 349526, 699050, 1398102, 2796202, 5592406, 11184810};
size_t node_num[] = {0,		 1,		 3,		  7,	   15,		31,		 63,	  127,	 255,
					 511,	 1023,	 2047,	  4095,	   8191,	16383,	 32767,	  65535, 131071,
					 262143, 524287, 1048575, 2097151, 4194303, 8388607, 16777215};
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

size_t getEnd(size_t count, std::vector<Chain*> array) {
	size_t end;

	if (node_num[count + 2] < array.size())	 // node_num[1] = 3, 7 ....
		end = node_num[count + 2] - 1;
	else
		end = array.size() - 1;

	return end;
}

size_t getInsertSize(size_t s_size, size_t count) {
	size_t insert_size;

	if (d_jacob[count + 1] < s_size)  // d_jacob[1] = 2, 2, 6 ....
		insert_size = d_jacob[count + 1];
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

		size_t end = getEnd(count, array);
		size_t insert_size = getInsertSize(s_size, count);

		insertPart(small_array, insert_size, base, array, end);

		s_size -= insert_size;
		base += insert_size;
		count++;
	}
}