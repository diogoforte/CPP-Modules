#include "Span.hpp"

Span::Span() : N(0) {}

Span::~Span() {}

Span::Span(const Span &other) : N(other.N), numbers(other.numbers) {}

Span &Span::operator=(const Span &other) {
  if (this != &other) {
    N = other.N;
    numbers = other.numbers;
  }
  return *this;
}

Span::Span(unsigned int N) : N(N) {}

void Span::addNumber(int number) {
  if (numbers.size() >= N)
    throw std::runtime_error("Span is full");
  numbers.push_back(number);
}

int Span::shortestSpan() {
  if (numbers.size() < 2)
    throw std::runtime_error("Not enough numbers in span");
  std::sort(numbers.begin(), numbers.end());
  int shortest = numbers[1] - numbers[0];
  for (unsigned int i = 2; i < numbers.size(); ++i)
    shortest = std::min(shortest, numbers[i] - numbers[i - 1]);
  return shortest;
}

int Span::longestSpan() {
  if (numbers.size() < 2)
    throw std::runtime_error("Not enough numbers in span");
  return *std::max_element(numbers.begin(), numbers.end()) -
         *std::min_element(numbers.begin(), numbers.end());
}

void Span::printNumbers() {
  for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end();
       ++it)
    std::cout << *it << " ";
  std::cout << std::endl;
}