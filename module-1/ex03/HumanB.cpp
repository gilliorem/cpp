#include "HumanB.hpp"

HumanB::HumanB(std::string const &name): Human(name)
{
	_weapon = NULL;
}

void HumanB::attack()
{
	std::cout << _name << " attacks with its " << _weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}
