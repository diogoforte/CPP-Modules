#include "../inc/Fixed.hpp"

Fixed::Fixed() : fixed_point_value(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num) {
  std::cout << "Int constructor called" << std::endl;
  fixed_point_value = num << fractional_bits;
}

Fixed::Fixed(const float num) {
  std::cout << "Float constructor called" << std::endl;
  fixed_point_value = roundf(num * (1 << fractional_bits));
}

Fixed::Fixed(const Fixed &other) : fixed_point_value(other.fixed_point_value) {
  std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &other) {
    fixed_point_value = other.fixed_point_value;
  }
  return *this;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

float Fixed::toFloat(void) const {
  return static_cast<float>(fixed_point_value) / (1 << fractional_bits);
}

int Fixed::toInt(void) const { return fixed_point_value >> fractional_bits; }

std::ostream &operator<<(std::ostream &out, const Fixed &f) {
  out << f.toFloat();
  return out;
}

int Fixed::getRawBits(void) const { return fixed_point_value; }

void Fixed::setRawBits(int const raw) { fixed_point_value = raw; }
