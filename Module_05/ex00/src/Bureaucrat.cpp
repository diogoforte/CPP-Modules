#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("empty"), grade(0) {
  std::cout << "Bureaucrat NULL" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade) {
  if (grade < 1) {
    throw GradeTooHighException();
  } else if (grade > 150) {
    throw GradeTooLowException();
  }
  std::cout << "Created Bureaucrat " << name << " with the grade " << grade
            << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &source)
    : name(source.name), grade(source.grade) {
  std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &source) {
  std::cout << "Bureaucrat assignment operator called" << std::endl;
  if (this == &source) {
    return *this;
  }
  this->grade = source.grade;
  return *this;
}

std::string Bureaucrat::getName() const { return this->name; }

int Bureaucrat::getGrade() const { return this->grade; }

Bureaucrat::~Bureaucrat() {
  std::cout << "Destroyed Bureaucrat " << name << std::endl;
}

void Bureaucrat::incrementGrade() {
  if (grade - 1 < 1)
    throw GradeTooHighException();
  else
    grade--;
}

void Bureaucrat::decrementGrade() {
  if (grade + 1 > 150)
    throw GradeTooLowException();
  else
    grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return ("Grade is too High (Integer value is too low)");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return ("Grade is too Low (Integer value is too high)");
}

std::ostream &operator<<(std::ostream &os, Bureaucrat &bureaucrat) {
  os << bureaucrat.getName() << " has the grade " << bureaucrat.getGrade();
  return os;
}
