#include "ScalarConverter.hpp"

void ScalarConverter::printChar(const std::string &literal) {
  int c;
  std::stringstream ss(literal);

  std::cout << "char: ";
  if (ss >> c) {
    if (isprint(c))
      std::cout << "'" << static_cast<char>(c) << "'" << std::endl;
    else
      std::cout << "Non displayable" << std::endl;
  } else
    std::cout << "Impossible" << std::endl;
}

void ScalarConverter::printInt(const std::string &literal) {
  int i;
  std::stringstream ss(literal);

  std::cout << "int: ";
  if (ss >> i)
    std::cout << static_cast<int>(i) << std::endl;
  else
    std::cout << "Impossible" << std::endl;
}

void ScalarConverter::printFloat(const std::string &literal) {
  float f;
  std::stringstream ss(literal);

  std::cout << "float: ";
  if (literal == "nan")
    std::cout << "nanf" << std::endl;
  else if (ss >> std::noskipws >> f)
    std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
  else
    std::cout << "Impossible" << std::endl;
}

void ScalarConverter::printDouble(const std::string &literal) {
  double d;
  std::stringstream ss(literal);

  std::cout << "double: ";
  if (literal == "nan")
    std::cout << "nan" << std::endl;
  else if (ss >> std::noskipws >> d)
    std::cout << std::fixed << std::setprecision(1) << d << std::endl;
  else
    std::cout << "Impossible" << std::endl;
}

void ScalarConverter::convert(const std::string &literal) {
  printChar(literal);
  printInt(literal);
  printFloat(literal);
  printDouble(literal);
}