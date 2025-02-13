#include "ex02.hpp"

int d_jacob[] = {0,2,2,6,10,22,42,86,170,342,682,1366,2730,5462,10922,21846,43690,87382,174762,349526,699050,1398102,2796202,5592406,11184810};
int node_num[] = {0,1,3,7,15,31,63,127,255,511,1023,2047,4095,8191,16383,32767,65535,131071,262143,524287,1048575,2097151,4194303,8388607,16777215};
// node_num の index がそのまま最大の比較回数となる

int comp_count = 0;
int max_comp_count = 0;

void insertPart(std::vector<Chain*> &array, Chain *chain, int index) // copyによって省力化を図ることはできる
{
	std::cout << "Insert " << chain->getNum() << " at " << index << std::endl;

	std::vector<Chain*> new_array;

	for (int i = 0; i < array.size(); i++) {
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

int binarySearch(std::vector<Chain*> array, int start_index, int end_index, Chain *node)
{
	int size = end_index - start_index + 1;
	int center_index;
	center_index = size / 2 + start_index;

	comp_count++;

	if (*array[center_index] < *node)
	{
		if (center_index == end_index)
			return center_index + 1;
		return binarySearch(array, center_index + 1, end_index, node);
	}
	else
	{
		if (center_index == start_index)
			return center_index;
		return binarySearch(array, start_index, center_index - 1, node);
	}
}

void getSmallArrays(std::vector<Chain*> array, std::vector<Chain*> &small_chains, std::vector<Layer> layers, int layer_index)
{
	for (std::vector<Chain*>::iterator it = array.begin(); it != array.end(); ++it)
	{
		Chain* pair;
		pair = (*it)->getPair(layer_index);
		small_chains.push_back(pair);
	}
	if (layers[layer_index - 1].hasRest)
	{
		small_chains.push_back(layers[layer_index - 1].rest);
	}
}

int getEnd(int count, std::vector<Chain*> array)
{
	int end;

	if (node_num[count + 2] < array.size()) // node_num[1] = 3, 7 ....
		end = node_num[count + 2] - 1;
	else
		end = array.size() - 1;

	return end;
}

int getInsertSize(int s_size, int count)
{
	int insert_size;

	if (d_jacob[count + 1] < s_size) // d_jacob[1] = 2, 2, 6 ....
		insert_size = d_jacob[count + 1];
	else
		insert_size = s_size;
	
	return insert_size;
}

// あくまでも２つのソート済み配列をマージする関数
void mergePart(std::vector<Chain*> &array, std::vector<Layer> layers, int layer_index)
{
	if (layer_index == 0)
		return;

	std::vector<Chain*> small_array;
	int s_size;
	int count = 0;
	int base = 0;

	getSmallArrays(array, small_array, layers, layer_index);
	s_size = small_array.size();

	std::cout << "[big array] : "; printChainArray(array);
	std::cout << "[small array] : "; printChainArray(small_array);

	insertPart(array, small_array[0], 0);
	s_size--;

	for (;;)
	{
		if (s_size == 0)
			break;

		int end = getEnd(count, array);
		int insert_size = getInsertSize(s_size, count);

		max_comp_count += insert_size * (count + 2);

		std::cout << " ======== End: " << end << ", Insert Size: " << insert_size << " ========" << std::endl;
		for (int i = 0; i < insert_size; i++)
		{
			Chain* node = small_array[insert_size - i + base];
			int insert_index = binarySearch(array, 0, end, node);

			insertPart(array, node, insert_index);
			s_size--;
		}

		base += insert_size;
		count++;
	}
}

Chain* getTop(std::vector<Layer> layers)
{
	for (int i = 0; i < layers.size(); i++)
	{
		if (layers[i].hasTop)
			return layers[i].top;
	}
	return NULL;
}

void sort(std::vector<Chain*> &array, std::vector<Layer> layers)
{
	Chain *top = getTop(layers);
	array.push_back(top);

	int layer_size = layers.size();

	for (int i = layer_size - 1; i >= 0; --i)
	{
		std::cout << "===== Layer Index: " << i << " =====" << std::endl;
		mergePart(array, layers, i);
	}
}

void makeLayer(std::vector<Chain*> &array, std::vector<Layer> &layers)
{
	printChainArray(array);

	int i = 0;
	int size = array.size();
	std::vector<Chain*> new_array;
	Layer layer;

	layer.hasRest = false;
	layer.hasTop = false;
	if (size == 1)
	{
		layer.hasTop = true;
		layer.top = array[0];
		layers.push_back(layer);
		return;
	}
	else if (size % 2 == 1)
	{
		layer.hasRest = true;
		layer.rest = array[size - 1];
	}
	layers.push_back(layer);

	while (1)
	{
		if (i + 1 > size - 1)
			break;

		Chain *big_chain;
		if (*array[i] > *array[i + 1])
		{
			array[i]->getHead().push_back(array[i + 1]);
			big_chain = array[i];
		}
		else
		{
			array[i + 1]->getHead().push_back(array[i]);
			big_chain = array[i + 1];
		}
		new_array.push_back(big_chain);
		i += 2;
	}
	makeLayer(new_array, layers);
}


std::vector<Chain*> initChain(int size, int range)
{
	std::vector<Chain*> chains;

	srand((unsigned)time(NULL));

	for (int i = 0; i < size; i++)
	{
		Chain *chain = new Chain(rand() % range, NULL);
		chains.push_back(chain);
	}
	return chains;
}

bool isSorted(std::vector<Chain*> array)
{
	for (int i = 0; i < array.size() - 1; i++)
	{
		if (*array[i] > *array[i + 1])
			return false;
	}
	return true;
}

int main()
{
	int size = 1;
	int length = 600;
	int range = 1000000;

	for (int i = 0; i < size; i++)
	{
		std::vector<Chain*> chains;
		std::vector<Layer> layers;

		chains = initChain(length - i, range);

		printChainArray(chains);

		makeLayer(chains, layers);

		std::cout << "======================" << std::endl << std::endl;
		printLayer(layers);

		std::cout << "======================" << std::endl << std::endl;
		printChain(getTop(layers), 0);

		std::cout << "======================" << std::endl << std::endl;
		std::vector<Chain*> sorted_array;
		sort(sorted_array, layers);
		printChainArray(sorted_array);
		
		std::cout << "max comp count: " << max_comp_count << ", comp count: " << comp_count << std::endl;

		if (!isSorted(sorted_array))
		{
			std::cout << "Not Sorted!" << std::endl;
			break;
		}
		if (i == size - 1)
		{
			std::cout << "All Sorted!" << std::endl;
		}
	}
	return 0;
}
