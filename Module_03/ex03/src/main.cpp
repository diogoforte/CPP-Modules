#include "../inc/ClapTrap.hpp"
#include "../inc/DiamondTrap.hpp"
#include "../inc/FragTrap.hpp"
#include "../inc/ScavTrap.hpp"

int main() {
  ClapTrap trap("Clap");
  trap.attack("Target");
  trap.takeDamage(50);
  trap.beRepaired(5);

  ScavTrap scav("Scav");
  scav.attack("Target");
  scav.guardGate();
  scav.takeDamage(30);
  scav.beRepaired(10);

  FragTrap frag("Frag");
  frag.attack("Target");
  frag.highFivesGuys();
  frag.takeDamage(40);
  frag.beRepaired(20);

  DiamondTrap diamond("Diamond");
  diamond.whoAmI();
  diamond.attack("Target");
  diamond.guardGate();
  diamond.highFivesGuys();
  diamond.takeDamage(40);
  diamond.beRepaired(20);
}
