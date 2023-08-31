#include "../inc/Fixed.hpp"
#include <iostream>

Fixed::Fixed() : fixed_point_value(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &otherobj) {
  std::cout << "Copy constructor called" << std::endl;
  fixed_point_value = otherobj.fixed_point_value;
}

Fixed &Fixed::operator=(const Fixed &otherobj) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &otherobj) {
    fixed_point_value = otherobj.fixed_point_value;
  }
  return *this;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return fixed_point_value;
}
void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called" << std::endl;
  fixed_point_value = raw;
}