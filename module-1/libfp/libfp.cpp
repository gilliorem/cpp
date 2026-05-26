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
