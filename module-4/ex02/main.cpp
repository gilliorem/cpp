#include "AAnimal.hpp"
#include <iostream>
/*
int main()
{
	Animal animals[4];
	
	for (int i = 0; i < 4; i++)
	{
		if (i % 2 == 0)
		{
			animals[i] = Cat();
		}
		else
			animals[i] = Dog();
	}

	Cat cats[2];
	std::cout << "first cat idea: " << cats[0].getIdea(0) << std::endl;
	cats[0].setIdea("miaou", 0);
	
	Cat c(cats[0]);

	std::cout << "first cat idea: " << cats[0].getIdea(0) << std::endl;
	std::cout << "cat c idea: " << c.getIdea(0) << std::endl;

	cats[0].setIdea("wouf wouf", 0);

	std::cout << "first cat idea: " << cats[0].getIdea(0) << std::endl;
	std::cout << "cat c idea: " << c.getIdea(0) << std::endl;




	return 0;
}
*/

int main()
{
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	delete j;//should not create a leak
	delete i;
	//const Animal animal; zhege bu kei
	//const Animal* a = new Animal(); zhege ye bu kei in wei abstract ke
	return 0;
}
