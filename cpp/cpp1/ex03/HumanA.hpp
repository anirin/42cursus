#ifndef _HUMANA_H_
#define _HUMANA_H_

#include <iostream>
#include <string>
#include "Weapon.hpp"

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

class HumanA {
private:
  std::string name_;
  Weapon &weapon_;

public:
  HumanA(std::string name, Weapon &weapon);
  ~HumanA();
  void attack();
};

#endif