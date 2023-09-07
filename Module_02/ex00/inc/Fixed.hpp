#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
private:
  int RawBits;
  static const int fractional_bits = 8;

public:
  Fixed();
  Fixed(const Fixed &otherobj);
  Fixed &operator=(const Fixed &otherobj);
  ~Fixed();
  int getRawBits(void) const;
  void setRawBits(int const raw);
};

#endif