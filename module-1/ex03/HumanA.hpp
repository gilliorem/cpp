#pragma once
#include <string>
#include "Weapon.hpp"
#include "Human.hpp"
class HumanA : public Human
{
	public:
		HumanA(std::string const &name, Weapon &weapon);
		void attack();
	private:
		Weapon& _weapon;
};
