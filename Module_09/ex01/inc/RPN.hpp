#ifndef RPN_HPP
#define RPN_HPP

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stack>
#include <vector>

class RPN {
private:
  std::vector<std::string> data;

public:
  RPN(const char *av);
  ~RPN();
  void makeOperation();
};

#endif