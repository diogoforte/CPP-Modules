#include "../inc/Zombie.hpp"
#include <iostream>

int main() {
  Zombie *heapZombie = newZombie("Cristiano");
  heapZombie->announce();
  delete heapZombie;
  randomChump("Ronaldo");
}