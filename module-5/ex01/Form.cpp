#include "Form.hpp"
#include <iostream>

/* Construct the Form with by default the maximum grade which is 1 */
Form::Form():_name("Default Form"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << this->_name << " created with default grades|Grade to sign:" << this->_gradeToSign << "|Grade to execute:" << this->_gradeToExecute << std::endl; 
}

Form::Form(const Form& other):_name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	std::cout << this->_name << " : [" << this << "] was creating using the copy constructor. Other bureaucrat used as reference: " << other._name << " [" << &other << "]\n";
}

Form& Form::operator=(const Form& other)
{
	if (this == &other)
		return *this;
	this->_signed = other._signed;
	std::cout << this->_name << " : [" << this << "] attributes were assigned using the operator overload '='. Other bureaucrat used as reference: " << other._name << " [" << &other << "]\n";
	return *this;
}

Form::~Form() { std::cout << this->_name << " Form destroyed\n"; }

Form::Form(const std::string& name, const unsigned int gradeToSign, const unsigned int gradeToExecute):_name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if ((gradeToSign < 1) || (gradeToExecute < 1))
		throw GradeTooHighException();	
	if ((gradeToSign > 150) || (gradeToExecute > 150))
		throw GradeTooLowException();
	std::cout << this->_name << " Form created using perso constructor with grade: " << this->_gradeToSign << " and " << this->_gradeToExecute << std::endl;
}
std::ostream& operator<<(std::ostream &o, const Form& b)
{
	o << b.getName() << ", grade to sign: " << b.getGradeToSign() << " grade to execute: " << b.getGradeToExecute() ;
	return o;
}

const std::string& Form::getName() const
{
	return this->_name;
}

unsigned int Form::getGradeToSign() const
{
	return this->_gradeToSign;
}

unsigned int Form::getGradeToExecute() const
{
	return this->_gradeToExecute;
}

bool Form::getSigned(Form *self) 
{
	if (self->_signed == true)
		return true;
	return false;
}

void Form::beSigned(Bureaucrat& b)
{
	if (b.getGrade() < 1) 
		throw GradeTooHighException();
	else if (b.getGrade() > this->_gradeToSign || b.getGrade() > 150)
		throw GradeTooLowException();
	else
		this->_signed = true;
}

const char* Form::GradeTooHighException::log() const
{
	return "Grade is too high";
}

const char* Form::GradeTooLowException::log() const
{
	return "Grade is too low";
}
