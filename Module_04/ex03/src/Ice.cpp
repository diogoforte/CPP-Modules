#include "../inc/Ice.hpp"

Ice::Ice(void) : AMateria("ice") {}

Ice::Ice(Ice const &source) { *this = source; }

Ice &Ice::operator=(Ice const &source) {
  this->type = source.getType();
  return *this;
}

AMateria *Ice::clone() const { return (new Ice(*this)); }

void Ice::use(ICharacter &target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << " *"
            << std::endl;
}

Ice::~Ice(void) {}
