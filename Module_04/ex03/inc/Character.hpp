#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "../inc/ICharacter.hpp"
#include <string>

class Character : public ICharacter {
private:
  static const int inventory_size = 4;
  std::string name;
  AMateria *inventory[inventory_size];

public:
  Character(void);
  Character(std::string const &name);
  Character(Character const &source);
  Character &operator=(Character const &source);
  virtual ~Character(void);

  virtual std::string const &getName() const;
  virtual void equip(AMateria *m);
  virtual void unequip(int idx);
  virtual void use(int idx, ICharacter &target);
};

#endif
