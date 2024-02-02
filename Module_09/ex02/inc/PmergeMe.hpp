#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <ctime>
#include <deque>
#include <iostream>
#include <list>
#include <sstream>
#include <iomanip>

class PmergeMe {
  std::list<int> list;
  std::deque<int> deque;

public:
  PmergeMe(char **av);

private:
  template <typename T>
  void printContainer(const T &container);
  double measureAndSort(std::list<int> &container);
  double measureAndSort(std::deque<int> &container);
};

#endif