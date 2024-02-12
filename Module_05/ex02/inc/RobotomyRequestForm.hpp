#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

class RobotomyRequestForm : public AForm {
private:
  std::string target;
  RobotomyRequestForm(void);

public:
  RobotomyRequestForm(std::string target);
  RobotomyRequestForm(const RobotomyRequestForm &source);
  RobotomyRequestForm &operator=(const RobotomyRequestForm &source);
  ~RobotomyRequestForm(void);
  void execute(Bureaucrat const &executor) const;
  std::string getTarget() const;
};

#endif