#include "libfp.hpp"
#include <cstdlib> //std::rand()
#include <iostream>
#include <iomanip>

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

void displayStringAttribute(std::string attribute, std::string& attributeValue)
{
	std::cout << std::setw(10) << attribute << ":" << std::setw(10) << attributeValue << "|";
}

void displayIntAttribute(std::string attribute, int attributeValue)
{
	std::cout << std::setw(10) << attribute << ":" << std::setw(10) << attributeValue << "|";
}

int captureFieldInput(std::string &str, std::string field)
{
	if (!std::getline(std::cin, str))
	{
		std::cout << "Ctrl-d exiting..." << std::endl;
		exit (1);
	}
	while (str.empty())
	{
		std::cout << "Field empty. Please enter a valid field." << std::endl;
		std::cout << field << ":";
		if (!std::getline(std::cin, str))
		{
			std::cout << "Ctrl-d exiting\n";
			exit (1);
		}
	}
	return 1;
}

