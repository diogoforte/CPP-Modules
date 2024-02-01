#include "Span.hpp"
#include <iostream>

int main() {
  std::vector<int> numbers;
  numbers.push_back(-10000);
  numbers.push_back(0);
  numbers.push_back(10000);

  Span sp(5);
  sp.addNumber(numbers.begin(), numbers.end());

  try {
    std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
  } catch (const std::runtime_error &e) {
    std::cout << e.what() << std::endl;
  }

  try {
    std::cout << "longest span: " << sp.longestSpan() << std::endl;
  } catch (const std::runtime_error &e) {
    std::cout << e.what() << std::endl;
  }
}