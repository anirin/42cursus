#include "phonebook.hpp"

int main() {
  PhoneBook phone_book;

  while (1) {
    std::string input;
    std::cout << GREEN << std::endl
              << "アドレス追加 : ADD" << std::endl
              << "アドレス検索 : SEARCH" << std::endl
              << "終了　　　　 : EXIT" << std::endl
              << std::endl
              << RESET;

    if (!std::getline(std::cin, input)) {
      if (std::cin.eof()) {
        std::cout << RED << std::endl
                  << "<<EOFを検出したので、プログラムを終了します>>"
                  << std::endl
                  << RESET;
        return 1;
      }
      std::cin.clear();
      std::cin.ignore();
      std::cout << RED << "<<入力エラーが発生しました。再度入力してください>>"
                << std::endl
                << std::endl
                << RESET;
      continue;
    }

    if (input == "add") {
      phone_book.add();
    } else if (input == "search") {
      if (!phone_book.search()) {
        return 1;
      }
    } else if (input == "exit") {
      std::cout << std::endl << "<<終了>>" << std::endl;
      return 0;
    } else {
      std::cout << RED << "<<不正なコマンドです！>>" << std::endl << RESET;
    };
  }
}