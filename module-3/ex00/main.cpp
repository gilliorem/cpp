#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("Remi");
	ClapTrap b("Yuchi");

	std::string target = "Remi";
	b.attack(target);

	a.takeDamage(1);
	a.beRepared(1);
}
