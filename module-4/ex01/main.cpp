#include "Animal.hpp"
#include <iostream>
int main()
{
	//Animal animals[4];

	Animal* animals[4];
	
	for (int i = 0; i < 4; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}
	for (int i = 0; i < 4; ++i)
	{
		animals[i]->makeSound();
	}

	for (int i = 0; i < 4; ++i)
		delete animals[i];

	Cat cats[2];
	std::cout << "first cat idea: " << cats[0].getIdea(0) << std::endl;
	cats[0].setIdea("miaou", 0);
	
	Cat c(cats[0]);

	std::cout << "first cat idea: " << cats[0].getIdea(0) << std::endl;
	std::cout << "cat c idea: " << c.getIdea(0) << std::endl;

	cats[0].setIdea("wouf wouf", 0);

	std::cout << "first cat idea: " << cats[0].getIdea(0) << std::endl;
	std::cout << "cat c idea: " << c.getIdea(0) << std::endl;


	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;
	return 0;
}
