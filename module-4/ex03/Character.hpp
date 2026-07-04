#include "Materia.hpp"
class ICharacter
{
	public:
		virtual ~ICharacter(){};
		virtual std::string const &getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

class Character: public ICharacter
{	
	private:
		std::string _name;
		AMateria* _inventory[4];

	public:
	Character();
	Character(const std::string &name);
	Character(const Character& other);
	Character& operator=(const Character& other);
	~Character();

	const std::string& getName() const;

	void initInventory();
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};
