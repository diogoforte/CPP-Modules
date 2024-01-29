#include "Base.hpp"

Base *generate(void) {
  srand(time(0));
  switch (rand() % 3) {
  case 0:
    return new A;
  case 1:
    return new B;
  case 2:
    return new C;
  }
  return NULL;
}

void identify(Base *p) {
  if (dynamic_cast<A *>(p))
    std::cout << "A\n";
  else if (dynamic_cast<B *>(p))
    std::cout << "B\n";
  else if (dynamic_cast<C *>(p))
    std::cout << "C\n";
}

void identify(Base &p) {
  if (dynamic_cast<A *>(&p))
    std::cout << "A\n";
  else if (dynamic_cast<B *>(&p))
    std::cout << "B\n";
  else if (dynamic_cast<C *>(&p))
    std::cout << "C\n";
}