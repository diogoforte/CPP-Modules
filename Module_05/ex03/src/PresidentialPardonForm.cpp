#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm(target, 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &source)
    : AForm(source.getName(), source.getGradeToSign(),
            source.getGradeToExecute()) {
  *this = source;
}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &source) {
  if (this == &source) {
    return *this;
  }
  this->target = source.target;
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

std::string PresidentialPardonForm::getTarget() const { return this->target; }

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
  if (!getIsSigned() || executor.getGrade() > getGradeToExecute()) {
    throw GradeTooLowException();
  }
  std::cout << executor.getName()
            << " has been pardoned by Zafod Beeblebrox.\n";
}