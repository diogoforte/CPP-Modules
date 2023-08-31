#include "../inc/Contact.hpp"

void Contact::setContactInfo(std::string first, std::string last,
                             std::string nick, std::string phone,
                             std::string secret) {
  firstName = first;
  lastName = last;
  nickname = nick;
  phoneNumber = phone;
  darkestSecret = secret;
}

std::string Contact::formatStringForDisplay(const std::string &input) {
  if (input.size() > 10) {
    return input.substr(0, 9) + ".";
  } else {
    return input;
  }
}

void Contact::printBrief() {
  std::cout << std::right << std::setw(10) << formatStringForDisplay(firstName)
            << "|";
  std::cout << std::right << std::setw(10) << formatStringForDisplay(lastName)
            << "|";
  std::cout << std::right << std::setw(10) << formatStringForDisplay(nickname)
            << std::endl;
}

void Contact::printFull() {
  std::cout << "First Name: " << firstName << std::endl;
  std::cout << "Last Name: " << lastName << std::endl;
  std::cout << "Nickname: " << nickname << std::endl;
  std::cout << "Phone Number: " << phoneNumber << std::endl;
  std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}