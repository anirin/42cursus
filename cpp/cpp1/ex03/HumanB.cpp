#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name_(name) {}

HumanB::~HumanB() {}

void HumanB::attack() {
  if (!weapon_) {
    std::cout << name_ << " does not have weapon ..." << std::endl;
    return;
  }
  const std::string &type = weapon_->getType();
  std::cout << name_ << " attacks with their " << type << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) { weapon_ = &weapon; }