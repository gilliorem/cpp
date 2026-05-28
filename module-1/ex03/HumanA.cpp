#include "HumanA.hpp"
HumanA::HumanA(std::string const &name, Weapon& weapon): Human(name), _weapon(weapon)
{
	std::cout << _name << " spawned with a " << _weapon.getType() << std::endl ;
}

void HumanA::attack()
{
	std::cout << _name << " attacks with its " << _weapon.getType() << std::endl;
}

