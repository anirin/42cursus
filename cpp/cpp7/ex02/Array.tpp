#include "Array.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

template <typename T> Array<T>::Array() : _array(new T[0]()), _size(0) {}

template <typename T> Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n) {}

template <typename T> Array<T>::Array(const Array& src) : _array(new T[src._size]()), _size(src._size) {
	for (size_t i = 0; i < _size; i++) {
		_array[i] = src._array[i];
	}
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

template <typename T> Array<T>::~Array() {
	delete[] _array;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

template <typename T> Array<T>& Array<T>::operator=(Array const& rhs) {
	if (this != &rhs) {
		delete[] _array;
		_array = new T[rhs._size]();
		_size = rhs._size;
		for (size_t i = 0; i < _size; i++) {
			_array[i] = rhs._array[i];
		}
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

//todo templateを２つ作る必要あり
template <typename T> const T& Array<T>::operator[](unsigned int index) {
	if (index >= _size) {
		throw "Index out of range";
	}
	return _array[index];
}

template <typename T> unsigned int Array<T>::size() const {
	return _size;
}

/* ************************************************************************** */