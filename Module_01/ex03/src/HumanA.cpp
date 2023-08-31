#include "../inc/HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &w) : name(name), weapon(&w) {}

void HumanA::attack() {
  std::cout << this->name << " attacks with his " << this->weapon->getType()
            << std::endl;
}