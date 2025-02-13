#pragma once

#include <vector>

class Chain {
private:
	size_t _num;
	std::vector<Chain*> _pairs;

public:
	// constructor
	Chain();
	Chain(size_t num, Chain* chain);
	~Chain();

	// operator
	bool operator>(Chain& other) const;
	bool operator<(Chain& other) const;
	bool operator==(Chain& other) const;
	bool operator!=(Chain& other) const;

	// getter
	size_t getNum();
	std::vector<Chain*>& getHead();
	Chain*& getPair(size_t layer_index);
};