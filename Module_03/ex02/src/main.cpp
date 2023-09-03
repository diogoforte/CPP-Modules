#include "../inc/ClapTrap.hpp"
#include "../inc/ScavTrap.hpp"
#include "../inc/FragTrap.hpp"

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
}