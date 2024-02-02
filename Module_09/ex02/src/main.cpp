#include "PmergeMe.hpp"

int main(int ac, char **av) {
  try {
    if (ac < 2)
      throw std::runtime_error("Usage: ./PmergeMe ARGS");
    PmergeMe pmergeMe(av);
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}