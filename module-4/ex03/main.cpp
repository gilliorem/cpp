#include "Materia.hpp"
#include "Character.hpp"
#include <iostream>

int main()
{
	MateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;

	/* uncomment the line below to run more test */
	//return 0;

	AMateria* materia = new Ice("ice");
	AMateria* clone = materia->clone();
	AMateria* cureMateria = new Cure("cure");
	AMateria* cureClone = cureMateria->clone();

	std::cout << materia->getType() << std::endl;
	std::cout << clone->getType() << std::endl;
	std::cout << cureMateria->getType() << std::endl;
	std::cout << cureClone->getType() << std::endl;

	std::cout << "===== Character creation =====" << std::endl;

	/* Uncomment the 2 lines below to run test using memory stack */
	//Character mandrag("Mandragold");
	//Character mandrar("Mandrage");
	Character* mandrag = new Character("Mandragold");
	Character* mandrar = new Character("Mandrage");

	mandrag->equip(materia);
	mandrag->use(0, *mandrar);
	mandrar->equip(cureClone);
	mandrar->use(0, *mandrar);

	std::cout << "===== Materia Source =====" << std::endl;

	MateriaSource* source = new MateriaSource();
	source->learnMateria(new Ice("ice"));
	source->learnMateria(new Cure("cure"));
	return 0;
}
