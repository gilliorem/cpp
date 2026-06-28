#pragma once
#include <string>
#include <iostream>
#include <iomanip>

class Attribute
{
	public:
		virtual void display(std::ostream& os) const = 0;
};

void log(std::string const &msg);
std::string generateRandomName();
int captureFieldInput(std::string &str, std::string field);
void displayStringAttribute(std::string attribute, std::string& attributeValue);
void displayIntAttribute(std::string attribute, int attributeValue);


/*
class Contact : public Attribute 
{
	private:
		std::string _name;
		//char _name[10];
	public:
		void display(std::ostream &os) const override
		{
			os << "Name: " << _name << std::endl ;
		}
};
*/
