#pragma once
#include <string>
#include <iostream>

class Weapon
{
	public:
		Weapon(std::string type);
		~Weapon();
		void setType(std::string const &type);
		std::string const &getType();
	private:
		std::string _type;
};
