#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

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
    std::cout << "A" << std::endl;
  else if (dynamic_cast<B *>(p))
    std::cout << "B" << std::endl;
  else if (dynamic_cast<C *>(p))
    std::cout << "C" << std::endl;
  else
    std::cout << "Unknown type" << std::endl;
}

void identify(Base &p) {
  try {
    A a = dynamic_cast<A &>(p);
    std::cout << "A" << std::endl;
  } catch (std::exception &e) {
    try {
      B b = dynamic_cast<B &>(p);
      std::cout << "B" << std::endl;
    } catch (std::exception &e) {
      try {
        C c = dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
      } catch (std::exception &e) {
        std::cout << "Unknown type" << std::endl;
      }
    }
  }
}