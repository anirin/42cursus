#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <iostream>
#include <string>

class Cat : public Animal {
public:
	Cat();
	Cat(Cat const& src);
	~Cat();

	Cat& operator=(Cat const& rhs);

	void makeSound();

private:
};

#endif /* ************************************************************* CAT_H */