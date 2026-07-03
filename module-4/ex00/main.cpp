#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include <iostream>

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const Cat a;
	std::cout << a.getType() << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	const WrongAnimal* wrongCat = new WrongCat();
	std::cout << wrongCat->getType() << std::endl;
	wrongCat->makeSound();

	return 0;
}
