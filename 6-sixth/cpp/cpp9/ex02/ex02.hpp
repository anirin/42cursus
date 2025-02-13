#pragma once

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

class Chain {
private:
	int num;
	std::vector<Chain*> pairs;

public:
	Chain();
	Chain(int num, Chain *chain) : num(num) {
		pairs.push_back(chain);
	}
	~Chain();

	bool operator>(Chain& other) const { return num > other.getNum(); }
	bool operator<(Chain& other) const { return num < other.getNum(); }
	bool operator==(Chain& other) const { return num == other.getNum(); }
	bool operator!=(Chain& other) const { return num != other.getNum(); }


	int getNum() {
		if (pairs.size() == 0)
			return -1;
		return num;
	}

	std::vector<Chain*> &getHead() {
		return pairs;
	}

	Chain* &getPair(int layer_index) {
		return pairs[layer_index];
	}
};


struct Layer {
	bool hasRest;
	Chain *rest;

	bool hasTop;
	Chain *top;
};

void printChain(Chain *chain, int indent);
void printChainArray(std::vector<Chain*> array);
void printLayer(std::vector<Layer> layers);