#include "AForm.hpp"

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign),
      gradeToExecute(gradeToExecute) {
  if (gradeToSign < 1 || gradeToExecute < 1) {
    throw GradeTooHighException();
  } else if (gradeToSign > 150 || gradeToExecute > 150) {
    throw GradeTooLowException();
  }
}

std::string AForm::getName() const { return this->name; }

bool AForm::getIsSigned() const { return this->isSigned; }

int AForm::getGradeToSign() const { return this->gradeToSign; }

int AForm::getGradeToExecute() const { return this->gradeToExecute; }

void AForm::beSigned(const Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > this->gradeToSign) {
    throw GradeTooLowException();
  }
  this->isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw() {
  return ("Grade is too High (Integer value is too low)");
}

const char *AForm::GradeTooLowException::what() const throw() {
  return ("Grade is too Low (Integer value is too high)");
}

std::ostream &operator<<(std::ostream &os, const AForm &form) {
  os << "Form " << form.getName() << " is ";
  if (!form.getIsSigned()) {
    os << "not ";
  }
  os << "signed. Grade to sign: " << form.getGradeToSign()
     << ". Grade to execute: " << form.getGradeToExecute() << ".";
  return os;
}

void AForm::execute(Bureaucrat const &executor) const {
  if (!getIsSigned()) {
    throw std::runtime_error("Form is not signed");
  }
  (void)executor;
}

AForm::~AForm() {
  std::cout << "Destroyed Form " << name << std::endl;
}
