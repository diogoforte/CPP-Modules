#include "../inc/FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap() {
  hp = 100;
  ep = 100;
  ad = 30;
  std::cout << "Default FragTrap " << name << " has been created!" << std::endl;
}

FragTrap::FragTrap(std::string newName) : ClapTrap(newName) {
  hp = 100;
  ep = 100;
  ad = 30;
  std::cout << "FragTrap " << name << " has been created!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &source) : ClapTrap(source) {
  std::cout << "FragTrap " << name << " is a duplicate from the factory!"
            << std::endl;
}

FragTrap::~FragTrap() {
  std::cout << "FragTrap " << name << " is destroyed!" << std::endl;
}

void FragTrap::highFivesGuys() {
  std::cout << "FragTrap " << name << " requests a high five!" << std::endl;
}
