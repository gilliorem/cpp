#include "FragTrap.hpp"

int main()
{
	FragTrap a("Remi");
	FragTrap b("Yuchi");
	std::string yuchi = "Yuchi";
	a.attack(yuchi);
	b.takeDamage(30);
	b.beRepaired(10);

	a.highFivesGuys();
}
