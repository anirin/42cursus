#include "Zombie.hpp"

Zombie::Zombie() {
  std::cout << GREEN << "new Zombie has created with name" << RESET
            << std::endl;
}

Zombie::Zombie(std::string name) {
  name_ = name;
  std::cout << GREEN << "new Zombie has created with name" << RESET
            << std::endl;
}

Zombie::~Zombie() {
  std::cout << RED << "Zombie has deleted" << RESET << std::endl;
}

void Zombie::anounce() {
  std::cout << name_ << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name(std::string name) { name_ = name; }