#include "PresidentialPardonForm.hpp"
#include <iostream>

void pardon(const std::string& target)
{
	std::cout << target << " has been forgiven\n";
} 

const std::string& PresidentialPardonForm::target() const
{
	return this->_target;
}

PresidentialPardonForm::PresidentialPardonForm():AForm("Presidential Pardon Form", 72, 45), _target("default_target")
{

	std::cout << this->getName() << " created using Default constructor with Grade to Sign:" << this->getGradeToSign() << "| grade to execute:" << this->getGradeToExecute() << std::endl; 
}
PresidentialPardonForm::PresidentialPardonForm(const std::string& target):AForm("Presidential Pardon Form", 72, 45), _target(target)
{
	std::cout << this->getName() << " created with this grade to sign: " << this->getGradeToSign() << " and this grade to execute: " << this->getGradeToExecute() << std::endl;	
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& other): AForm(other)
{
	std::cout << this->getName() << " created using the copy constructor.\n"; 
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this == &other)
		return *this;
	AForm::operator=(other);
	std::cout << "Copy assigement operator called.\n";
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << this->getName() << " destroyed.\n";
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (executor.getGrade() > this->getGradeToSign())
		throw AForm::GradeTooLowException();
	else if (executor.getGrade() < 1)
		throw AForm::GradeTooHighException();
	pardon(this->target());
}
