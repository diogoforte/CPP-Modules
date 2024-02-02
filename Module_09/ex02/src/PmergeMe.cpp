#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **av) {
  for (int i = 1; av[i]; i++) {
    int n = atoi(av[i]);
    list.push_back(n);
    deque.push_back(n);
  }
  double listTime, dequeTime;
  std::cout << "Before: ";
  printContainer(list);
  listTime = measureAndSort(list);
  dequeTime = measureAndSort(deque);
  std::cout << "After:  ";
  printContainer(list);
  std::setprecision(5);
std::cout << std::fixed << std::setprecision(5) << "Time to process a range of " << list.size()
          << " elements with std::list: " << listTime << " us\n";
std::cout << std::fixed << std::setprecision(5) << "Time to process a range of " << deque.size()
          << " elements with std::deque"<< ": " << dequeTime << " us\n";
}

template <typename T> void PmergeMe::printContainer(const T &container) {
  for (typename T::const_iterator it = container.begin(); it != container.end();
       ++it)
    std::cout << *it << ' ';
  std::cout << '\n';
}

double PmergeMe::measureAndSort(std::list<int> &container) {
  clock_t start = clock();
  container.sort();
  double time = double(clock() - start) / CLOCKS_PER_SEC;
  return time;
}

double PmergeMe::measureAndSort(std::deque<int> &container) {
  clock_t start = clock();
  std::sort(container.begin(), container.end());
  double time = double(clock() - start) / CLOCKS_PER_SEC;
  return time;
}
