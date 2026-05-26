#include "Phonebook.hpp"

void welcome()
{
	std::cout << "========== MY SCRAPY PHONEBOOK ==========" << std::endl;
}

void chooseOption(PhoneBook &phonebook)
{
	std::cout << "ADD" << std::endl;	
	std::cout << "SEARCH" << std::endl;	
	std::cout << "EXIT" << std::endl;

	std::string option;

	std::cout << "> ";
	captureFieldInput(option, "> ");
	if (option == "ADD")
		phonebook.addContact();
	else if (option == "SEARCH")
		phonebook.displayContacts();
	else if (option == "EXIT")
		exit (0);
	else
		std::cout << "Please enter a valid option" << std::endl;
}

int main()
{
	PhoneBook phonebook;
	welcome();
	while (1)
	{
		chooseOption(phonebook);		
	}
	return 0;
}
