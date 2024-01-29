#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>

int main() {
    Bureaucrat a("Emperor", 1);
    Intern z;

    AForm* b = z.makeForm("RobotomyRequestForm", "Bender");
    AForm* c = z.makeForm("ShrubberyCreationForm", "Christmas");

    std::cout << a << std::endl << *b << std::endl << *c << std::endl;

    b->beSigned(a);
    a.signForm(*c);

    std::cout << *b << std::endl << *c << std::endl;

    for (int i = 0; i < 10; i++)
        b->execute(a);

    a.executeForm(*c);

    delete b;
    delete c;

    return 0;
}