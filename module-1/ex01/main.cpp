#include "Zombie.hpp"
int main()
{
	Zombie *horde = zombieHorde(10, "Ear"); 
	delete[] horde;
	return 0;
}
