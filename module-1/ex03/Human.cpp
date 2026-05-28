#include <iostream>
#include "Human.hpp"

Human::Human(std::string const &name): _name(name)
{
	std::cout << _name << " is born" << std::endl;
}
Human::~Human()
{
	std::cout << _name << " died" << std::endl;
}
