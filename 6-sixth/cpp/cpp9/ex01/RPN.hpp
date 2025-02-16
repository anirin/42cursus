#pragma once

#include <stack>

#include <iostream>

class RPN
{
private:
	// size_t _ret;
	std::stack<char> _stack;

public:
	RPN();
	~RPN();

	double rpn(std::string arg);
};