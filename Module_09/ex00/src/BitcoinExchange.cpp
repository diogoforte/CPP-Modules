#include "BitcoinExchange.hpp"

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange() {
  std::ifstream file("data.csv");
  if (!file.is_open())
    throw std::runtime_error("Error: Data file not found");
  std::string line;
  std::getline(file, line);
  while (std::getline(file, line)) {
    std::istringstream iss(line);
    std::string date;
    double value;
    if (std::getline(iss, date, ',') && iss >> value)
      data[date] = value;
  }
}

void BitcoinExchange::crossData(const char *filePath) const {
  std::ifstream file(filePath);
  if (!file.is_open())
    throw std::runtime_error("Error: Input file not found");
  std::string line;
  std::getline(file, line);
  while (std::getline(file, line)) {
    try {
      std::istringstream iss(line);
      std::string date;
      double value;
      std::getline(iss, date, '|');
      iss >> value;
      if (iss.fail())
        throw std::runtime_error("Error: bad input => " + date);
      if (value < 0)
        throw std::runtime_error("Error: not a positive number");
      if (value > 1000)
        throw std::runtime_error("Error: too large a number");
      std::map<std::string, double>::const_iterator it = data.upper_bound(date);
      if (it != data.begin()) {
        --it;
        std::cout << date << " => " << value << " = " << value * it->second
                  << std::endl;
      } else
        throw std::runtime_error("Error: " + date + " not found");
    } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }
}