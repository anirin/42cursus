#include <iostream>

void strToUpper(char *str) {
  for (int i = 0; i < (int)strlen(str); i++) {
    std::cout << (char)toupper(str[i]);
  }
  std::cout << std::endl;
}

int main(int argc, char *argv[]) {
  if (argc <= 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
  }

  for (int i = 1; i < argc; i++) {
    strToUpper(argv[i]);
  }
  return 0;
}