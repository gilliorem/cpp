#include "Phonebook.hpp"

Contact::Contact(){};
Contact::~Contact(){};
void Contact::setFields()
{
	field[0] = "First Name";
	field[1] = "Last Name";
	field[2] = "Nickname";
	field[3] = "Phone";
	field[4] = "Secret";
	std::string input;
	for (int i = 0; i < 5; i++)
	{
		std::cout << field[i] << ": ";
		{
			if (!captureFieldInput(input, field[i]))
				return;
			this->field_value[i] = input;
		}
	}
}
void Contact::log()
{
	for (int i = 0; i < 3; i++)
	{
		std::cout << std::setw(10) << this->field_value[i] << "|";	
	}
	std::cout << std::endl;

}
void Contact::logAllInfo()
{
	for (int i = 0; i < 5; i++)
	{
		std::cout << this->field[i] << ": ";
		std::cout << this->field_value[i] << std::endl;
	}
	std::cout << std::endl;
}

void Contact::setName(std::string name)
{
	std::string input;
	if (!captureFieldInput(input, field_value[0]))
		return ;
	for (size_t i = 0; i < input.length(); i++)
	{
		if (isdigit(input[i]))
		{
			std::cout << "Name cannot contain digit." << std::endl;
		}
	}
	name = input;
}
std::string Contact::getFirstName()
{
	firstName = field_value[0];
	return (this->firstName);
}
void Contact::logFirstName()
{
	std::cout << this->firstName << std::endl;
}
int Contact::emptyField()
{
	for (int i = 0; i < 5; i++)
		if (field_value[i].empty())
			return 0;
	return 1;
}
