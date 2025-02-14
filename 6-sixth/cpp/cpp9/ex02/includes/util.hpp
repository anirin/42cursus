#pragma once

#include <cstdlib>
#include <ctime>
#include <iostream>

#include <list>

#include "Chain.hpp"

struct Layer {
	bool hasRest;
	Chain* rest;

	bool hasTop;
	Chain* top;
};

// insertPart.cpp
void insertPart(std::vector<Chain*>& small_array, size_t insert_size, size_t base, std::vector<Chain*>& array, size_t end);
void insertPart(std::list<Chain*>& small_array, size_t insert_size, size_t base, std::list<Chain*>& array, size_t end);

// makeLayer.cpp
void makeLayer(std::vector<Chain*>& array, std::vector<Layer>& layers);
void makeLayer(std::list<Chain*>& array, std::vector<Layer>& layers);

// mergePart.cpp
void mergePart(std::vector<Chain*>& array, std::vector<Layer> layers, size_t layer_index);
void mergePart(std::list<Chain*>& array, std::vector<Layer> layers, size_t layer_index);

// sort.cpp
Chain* getTop(std::vector<Layer> layers);
void sort(std::vector<Chain*> array, std::vector<Chain*>& sorted);
void sort(std::list<Chain*> array, std::list<Chain*>& sorted);

Chain* &getListNode(std::list<Chain*>& array, int n);

// debug
void printChain(Chain* chain, size_t indent);
void printChainArray(std::vector<Chain*> array);
void printChainList(std::list<Chain*> array);
void printNums(std::vector<int> array);
void printLayer(std::vector<Layer> layers);