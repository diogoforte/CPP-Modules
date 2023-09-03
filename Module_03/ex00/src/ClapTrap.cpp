#include "../inc/ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : name("Unknown"), hp(10), ep(10), ad(0) {
  std::cout << "Default ClapTrap " << name << " is created!" << std::endl;
}

ClapTrap::ClapTrap(std::string newName) : name(newName), hp(10), ep(10), ad(0) {
  std::cout << "ClapTrap " << name << " is created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &source)
    : name(source.name), hp(source.hp), ep(source.ep), ad(source.ad) {
  std::cout << "ClapTrap " << name << " is copy created!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &source) {
  if (this != &source) {
    name = source.name;
    hp = source.hp;
    ep = source.ep;
    ad = source.ad;
  }
  std::cout << "ClapTrap " << name << " is copy assigned!" << std::endl;
  return *this;
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap " << name << " is destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string &target) {
  if (hp == 0 || ep == 0) {
    std::cout << "ClapTrap " << name
              << " can't attack due to low health or energy!" << std::endl;
    return;
  }
  std::cout << "ClapTrap " << name << " attacks " << target << ", causing "
            << ad << " points of damage!" << std::endl;
  ep--;
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (hp == 0) {
    std::cout << "ClapTrap " << name << " can't take more damage!" << std::endl;
    return;
  }
  hp -= (amount < hp) ? amount : hp;
  std::cout << "ClapTrap " << name << " took damage and now has " << hp
            << " hit points left!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (ep == 0) {
    std::cout << "ClapTrap " << name << " can't be repaired due to low energy!"
              << std::endl;
    return;
  }
  hp += amount;
  std::cout << "ClapTrap " << name << " has been repaired and now has " << hp
            << " hit points!" << std::endl;
  ep--;
}
