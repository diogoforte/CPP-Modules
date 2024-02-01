#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <stdexcept>
#include <vector>

class Span {
private:
  unsigned int N;
  std::vector<int> numbers;

public:
  Span(unsigned int N) : N(N) {}

  void addNumber(int number) {
    if (numbers.size() >= N) {
      throw std::runtime_error("Span is full");
    }
    numbers.push_back(number);
  }

  template <typename InputIterator>
  void addNumber(InputIterator first, InputIterator last) {
    while (first != last)
      addNumber(*first++);
  }

  int shortestSpan() {
    if (numbers.size() < 2) {
      throw std::runtime_error("Not enough numbers in span");
    }
    std::sort(numbers.begin(), numbers.end());
    int shortest = numbers[1] - numbers[0];
    for (unsigned int i = 2; i < numbers.size(); ++i) {
      shortest = std::min(shortest, numbers[i] - numbers[i - 1]);
    }
    return shortest;
  }

  int longestSpan() {
    if (numbers.size() < 2) {
      throw std::runtime_error("Not enough numbers in span");
    }
    return *std::max_element(numbers.begin(), numbers.end()) -
           *std::min_element(numbers.begin(), numbers.end());
  }
};

#endif