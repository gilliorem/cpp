#include <string>

class Animal
{
	protected:
		std::string type;
};

class Dog: public Animal
{
	public:
		void makeSound();
};

class Cat: public Animal
{
	public:
		void makeSound();
};
