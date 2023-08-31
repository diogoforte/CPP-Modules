#include "../inc/Fixed.hpp"
#include <iostream>

int main(void) {
  Fixed a;
  Fixed c;

  Fixed b(a);
  c = b;
  std::cout << a.getRawBits() << std::endl;
  std::cout << b.getRawBits() << std::endl;
  std::cout << c.getRawBits() << std::endl;
  return (0);
}
