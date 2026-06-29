#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& clapTrap);
		ScavTrap& operator=(const ScavTrap &clapTrap);
		~ScavTrap();
		
		void	attack(std::string& target);
		void	guardGate();
};
