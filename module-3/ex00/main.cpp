#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("Remi");
	ClapTrap b("Yuchi");

	std::string target = "Yuchi";
	a.attack(target);
	b.takeDamage(0);
	b.beRepaired(1);
}
