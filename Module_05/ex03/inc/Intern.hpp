#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <string>

class Intern {
private:
public:
  Intern();
  Intern(const Intern &src);
  ~Intern();
  Intern &operator=(const Intern &src);
  AForm *makeForm(const std::string form, const std::string target);
};