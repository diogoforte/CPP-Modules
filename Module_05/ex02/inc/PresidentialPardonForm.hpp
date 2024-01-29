#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <iostream>

class PresidentialPardonForm : public AForm {
private:
  std::string target;
  PresidentialPardonForm(void);

public:
  PresidentialPardonForm(std::string target);
  PresidentialPardonForm(const PresidentialPardonForm &source);
  PresidentialPardonForm &operator=(const PresidentialPardonForm &source);
  ~PresidentialPardonForm(void);
  void execute(Bureaucrat const &executor) const;
  std::string getTarget() const;
};

#endif