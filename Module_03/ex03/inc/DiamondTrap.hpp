#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "../inc/FragTrap.hpp"
#include "../inc/ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
private:
  std::string name;

public:
  DiamondTrap();
  DiamondTrap(std::string newName);
  DiamondTrap(const DiamondTrap &source);
  ~DiamondTrap();

  void whoAmI();
};

#endif
