#include "Zombie.hpp"

int main() {
  int zombie_size = 5;
  Zombie *zombies = zombieHorde(zombie_size, "jon");
  for (int i = 0; i < zombie_size; i++) {
    zombies[i].anounce();
  }
  delete[] zombies;

    zombie_size = 0;
    zombies = zombieHorde(zombie_size, "ken");
    for (int i = 0; i < zombie_size; i++) {
      zombies[i].anounce();
    }
    delete[] zombies;

    zombie_size = 1;
    zombies = zombieHorde(zombie_size, "hanna");
    for (int i = 0; i < zombie_size; i++) {
      zombies[i].anounce();
    }
    delete[] zombies;

  return 0;
}