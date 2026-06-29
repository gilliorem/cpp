#include "ScavTrap.hpp"

int main()
{
	ScavTrap a("Remi");
	ScavTrap b("Yuchi");
	std::string yuchi = "Yuchi";
	a.attack(yuchi);
	b.takeDamage(20);
	b.beRepaired(10);

	a.guardGate();
}
