#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iomanip>
#include <iostream>

class Contact {
private:
  std::string firstName;
  std::string lastName;
  std::string nickname;
  std::string phoneNumber;
  std::string darkestSecret;

public:
  void setContactInfo(std::string first, std::string last, std::string nick,
                      std::string phone, std::string secret) {
    firstName = first;
    lastName = last;
    nickname = nick;
    phoneNumber = phone;
    darkestSecret = secret;
  }

  std::string formatStringForDisplay(const std::string &input) {
    if (input.size() > 10) {
      return input.substr(0, 9) + ".";
    } else {
      return input;
    }
  }

  void printBrief() {
    std::cout << std::right << std::setw(10)
              << formatStringForDisplay(firstName) << "|";
    std::cout << std::right << std::setw(10) << formatStringForDisplay(lastName)
              << "|";
    std::cout << std::right << std::setw(10) << formatStringForDisplay(nickname)
              << std::endl;
  }

  void printFull() {
    std::cout << "First Name: " << firstName << std::endl;
    std::cout << "Last Name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << darkestSecret << std::endl;
  }
};

#endif