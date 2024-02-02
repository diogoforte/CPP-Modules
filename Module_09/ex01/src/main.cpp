#include "RPN.hpp"

int main(int ac, char **av) {
  try {
    if (ac != 2)
      throw std::runtime_error("Usage: ./RPN \"ARGS\"");
    RPN rpn(av[1]);
    rpn.makeOperation();
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}