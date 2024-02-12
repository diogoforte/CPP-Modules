#include "../inc/Harl.hpp"

void Harl::debug() const {
  std::cout << "[ DEBUG ]" << std::endl;
  std::cout
      << "I love having extra bacon for my "
         "7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
      << std::endl;
}

void Harl::info() const {
  std::cout << "[ INFO ]" << std::endl;
  std::cout
      << "I cannot believe adding extra bacon costs more money. You didn’t put "
         "enough bacon in my burger! If you did, I wouldn’t be asking for more!"
      << std::endl;
}

void Harl::warning() const {
  std::cout << "[ WARNING ]" << std::endl;
  std::cout
      << "I think I deserve to have some extra bacon for free. I’ve been "
         "coming for years whereas you started working here since last month."
      << std::endl;
}

void Harl::error() const {
  std::cout << "[ ERROR ]" << std::endl;
  std::cout << "This is unacceptable! I want to speak to the manager now."
            << std::endl;
}

Harl::LogLevel Harl::getLogLevel(const std::string &level) {
  if (level == "DEBUG")
    return DEBUG;
  if (level == "INFO")
    return INFO;
  if (level == "WARNING")
    return WARNING;
  if (level == "ERROR")
    return ERROR;
  return UNKNOWN;
}

void Harl::complain(const char *av) const {
  Harl::LogLevel level = Harl::getLogLevel(av);
  switch (level) {
  case ERROR:
    error();
  case WARNING:
    warning();
  case INFO:
    info();
  case DEBUG:
    debug();
    break;
  default:
    std::cout << "[ Probably complaining about insignificant problems ]"
              << std::endl;
    break;
  }
}
