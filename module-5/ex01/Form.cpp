#include "Form.hpp"
#include <iostream>

Form::Form():_name("Default Form"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << this->_name << " created with default grade:\n";
}

Form::Form(const Form& other)
{
	*this = other;
	std::cout << this->_name << " Form: [" << this << "] was creating using the copy constructor. Other bureaucrat used as reference: " << other._name << " [" << &other << "]\n";
}

Form& Form::operator=(const Form& other)
{
	if (this == &other)
		return *this;
	this->_name = other._name;
	this->_grade = other._grade;
	*this = other;
	std::cout << this->_name << " Form: [" << this << "] attributes were assigned using the operator overload '='. Other bureaucrat used as reference: " << other._name << " [" << &other << "]\n";
	return *this;
}

Form::~Form() { std::cout << this->_name << " Form destroyed\n"; }

Form::Form(const std::string& name, const int& grade):_name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();	
	if (grade > 150)
		throw GradeTooLowException();	
	std::cout << this->_name << " created using perso constructor with grade: " << this->_grade << std::endl;
}
std::ostream& operator<<(std::ostream &o, const Form& b)
{
	o << b.getName() << ", bureaucrat grade: " << b.getGrade() ;
	return o;
}

const std::string& Form::getName() const
{
	return this->_name;
}

int Form::getGrade() const
{
	return this->_grade;
}

const char* Form::GradeTooHighException::log() const
{
	return "Grade is too high";
}

const char* Form::GradeTooLowException::log() const
{
	return "Grade is too low";
}


