#include <string>
#include <iostream>
#include <functional>

// we tell the compiler that a Class Animal is coming
class Animal;

typedef void (*soundFounc)(Animal*); // this function pointer will act as our variable that is going to be overwritten. it has to take an Animal pointer in parameter.

void defaultSound(Animal* self);
class Animal 
{
	private:
//		std::function<void(Animal*)> over_makeSound = func;
	protected:
		std::string type = "Animal";
		soundFounc makeSoundFunc;
		//std::function<void(Animal*)> new_makeSound;
	public:
		void makeSound() // We will overwrite the function pointer var with makesound
		{
			this->makeSoundFunc(this);
		}
};

void meaw(Animal* self){std::cout << "Meaw!\n";}
class Cat:public Animal
{
	private:
	std::string type = "Cat";

	public:
		Cat()
		{
			this->makeSoundFunc = meaw;
		}
};

void bark(Animal* self){std::cout << "Wouf!\n";}
class Dog:public Animal
{
	private:
	std::string type = "Dog";

	public:
		Dog()
		{
			this->makeSoundFunc = bark;
		}
		
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
		animal[i].makeSound();
	}
}
