#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
	name_ = name;
	std::cout << "new Zombie has created with name" << std::endl;
}

Zombie::~Zombie() {
	std::cout << "Zombie has deleted" << std::endl;
}

void Zombie::anounce() {
	std::cout << name_ << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}