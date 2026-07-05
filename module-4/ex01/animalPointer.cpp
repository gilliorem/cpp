#include <string>
#include <iostream>

// we tell the compiler that a Class Animal is coming
class Animal;

typedef void (*soundFunc)(Animal*); // this function pointer will act as our variable that is going to be overwritten. it has to take an Animal pointer in parameter.

void defaultSound(Animal* self){std::cout << "*Random animal sound*\n";}; //  this argument `self` represent the Animal pointer define in our typedef `soundFunc`
class Animal 
{
	private:
	protected:
		std::string type = "Animal";
		soundFunc makeSoundFunc; // every childr member will have a makeSoundFunc function of type `soundFunc`
	public:
		void makeSound() // We will overwrite the function pointer var with makesound
		{
			this->makeSoundFunc(this); // we assign the specific function based on the type (Animal/Dog/Cat) 
			//                    ^->will change based on the type | Dog | Cat // though at this point, how does the compiler knows that it needs to call defaultSound ?
		}
		Animal()
		{
			this->makeSoundFunc = defaultSound;
			//makeSound();
			//makeSound();
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
	for (int i = 0; i < 10; ++i)
		animal[i].makeSound(); 
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
