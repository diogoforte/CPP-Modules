#include "../inc/ClapTrap.hpp"

int main() {
  ClapTrap trap("Clap");
  trap.attack("Target");
  trap.takeDamage(50);
  trap.beRepaired(5);
}