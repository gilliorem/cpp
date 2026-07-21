#include "ShrubberyCreationForm.hpp"
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm():_name("Shrubbery Creation Form"), _signed(false), _gradeToSign(145), _gradeToExecute(137)
{
	std::cout << this->_name << " created using Default constructor with Grade to Sign:" << this->_gradeToSign << "| grade to execute:" << this->_gradeToExecute << std::endl; 
}


ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& other): _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	std::cout << this->_name << " created using the copy constructor.\n"; 
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this == &other)
		return *this;
	this->_signed = other._signed;
	std::cout << "Copy assignement operator called.\n";
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << this->_name << " destroyed.\n";
}

const std::string& ShrubberyCreationForm::getName() const
{
	return this->_name;
}

unsigned int ShrubberyCreationForm::getGradeToSign() const 
{
	return this->_gradeToSign;
}

unsigned int ShrubberyCreationForm::getGradeToExecute() const 
{
	return this->_gradeToExecute;
}

void ShrubberyCreationForm::beSigned(Bureaucrat& b)
{
	if (b.getGrade() < 1) 
		throw GradeTooHighException();
	else if (b.getGrade() > this->_gradeToSign || b.getGrade() > 150)
	{
		throw GradeTooLowException();
	}
	else
	{
		this->_signed = true;
	}
}
