#include <iostream>

class AMateria
{
	protected:
		std::string type;
	public:
		AMateria(const std::string& type);
		AMateria();
		AMateria(const AMateria& other);
		AMateria& operator=(const AMateria& other);
		~AMateria();
	
		const std::string& getType() const; // Return the Materia type.
		
		virtual AMateria* clone() const = 0;
	//	virtual void use(ICharacter& target);
};
AMateria::AMateria():type("") { std::cout << "Default Materia was created\n"; }

AMateria::AMateria(const AMateria& other) { this->type = other.type; std::cout << this->type << " was created using a *copy* of " << &other << std::endl; }

AMateria& AMateria::operator=(const AMateria& other) { if (&other == this) return *this; this->type = other.type;
	std::cout << this->type << " was assigned using the '=' operator and " << &other << " as a reference\n"; return *this; }

AMateria::~AMateria() { std::cout << this->type << " was destroyed\n"; }

const std::string& AMateria::getType() const { return this->type; }

class Ice: public AMateria
{
	public:
		Ice();
		Ice(const Ice& other);
		Ice& operator=(const Ice& other);
		Ice(const std::string& type);
		~Ice();

		AMateria* clone() const;
};
Ice::Ice() {std::cout << this->type << " was created with the default constructor\n";}
Ice::Ice(const Ice& other) {this->type = other.type; std::cout << this->type << " [" << this <<  "] " << " was created copying this [" << &other << "] ice materia reference.\n"; }
Ice& Ice::operator=(const Ice& other) { if (this == &other) return *this; this->type = other.type; return *this; }
Ice::Ice(const std::string& type) {this->type = type; std::cout << this->type << " was created\n";}
Ice::~Ice() {std::cout << this->type << " destroyed\n";}
AMateria* Ice::clone() const
{
	AMateria* clone = new Ice(*this);
	std::cout << type << " clone created\n";
	return clone;
}

class Cure: public AMateria
{
	public:
		Cure();
		Cure(const Cure& other);
		Cure& operator=(const Cure& other);
		Cure(const std::string& type);
		~Cure();

		AMateria* clone() const;
};
Cure::Cure() {std::cout << this->type << " was created with the default constructor\n";}
Cure::Cure(const Cure& other) {this->type = other.type; std::cout << this->type << " [" << this <<  "] " << " was created copying this [" << &other << "] cure materia reference.\n"; }
Cure& Cure::operator=(const Cure& other) { if (this == &other) return *this; this->type = other.type; return *this; }
Cure::Cure(const std::string& type) {this->type = type; std::cout << this->type << " was created\n";}
Cure::~Cure() {std::cout << this->type << " destroyed\n";}
AMateria* Cure::clone() const
{
	AMateria* clone = new Cure(*this);
	std::cout << type << " clone created\n";
	return clone;
}

class ICharacter
{
	public:
		virtual ~ICharacter(){};
		virtual std::string const &getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(AMateria* m) = 0;
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
	void unequip(AMateria* m);
	void use(int idx, ICharacter& target);
};

Character::Character(){std::cout << this->_name << " was created using the default constructor\n";}
Character::Character(const Character& other){this->_name = other._name; std::cout << this->_name << " [" << this << "] " << "was created using a copy of this Character:[" << &other << "]\n";}
Character::Character(const std::string& name):_name(name){std::cout << this->_name << " created \n";}
Character::~Character(){std::cout << this->_name << " destroyed\n";}
const std::string& Character::getName(void) const { return this->_name; }
void Character::initInventory()
{
	for (int i = 0; i < 4; ++i)
		this->_inventory[i] = NULL;
}
void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; ++i)
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			return;
		}
		else
		{
			std::cout << this->_name << " inventory is full!\n";
			return;
		}
}

void Character::unequip(AMateria *m)
{
	for (int i = 0; i < 4; ++i)
	{
		if (this->_inventory[i] == m)
		{
			this->_inventory[i] = NULL;
			std::cout << "Drop "<< this->_inventory[i]->getType() << " out of inventory" << std::endl;
			std::cout << "Slot " << i << " has been cleared\n";
		}
		else
		{
			std::cout << "Iventory is empty\n";
			return;
		}
	}
}

void Character::use(int idx, ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << &target << std::endl;

	std::cout << "* heals " << &target << " wounds" << std::endl;
}

int main()
{
	AMateria* materia = new Ice("ice");
	AMateria* clone = materia->clone();
	AMateria* cureMateria = new Cure("cure");
	AMateria* cureClone = cureMateria->clone();

	std::cout << materia->getType() << std::endl;
	std::cout << clone->getType() << std::endl;
	std::cout << cureMateria->getType() << std::endl;
	std::cout << cureClone->getType() << std::endl;
	return 0;
}
