#include <cstdlib>
#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <ctime>

void makeDrillingNoise()
{
	std::system("afplay ./drilling_sound.mp3");	
} 

const std::string& RobotomyRequestForm::target() const
{
	return this->_target;
}

RobotomyRequestForm::RobotomyRequestForm():AForm("Robotomy Request Form", 72, 45), _target("default_target")
{

	std::cout << this->getName() << " created using Default constructor with Grade to Sign:" << this->getGradeToSign() << "| grade to execute:" << this->getGradeToExecute() << std::endl; 
}
RobotomyRequestForm::RobotomyRequestForm(const std::string& target):AForm("Robotomy Request Form", 72, 45), _target(target)
{
	std::cout << this->getName() << " created with this grade to sign: " << this->getGradeToSign() << " and this grade to execute: " << this->getGradeToExecute() << std::endl;	
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& other): AForm(other)
{
	std::cout << this->getName() << " created using the copy constructor.\n"; 
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this == &other)
		return *this;
	AForm::operator=(other);
	std::cout << "Copy assigement operator called.\n";
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << this->getName() << " destroyed.\n";
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (executor.getGrade() > this->getGradeToSign())
		throw AForm::GradeTooLowException();
	else if (executor.getGrade() < 1)
		throw AForm::GradeTooHighException();
	makeDrillingNoise();
	time_t sec = time(NULL);
	bool fail = false;
	if (sec % 2 == 0)
		fail = true;
	if (fail)
	{
		std::cout << "Robotomize " << this->target() << " has failed\n";
		return;
	}
	
	std::cout << this->target() << " has been robotomized\n";
}
