#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

class Bureaucrat;

class Form {
private:
  const std::string name;
  bool isSigned;
  const int gradeToSign;
  const int gradeToExecute;

public:
  Form(std::string name, int gradeToSign, int gradeToExecute);

  std::string getName() const;
  bool getIsSigned() const;
  int getGradeToSign() const;
  int getGradeToExecute() const;

  void beSigned(const Bureaucrat &bureaucrat);

  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif