#include "../inc/ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap() {
  hp = 100;
  ep = 50;
  ad = 20;
  std::cout << "Default ScavTrap " << name << " is created!" << std::endl;
}

ScavTrap::ScavTrap(std::string newName) : ClapTrap(newName) {
  hp = 100;
  ep = 50;
  ad = 20;
  std::cout << "ScavTrap " << name << " is created!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &source) : ClapTrap(source) {
  std::cout << "ScavTrap " << name << " is copy created!" << std::endl;
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap " << name << " is destroyed!" << std::endl;
}

void ScavTrap::guardGate() {
  std::cout << "ScavTrap " << name << " has entered Gate keeper mode!"
            << std::endl;
}

void ScavTrap::attack(const std::string &target) {
  if (hp == 0 || ep == 0) {
    std::cout << "ScavTrap " << name
              << " can't attack due to low health or energy!" << std::endl;
    return;
  }
  std::cout << "ScavTrap " << name << " attacks " << target << ", causing "
            << ad << " points of damage!" << std::endl;
  ep--;
}
