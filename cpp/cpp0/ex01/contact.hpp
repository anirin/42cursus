#ifndef _CONTACT_H
#define _CONTACT_H

#include <iostream>
#include <string>
#include <sstream>

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

#endif