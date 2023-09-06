#include "../inc/Harl.hpp"
#include <string>

int main(int ac, char **av) {
  if (ac != 2) {
    std::cerr << "Usage: " << av[0] << " <log level>" << std::endl;
    return 1;
  }
  Harl harl;
  harl.complain(av[1]);
}
