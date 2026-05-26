#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# include <iostream>
# include <string>
# include <iomanip>
# include <sstream>
# include "Contact.hpp"

int captureFieldInput(std::string &str, std::string field);
class PhoneBook
{
	private:
		static const int MAX_CONTACTS = 8;
		Contact contact[MAX_CONTACTS];
		int count;
		int index;
	public:
		PhoneBook();
		void addContact();
		void displayContacts();
};


#endif
