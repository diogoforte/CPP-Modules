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

Contact inputContactFromUser() {
  Contact newContact;
  std::string first, last, nick, phone, secret;
  while (!first.size()) {
    std::cout << "Enter First Name: ";
    std::getline(std::cin, first);
  }
  while (!last.size()) {
    std::cout << "Enter Last Name: ";
    std::getline(std::cin, last);
  }
  while (!nick.size()) {
    std::cout << "Enter Nickname: ";
    std::getline(std::cin, nick);
  }
  while (!phone.size()) {
    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, phone);
  }
  while (!secret.size()) {
    std::cout << "Enter Darkest Secret: ";
    std::getline(std::cin, secret);
  }
  newContact.setContactInfo(first, last, nick, phone, secret);
  return newContact;
}

void PhoneBook::runPhoneBook(void) {
  PhoneBook myPhoneBook;
  std::string command;
  std::string index;

  std::cout << "\033[H\033[2J";
  while (true) {
    std::cout << "Enter command (ADD, SEARCH, EXIT): ";
    std::getline(std::cin, command);
    if (std::cin.eof())
      break;
    if (command == "ADD") {
      Contact newContact = inputContactFromUser();
      myPhoneBook.addContact(newContact);
    } else if (command == "SEARCH") {
      myPhoneBook.displayContacts();
      while (!index.size()) {
        std::cout << "Enter index to view details: ";
        std::getline(std::cin, index);
      }
      myPhoneBook.displaySpecificContact(index);
      index.clear();
    } else if (command == "EXIT")
      break;
    else
      std::cout << "Invalid command!" << std::endl;
  }
}