#pragma once
#include <string>
#include "../libfp/libfp.hpp"
#include <iostream>

class Zombie 
{
	public:
		Zombie();
		Zombie(std::string const &name);
		~Zombie();
		void announce();
		void setName(std::string name);
	
	private:
		std::string _name;
};

Zombie *zombieHorde(int N, std::string name);
