#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class Base {
public:
	Base();
	virtual ~Base();

	static Base* generate();
	static void identify(Base* p);
	static void identify(Base& p);

private:
};

#endif /* ************************************************************ BASE_H */