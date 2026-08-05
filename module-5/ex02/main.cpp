#include <iostream>
#include <exception>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat b("Remi", 4);
	
	AForm *a = new ShrubberyCreationForm(); // should not create a file
	//AForm *a = new PresidentialPardonForm(); // should not create a file
	
	a->execute(b);

	std::cout << a->getGradeToSign() << std::endl;
	std::cout << a->getGradeToExecute() << std::endl;

	b.signForm(a); 
	
	delete a;		
	
	return 0;
}
