#include "FragTrap.hpp"
#include "iostream"

FragTrap::FragTrap():_hitPoints(100), _energyPoints(100), _attackDamage(30)
{
	std::cout << "FragTrap created using the default constructor\n";
}

FragTrap::FragTrap(const std::string& name):_name(name),_hitPoints(100), _energyPoints(100), _attackDamage(30)
{
	std::cout << "FragTrap " << _name << " was created\n";
}

FragTrap::FragTrap(const FragTrap& other):_name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
	std::cout << "FragTrap Copy constructor called\n";
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	std::cout << "Copy assignment operator called\n";

	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " was destroyed\n";
}

void FragTrap::attack(std::string& target)
{
	if (_energyPoints > 100 || _energyPoints == 0)
	{
		std::cout << "FragTrap " << _name << " energy points are to low to attack!\n" ;
		return ;
	}
	if (_hitPoints > 100 || _hitPoints == 0)
	{
		std::cout << "FragTrap " << _name << " hit points are to low to attack!\n";
		return ;
	}

	if (_energyPoints > 0 && _energyPoints <= 100)
		_energyPoints -= 1;
	std::cout << "FragTrap " << _name << " attacks "  << target << " causing " << _attackDamage << " points of damage !\n";
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << _name << " is requesting a high fives! (+).\n";
}
