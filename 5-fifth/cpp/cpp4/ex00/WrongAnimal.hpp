#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include <iostream>
#include <string>

class WrongAnimal {
public:
	WrongAnimal();
	WrongAnimal(WrongAnimal const& src);
	~WrongAnimal();
	WrongAnimal& operator=(WrongAnimal const& rhs);
	void makeSound();

protected:
	std::string type_;

private:
};

#endif /* ***************************************************** WRONGANIMAL_H */