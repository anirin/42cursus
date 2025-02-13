#include "Chain.hpp"

// constructor

Chain::Chain() : _num(-1) {
	_pairs.clear();	 // pairsにnull入れたい
}

Chain::Chain(size_t _num, Chain* chain) : _num(_num) {
	_pairs.push_back(chain);
}

Chain::~Chain() {
	_pairs.clear();	 // new したものを delete する必要あり
}

// operator

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