#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& clapTrap);
		FragTrap& operator=(const FragTrap &clapTrap);
		~FragTrap();
		
		void	highFivesGuys();
};
