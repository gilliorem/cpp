#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>
#include <cstdio>

int createAsciiTreeFile(std::string target)
{
	std::string postfix = "_shrubbery";
	std::string filename = target.append(postfix);

	std::ofstream file(filename.c_str());

	if (!file.is_open())
	{
		std::cerr << "Error: could not open file\n";
		return 1;
	}

	for (int i = 0; i < 3; ++i)
	{
		file << "   @  \n";
		file << "  @@@ \n";
		file << " @@@@ \n";
		file << "@@@@@@\n";
		file << "  ||\n";
		file << "  ||\n";
		file << "  ||\n";

	}
	file.close();

	return 0;
} 


int writeBonsai(std::string target)
{
	std::string postfix = "_shrubbery";
	std::string filename = target.append(postfix);

	std::ofstream file(filename.c_str());

	if (!file.is_open())
	{
		std::cerr << "Error: can't open file\n";
		return 1;
	}

	FILE* pipe = popen("/home/regillio/.local/bin/pybonsai -i", "r");
	//FILE* pipe = popen("/usr/local/bin/pybonsai -i", "r"); // MAC OS
	if (!pipe)
	{
		return 1;
	}
	char c_buffer[4096];
	while (fgets(c_buffer, sizeof(c_buffer), pipe) != NULL)
	{
		file << c_buffer;
	}
	
	file.close();

	pclose(pipe);
	return 0;
}


const std::string& ShrubberyCreationForm::target() const
{
	return this->_target;
}

ShrubberyCreationForm::ShrubberyCreationForm():AForm("Shrubbery Creation Form", 145, 137), _target("default_target")
{
	std::cout << this->getName() << " created using Default constructor with Grade to Sign:" << this->getGradeToSign() << "| grade to execute:" << this->getGradeToExecute() << std::endl; 
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target):AForm("Shrubbery Creation Form", 145, 137), _target(target)
{
	std::cout << this->getName() << " created with this grade to sign: " << this->getGradeToSign() << " and this grade to execute: " << this->getGradeToExecute() << std::endl;	
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& other): AForm(other)
{
	std::cout << this->getName() << " created using the copy constructor.\n"; 
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this == &other)
		return *this;
	AForm::operator=(other);
	std::cout << "Copy assignment operator called.\n";
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << this->getName() << " destroyed.\n";
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (executor.getGrade() > this->getGradeToSign())
		throw AForm::GradeTooLowException();
	else if (executor.getGrade() < 1)
		throw AForm::GradeTooHighException();
	//createAsciiTreeFile(this->target());
	writeBonsai(this->target());
}
