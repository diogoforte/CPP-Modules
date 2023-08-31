#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
  Contact contacts[8];
  int contactCount;

public:
  PhoneBook() : contactCount(0) {}

  void addContact(Contact &contact) {
    if (contactCount < 8) {
      contacts[contactCount++] = contact;
    } else {
      for (int i = 0; i < 7; ++i)
        contacts[i] = contacts[i + 1];
      contacts[7] = contact;
    }
  }

  void displayContacts() {
    for (int i = 0; i < contactCount; i++) {
      std::cout << std::right << std::setw(10) << i << "|";
      contacts[i].printBrief();
    }
  }

  void displaySpecificContact(int index) {
    if (index < 0 || index >= contactCount) {
      std::cout << "Invalid index!" << std::endl;
      return;
    }
    contacts[index].printFull();
  }
};

#endif