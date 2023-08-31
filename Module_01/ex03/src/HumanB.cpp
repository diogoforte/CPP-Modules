#include "../inc/HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : name(name), weapon(NULL) {}

void HumanB::setWeapon(Weapon &w) { weapon = &w; }

void HumanB::attack() {
  if (weapon) {
    std::cout << this->name << " attacks with his " << weapon->getType()
              << std::endl;
  } else {
    std::cout << this->name << " has no weapon!" << std::endl;
  }
}