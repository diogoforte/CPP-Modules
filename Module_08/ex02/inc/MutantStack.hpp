#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T> class MutantStack : public std::stack<T> {
public:
  typedef typename std::stack<T>::container_type::iterator iterator;
  iterator begin() { return std::stack<T>::c.begin(); }
  iterator end() { return std::stack<T>::c.end(); }

  MutantStack();
  MutantStack(MutantStack const &src);
  MutantStack &operator=(MutantStack const &other);
  ~MutantStack();
};

template <typename T> MutantStack<T>::MutantStack() {}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const &src) : std::stack<T>(src) {}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack const &other) {
  if (this != &other)
    std::stack<T>::operator=(other);
  return *this;
}

template <typename T> MutantStack<T>::~MutantStack() {}

#endif