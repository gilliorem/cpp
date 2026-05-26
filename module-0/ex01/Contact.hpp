#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact
{
	private:
		std::string field_value[5];
		std::string firstName;
	public:
		Contact();
		~Contact();
		std::string field[5];
		void setFields();
		void log();
		void logAllInfo();
		void setName(std::string name);
		std::string getFirstName();
		void logFirstName();
		int emptyField();
};

#endif
