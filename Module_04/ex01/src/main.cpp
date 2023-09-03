#include "../inc/Animal.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"
#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"

int main() {
  const Animal *animals[2];

  animals[0] = new Dog();
  animals[1] = new Cat();

  Dog originalDog;
  Dog copiedDog(originalDog);

  for (int i = 0; i < 2; i++) {
    delete animals[i];
  }

  return 0;
}
