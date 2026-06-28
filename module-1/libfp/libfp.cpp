#include "libfp.hpp"
#include <cstdlib> //std::rand()
#include <iostream>
void log(std::string const &msg)
{
	std::cout << msg << std::endl;
}

std::string generateRandomName()
{
	char randomName[11];
	for (int i = 0; i < 11; i++)
		randomName[i] = '\0';
	char letters[] = "abcdefghijklmnopqrstuvwxyz";
	for (int i = 0; i < std::rand() % 10 + 1; i++)
		randomName[i] = letters[std::rand() % 26];
	randomName[0]-=32;
	randomName[10] = '\0';	
	std::string s(randomName);
	return s;
	
}

// can use a class Display
// can use function pointer.

class Attribute
{
	public:
		virtual ~Attribute();
		virtual void display(std::ostream &o) const = 0;
};


/*
void displayAttributes(ClapTrap &)
{
	index = count % 8;
	if (count < 1)
	{
		std::cout << "There is no contact in your phonebook !" << std::endl;
		return ;
	}
	std::cout << std::setw(10) << "index" << "|";
	std::cout << std::setw(10) << "First name" << "|";
	std::cout << std::setw(10) << "Last name" << "|";
	std::cout << std::setw(10) << "Nickname" << "|";
	std::cout << std::endl;
	for (int i = 0; i < count; i++)
	{
		std::cout << std::setw(10) << i << "|";
		contact[i].log();
	}
	std::cout << "input index: ";
	std::string input;
	captureFieldInput(input, "input index: ");
	int num;
	std::istringstream iss(input);
	if (!(iss >> num) || !iss.eof() || num < 0 || num >= count)
	{
		std::cout << "Please Enter a valid index" << std::endl;
		return;
	}
	//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // flush
	contact[num].logAllInfo();	
}
*/
