#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main() {
  MutantStack<int> mstack;
  std::list<int> mlist;

  mstack.push(5);
  mlist.push_back(5);
  mstack.push(17);
  mlist.push_back(17);

  std::cout << "MutantStack top: " << mstack.top() << std::endl;
  std::cout << "List back: " << mlist.back() << std::endl;

  mstack.pop();
  mlist.pop_back();

  std::cout << "MutantStack size: " << mstack.size() << std::endl;
  std::cout << "List size: " << mlist.size() << std::endl;

  mstack.push(3);
  mlist.push_back(3);
  mstack.push(5);
  mlist.push_back(5);
  mstack.push(737);
  mlist.push_back(737);
  mstack.push(0);
  mlist.push_back(0);

  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  std::list<int>::iterator lit = mlist.begin();
  std::list<int>::iterator lite = mlist.end();

  std::cout << "MutantStack elements: ";
  while (it != ite)
    std::cout << *it++ << " ";
  std::cout << std::endl;

  std::cout << "List elements: ";
  while (lit != lite)
    std::cout << *lit++ << " ";
  std::cout << std::endl;
}