#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main() {
  std::vector<int> numbers;
  numbers.push_back(1);
  numbers.push_back(2);
  numbers.push_back(3);
  numbers.push_back(4);
  numbers.push_back(5);

  try {
    std::cout << "Trying to find value 3" << std::endl;
    int value = easyfind(numbers, 3);
    std::cout << "Found value: " << value << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  try {
    std::cout << "Trying to find value 6" << std::endl;
    int value = easyfind(numbers, 6);
    std::cout << "Found value: " << value << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}