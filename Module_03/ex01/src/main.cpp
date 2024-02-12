#include "../inc/ClapTrap.hpp"
#include "../inc/ScavTrap.hpp"
#include <iostream>

int main() {
  ClapTrap trap("Clap");
  trap.attack("Target");
  trap.takeDamage(50);
  trap.beRepaired(5);
  std::cout << std::endl << std::endl;
  ScavTrap scav("Scav");
  scav.attack("Target");
  scav.guardGate();
  scav.takeDamage(30);
  scav.beRepaired(10);
}