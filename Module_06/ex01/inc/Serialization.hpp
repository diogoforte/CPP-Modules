#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <iostream>
#include <stdint.h>

struct Data {
  int a;
  double b;
};

class Serializer {
public:
  Serializer();
  ~Serializer();
  Serializer(const Serializer &other);
  Serializer &operator=(const Serializer &);
  static uintptr_t serialize(Data *ptr);
  static Data *deserialize(uintptr_t raw);
};

#endif