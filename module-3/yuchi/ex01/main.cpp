#include <string>
#include <iostream>

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);
		~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	private:
		std::string _name;
		unsigned int _hitPoints;
		unsigned int _energyPoints;
		unsigned int _attackDamage;
};

ClapTrap::ClapTrap()
{
	std::cout << "Default constructor" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << this->_name << " created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	if (this != &other)
		*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " destroyed" << std::endl;
}

// When ClapTrap attacks, it causes its target to lose attack damage hit points.
void ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoints == 0 || this->_energyPoints == 0)
		return ;

	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	
	this->_energyPoints -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
		return ;

	std::cout << "ClapTrap " << this->_name << " takes damage " << amount << " points of damage!" << std::endl;
	
	this->_hitPoints -= amount;

	if (this->_hitPoints < 0)
		this->_hitPoints = 0;

	std::cout << "_hitPoints = " << this->_hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == 0 || this->_energyPoints == 0)
		return ;
	
	std::cout << "ClapTrap " << this->_name << " repairs itself " << amount << " hit points!" << std::endl; 
	
	this->_energyPoints -= 1;
	
	this->_hitPoints += amount;

	if (this->_hitPoints > 10)
		this->_hitPoints = 10;

	std::cout << "_hitPoints = " << this->_hitPoints << std::endl;
}

class ScavTrap: public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const ScavTrap& other);
		ScavTrap& operator=(const ScavTrap& other);
		~ScavTrap();

		void attack(const std::string& target);

	private:
};

int main()
{
	ClapTrap Remi = ClapTrap("Remi");
	Remi.attack("Yuchi");
	Remi.takeDamage(2);
	Remi.beRepaired(3);
}
