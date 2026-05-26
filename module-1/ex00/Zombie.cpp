#include "Zombie.hpp"
#include "../libfp/libfp.hpp"
#include <iostream>

void Zombie::announce()
{
	std::cout << _name << ": ";
	log("BraiiiiiiinnnzzzZ...");
}

Zombie::Zombie(std::string const &name): _name(name)
{
	announce();
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << _name << " died." << std::endl;
}
