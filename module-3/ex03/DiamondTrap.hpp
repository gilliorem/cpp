#pragma once
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>

/* The DiamondTrap class will have a private attribute name:
 * it must have the same value as the one in the ClapTrap base class.
 * If ClapTrap's variable is name, give the DiamondTrap's variable the name name
 * If ClapTrap's variable is _name, give the DiamondTrap's variable the name _name.
 *
 * Its function and attributes will be inherited from its parent class:
 *  - Name (passed as a parametor to a constructor)
 *  - Hit points (FragTrap)
 *  - Energy points (ScavTrap)
 *  - Attack damage (FragTrap)
 *  - attack (ScavTrap)
 * */

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string _name;

	public:
		DiamondTrap();
		DiamondTrap(const std::string& name);
		DiamondTrap(const DiamondTrap& other);
		DiamondTrap& operator=(const DiamondTrap &other);
		~DiamondTrap();

		void attack(std::string& target);
		void whoAmI();
		
	
};
