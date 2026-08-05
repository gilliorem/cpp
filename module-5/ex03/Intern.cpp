#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

Intern::Intern() {}
Intern::~Intern() {}

AForm* Intern::makeForm(std::string formName, std::string formTarget)
{
	AForm* formptr = NULL;
	std::string formNames[] = 
	{
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	int formIndex = -1;

	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			formIndex = i;
			break;
		}
	}


	switch (formIndex)
	{
		case 0:
			std::cout << "Intern creates " << formName << std::endl;
			formptr = new ShrubberyCreationForm(formTarget);
			break;
		case 1:
			std::cout << "Intern created " << formName << std::endl;
			formptr = new RobotomyRequestForm(formTarget);
			break;
		case 2:
			std::cout << "Intern created " << formName << std::endl;
			formptr = new PresidentialPardonForm(formTarget);
			break;
		default:
			std::cout << "Error: "<< formName << " form does not exist\n";
	}
	return formptr;
}
