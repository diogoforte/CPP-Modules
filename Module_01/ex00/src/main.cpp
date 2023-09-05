#include "../inc/Zombie.hpp"
#include <iostream>

int main() {
  Zombie *heapZombie = newZombie("Heap Zombie");
  heapZombie->announce();
  delete heapZombie;
  randomChump("Stack Zombie");
}