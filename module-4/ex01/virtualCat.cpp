#include <string>
#include <iostream>

class Animal 
{
	protected:
		std::string type = "Animal";
	
	public:
		virtual void makeSound(){};

};

class Cat:public Animal
{
	std::string type = "Cat";

	public:
		Cat(){std::cout << type << std::endl;}
		virtual void makeSound() override {std::cout << "Miaou" << std::endl;}
		
};

class Dog:public Animal
{
	std::string type = "Dog";

	public:
		Dog(){std::cout << type << "\n";}
		virtual void makeSound() override {std::cout << "Waouf" << std::endl;}
		
};

int main()
{
	//Animal animal[10];
	Animal *animal[10];
	for (int i = 0; i < 10; ++i)
	{
		if (i % 2 == 0)
			animal[i] = new Cat();
		else
			animal[i] = new Dog();
	}
	for (int i = 0; i < 10; ++i)
	{
		animal[i]->makeSound();
	}
}
