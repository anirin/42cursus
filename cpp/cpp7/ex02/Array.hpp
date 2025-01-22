#pragma once

#include <iostream>
#include <string>

template <typename T> class Array {
public:
	Array();
	Array(size_t n);
	Array(Array const& src);
	~Array();

	size_t size() const;

	Array& operator=(Array const& rhs) const;
	T& operator[](size_t index) const;

private:
	T* _array;
	size_t _size;
};

#include "Array.tpp"