#pragma once
#include <string>

class Zombie
{
	public:
		Zombie(std::string const &name);
		~Zombie();
		void announce();
	private:
		std::string _name;
};


void randomChump( std::string name );
void moreChumps(int chumps);
