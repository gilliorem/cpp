#include "Materia.hpp"
#include "Character.hpp"
#include <string>
#include <iostream>

AMateria::AMateria(const std::string& type){this->type = type;std::cout << "Materia created\n";}

AMateria::AMateria():type("") { std::cout << "Default Materia was created\n"; }

AMateria::AMateria(const AMateria& other) { this->type = other.type; std::cout << this->type << " was created using a *copy* of " << &other << std::endl; }

AMateria& AMateria::operator=(const AMateria& other) { if (&other == this) return *this; this->type = other.type;
	std::cout << this->type << " was assigned using the '=' operator and " << &other << " as a reference\n"; return *this; }

AMateria::~AMateria() { std::cout << this->type << " was destroyed\n"; }

const std::string& AMateria::getType() const { return this->type; }

void AMateria::use(ICharacter& target)
{
	(void)target;
}

Ice::Ice() {this->type = "ice"; std::cout << this->type << " was created with the default constructor\n";}
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

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << std::endl;
}

Cure::Cure() {this->type = "cure"; std::cout << this->type << " was created with the default constructor\n";}
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

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds" << std::endl;
}

MateriaSource::MateriaSource() {initSkillSet();std::cout << "Materia source was created using default constructor\n"; }
MateriaSource::MateriaSource(const MateriaSource& other) { *this = other; }
MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (&other != this)
		*this = other;
	initSkillSet();
	return *this;
}
MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; ++i)
	{
		if (this->_skillSet[i])
			delete this->_skillSet[i];
	}
	std::cout << "Materia source destroyed\n";}

void MateriaSource::initSkillSet()
{
	for (int i = 0; i < 4; ++i)
	{
		this->_skillSet[i] = NULL;
	}
	std::cout << "The materia source's skillset has been initialised\n";
}

void MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; ++i)
	{
		if (_skillSet[i] == NULL)
		{
			_skillSet[i] = m;
			break;
		}
	}
	std::cout << m->getType() << " learned\n";
}

AMateria* MateriaSource::createMateria(const std::string& type)
{
	AMateria* m = NULL;
	for (int i = 0; i < 4; ++i)
	{
		std::cout << i << ": " << _skillSet[i]->getType() << std::endl;
		if (this->_skillSet[i] == NULL)
			continue;
		if (this->_skillSet[i]->getType() == type)
		{
			m = this->_skillSet[i]->clone();
			break;
		}
	}
	if (m)
	{
		std::cout << "Materia source: " <<  m->getType() << " created\n";
		return m;
	}
	return 0;
}
