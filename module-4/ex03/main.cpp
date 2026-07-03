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

AMateria::AMateria():type("")
{
	std::cout << "Default Materia was created\n";
}

AMateria::AMateria(const AMateria& other)
{
	this->type = other.type;
	std::cout << this->type << " was created using a *copy* of " << &other << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other)
{
	if (&other == this)
		return *this;

	this->type = other.type;

	std::cout << this->type << " was assigned using the '=' operator and " << &other << " as a reference\n";

	return *this;
}

AMateria::~AMateria()
{
	std::cout << this->type << " was destroyed\n";
}

const std::string& AMateria::getType() const
{
	return this->type;
}



class Ice: public AMateria
{
	public:
		Ice(){};
		Ice(const Ice& other){this->type = other.type;std::cout << "copy\n";};
		Ice& operator=(const Ice& other){this->type = other.type; std::cout <<"assignement= operator\n";return *this;};
		~Ice(){std::cout << type << " destroyed\n";};

		AMateria* clone() const
		{
			AMateria* clone = NULL;
			*clone = *this;
			return clone;
		}
};

int main()
{
	AMateria* materia = new AMateria("ice");
	//AMateria* ice = new Ice("ice");
	//AMateria* iceClone = ice->clone();

	//std::cout << iceClone->getType() << std::endl;
	std::cout << ice->getType() << std::endl;
	return 0;
}
