#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>

template <typename T> class Array {
public:
	Array();
	Array(size_t n);
	Array(Array const& src);
	~Array();

	size_t size() const;

	// todo constを書く必要あり
	Array& operator=(Array const& rhs);
	T& operator[](size_t index);

private:
	T* _array;
	size_t _size;
};


#endif /* *********************************************************** ARRAY_H */