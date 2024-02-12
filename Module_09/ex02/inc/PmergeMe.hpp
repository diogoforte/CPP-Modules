#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <ctime>
#include <deque>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>
#include <queue>

class PmergeMe {
private:
  std::vector<int> vector;
  std::deque<int> deque;

public:
  PmergeMe(char **av);
  template <typename T> void printContainer(const T &container);
  template <typename T> double measureAndSort(T &container);
  template <typename T> void fordJohnsonSort(T &container);

  PmergeMe();
  ~PmergeMe();
  PmergeMe(const PmergeMe &other);
  PmergeMe &operator=(const PmergeMe &other);
};

#endif