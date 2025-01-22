#ifndef _WEAPON_H_
#define _WEAPON_H_

#include <iostream>
#include <string>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

class Weapon {
private:
  std::string type_;

public:
  Weapon(std::string str);
  ~Weapon();
  void setType(std::string str);
  const std::string& getType() const;
};

#endif