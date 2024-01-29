#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <iomanip>

class ScalarConverter {
private:
  ScalarConverter();

public:
  static void convert(const std::string &literal);
};

#endif