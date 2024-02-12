#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "../inc/ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
  ScavTrap();
  ScavTrap(std::string newName);
  ScavTrap(const ScavTrap &source);
  ~ScavTrap();

  void guardGate();
  void attack(const std::string &target);
};

#endif
