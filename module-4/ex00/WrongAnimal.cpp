#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal()
{
	std::cout << "New Wrong Animal was created using the default constructor\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	this->type = other.type;
	std::cout << this->type << " was created using the copy constructor\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	this->type = other.type;
	std::cout << this->type << " attributes were assigned using the assignment operator '='\n";
	return *this;
}

const std::string& WrongAnimal::getType() const
{
	return type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Wrong Animal makes sound\n";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Wrong animal: " << this << std::endl;
	std::cout <<  "A wrong animal was destroyed\n";
}

WrongCat::WrongCat()
{
	this->type = "Wrong Cat";
	std::cout << type << " was created using the default constructor\n";
}

WrongCat::WrongCat(const WrongCat& other)
{
	this->type = other.type;
	std::cout << this->type << " was created using the copy constructor\n";
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	this->type = other.type;
	std::cout << this->type << " attributes were assigned using the assignment operator '='\n";
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << this << std::endl;
	std::cout << this->type << " was destroyed \n";
}

void WrongCat::makeSound() const
{
	std::cout << "Weeeeam\n";
}
