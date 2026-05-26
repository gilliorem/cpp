#include "Phonebook.hpp"

PhoneBook::PhoneBook() : count(0), index(count % 8){}

void PhoneBook::addContact()
{
	index = count % 8;
	contact[index].setFields();
	if (count < 8)
		count++;
}

void PhoneBook::displayContacts()
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
