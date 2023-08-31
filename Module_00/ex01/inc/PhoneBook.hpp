#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "../inc/Contact.hpp"
#include <cstdlib>

class PhoneBook {
private:
  Contact contacts[8];
  int contactCount;

public:
  PhoneBook();
  void addContact(Contact &contact);
  void displayContacts();
  void displaySpecificContact(const std::string& str_index);
};

#endif