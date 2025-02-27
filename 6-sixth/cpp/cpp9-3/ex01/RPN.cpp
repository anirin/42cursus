#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN &other)
{
	if (this == &other)
		return;
	_stack = other._stack;
	return ;
}

RPN::~RPN()
{
}

RPN &RPN::operator=(const RPN &other)
{
	if (this == &other)
		return *this;
	_stack = other._stack;
	return *this;
}

bool isValid(std::string string)
{
	if (string.size() == 1 && ((string[0] >= '0' && string[0] <= '9') || 
		(string[0] == '+' || string[0] == '-' || string[0] == '*' || string[0] == '/')))
	{
		return true;
	}
	return false;
}

void printStack(std::stack<double> stack)
{
	for (size_t i = 0; i < stack.size(); i++)
	{
		std::cout << stack.top() << " ";
		stack.pop();
	}
	std::cout << std::endl;
}

double RPN::rpn(std::string target)
{
	std::string separator = " ";

	std::stack<double> stack;
	std::string string;
	size_t pos;

	double back = 0.0;
	double front = 0.0;
	pos = 0;

	while (pos != std::string::npos)
	{
		// printStack(stack);


		pos = target.find(separator);
		string = target.substr(0, pos);
		target = target.substr(pos + separator.size());
		back = 0;
		front = 0;

		if(!isValid(string))
			throw std::invalid_argument("Invalid RPN expression (invalid character)");
		
		if (string.size() == 1 && ((string[0] >= '0' && string[0] <= '9')))
		{
			double num = string[0] - '0';
			stack.push(num);
			continue;
		}

		if (stack.size() < 2)
			throw std::invalid_argument("Invalid RPN expression + (not enough operands)");
		back = stack.top();
		stack.pop();
		front = stack.top();
		stack.pop();

		// std::cout << "-- front: " << front << " back: " << back << std::endl;

		switch (string[0])
		{
		case '+':
			if (front > 0 && front > std::numeric_limits<double>::max() - back)
				throw std::invalid_argument("Invalid RPN expression (overflow)");
			stack.push(front + back);
			break;
		case '-':
			if (front < 0 && front < -std::numeric_limits<double>::max() + back)
				throw std::invalid_argument("Invalid RPN expression (underflow)");
			stack.push(front - back);
			break;
		case '*':
			if (front < 0 && front < -std::numeric_limits<double>::max() / back)
				throw std::invalid_argument("Invalid RPN expression (underflow)");
			if (front > 0 && front > std::numeric_limits<double>::max() / back)
				throw std::invalid_argument("Invalid RPN expression (overflow)");
			
			// std::cout << front << " * " << back << " = " << front * back << std::endl;
			
			stack.push(front * back);
			break;
		case '/':
			if (back == 0)
				throw std::invalid_argument("Invalid RPN expression (division by zero)");

			// std::cout << front << " / " << back << " = " << front / back << std::endl;

			stack.push(front / back);
			break;
		default:
			throw std::invalid_argument("Invalid RPN expression (invalid operator)");
		}
	}

	if (stack.size() != 1)
		throw std::invalid_argument("Invalid RPN expression (too many numbers)");

	return stack.top();
}