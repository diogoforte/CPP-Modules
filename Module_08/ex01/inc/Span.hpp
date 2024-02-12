#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

class Span {
private:
  unsigned int N;
  std::vector<int> numbers;

public:
  Span();
  ~Span();
  Span(const Span &other);
  Span &operator=(const Span &other);
  Span(unsigned int N);

  template <typename InputIterator>
  void addNumber(InputIterator first, InputIterator last) {
    if (std::distance(first, last) + numbers.size() > N)
      throw std::runtime_error("Adding these exceeds the span");
    numbers.insert(numbers.end(), first, last);
  }
  void addNumber(int number);
  int shortestSpan();
  int longestSpan();

  void printNumbers();
};

#endif