#include "Zombie.hpp"

int main() {
  Zombie *heep_zombie;

  heep_zombie = newZombie("heep_zombie");
  heep_zombie->anounce();
  delete heep_zombie;

  randomChump("stack_zombie");

  return 0;
}