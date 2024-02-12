#ifndef ICE_HPP
#define ICE_HPP

#include "../inc/AMateria.hpp"

class Ice : public AMateria {
public:
  Ice(void);
  Ice(Ice const &source);
  Ice &operator=(Ice const &source);
  ~Ice(void);

  virtual AMateria *clone() const;
  virtual void use(ICharacter &target);
};

#endif
