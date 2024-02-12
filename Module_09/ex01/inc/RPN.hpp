#ifndef RPN_HPP
#define RPN_HPP

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stack>

class RPN {
private:
  std::stack<int> stack;

public:
  RPN(const char *av);
  ~RPN();
};

#endif