#include "ShrubberyCreationForm.hpp"
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm():_name("Shrubbery Creation Form"), _signed(false), _gradeToSign(145), _gradeToExecute(137)
{
	std::cout << this->_name << " created using Defaut constructor.\n"; 
}


ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& other): _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	std::cout << this->_name << " created using the copy constructor.\n"; 
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm& other)
{
	if (this == &other)
		return *this;
	*this = other;

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
