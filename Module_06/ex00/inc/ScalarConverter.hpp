#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cctype>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

class ScalarConverter {
private:
  ScalarConverter();
  ScalarConverter(const ScalarConverter &other);
  ScalarConverter &operator=(const ScalarConverter &);
  ~ScalarConverter();

public:
  static void printChar(const std::string &literal);
  static void printInt(const std::string &literal);
  static void printFloat(const std::string &literal);
  static void printDouble(const std::string &literal);
  static void convert(const std::string &literal);
};

#endif