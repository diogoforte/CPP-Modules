#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

class BitcoinExchange {
private:
  std::map<std::string, double> data;

public:
  BitcoinExchange();
  ~BitcoinExchange();
  void crossData(const char *filePath) const;
};

#endif