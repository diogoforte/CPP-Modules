#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <typename T> class Array {
private:
  T *array;
  unsigned int size_;

public:
  Array() : array(NULL), size_(0) {}

  Array(unsigned int n) : array(new T[n]()), size_(n) {}

  ~Array() { delete[] array; }

  Array(const Array &other) : array(new T[other.size_]), size_(other.size_) {
    for (unsigned int i = 0; i < size_; ++i)
      array[i] = other.array[i];
  }

  Array &operator=(const Array &other) {
    if (this != &other) {
      delete[] array;
      array = new T[other.size_];
      size_ = other.size_;
      for (unsigned int i = 0; i < size_; ++i)
        array[i] = other.array[i];
    }
    return *this;
  }

  T &operator[](unsigned int index) {
    if (index >= size_)
      throw std::out_of_range("Array index out of bounds");
    return array[index];
  }

  unsigned int size() const { return size_; }
};

#endif