#include "../inc/AMateria.hpp"

AMateria::AMateria(void) {}

AMateria::AMateria(std::string const &type) : type(type) {}

AMateria::AMateria(AMateria const &source) { *this = source; }

AMateria &AMateria::operator=(AMateria const &source) {
  this->type = source.getType();
  return *this;
}

const std::string &AMateria::getType() const { return (this->type); }

void AMateria::use(ICharacter &target) {
  std::cout << "AMateria use????" << target.getName() << std::endl;
}
