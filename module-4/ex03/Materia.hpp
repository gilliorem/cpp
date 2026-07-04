#pragma once
#include <string>

class ICharacter;

class AMateria
{
	protected:
		std::string type;
	public:
		AMateria(const std::string& type);
		AMateria();
		AMateria(const AMateria& other);
		AMateria& operator=(const AMateria& other);
		virtual ~AMateria();
	
		const std::string& getType() const; // Return the Materia type.
		
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

class Ice: public AMateria
{
	public:
		Ice();
		Ice(const Ice& other);
		Ice& operator=(const Ice& other);
		Ice(const std::string& type);
		~Ice();

		AMateria* clone() const;
		void use(ICharacter& target);
};

class Cure: public AMateria
{
	public:
		Cure();
		Cure(const Cure& other);
		Cure& operator=(const Cure& other);
		Cure(const std::string& type);
		~Cure();

		AMateria* clone() const;
		void use(ICharacter& target);
};

class IMateriaSource
{
	public:
		virtual ~IMateriaSource(){};
		virtual void learnMateria(AMateria* ) = 0;
		virtual AMateria* createMateria(const std::string& type) = 0;
};

class MateriaSource
{
	private:
		AMateria*	_skillSet[4];	

	public:
		MateriaSource();
		MateriaSource(const MateriaSource& other);
		MateriaSource& operator=(const MateriaSource& other);
		~MateriaSource();

		void initSkillSet();
		
		void learnMateria(AMateria* m);
		AMateria* createMateria(const std::string& type);
};
