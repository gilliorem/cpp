#pragma once
#include <string>
#include "Weapon.hpp"
#include "Human.hpp"
class HumanB : public Human
{
	public:
		HumanB(std::string const &name);
		HumanB();
		void setWeapon(Weapon &weapon);
		void attack();
	private:
		Weapon *_weapon;
};
