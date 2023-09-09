#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "../inc/../inc/WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
  WrongCat();
  WrongCat(const WrongCat &other);
  WrongCat &operator=(const WrongCat &other);
  virtual ~WrongCat();
};

#endif
