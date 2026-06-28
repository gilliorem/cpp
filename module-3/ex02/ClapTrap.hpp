#include <string> 

class ClapTrap
{
	private:
		std::string _name;
		unsigned int _hitPoints;
		unsigned int _energyPoints;
		unsigned int _attackDamage;

	public:
		ClapTrap();
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& clapTrap);
		ClapTrap& operator=(const ClapTrap &clapTrap);
		~ClapTrap();

		void attack(std::string& target);
		void takeDamage(unsigned int amount);
		void beRepared(unsigned int amount);
};
