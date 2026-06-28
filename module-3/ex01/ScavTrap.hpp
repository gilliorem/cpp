#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		std::string _name;
		unsigned int _hitPoints;
		unsigned int _energyPoints;
		unsigned int _attackDamage;

	public:
		ScavTrap();
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& clapTrap);
		ScavTrap& operator=(const ScavTrap &clapTrap);
		~ScavTrap();
		
		void	attack(std::string& target);
		void	guardGate();
};
