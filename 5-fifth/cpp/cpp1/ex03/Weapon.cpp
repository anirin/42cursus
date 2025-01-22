#include "Weapon.hpp"

Weapon::Weapon(std::string str) : type_(str) {}

Weapon::~Weapon() {}

void Weapon::setType(std::string str) { type_ = str; }

const std::string &Weapon::getType() const { return type_; }
