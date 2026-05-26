#include "../libfp.hpp"
#include "Zombie.hpp"

zombie::zombie(std::string name)
{
	std::cout << name << ": ";
	log("Brainz");
}

int main()
{
	zombie zozo("Michel");
}

