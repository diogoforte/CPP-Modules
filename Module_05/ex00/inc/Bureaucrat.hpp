#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>

class Bureaucrat {
private:
  const std::string name;
  int grade;

public:
  Bureaucrat();
  Bureaucrat(std::string name, int grade);
  Bureaucrat(const Bureaucrat &source);
  Bureaucrat &operator=(const Bureaucrat &source);
  ~Bureaucrat();
  std::string getName() const;
  int getGrade() const;
  void incrementGrade();
  void decrementGrade();

  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw();
  };
};
std::ostream &operator<<(std::ostream &os, Bureaucrat &bureaucrat);
#endif