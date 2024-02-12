#include "RPN.hpp"

RPN::RPN(const char *av) {
  std::stringstream ss(av);
  std::string token;
  while (std::getline(ss, token, ' ')) {
    if ((isdigit(token[0]) || (token[0] == '+' || token[0] == '-' ||
                               token[0] == '*' || token[0] == '/')) &&
        token.size() == 1) {
      if (isdigit(token[0]))
        stack.push(std::strtol(token.c_str(), 0, 10));
      else {
        if (stack.size() < 2)
          throw std::runtime_error("Error: not enough operands");
        int a = stack.top();
        stack.pop();
        int b = stack.top();
        stack.pop();
        if (token[0] == '+')
          stack.push(a + b);
        else if (token[0] == '-')
          stack.push(b - a);
        else if (token[0] == '*')
          stack.push(a * b);
        else if (token[0] == '/') {
          if (a == 0)
            throw std::runtime_error("Error: division by zero");
          stack.push(b / a);
        }
      }
    } else
      throw std::runtime_error("Invalid token");
  }
  if (stack.size() == 0)
    throw std::runtime_error("Error: no operands");
  if (stack.size() != 1)
    throw std::runtime_error("Error: too many operands");
  std::cout << stack.top() << std::endl;
}

RPN::~RPN() {}
