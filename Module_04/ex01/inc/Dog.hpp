#ifndef DOG_HPP
#define DOG_HPP

#include "../inc/../inc/Animal.hpp"
#include "../inc/../inc/Brain.hpp"

class Dog : public Animal {
private:
  Brain *brain;

public:
  Dog();
  Dog(const Dog &other);
  Dog &operator=(const Dog &other);
  virtual ~Dog();

  void makeSound() const;
};

#endif
