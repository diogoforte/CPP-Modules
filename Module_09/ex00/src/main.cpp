#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
  try {
    if (ac != 2)
      throw std::runtime_error("Usage: ./btc [filename]");
    BitcoinExchange exchange;
    exchange.crossData(av[1]);
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}