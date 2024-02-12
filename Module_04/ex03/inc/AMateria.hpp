#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "../inc/ICharacter.hpp"

class ICharacter;

class AMateria {
protected:
  std::string type;

public:
  AMateria(void);
  AMateria(std::string const &type);
  AMateria(AMateria const &source);
  AMateria &operator=(AMateria const &source);
  virtual ~AMateria(void){};

  std::string const &getType() const;
  virtual AMateria *clone() const = 0;
  virtual void use(ICharacter &target);
};

#endif
