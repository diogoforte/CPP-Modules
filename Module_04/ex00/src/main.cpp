#include "../inc/Animal.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"
#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"

int main() {
  const Animal *meta = new Animal();
  const Animal *j = new Dog();
  const Animal *i = new Cat();
  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound();
  j->makeSound();
  meta->makeSound();

  const WrongAnimal *wrongMeta = new WrongAnimal();
  const WrongAnimal *wrongI = new WrongCat();
  std::cout << wrongI->getType() << " " << std::endl;
  wrongI->makeSound();
  wrongMeta->makeSound();

  delete meta;
  delete j;
  delete i;
  delete wrongMeta;
  delete wrongI;

  return 0;
}
