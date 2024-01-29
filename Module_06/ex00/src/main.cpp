#include "ScalarConverter.hpp"

int main() {
  std::string input;

  std::cin >> input;
  ScalarConverter::convert(input);
  // ScalarConverter::convert("a");      // char
  // std::cout << std::endl;
  // ScalarConverter::convert("42");     // int
  // std::cout << std::endl;
  // ScalarConverter::convert("4.2f");   // float
  // std::cout << std::endl;
  // ScalarConverter::convert("4.2");    // double
  // std::cout << std::endl;
  // ScalarConverter::convert("-inff");  // pseudo float
  // std::cout << std::endl;
  // ScalarConverter::convert("+inf");   // pseudo double
  // std::cout << std::endl;
  // ScalarConverter::convert("nan");    // pseudo double
}