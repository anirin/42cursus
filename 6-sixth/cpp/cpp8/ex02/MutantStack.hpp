#pragma once

#include <deque>
#include <iostream>
#include <stack>
#include <string>

template <typename T> class MutantStack : public std::stack<T> {
public:
	MutantStack();
	MutantStack(MutantStack const& src);
	~MutantStack();

	MutantStack& operator=(MutantStack const& rhs);

	// iterator型宣言
	typedef typename std::deque<T>::iterator iterator;

	// iteratorを返すbegin, endメンバ関数
	iterator begin();
	iterator end();

private:
};

#include "MutantStack.tpp"