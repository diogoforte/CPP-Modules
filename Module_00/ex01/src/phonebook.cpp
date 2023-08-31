#include "PhoneBook.hpp"
#include "Contact.hpp"

int main() {
  std::string command;
  PhoneBook myPhoneBook;

  while (true) {
    std::cout << "Enter command (ADD, SEARCH, EXIT): ";
    std::cin >> command;
    if (command == "ADD") {
      Contact newContact;
      std::string first, last, nick, phone, secret;
      std::cout << "Enter first name: ";
      std::cin >> first;
      std::cout << "Enter last name: ";
      std::cin >> last;
      std::cout << "Enter nickname: ";
      std::cin >> nick;
      std::cout << "Enter phone number: ";
      std::cin >> phone;
      std::cout << "Enter darkest secret: ";
      std::cin >> secret;
      newContact.setContactInfo(first, last, nick, phone, secret);
      myPhoneBook.addContact(newContact);
    } else if (command == "SEARCH") {
      myPhoneBook.displayContacts();
      std::cout << "Enter index to view details: ";
      int index;
      std::cin >> index;
      myPhoneBook.displaySpecificContact(index);
    } else if (command == "EXIT")
      break;
    else
      std::cout << "Invalid command!" << std::endl;
  }
}