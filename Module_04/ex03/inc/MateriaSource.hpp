#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "../inc/IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
private:
  static const int maxMateria = 4;
  AMateria *materias[maxMateria];
  int materiasLearned;

public:
  MateriaSource(void);
  MateriaSource(MateriaSource const &source);
  ~MateriaSource(void);
  MateriaSource &operator=(MateriaSource const &source);

  virtual void learnMateria(AMateria *);
  virtual AMateria *createMateria(std::string const &type);
};

#endif