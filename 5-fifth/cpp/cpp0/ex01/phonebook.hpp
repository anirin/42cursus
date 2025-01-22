#ifndef _PHONEBOOK_H_
#define _PHONEBOOK_H_

#include "contact.hpp"

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

const int contact_limit = 8;
const int str_limit = 10;

class PhoneBook {
private:
  int index_;
  Contact contacts[8];

public:
  PhoneBook();
  ~PhoneBook();
  void add();
  bool search();
};

#endif