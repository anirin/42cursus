#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
public:
	Brain();
	Brain(Brain const& src);
	~Brain();

	Brain& operator=(Brain const& rhs);

	const std::string getter(int i) const;
	void setter(int i, std::string std);

private:
	std::string ideas_[100];
};

#endif /* *********************************************************** BRAIN_H */