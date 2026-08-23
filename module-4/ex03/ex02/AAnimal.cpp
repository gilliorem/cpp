#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal()
{
	std::cout << "New AAnimal was created using the default constructor\n";
}

AAnimal::AAnimal(const AAnimal& other)
{
	this->type = other.type;
	std::cout << this->type << " was created using the copy constructor\n";
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
	this->type = other.type;
	std::cout << this->type << " attributes were assigned using the assignment operator '='\n";
	return *this;
}

const std::string& AAnimal::getType() const
{
	return type;
}

AAnimal::~AAnimal()
{
	std::cout <<  "An animal was destroyed\n";
}

Brain::Brain()
{
	std::cout << "New Brain was created using the default constructor\n";
}

Brain::Brain(const Brain& other)
{
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = other.ideas[i];
	}
	std::cout << this->ideas << " was created using the copy constructor\n";
}

Brain& Brain::operator=(const Brain& other)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
	std::cout << this->ideas << " attributes were assigned using the assignment operator '='\n";
	return *this;
}

Brain::~Brain()
{
	std::cout <<  "A Brain was destroyed\n";
}

const std::string& Brain::getIdea(int index) const
{
	return ideas[index];
}

void Brain::setIdea(const std::string& idea, int index)
{
	ideas[index] = idea;
}

Dog::Dog()
{
	this->type = "Dog";
	this->brain = new Brain();
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
	this->brain = other.brain;
	std::cout << this->type << " attributes were assigned using the assignment operator '='\n";
	return *this;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << this->type << " was destroyed \n";
}

void Dog::makeSound() const
{
	std::cout << "Wouaf Wouaf Wouaf!\n";
}

Cat::Cat():AAnimal()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << type << " was created using the default constructor\n";
}

Cat::Cat(const Cat& other)
{
	this->type = other.type;
	this->brain = new Brain(*other.brain);
	std::cout << this->type << " was created using the copy constructor\n";
}

Cat& Cat::operator=(const Cat& other)
{
	this->type = other.type;
	//this->brain = new Brain(*other.brain);
	*this->brain = *other.brain;
	//this->brain = other.brain;
	std::cout << this->type << " attributes were assigned using the assignment operator '='\n";
	return *this;
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << this->type << " was destroyed \n";
}

const std::string& Cat::getIdea(int index) const
{
	return brain->getIdea(index);
}

void Cat::setIdea(const std::string& idea, int index)
{
	brain->setIdea(idea, index);
}


void Cat::makeSound() const
{
	std::cout << "Meeeeaww\n";
}

int main()
{
	AAnimal a;
}
