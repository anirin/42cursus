#ifndef _HUMANB_H_
#define _HUMANB_H_

#include <iostream>
#include <string>
#include "Weapon.hpp"

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

class HumanB {
private:
  std::string name_;
  Weapon *weapon_;

public:
  HumanB(std::string);
  ~HumanB();
  void attack();
  void setWeapon(Weapon&);
};

#endif