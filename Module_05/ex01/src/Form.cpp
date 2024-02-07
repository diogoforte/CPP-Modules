#include "Form.hpp"

Form::Form(std::string name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign),
      gradeToExecute(gradeToExecute) {
  if (gradeToSign < 1 || gradeToExecute < 1) {
    throw GradeTooHighException();
  } else if (gradeToSign > 150 || gradeToExecute > 150) {
    throw GradeTooLowException();
  }
}

std::string Form::getName() const { return this->name; }

bool Form::getIsSigned() const { return this->isSigned; }

int Form::getGradeToSign() const { return this->gradeToSign; }

int Form::getGradeToExecute() const { return this->gradeToExecute; }

void Form::beSigned(const Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > this->gradeToSign) {
    throw GradeTooLowException();
  }
  this->isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw() {
  return ("Grade is too High");
}

const char *Form::GradeTooLowException::what() const throw() {
  return ("Grade is too Low");
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
  os << "Form " << form.getName() << " is ";
  if (!form.getIsSigned()) {
    os << "not ";
  }
  os << "signed. Grade to sign: " << form.getGradeToSign()
     << ". Grade to execute: " << form.getGradeToExecute() << ".";
  return os;
}

Form::Form() : name("default"), isSigned(false), gradeToSign(150),
               gradeToExecute(150) {}

Form::Form(const Form &source)
    : name(source.getName()), isSigned(source.getIsSigned()),
      gradeToSign(source.getGradeToSign()),
      gradeToExecute(source.getGradeToExecute()) {}

Form &Form::operator=(const Form &source) {
  if (this == &source) {
    return *this;
  }
  this->isSigned = source.getIsSigned();
  return *this;
}

Form::~Form() {}