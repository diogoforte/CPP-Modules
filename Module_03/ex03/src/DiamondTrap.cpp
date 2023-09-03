#include "../inc/DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap() {
  ClapTrap::name = "Unnamed_clap_name";
  name = "Unnamed";
  std::cout << "Default DiamondTrap " << name << " has been forged!"
            << std::endl;
}

DiamondTrap::DiamondTrap(std::string newName)
    : ScavTrap(newName), FragTrap(newName) {
  ClapTrap::name = newName + "_clap_name";
  name = newName;
  std::cout << "DiamondTrap " << name << " has been forged!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &source) 
    : ClapTrap(source), ScavTrap(source), FragTrap(source) {
  name = source.name;
  std::cout << "DiamondTrap " << name << " is a diamond duplicate!"
            << std::endl;
}

DiamondTrap::~DiamondTrap() {
  std::cout << "DiamondTrap " << name << " has been shattered!" << std::endl;
}

void DiamondTrap::whoAmI() {
  std::cout << "DiamondTrap Identity: " << name
            << ", ClapTrap Identity: " << ClapTrap::name << std::endl;
}
