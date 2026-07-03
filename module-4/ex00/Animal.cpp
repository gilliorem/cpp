#include "Animal.hpp"
#include <iostream>

Animal::Animal()
{
	std::cout << "New Animal was created using the default constructor\n";
}

Animal::Animal(const Animal& other)
{
	this->type = other.type;
	std::cout << this->type << " was created using the copy constructor\n";
}

Animal& Animal::operator=(const Animal& other)
{
	this->type = other.type;
	std::cout << this->type << " attributes were assigned using the assignment operator '='\n";
	return *this;
}

const std::string& Animal::getType() const
{
	return type;
}

void Animal::makeSound() const
{
	std::cout << "Animal makes sound\n";
}

Animal::~Animal()
{
	std::cout <<  "An animal was destroyed\n";
}

Dog::Dog()
{
	this->type = "Dog";
	std::cout << type << " was created using the default constructor\n";
}

Dog::Dog(const Dog& other)
{
	this->type = other.type;
	std::cout << this->type << " was created using the copy constructor\n";
}

Dog& Dog::operator=(const Dog& other)
{
	this->type = other.type;
	std::cout << this->type << " attributes were assigned using the assignment operator '='\n";
	return *this;
}

Dog::~Dog()
{
	std::cout << this->type << " was destroyed \n";
}

void Dog::makeSound() const
{
	std::cout << "Wouaf Wouaf Wouaf!\n";
}

Cat::Cat():Animal()
{
	this->type = "Cat";
	std::cout << type << " was created using the default constructor\n";
}

Cat::Cat(const Cat& other)
{
	this->type = other.type;
	std::cout << this->type << " was created using the copy constructor\n";
}

Cat& Cat::operator=(const Cat& other)
{
	this->type = other.type;
	std::cout << this->type << " attributes were assigned using the assignment operator '='\n";
	return *this;
}

Cat::~Cat()
{
	std::cout << this->type << " was destroyed \n";
}

void Cat::makeSound() const
{
	std::cout << "Meeeeaww\n";
}
