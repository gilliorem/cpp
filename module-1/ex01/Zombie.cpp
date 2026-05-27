#include "Zombie.hpp"

void Zombie::announce()
{
	std::cout << _name << ": ";
	log("BraaaaaaiiiiinnnzzZ");
}

void Zombie::setName(std::string name)
{
	_name = name;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << _name << " died." << std::endl;
}

Zombie::Zombie(std::string const &name): _name(name)
{
	announce();
}

Zombie::Zombie(){}

