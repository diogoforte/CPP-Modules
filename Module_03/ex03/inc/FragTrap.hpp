#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "../inc/ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
public:
  FragTrap();
  FragTrap(std::string newName);
  FragTrap(const FragTrap &source);
  ~FragTrap();

  void highFivesGuys();
};

#endif
