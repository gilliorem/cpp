#include <iostream>
#include "../libfp.hpp"

class ClapTrap : public Attribute
{
	private:
		std::string _name;
		unsigned int _health; // health ; did they mean health points ? // hit points(10)
		unsigned int _mana; // energy points(10)
		unsigned int _hit; // attack damage (0)

	public:
		void display(std::ostream &os) const override;

		void attack(const std::string& target); // it takes the string to another ClapTrap, not the instance...
		void takeDamage(unsigned int amount); // CP a attack CP b CP b takes damages
		void beRepared(unsigned int amount);

		std::string& getName(void);
		unsigned int getHealth(void);
		unsigned int getMana(void);
		unsigned int getHit(void);
		
		bool isDead();

		void setName(std::string &name); 
		void setHealth(unsigned int health);
		void setMana(unsigned int mana);
		void setHit(unsigned int hit);

		ClapTrap();
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& clapTrap);
		ClapTrap& operator=(const ClapTrap &clapTrap);
		~ClapTrap();
};

ClapTrap::ClapTrap():_health(10), _mana(10), _hit(0)
{
	std::cout << "Default constructor called\n";
}

ClapTrap::ClapTrap(const std::string& name):_name(name), _health(10), _mana(10), _hit(0)
{
	std::cout << "ClapTrap " << _name << "created\n";
}

class ScavTrap : public ClapTrap
{
	private:
		std::string _name;
		int _health;
		int _mana ;
		int _hit;
	
	public:
		void attack(const std::string& target);
		void guardGate();

		ScavTrap(const std::string& name);
		ScavTrap();
		ScavTrap(const ScavTrap& scavTrap);
		ScavTrap& operator=(const ScavTrap &scavTrap);
		~ScavTrap();
};

/* FRAG TRAP */
/*When a FragTrap is created, the program starts by constructing a ClapTrap.
 * Destruction occurs in reverse order*/

class FragTrap : public ClapTrap 
{
	private:
		std::string _name;
		int _health;
		int _mana ;
		int _hit;
	
	public:
		void attack(const std::string& target);
		void highFivesGuys();

		FragTrap(const std::string& name);
		FragTrap();
		FragTrap(const FragTrap& fragTrap);
		FragTrap& operator=(const FragTrap &fragTrap);
		~FragTrap();

};

class DiamondTrap : public virtual ScavTrap, public virtual FragTrap
{
	private:
		// must have the smae variable name as in the ClapTrap base class (without referring to the robot's name)
		std::string _name;
		int _health;
		int _mana ;
		int _hit;
	
	public:
		void attack(const std::string& target);
		void whoAmI();

		DiamondTrap(const std::string& name);
		DiamondTrap();
		DiamondTrap(const DiamondTrap& diamondTrap);
		DiamondTrap& operator=(const DiamondTrap &diamondTrap);
		~DiamondTrap();

};

void DiamondTrap::attack(const std::string& target)
{
	// ScavTrap
}

DiamondTrap::DiamondTrap():_health(100), _mana(100), _hit(30)
{
	std::cout << "DiamondTrap " << _name << " created\n";
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << _name << " destroyed\n";
}

DiamondTrap::DiamondTrap(const std::string& name):_name(name)
{
	std::cout << "DiamondTrap "<< _name << " created\n";
	_health = 100; // FragTrap
	_mana = 100; // ScavTrap
	_hit = 100; // FragTrap
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &diamondTrap)
{
	_name = diamondTrap._name;
	_health = diamondTrap._health;
	_mana = diamondTrap._mana;		
	_hit = diamondTrap._hit;		

	return *this;
}


void FragTrap::highFivesGuys()
{
	std::cout << "High-fives ?\n";
}

FragTrap::FragTrap():_health(100), _mana(100), _hit(30)
{
	std::cout << "FragTrap " << _name << " created\n";
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " destroyed\n";
}

FragTrap::FragTrap(const std::string& name):_name(name)
{
	std::cout << "FragTrap "<< _name << " created\n";
	_health = 100;
	_mana = 100;
	_hit = 100;
}

FragTrap& FragTrap::operator=(const FragTrap &fragTrap)
{
	_name = fragTrap._name;
	_health = fragTrap._health;
	_mana = fragTrap._mana;		
	_hit = fragTrap._hit;		

	return *this;
}


ScavTrap& ScavTrap::operator=(const ScavTrap &scavTrap)
{
	_name = scavTrap._name;
	_health = scavTrap._health;
	_mana = scavTrap._mana;		
	_hit = scavTrap._hit;		

	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " destroyed.\n";
}

ScavTrap::ScavTrap():_health(100), _mana(50), _hit(20)
{
	std::cout << "ScavTrap default constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap& scavTrap)
{
	_health = scavTrap._health;
	_mana = scavTrap._mana;
	_hit = scavTrap._hit;
	std::cout << "ScavTrap copy constructor called\n";
}

ScavTrap::ScavTrap(const std::string &name):_name(name)
{
	_health = 100;
	_mana = 50;
	_hit = 20;
	std::cout << "ScavTrap " << _name << "created\n";
}

void ScavTrap::attack(const std::string &target)
{
	if (_mana <= 0)
	{
		std::cout << "mana is too low to attack !\n";
		return ;
	}
	_mana -= 1;
	std::cout << "ScavTrap" <<  _name << " attack " << target << std::endl;
	std::cout << _name << " used 1 mana points" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << "is now in Gate Keeper Mode.\n";
}


bool ClapTrap::isDead()
{
	if (_health <= 0)
	{
		std::cout << _name << " died\n";
		return true;
	}
	return false;
}

void ClapTrap::display(std::ostream &os) const 
{
	os << std::setw(10) << "Name: " << std::setw(10) << _name << " |";
	os << std::setw(10) << "HP: " << std::setw(10) << _health << " |";
	os << std::setw(10) << "MANA: " << std::setw(10) << _mana << " |";
	os << std::setw(10) << "HIT: " << std::setw(10) << _hit << " |";
	std::cout << std::endl;
}

std::string& ClapTrap::getName(void)
{
	return _name;
}

unsigned int ClapTrap::getHealth(void)
{
	return _health;
}

unsigned int ClapTrap::getMana(void)
{
	return _mana;
}

unsigned int ClapTrap::getHit(void)
{
	return _hit;
}

void ClapTrap::attack(const std::string &target)
{
	if (_mana <= 0)
	{
		std::cout << "mana is too low to attack !\n";
		return ;
	}
	_mana -= 1;
	std::cout << _name << " attack " << target << std::endl;
	std::cout << _name << " used 1 mana points" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_health > 0)
	{
		_health -= amount; // TODO:  randomize the amounet health -= rand(2, 10) if 10: critical hit
		std::cout << _name << " takes " << amount << " damage" << std::endl;
	}
	if (_health <= 0)
	{
		std::cout << _name << " is dead\n";
		_health = 0;
	}
}

void ClapTrap::beRepared(unsigned int amount)
{
	if (_health < 100)
	{
		_health += amount;
		std::cout << _name << " repairs it self: +" << amount << " HP" << std::endl;
	}
	if (_health >= 100)
	{
		_health = 100;
	}
	std::cout << _name << " Health Points: " << _health << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& clapTrap):_name(clapTrap._name), _health(clapTrap._health), _mana(clapTrap._mana), _hit(clapTrap._hit)
{
	std::cout << "Copy constructor called\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& clapTrap)
{
	_name = clapTrap._name;
	_health = clapTrap._health;
	_mana = clapTrap._mana;
	_hit = clapTrap._hit;

	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Clap Trap destroyed\n";
}

void welcome()
{
	std::cout << "======== CLAP TRAP BATTLE ========" << std::endl;
}

void chooseOption(ClapTrap& clapTrap, std::string target)
{
	std::cout << "ATTACK" << std::endl;
	std::cout << "REPAIR" << std::endl;
	std::cout << "EXIT" << std::endl;

	std::string option;
	std::cout << "> ";
	captureFieldInput(option, "> ");
	if (option == "ATTACK")
		clapTrap.attack(target);

	else if (option == "REPAIR")
		clapTrap.beRepared(10);
	else if (option == "EXIT")
		exit (0);
	else
		std::cout << "Please enter a valid option.\n";
}

int main()
{
	DiamondTrap a("remi");
}
