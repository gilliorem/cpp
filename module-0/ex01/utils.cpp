#include "Phonebook.hpp"

int captureFieldInput(std::string &str, std::string field)
{
	if (!std::getline(std::cin, str))
	{
		std::cout << "Ctrl-d exiting..." << std::endl;
		exit (1);
	}
	while (str.empty())
	{
		std::cout << "Please enter a valid field." << std::endl;
		std::cout << field << ":";
		std::getline(std::cin, str);
	}
	if (str.length() > 10)
	{
		str = str.substr(0,9);
		str+= '.';
	}
	return 1;
}

