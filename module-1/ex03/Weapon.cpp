#include "Weapon.hpp"

Weapon::Weapon(std::string type): _type(type)
{
	std::cout << _type << " was created." << std::endl;
}

Weapon::~Weapon()
{
	std::cout << _type << " was destroyed." << std::endl;
}

std::string const &Weapon::getType()
{
	return _type;
}

void Weapon::setType(std::string const &type)
{
	_type = type;
	std::cout << "weapon sets to: " << _type << std::endl;
}
