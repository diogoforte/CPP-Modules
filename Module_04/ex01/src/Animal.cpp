#include "../inc/../inc/Animal.hpp"

Animal::Animal() : type("Animal") {
  std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type) {
  std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
  std::cout << "Animal assignment operator called" << std::endl;
  if (this != &other) {
    type = other.type;
  }
  return *this;
}

Animal::~Animal() { std::cout << "Animal destructor called" << std::endl; }

const std::string &Animal::getType() const { return type; }

void Animal::makeSound() const { std::cout << "Animal sound" << std::endl; }
