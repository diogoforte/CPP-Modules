#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "../inc/Weapon.hpp"
#include <string>

class HumanB {
private:
  std::string name;
  Weapon *weapon;

public:
  HumanB(std::string name);
  ~HumanB(){};
  void setWeapon(Weapon &w);
  void attack(void);
};

#endif