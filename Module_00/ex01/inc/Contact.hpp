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
                      std::string phone, std::string secret);
  std::string formatStringForDisplay(const std::string &input);
  void printBrief();
  void printFull();
};

#endif