#include "RPN.hpp"

RPN::~RPN() {}

RPN::RPN(const char *av) {
  std::stringstream ss(av);
  std::string token;
  while (std::getline(ss, token, ' ')) {
    if ((isdigit(token[0]) || (token[0] == '+' ||token[0] == '-' ||
      token[0] == '*' || token[0] == '/')) && token.size() == 1)
      data.push_back(token);
    else
      throw std::runtime_error("Invalid token");
  }
}

void RPN::makeOperation() {
  std::stack<int> stack;
  std::vector<std::string>::iterator it = data.begin();
  try {
    for (; it != data.end(); it++) {
      if (isdigit((*it)[0]))
        stack.push(atoi(it->c_str()));
      else {
        if (stack.size() < 2)
          throw std::runtime_error("Error: not enough operands");
        int a = stack.top();
        stack.pop();
        int b = stack.top();
        stack.pop();
        if ((*it)[0] == '+')
          stack.push(a + b);
        else if ((*it)[0] == '-')
          stack.push(b - a);
        else if ((*it)[0] == '*')
          stack.push(a * b);
        else if ((*it)[0] == '/') {
          if (a == 0)
            throw std::runtime_error("Error: division by zero");
          stack.push(b / a);
        }
      }
    }
    if (stack.size() == 0)
      throw std::runtime_error("Error: no operands");
    if (stack.size() != 1)
      throw std::runtime_error("Error: too many operands");
    std::cout << stack.top() << std::endl;
  } catch (const std::runtime_error &e) {
    std::cerr << e.what() << std::endl;
  }
}