#include "../inc/Character.hpp"

Character::Character(void) : name("")
{
	for (int i = 0; i < inventory_size; i++)
		inventory[i] = 0;
}

Character::Character(std::string const &name) : name(name)
{
	for (int i = 0; i < inventory_size; i++)
		inventory[i] = 0;
}

Character::Character(Character const &source)
{
	for (int i = 0; i < inventory_size; i++)
		this->inventory[i] = 0;
	*this = source;
}

Character &Character::operator=(Character const &source)
{
	this->name = source.getName();
	for (int i = 0; i < inventory_size; i++)
		if (this->inventory[i])
		{
			delete this->inventory[i];
			this->inventory[i] = 0;
			this->inventory[i] = source.inventory[i]->clone();
		}
	return *this;
}

std::string const &Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria *m)
{
	if (!m)
		return;
	bool equipped = false;

	for (int i = 0; i < inventory_size; i++)
	{
		if (inventory[i] == 0)
		{
			inventory[i] = m;
			equipped = true;
			std::cout << "Materia " << m->getType() << " equipped in inventory " << i << std::endl;
			return;
		}
	}
	if (equipped == false)
		std::cout << "Inventory is full!" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
	{
		if (this->inventory[idx])
		{
			std::cout << "Materia " << inventory[idx]->getType() << " unequipped in inventory " << idx << std::endl;
			this->inventory[idx] = 0;
		}
		else
			std::cout << "Inventory " << idx << " is already empty" << std::endl;
	}
	else
		std::cout << "Wrong index to unequip" << std::endl;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4)
	{
		if (this->inventory[idx])
			this->inventory[idx]->use(target);
		else
			std::cout << "There's no materia equipped in inventory " << idx << std::endl;
	}
	else
		std::cout << "I can only use 4 equipped materias" << std::endl;
}

Character::~Character(void)
{
	for (int i = 0; i < inventory_size; i++)
		delete inventory[i];
}
