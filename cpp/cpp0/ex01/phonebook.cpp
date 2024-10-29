#include "phonebook.hpp"

PhoneBook::PhoneBook() { index_ = 0; }

PhoneBook::~PhoneBook() {}

void print_max_ten_words(std::string str) {
  int i;

  if (str.length() >= str_limit) {
    std::cout << str.substr(0, str_limit - 2);
    std::cout << ".";
  } else {
    std::cout << str;
    for (i = 0; i < (str_limit - (int)str.length()); i++) {
      std::cout << ".";
    }
  }
  return;
}

bool PhoneBook::search() {
  int i = 0;

  std::cout << "index      | first_name | last_name  | nickname  " << std::endl;
  while (i < index_ && i < contact_limit) {
    std::cout << i << "         ";
    std::cout << " | ";
    print_max_ten_words(contacts[i].get_first_name());
    std::cout << " | ";
    print_max_ten_words(contacts[i].get_last_name());
    std::cout << " | ";
    print_max_ten_words(contacts[i].get_nickname());
    std::cout << std::endl;
    i++;
  }

  std::string str_num;
  std::cout << "検索したいアドレスの番号を入力してください" << std::endl;
  std::getline(std::cin, str_num);

  if (std::cin.eof()) {
    std::cout << RED << std::endl
              << "<<EOFを検出したので、プログラムを終了します>>" << std::endl
              << RESET;
    return false;
  }
  if (str_num.find(' ') != std::string::npos ||
      str_num.find('\t') != std::string::npos) {
    std::cout << "空白文字を含む入力はやめてください。" << std::endl;
    return true;
  }

  int num;
  num = std::stoi(str_num);
  if (num >= i || num < 0) {
    std::cout << "不正な番号です。番号の範囲内で再度SEAECHしてください。"
              << std::endl;
    return true;
  }

  std::cout << "first_name  : " + contacts[num].get_first_name() << std::endl;
  std::cout << "last_name   : " + contacts[num].get_last_name() << std::endl;
  std::cout << "nickname    : " + contacts[num].get_nickname() << std::endl;
  std::cout << "phone_number: " + contacts[num].get_phone_number() << std::endl;
  std::cout << "dark_history: " + contacts[num].get_darkest_secret()
            << std::endl;
  return true;
}

void PhoneBook::add() {
  std::string tmp;
  int contact_num;
  contact_num = index_ % contact_limit;

  std::cout << "姓を入力してください" << std::endl;
  std::getline(std::cin, tmp);
  if (tmp.empty()) {
    std::cout << "空を入力することはできません。やり直してください"
              << std::endl;
    return;
  }
  contacts[contact_num].set_first_name(tmp);

  std::cout << "名を入力してください" << std::endl;
  std::getline(std::cin, tmp);
  if (tmp.empty()) {
    std::cout << "空を入力することはできません。やり直してください"
              << std::endl;
    return;
  }
  contacts[contact_num].set_last_name(tmp);

  std::cout << "ニックネームを入力してください" << std::endl;
  std::getline(std::cin, tmp);
  if (tmp.empty()) {
    std::cout << "空を入力することはできません。やり直してください"
              << std::endl;
    return;
  }
  contacts[contact_num].set_nickname(tmp);

  std::cout << "電話番号を入力してください" << std::endl;
  std::getline(std::cin, tmp);
  if (tmp.empty()) {
    std::cout << "空を入力することはできません。やり直してください"
              << std::endl;
    return;
  }
  contacts[contact_num].set_phone_number(tmp);

  std::cout << "黒歴史を教えてください" << std::endl;
  std::getline(std::cin, tmp);
  if (tmp.empty()) {
    std::cout << "空を入力することはできません。やり直してください"
              << std::endl;
    return;
  }
  contacts[contact_num].set_darkest_secret(tmp);

  index_++;
  return;
}