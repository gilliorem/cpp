#include <iostream>
#include <functional>
#include <string>

class Animal 
{
	protected:
		std::function<void()> onMakeSound;
	
	public:
		Animal()
		{
			onMakeSound = [this]() { this->makeSound(); };
		}
		void makeSound()
		{
			std::cout << "Animal makes sound\n";
		}
		void executeSound()
		{
			onMakeSound();
		}

};

class Dog: public Animal
{
	public:
		Dog()
		{
			onMakeSound = [this]() { this->makeSound(); };
		}
		void makeSound()
		{
			std::cout << "Wouf!\n";
		}
};

int main() {

	Animal a[2];
	a[0].makeSound(); //Animal makes sound
	for (int i = 0; i < 2; i++)
		a[i] = Dog();
	for (int i = 0; i < 2; i++)
		a[i].executeSound(); //Wouf !

	return 0;
}
