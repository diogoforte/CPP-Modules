#include "../inc/Fixed.hpp"

Fixed::Fixed() : fixed_point_value(0) {}

Fixed::Fixed(const int num) { fixed_point_value = num << fractional_bits; }

Fixed::Fixed(const float num) {
  fixed_point_value = roundf(num * (1 << fractional_bits));
}

Fixed::Fixed(const Fixed &rhs) : fixed_point_value(rhs.fixed_point_value) {}

Fixed &Fixed::operator=(const Fixed &rhs) {
  if (this != &rhs) {
    fixed_point_value = rhs.fixed_point_value;
  }
  return *this;
}

Fixed::~Fixed() {}

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

bool Fixed::operator>(const Fixed &rhs) const {
  return fixed_point_value > rhs.fixed_point_value;
}

bool Fixed::operator<(const Fixed &rhs) const {
  return fixed_point_value < rhs.fixed_point_value;
}

bool Fixed::operator>=(const Fixed &rhs) const {
  return fixed_point_value >= rhs.fixed_point_value;
}

bool Fixed::operator<=(const Fixed &rhs) const {
  return fixed_point_value <= rhs.fixed_point_value;
}

bool Fixed::operator==(const Fixed &rhs) const {
  return fixed_point_value == rhs.fixed_point_value;
}

bool Fixed::operator!=(const Fixed &rhs) const {
  return fixed_point_value != rhs.fixed_point_value;
}

Fixed Fixed::operator+(const Fixed &rhs) const {
  return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(const Fixed &rhs) const {
  return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed &rhs) const {
  return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed &rhs) const {
  if (rhs.fixed_point_value == 0) {
    std::cerr << "Division by zero!" << std::endl;
    exit(1);
  }
  return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed &Fixed::operator++() {
  fixed_point_value++;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed old = *this;
  operator++();
  return old;
}

Fixed &Fixed::operator--() {
  fixed_point_value--;
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed old = *this;
  operator--();
  return old;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) { return (a > b) ? a : b; }

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
  return (a > b) ? a : b;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) { return (a < b) ? a : b; }

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
  return (a < b) ? a : b;
}