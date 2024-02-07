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
  return ("Grade is too High");
}

const char *AForm::GradeTooLowException::what() const throw() {
  return ("Grade is too Low");
}

std::ostream &operator<<(std::ostream &os, const AForm &Aform) {
  os << "Form " << Aform.getName() << " is ";
  if (!Aform.getIsSigned()) {
    os << "not ";
  }
  os << "signed. Grade to sign: " << Aform.getGradeToSign()
     << ". Grade to execute: " << Aform.getGradeToExecute() << ".";
  return os;
}

AForm::AForm() : name("default"), isSigned(false), gradeToSign(150),
               gradeToExecute(150) {}

AForm::AForm(const AForm &source)
    : name(source.getName()), isSigned(source.getIsSigned()),
      gradeToSign(source.getGradeToSign()),
      gradeToExecute(source.getGradeToExecute()) {}

AForm &AForm::operator=(const AForm &source) {
  if (this == &source) {
    return *this;
  }
  this->isSigned = source.getIsSigned();
  return *this;
}

AForm::~AForm() {}

void AForm::execute(Bureaucrat const &executor) const {
  if (!getIsSigned()) {
    throw std::runtime_error("Form is not signed");
  }
  (void)executor;
}