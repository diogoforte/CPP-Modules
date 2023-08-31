#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl {
public:
  enum LogLevel { DEBUG, INFO, WARNING, ERROR, UNKNOWN };

  void debug() const;
  void info() const;
  void warning() const;
  void error() const;
  static LogLevel getLogLevel(const std::string &level);
  void complain(const LogLevel level) const;
};

#endif