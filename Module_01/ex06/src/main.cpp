#include "../inc/Harl.hpp"
#include <string>

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <log level>" << std::endl;
    return 1;
  }
  Harl harl;
  Harl::LogLevel level = Harl::getLogLevel(argv[1]);
  harl.complain(level);
}
