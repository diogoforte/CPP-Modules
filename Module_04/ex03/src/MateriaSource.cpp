#include "../inc/MateriaSource.hpp"

MateriaSource::MateriaSource(void) : materiasLearned(0)
{
	for (int i = 0; i < maxMateria; i++)
		materias[i] = 0;
}

MateriaSource::MateriaSource(MateriaSource const &source)
{
	*this = source;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &source)
{
	for (int i = 0; i < maxMateria; i++)
	{
		if (this->materias[i])
			delete this->materias[i];
		this->materias[i] = source.materias[i];
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria *mToLearn)
{
	if (materiasLearned == 4)
	{
		std::cout << "Can't learn more materias!" << std::endl;
		return;
	}
	for (int i = 0; i < maxMateria; i++)
	{
		if (this->materias[i] == 0)
		{
			this->materias[i] = mToLearn;
			materiasLearned++;
			std::cout << "Materia " << mToLearn->getType() << " learned!" << std::endl;
			return;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < maxMateria; i++)
	{
		if (this->materias[i] && this->materias[i]->getType() == type)
			return (this->materias[i]->clone());
	}
	return (0);
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < maxMateria; i++)
		if (this->materias[i])
			delete this->materias[i];
}
