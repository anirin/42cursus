#include "Harl.hpp"

void Harl::debug() { std::cout << "debug" << std::endl; }

void Harl::info() { std::cout << "info" << std::endl; }

void Harl::warning() { std::cout << "warning" << std::endl; }

void Harl::error() { std::cout << "error" << std::endl; }

void Harl::complain(std::string level) {
  FuncLevel func = NULL;
  FuncLevel func_array[] = {&Harl::debug, &Harl::info, &Harl::warning,
                            &Harl::error};
  std::string level_array[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

  for (int i = 0; i < 5; i++) {
    if (level_array[i] == level) {
      func = func_array[i];
      break;
    }
  }

  if (!func) {
    std::cout << "invalid level" << std::endl;
    return;
  }

  (this->*func)();
}