#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap():_hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap created using default constructor\n";
}

ClapTrap::ClapTrap(const std::string& name):_name(name),_hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " was created\n";
}

ClapTrap::ClapTrap(const ClapTrap& other):_name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap Copy constructor called\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	std::cout << "Copy assignment operator called\n";

	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " was destroyed\n";
}

void ClapTrap::attack(std::string& target)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " can't attack because he's dead!\n";
		return ;
	}
	if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " energy is to low to attack!\n" ;
		return ;
	}
	if (_energyPoints > 0)
		_energyPoints -= 1;
	std::cout << "ClapTrap " << _name << " attacks "  << target << " causing " << _attackDamage << " damage !\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is already dead!\n";
		return ;
	}
	if (amount >= _hitPoints)
	{
		_hitPoints = 0;
		std::cout << "ClapTrap " << _name << " takes " << amount << " damage and dies\n";
		return;
	}
	std::cout << "ClapTrap " << _name << " takes " << amount << " damage\n";
	_hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is dead!\n";
		return ;
	}
	if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " does not have enough energy to be repared!\n";
		return ;
	}
	_energyPoints -= 1;
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name << " repairs itself by " << amount << " points and now has " << _hitPoints  << " hit points! \n";
}
