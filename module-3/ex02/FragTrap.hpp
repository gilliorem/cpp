#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:
		std::string _name;
		unsigned int _hitPoints;
		unsigned int _energyPoints;
		unsigned int _attackDamage;

	public:
		FragTrap();
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& clapTrap);
		FragTrap& operator=(const FragTrap &clapTrap);
		~FragTrap();
		
		void	attack(std::string& target);
		void	highFivesGuys();
};
