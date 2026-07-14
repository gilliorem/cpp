#include <string>
#include <iostream>
#include <functional>

// we add a function pointer 



class Animal 
{
	private:
//		std::function<void(Animal*)> over_makeSound = func;
	protected:
		std::string type = "Animal";
		std::function<void(Animal*)> new_makeSound;
	
	public:
		virtual void makeSound(){};

};

class Cat:public Animal
{
	private:
	std::string type = "Cat";

	public:
		Cat(){std::cout << type << std::endl;}
		void makeSound() override {std::cout << "Miaou" << std::endl;}
		new_makeSound = makeSound;
		
};

class Dog:public Animal
{
	private:
	std::string type = "Dog";

	public:
		Dog(){std::cout << type << "\n";}
		void makeSound() override {std::cout << "Waouf" << std::endl;}
		new_makeSound = makeSound;
		
};

int main()
{
	Animal animal[10];
	//Animal* animal[10]; // this is an array of 10 pointers to Animal object 
	for (int i = 0; i < 10; ++i)
	{
		if (i % 2 == 0)
			animal[i] = Cat();
		else
			animal[i] = Dog();
	}
	for (int i = 0; i < 10; ++i)
	{
		animal[i].new_makeSound();
	}
}
