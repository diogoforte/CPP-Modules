#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <ctime>
#include <deque>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <sstream>

class PmergeMe {
private:
  std::list<int> list;
  std::deque<int> deque;

public:
  PmergeMe(char **av);
  template <typename T> void printContainer(const T &container);
  double measureAndSort(std::list<int> &container);
  double measureAndSort(std::deque<int> &container);
  void fordJohnsonSort(std::deque<int>::iterator first,
                       std::deque<int>::iterator last);

  PmergeMe();
  ~PmergeMe();
  PmergeMe(const PmergeMe &other);
  PmergeMe &operator=(const PmergeMe &other);
};

#endif