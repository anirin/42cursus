#pragma once

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Chain.hpp"

struct Layer {
	bool hasRest;
	Chain* rest;

	bool hasTop;
	Chain* top;
};

// insertPart.cpp
void insertPart(std::vector<Chain*>& small_array, size_t insert_size, size_t base, std::vector<Chain*>& array, size_t end);

// makeLayer.cpp
void makeLayer(std::vector<Chain*>& array, std::vector<Layer>& layers);

// mergePart.cpp
void mergePart(std::vector<Chain*>& array, std::vector<Layer> layers, size_t layer_index);

// sort.cpp
Chain* getTop(std::vector<Layer> layers);
void sort(std::vector<Chain*> array, std::vector<Chain*>& sorted);

// debug
void printChain(Chain* chain, size_t indent);
void printChainArray(std::vector<Chain*> array);
void printLayer(std::vector<Layer> layers);