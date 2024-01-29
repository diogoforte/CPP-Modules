#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <iostream>

class ShrubberyCreationForm : public AForm {
private:
  std::string target;
  ShrubberyCreationForm(void);

public:
  ShrubberyCreationForm(std::string target);
  ShrubberyCreationForm(const ShrubberyCreationForm &source);
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &source);
  ~ShrubberyCreationForm(void);
  void execute(Bureaucrat const &executor) const;
  std::string getTarget() const;
};

#endif