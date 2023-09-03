#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap {
private:
  std::string name;
  unsigned int hp;
  unsigned int ep;
  unsigned int ad;

public:
  ClapTrap();
  ClapTrap(std::string newName);
  ClapTrap(const ClapTrap &source);
  ClapTrap &operator=(const ClapTrap &source);
  ~ClapTrap();
  void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
};

#endif