#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "../inc/Weapon.hpp"
#include <string>

class HumanA {
private:
  std::string name;
  Weapon &weapon;

public:
  HumanA(std::string name, Weapon &w);
  ~HumanA(){};
  void attack(void);
};

#endif