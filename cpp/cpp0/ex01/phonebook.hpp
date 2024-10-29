#ifndef _PHONEBOOK_H_
#define _PHONEBOOK_H_

#include <iostream>
#include <string>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

const int contact_limit = 8;
const int str_limit = 10;

class Contact {
 private:
  std::string first_name_;
  std::string last_name_;
  std::string nickname_;
  std::string phone_number_;
  std::string darkest_secret_;

 public:
  void set_first_name(std::string str);
  void set_last_name(std::string str);
  void set_nickname(std::string str);
  void set_phone_number(std::string str);
  void set_darkest_secret(std::string str);
  std::string get_first_name();
  std::string get_last_name();
  std::string get_nickname();
  std::string get_phone_number();
  std::string get_darkest_secret();
};

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