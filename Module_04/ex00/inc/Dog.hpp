#ifndef DOG_HPP
#define DOG_HPP

#include "../inc/../inc/Animal.hpp"

class Dog : public Animal {
public:
  Dog();
  Dog(const Dog &other);
  Dog &operator=(const Dog &other);
  virtual ~Dog();

  void makeSound() const;
};

#endif
