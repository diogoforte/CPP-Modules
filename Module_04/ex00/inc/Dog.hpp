#ifndef DOG_HPP
#define DOG_HPP

#include "../inc/Animal.hpp"

class Dog : public Animal {
public:
  Dog();
  virtual ~Dog();

  void makeSound() const;
};

#endif
