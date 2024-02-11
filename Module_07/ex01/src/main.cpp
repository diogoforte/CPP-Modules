#include "Iter.hpp"
#include <iostream>

void increment(int &n) { ++n; }

int main() {
  int array[] = {1, 2, 3, 4, 5};
  size_t length = sizeof(array) / sizeof(array[0]);
  iter(array, length, increment);
  for (size_t i = 0; i < length; ++i)
    std::cout << array[i] << ' ';
}