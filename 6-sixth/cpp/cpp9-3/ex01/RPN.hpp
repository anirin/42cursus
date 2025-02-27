#pragma once

#include <stack>
#include <iostream>
#include <limits>

class RPN
{
private:
	std::stack<char> _stack;

public:
	RPN();
	RPN(const RPN &other);
	~RPN();

	RPN &operator=(const RPN &other);

	double rpn(std::string arg);
};