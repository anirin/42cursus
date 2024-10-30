#ifndef _HUMANA_H_
#define _HUMANA_H_

#include <iostream>
#include <string>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

class HumanB {
private:
  std::string type_;

public:
  HumanB();
  ~HumanB();
  void attack(std::string str);
};

#endif