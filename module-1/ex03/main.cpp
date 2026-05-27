#include <iostream>
#include <string>
#include "../libfp/libfp.hpp"

class Weapon
{
	public:
		Weapon(std::string type);
		Weapon();
		~Weapon();
		void setType(std::string const &type);
		std::string const &getType();
	private:
		std::string _type;
};

Weapon::Weapon(){}

Weapon::Weapon(std::string type): _type(type)
{
	std::cout << _type << " was created." << std::endl;
}

Weapon::~Weapon()
{
	std::cout << _type << " was destroyed." << std::endl;
}

std::string const &Weapon::getType()
{
	return _type;
}

void Weapon::setType(std::string const &type)
{
	_type = type;
	std::cout << "weapon sets to: " << _type << std::endl;
}

class Human
{
	public:
		Human(std::string const &name);
		~Human();
	protected:
		std::string const&_name;
};

Human::Human(std::string const &name): _name(name)
{
	std::cout << _name << " is born" << std::endl;
}
Human::~Human()
{
	std::cout << _name << " died" << std::endl;
}


class HumanA : public Human
{
	public:
		HumanA(std::string const &name, Weapon &weapon);
		void attack();
	private:
		Weapon& _weapon;
};

HumanA::HumanA(std::string const &name, Weapon& weapon): Human(name), _weapon(weapon)
{
	std::cout << _name << " spawned with a " << _weapon.getType() << std::endl ;
}

void HumanA::attack()
{
	std::cout << _name << " attacks with its " << _weapon.getType() << std::endl;
}

class HumanB : public Human
{
	public:
		HumanB(std::string const &name);
		//~HumanB();
		void setWeapon(Weapon &weapon);
		void attack();
	private:
		Weapon *_weapon;
};

HumanB::HumanB(std::string const &name): Human(name)
{
	_weapon = NULL;
}

void HumanB::attack()
{
	std::cout << _name << " attacks with its " << _weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	log("");
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
}
