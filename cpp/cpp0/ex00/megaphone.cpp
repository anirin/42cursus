#include <iostream>

void strToUpper(char *str) {
  for (size_t i = 0; i < std::strlen(str); i++) {
    std::cout << static_cast<char>(std::toupper(str[i]));
  }
}

int main(int argc, char *argv[]) {
  if (argc <= 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
  }

  for (int i = 1; i < argc; i++) {
    strToUpper(argv[i]);
  }
  std::cout << std::endl;
  return 0;
}