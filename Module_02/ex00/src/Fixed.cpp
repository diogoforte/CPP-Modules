#include "../inc/Fixed.hpp"
#include <iostream>

Fixed::Fixed() : RawBits(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &otherobj) {
  std::cout << "Copy constructor called" << std::endl;
  RawBits = otherobj.RawBits;
}

Fixed &Fixed::operator=(const Fixed &otherobj) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &otherobj) {
    RawBits = otherobj.RawBits;
  }
  return *this;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return RawBits;
}
void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called" << std::endl;
  RawBits = raw;
}