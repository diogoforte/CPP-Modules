#include "../inc/ClapTrap.hpp"
#include "../inc/DiamondTrap.hpp"
#include "../inc/FragTrap.hpp"
#include "../inc/ScavTrap.hpp"
#include <iostream>

int main() {
  std::cout << std::endl << "Clap" << std::endl;
  ClapTrap trap("Clap");
  trap.attack("Target");
  trap.takeDamage(50);
  trap.beRepaired(5);
   std::cout << std::endl << "Scav" << std::endl;
  ScavTrap scav("Scav");
  scav.attack("Target");
  scav.guardGate();
  scav.takeDamage(30);
  scav.beRepaired(10);
  std::cout << std::endl << "Frag" << std::endl;
  FragTrap frag("Frag");
  frag.attack("Target");
  frag.highFivesGuys();
  frag.takeDamage(40);
  frag.beRepaired(20);
  std::cout << std::endl << "Diamond" << std::endl;
  DiamondTrap diamond("Diamond");
  diamond.whoAmI();
  diamond.attack("Target");
  diamond.guardGate();
  diamond.highFivesGuys();
  diamond.takeDamage(40);
  diamond.beRepaired(20);
}
