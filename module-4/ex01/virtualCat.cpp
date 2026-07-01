#include <string>
#include <iostream>

class Animal 
{
	protected:
		std::string type = "Animal";
	
	public:
		void makeSound(){};

};

class Cat:public Animal
{
	std::string type = "Cat";

	public:
		Cat(){std::cout << type << std::endl;}
		void makeSound(){std::cout << "Miaou" << std::endl;}
		
};



class Dog:public Animal
{
	std::string type = "Dog";

	public:
		Dog(){std::cout << type << "\n";}
		void makeSound(){std::cout << "Waouf" << std::endl;}
		
};

int main()
{
	Animal animal[10];

	for (int i = 0; i < 10; ++i)
	{
		if (i % 2 == 0)
			animal[i] = Cat();
		else
			animal[i] = Dog();
	}
	for (int i = 0; i < 10; ++i)
	{
		animal[i].makeSound();
	}
}
