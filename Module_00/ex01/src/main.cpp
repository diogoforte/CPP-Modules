#include "../inc/Contact.hpp"
#include "../inc/PhoneBook.hpp"

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

int main() {
  PhoneBook myPhoneBook;
  std::string command;
  std::string index;

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
      std::cout << "Enter index to view details: ";
      std::getline(std::cin, index);
      myPhoneBook.displaySpecificContact(index);
    } else if (command == "EXIT")
      break;
    else
      std::cout << "Invalid command!" << std::endl;
  }
}