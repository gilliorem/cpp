#include <iostream>
#include <exception>
#include "ShrubberyCreationForm.hpp"

int main()
{
	Bureaucrat b("Remi", 146);
	AForm *a = new ShrubberyCreationForm();

	std::cout << a->getGradeToSign() << std::endl;
	std::cout << a->getGradeToExecute() << std::endl;

	b.signForm(a); // should not be able to sign...
	
	
	
	return 0;
}
