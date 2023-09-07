#include "../inc/Fixed.hpp"

Fixed::Fixed() : RawBits(0) {}

Fixed::Fixed(const int num) { RawBits = num << fractional_bits; }

Fixed::Fixed(const float num) {
  RawBits = roundf(num * (1 << fractional_bits));
}

Fixed::Fixed(const Fixed &rhs) : RawBits(rhs.RawBits) {}

Fixed &Fixed::operator=(const Fixed &rhs) {
  if (this != &rhs) {
    RawBits = rhs.RawBits;
  }
  return *this;
}

Fixed::~Fixed() {}

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

bool Fixed::operator>(const Fixed &rhs) const {
  return RawBits > rhs.RawBits;
}

bool Fixed::operator<(const Fixed &rhs) const {
  return RawBits < rhs.RawBits;
}

bool Fixed::operator>=(const Fixed &rhs) const {
  return RawBits >= rhs.RawBits;
}

bool Fixed::operator<=(const Fixed &rhs) const {
  return RawBits <= rhs.RawBits;
}

bool Fixed::operator==(const Fixed &rhs) const {
  return RawBits == rhs.RawBits;
}

bool Fixed::operator!=(const Fixed &rhs) const {
  return RawBits != rhs.RawBits;
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
  if (rhs.RawBits == 0) {
    std::cerr << "Division by zero!" << std::endl;
    exit(1);
  }
  return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed &Fixed::operator++() {
  RawBits++;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed old = *this;
  operator++();
  return old;
}

Fixed &Fixed::operator--() {
  RawBits--;
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