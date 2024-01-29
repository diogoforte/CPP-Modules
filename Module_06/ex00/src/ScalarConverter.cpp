#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &literal) {
  int c;
  int i;
  float f;
  double d;
  std::stringstream ss(literal);

  std::cout << "char: ";
  if (ss >> c) {
    if (isprint(c))
      std::cout << "'" << (char)c << "'" << std::endl;
    else
      std::cout << "Non displayable" << std::endl;
  } else
    std::cout << "Impossible" << std::endl;

  ss.clear();
  ss.str(literal);
  std::cout << "int: ";
  if (ss >> i)
    std::cout << i << std::endl;
  else
    std::cout << "Impossible" << std::endl;

  ss.clear();
  ss.str(literal);
  std::cout << "float: ";
  if (literal == "nan")
    std::cout << "nanf" << std::endl;
  else if (ss >> std::noskipws >> f)
    std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
  else
    std::cout << "Impossible" << std::endl;

  ss.clear();
  ss.str(literal);
  std::cout << "double: ";
  if (literal == "nan")
    std::cout << "nan" << std::endl;
  else if (ss >> std::noskipws >> d)
    std::cout << std::fixed << std::setprecision(1) << d << std::endl;
  else
    std::cout << "Impossible" << std::endl;
}