#include "Bureaucrat.hpp"
#include <iostream>

int main() {
  std::cout << "Enter a grade: ";
  int grade;
  std::cin >> grade;
  try {
    Bureaucrat salazar("Salazar", grade);
    std::cout << salazar << std::endl;
    salazar.incrementGrade();
    std::cout << salazar.getName() << "  incremented his grade to "
              << salazar.getGrade() << std::endl;
    salazar.decrementGrade();
    std::cout << salazar.getName() << " reseted his grade to "
              << salazar.getGrade() << std::endl;
    salazar.decrementGrade();
    std::cout << salazar.getName() << "  decremented his grade to "
              << salazar.getGrade() << std::endl;
  } catch (Bureaucrat::GradeTooHighException &exception) {
    std::cerr << "Caught GradeTooHighException: " << exception.what()
              << std::endl;
  } catch (Bureaucrat::GradeTooLowException &exception) {
    std::cerr << "Caught GradeTooLowException: " << exception.what()
              << std::endl;
  } catch (std::exception &exception) {
    std::cerr << "Caught exception: " << exception.what() << std::endl;
  }
}