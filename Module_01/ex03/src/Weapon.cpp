#include "../inc/Weapon.hpp"

Weapon::Weapon(std::string type) { this->type = type; }

void Weapon::setType(std::string type) { this->type = type; }

std::string Weapon::getType(void) { return this->type; }