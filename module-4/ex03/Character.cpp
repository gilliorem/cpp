#include "Character.hpp"
#include <iostream>

Character::Character(){std::cout << this->_name << " was created using the default constructor\n"; initInventory();}
Character::Character(const Character& other){this->_name = other._name; std::cout << this->_name << " [" << this << "] " << "was created using a copy of this Character:[" << &other << "]\n"; initInventory();}
Character& Character::operator=(const Character& other) { if (&other == this) return *this; this->_name = other._name; initInventory(); return *this; }
Character::Character(const std::string& name):_name(name){std::cout << this->_name << " created \n";initInventory();}
Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
		{
			std::cout << "delete " << this->_inventory[i]->getType() << std::endl;
			delete (this->_inventory[i]);
		}
	}
	std::cout << this->_name << " destroyed\n";
}
const std::string& Character::getName(void) const { return this->_name; }
void Character::initInventory()
{
	for (int i = 0; i < 4; ++i)
		this->_inventory[i] = NULL;
	std::cout << this->_name << " 's inventory has been initialized.\n";
}
void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; ++i)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			std::cout << this->_name << " picked up: " << m->getType() << std::endl;
			return;
		}
	}
	std::cout << this->_name << " inventory is full!\n";
	return;
}

void Character::unequip(int idx)
{
	if (idx > 3 || idx < 0)
	{
		std::cout << this->_name << ": index out of range\n";
		return;
	}
	if (this->_inventory[idx] == NULL)
	{
		std::cout << this->_name << ": No item found at slot " << idx << std::endl;
		return;
	}
	this->_inventory[idx] = NULL;
	std::cout << this->_name << " drop: " << this->_inventory[idx]->getType() << " out of inventory" << std::endl;
	std::cout << "Slot " << idx << " has been cleared\n";
	return;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx > 3 || idx < 0)
	{
		std::cout << this->_name << ": index out of range\n";
		return;
	}
	if (this->_inventory[idx] == NULL)
	{
		std::cout << this->_name << ": No item found at slot " << idx << std::endl;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == this->_inventory[idx])
		{
			if (this->_inventory[i]->getType() == "ice")
				std::cout << "* "<< this->_name << " shoots an ice bolt at " << target.getName() << std::endl;
			else if (this->_inventory[i]->getType() == "cure")
			{
				if (this->_name == target.getName())
				{
					std::cout << "* " << this->_name << " is healing its wounds " << "using " << this->_inventory[i]->getType() << std::endl;
					return;
				}
				std::cout << "* " << this->_name << " heals " << target.getName() << " wounds" << std::endl;

			}
			return;
		}
	}
	std::cout << "Item not found in the inventory at index " << idx << std::endl;
	return;
}
