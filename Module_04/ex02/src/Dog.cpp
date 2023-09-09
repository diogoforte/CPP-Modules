#include "../inc/../inc/Dog.hpp"

Dog::Dog() : brain(new Brain()) {
  type = "Dog";
  std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other), brain(new Brain(*other.brain)) {
  std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
  std::cout << "Dog assignment operator called" << std::endl;
  if (this != &other) {
    delete brain;
    brain = new Brain(*other.brain);
    Animal::operator=(other);
  }
  return *this;
}

Dog::~Dog() {
  delete brain;
  std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const { std::cout << "Woof!" << std::endl; }
