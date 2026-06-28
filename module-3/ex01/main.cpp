#include "ScavTrap.hpp"

int main()
{
	ScavTrap a("Remi");
	ScavTrap b("Yuchi");
	std::string yuchi = "Yuchi";
	a.attack(yuchi);

	a.guardGate();
}
