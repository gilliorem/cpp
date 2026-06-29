#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(): ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap created using the default constructor\n";
}

FragTrap::FragTrap(const std::string& name): ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << _name << " was created\n";
}

FragTrap::FragTrap(const FragTrap& other)
{
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;

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

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << _name << " is requesting a high fives! (+).\n";
}
