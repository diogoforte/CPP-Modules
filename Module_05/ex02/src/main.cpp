#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main() {
  srand(time(0));

  Bureaucrat bob("Bob", 1);

  ShrubberyCreationForm shrubberyForm("home");
  RobotomyRequestForm robotomyForm("target");
  PresidentialPardonForm pardonForm("criminal");

  bob.signForm(shrubberyForm);
  bob.signForm(robotomyForm);
  bob.signForm(pardonForm);

  bob.executeForm(shrubberyForm);
  bob.executeForm(robotomyForm);
  bob.executeForm(pardonForm);

  return 0;
}