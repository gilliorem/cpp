#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap created using the default constructor\n";
}

ScavTrap::ScavTrap(const std::string& name):_name(name),_hitPoints(100), _energyPoints(50), _attackDamage(20)
{
	std::cout << "ScavTrap " << _name << " was created\n";
}

ScavTrap::ScavTrap(const ScavTrap& other):_name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
	std::cout << "ScavTrap Copy constructor called\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	std::cout << "Copy assignment operator called\n";

	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " was destroyed\n";
}

void ScavTrap::attack(std::string& target)
{
	if (_energyPoints > 50 || _energyPoints == 0)
	{
		std::cout << "ScavTrap " << _name << " energy points are to low to attack!\n" ;
		return ;
	}
	if (_hitPoints > 100 || _hitPoints == 0)
	{
		std::cout << "ScavTrap " << _name << " hit points are to low to attack!\n";
		return ;
	}

	if (_energyPoints > 0 && _energyPoints <= 50)
		_energyPoints -= 1;
	std::cout << "ScavTrap " << _name << " attacks "  << target << " causing " << _attackDamage << " points of damage !\n";
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now is Gate keeper mode.\n";
}
