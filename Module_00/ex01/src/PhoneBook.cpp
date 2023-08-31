#include "../inc/PhoneBook.hpp"

PhoneBook::PhoneBook() : contactCount(0) {}

void PhoneBook::addContact(Contact &contact) {
  if (contactCount < 8) {
    contacts[contactCount++] = contact;
  } else {
    for (int i = 0; i < 7; ++i)
      contacts[i] = contacts[i + 1];
    contacts[7] = contact;
  }
}

void PhoneBook::displayContacts() {
  for (int i = 1; i <= contactCount; i++) {
    std::cout << std::right << std::setw(10) << i << "|";
    contacts[i - 1].printBrief();
  }
}

void PhoneBook::displaySpecificContact(const std::string &indexStr) {
  int idx = atoi(indexStr.c_str());
  if (idx < 1 || idx > contactCount) {
    std::cout << "Invalid index!" << std::endl;
    return;
  } else {
    contacts[idx - 1].printFull();
  }
}
