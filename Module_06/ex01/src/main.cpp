#include "Serialization.hpp"

int main() {
  Data data = {10, 20.5};
  Data *originalPtr = &data;

  std::size_t serialized = Serializer::serialize(originalPtr);
  Data *deserializedPtr = Serializer::deserialize(serialized);

  if (originalPtr == deserializedPtr) {
    std::cout << "Serialization and deserialization worked correctly."
              << std::endl;
  } else {
    std::cout << "Serialization and deserialization failed." << std::endl;
  }
}