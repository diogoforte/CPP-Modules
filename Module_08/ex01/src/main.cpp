#include "Span.hpp"
#include <iostream>

int main() {
  std::vector<int> numbers;
  for (int i = 0; i < 10000; ++i)
    numbers.push_back(i);
  Span span(10000);
  try {
    span.addNumber(numbers.begin(), numbers.end());
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
  try {
    std::cout << "shortest span: " << span.shortestSpan() << std::endl;
  } catch (const std::runtime_error &e) {
    std::cout << e.what() << std::endl;
  }

  try {
    std::cout << "longest span: " << span.longestSpan() << std::endl;
  } catch (const std::runtime_error &e) {
    std::cout << e.what() << std::endl;
  }
  // span.printNumbers();
}