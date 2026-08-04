#include <iostream>
#include <exception>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	Bureaucrat b("Remi", 4);
//	AForm *a = new ShrubberyCreationForm(); // should not create a file
	AForm *a = new RobotomyRequestForm(); // should not create a file
	
	a->execute(b);
	return 0;

	std::cout << a->getGradeToSign() << std::endl;
	std::cout << a->getGradeToExecute() << std::endl;

	b.signForm(a); // should not be able to sign...
	
	
	
	return 0;
}
