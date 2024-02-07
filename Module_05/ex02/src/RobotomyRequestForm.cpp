#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &source)
	: AForm(source.getName(), source.getGradeToSign(), source.getGradeToExecute()) {
  *this = source;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &source) {
  if (this == &source) {
	return *this;
  }
  this->target = source.target;
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

std::string RobotomyRequestForm::getTarget() const { return this->target; }

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
  if (!getIsSigned() || executor.getGrade() > getGradeToExecute()) {
    throw GradeTooLowException();
  }
  std::cout << "Drilling noises...\n";
  if (rand() % 2) {
    std::cout << executor.getName() << " has been robotomized successfully.\n";
  } else {
    std::cout << "Robotomy on " << executor.getName() << " failed.\n";
  }
}