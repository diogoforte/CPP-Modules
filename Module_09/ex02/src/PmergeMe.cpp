#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &other) { *this = other; }
PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
  if (this != &other) {
    list = other.list;
    deque = other.deque;
  }
  return *this;
}

PmergeMe::PmergeMe(char **av) {
  for (int i = 1; av[i]; i++) {
    int n = std::strtol(av[i], 0, 10);
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
  std::cout << std::fixed << std::setprecision(5)
            << "Time to process a range of " << list.size()
            << " elements with std::list: " << listTime << " us\n";
  std::cout << std::fixed << std::setprecision(5)
            << "Time to process a range of " << deque.size()
            << " elements with std::deque"
            << ": " << dequeTime << " us\n";
}

template <typename T> void PmergeMe::printContainer(const T &container) {
  for (typename T::const_iterator it = container.begin(); it != container.end();
       ++it)
    std::cout << *it << ' ';
  std::cout << '\n';
}

double PmergeMe::measureAndSort(std::list<int> &container) {
  std::deque<int> deque(container.begin(), container.end());
  clock_t start = clock();
  fordJohnsonSort(deque.begin(), deque.end());
  double time = (clock() - start) / CLOCKS_PER_SEC;
  container.assign(deque.begin(), deque.end());
  return time;
}

double PmergeMe::measureAndSort(std::deque<int> &container) {
  clock_t start = clock();
  fordJohnsonSort(container.begin(), container.end());
  return (clock() - start) / CLOCKS_PER_SEC;
}

void PmergeMe::fordJohnsonSort(std::deque<int>::iterator first,
                               std::deque<int>::iterator last) {
  std::deque<int> arr(first, last);
  int n = arr.size();
  int i = 0, j = n - 1;
  for (int k = 0; k < n; k += 2)
    *(first + k) = arr[i++];
  for (int k = 1; k < n; k += 2)
    *(first + k) = arr[j--];
  for (int k = 2; k < n; k *= 2) {
    for (int i = 0; i < n; i += 2 * k) {
      std::deque<int>::iterator mid = first + i + k;
      std::deque<int>::iterator end = first + std::min(i + 2 * k, n);
      if (mid > last)
        mid = last;
      if (end > last)
        end = last;
      std::inplace_merge(first + i, mid, end);
    }
  }
}
