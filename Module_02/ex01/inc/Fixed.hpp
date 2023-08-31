#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>
#include <ostream>

class Fixed {
private:
  int fixed_point_value;
  static const int fractional_bits = 8;
  static const int fractional_mask = (1 << fractional_bits) - 1;

public:
  Fixed();
  Fixed(const int num);
  Fixed(const float num);
  Fixed(const Fixed &other);
  Fixed &operator=(const Fixed &other);
  ~Fixed();
  float toFloat(void) const;
  int toInt(void) const;
  int getRawBits(void) const;
  void setRawBits(int const raw);
  friend std::ostream &operator<<(std::ostream &out, const Fixed &f);
};

#endif