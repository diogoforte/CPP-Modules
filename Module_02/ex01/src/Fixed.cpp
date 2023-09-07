#include "../inc/Fixed.hpp"

Fixed::Fixed() : RawBits(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num) {
  std::cout << "Int constructor called" << std::endl;
  RawBits = num << fractional_bits;
}

Fixed::Fixed(const float num) {
  std::cout << "Float constructor called" << std::endl;
  RawBits = roundf(num * (1 << fractional_bits));
}

Fixed::Fixed(const Fixed &other) : RawBits(other.RawBits) {
  std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &other) {
    RawBits = other.RawBits;
  }
  return *this;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

float Fixed::toFloat(void) const {
  return static_cast<float>(RawBits) / (1 << fractional_bits);
}

int Fixed::toInt(void) const { return RawBits >> fractional_bits; }

std::ostream &operator<<(std::ostream &out, const Fixed &f) {
  out << f.toFloat();
  return out;
}

int Fixed::getRawBits(void) const { return RawBits; }

void Fixed::setRawBits(int const raw) { RawBits = raw; }
