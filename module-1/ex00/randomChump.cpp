#include "Zombie.hpp"
#include "../libfp/libfp.hpp"
#include <unistd.h>

void randomChump( std::string name )
{
	Zombie y(name);
}

void moreChumps(int chumps)
{
	for (int i = 0; i < chumps; i++)
	{
		randomChump(generateRandomName());
		sleep(1);
	}
}
