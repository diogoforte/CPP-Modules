#ifndef CAT_HPP
#define CAT_HPP

#include "../inc/../inc/Animal.hpp"
#include "../inc/../inc/Brain.hpp"

class Cat : public Animal {
private:
  Brain *brain;

public:
  Cat();
  Cat(const Cat &other);
  Cat &operator=(const Cat &other);
  virtual ~Cat();

  void makeSound() const;
};

#endif