#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main() {
  std::vector<int> numbers;
  for (int i = 0; i < 5; i++)
    numbers.push_back(i);
  try {
    std::cout << "Trying to find value 3" << std::endl;
    int value = *easyfind(numbers, 3);
    std::cout << "Found value: " << value << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  try {
    std::cout << "Trying to find value 6" << std::endl;
    int value = *easyfind(numbers, 6);
    std::cout << "Found value: " << value << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}