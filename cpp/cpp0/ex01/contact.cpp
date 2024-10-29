#include "phonebook.hpp"

void Contact::set_first_name(std::string str) { first_name_ = str; }

void Contact::set_last_name(std::string str) { last_name_ = str; }

void Contact::set_nickname(std::string str) { nickname_ = str; }

void Contact::set_phone_number(std::string str) { phone_number_ = str; }

void Contact::set_darkest_secret(std::string str) { darkest_secret_ = str; }

std::string Contact::get_first_name() { return first_name_; }

std::string Contact::get_last_name() { return last_name_; }

std::string Contact::get_nickname() { return nickname_; }

std::string Contact::get_phone_number() { return phone_number_; }

std::string Contact::get_darkest_secret() { return darkest_secret_; }