#include "Array.hpp"
#include <iostream>

void printArray(Array<int> &array) {
  for (unsigned int i = 0; i < array.size(); ++i)
    std::cout << array[i] << " ";
  std::cout << std::endl;
}

int main() {
  Array<int> intArray(10);
  for (unsigned int i = 0; i < intArray.size(); ++i)
    intArray[i] = i * 2;
  printArray(intArray);
  Array<int> copyArray = intArray;
  printArray(copyArray);
  intArray[0] = 100;
  printArray(intArray);
  printArray(copyArray);
  try {
    intArray[10] = 200;
  } catch (std::out_of_range &e) {
    std::cout << "Caught exception: " << e.what() << std::endl;
  }
}