#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &type) : name_(name), weapon_(type) {}

HumanA::~HumanA() {}

void HumanA::attack() {
  const std::string &type = weapon_.getType();
  std::cout << name_ << " attacks with their " << type << std::endl;
}