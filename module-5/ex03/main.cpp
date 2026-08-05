#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Intern intern;

	AForm* formPtr;	

	formPtr = intern.makeForm("robotomy request", "home");

	Bureaucrat bureaucrat("Jean-Michel", 42);

	bureaucrat.signForm(formPtr);	

	formPtr->execute(bureaucrat);

	return 0;
	
	Bureaucrat b("Remi", 4);
	
	AForm *a = new ShrubberyCreationForm(); 
	//AForm *a = new PresidentialPardonForm(); 
	
	a->execute(b);

	std::cout << a->getGradeToSign() << std::endl;
	std::cout << a->getGradeToExecute() << std::endl;

	b.signForm(a); 
	
	delete a;		
	
	return 0;
}
