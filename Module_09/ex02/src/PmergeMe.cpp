#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &other) { *this = other; }
PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
  if (this != &other) {
    vector = other.vector;
    deque = other.deque;
  }
  return *this;
}

PmergeMe::PmergeMe(char **av) {
  for (int i = 1; av[i]; i++)
    for (int j = 0; av[i][j]; j++)
      if (!std::isdigit(av[i][j]))
        throw std::runtime_error("Error: ivalid parameter");
  for (int i = 1; av[i]; i++) {
    int n = std::strtol(av[i], 0, 10);
    vector.push_back(n);
    deque.push_back(n);
  }
  std::cout << "Before: ";
  printContainer(vector);
  double vectorTime = measureAndSort(vector);
  double dequeTime = measureAndSort(deque);
  std::cout << "After:  ";
  printContainer(vector);
  std::cout << std::fixed << std::setprecision(5)
            << "Time to process a range of " << vector.size()
            << " elements with std::vector: " << vectorTime << " us\n";
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

template <typename T> double PmergeMe::measureAndSort(T &container) {
  clock_t start = clock();
  fordJohnsonSort(container);
  return (double)(clock() - start) / CLOCKS_PER_SEC;
}

template <typename T> void PmergeMe::fordJohnsonSort(T &container) {
  if (container.size() < 2)
    return;
  std::vector<typename T::value_type> temp(container.size());
  for (size_t i = 0; i < container.size(); i += 2) {
    if (i + 1 < container.size()) {
      if (container[i] > container[i + 1]) {
        temp[i] = container[i + 1];
        temp[i + 1] = container[i];
      } else {
        temp[i] = container[i];
        temp[i + 1] = container[i + 1];
      }
    } else
      temp[i] = container[i];
  }
  size_t mid = (container.size() + 1) / 2;
  T firstHalf(temp.begin(), temp.begin() + mid);
  T secondHalf(temp.begin() + mid, temp.end());
  fordJohnsonSort(firstHalf);
  fordJohnsonSort(secondHalf);
  size_t i = 0, j = 0, k = 0;
  while (i < firstHalf.size() && j < secondHalf.size()) {
    if (firstHalf[i] < secondHalf[j])
      container[k++] = firstHalf[i++];
    else
      container[k++] = secondHalf[j++];
  }
  while (i < firstHalf.size())
    container[k++] = firstHalf[i++];
  while (j < secondHalf.size())
    container[k++] = secondHalf[j++];
}