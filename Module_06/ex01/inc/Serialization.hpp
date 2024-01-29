#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <iostream>

struct Data {
  int a;
  double b;
};

class Serializer {
private:
  Serializer() {}

public:
  static std::size_t serialize(Data *ptr);
  static Data *deserialize(std::size_t raw);
};

#endif