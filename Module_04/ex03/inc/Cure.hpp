#ifndef CURE_HPP
#define CURE_HPP

#include "../inc/AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure(void);
	Cure(Cure const &source);
	Cure &operator=(Cure const &source);
	~Cure(void);

	virtual AMateria *clone() const;
	virtual void use(ICharacter &target);
};

#endif
