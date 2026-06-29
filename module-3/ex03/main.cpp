#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap a("Remi");
	DiamondTrap b("Yuchi");

	std::string target = "Yuchi";
	a.attack(target);
	b.takeDamage(30);
	b.beRepaired(10);
	b.whoAmI();
	return 0;
}
