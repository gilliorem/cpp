#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

Bureaucrat::Bureaucrat():_name("Default"), _grade(150)
{
	std::cout << "Bureaucrat "<< this->_name << " created with default grade:" << this->_grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other):_name(other._name), _grade(other._grade)
{
	std::cout << "Bureaucrat " << this->_name << " :[" << this << "] was creating using the copy constructor. Other bureaucrat used as reference: " << other._name << " [" << &other << "]\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this == &other)
		return *this;
	this->_name = other._name;
	this->_grade = other._grade;
	std::cout << "Bureaucrat "<< this->_name << " : [" << this << "] attributes were assigned using the operator overload '='. Other bureaucrat used as reference: " << other._name << " [" << &other << "]\n";
	return *this;
}

Bureaucrat::~Bureaucrat() { std::cout << this->_name << " Bureaucrat destroyed\n"; }

Bureaucrat::Bureaucrat(const std::string& name, const int& grade):_name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();	
	if (grade > 150)
		throw GradeTooLowException();	
	std::cout << "Bureaucrat "<< this->_name << " created using perso constructor with grade: " << this->_grade << std::endl;
}
std::ostream& operator<<(std::ostream &o, const Bureaucrat& b)
{
	o << "Bureaucrat "<< b.getName() << ", Grade: " << b.getGrade() ;
	return o;
}

const std::string& Bureaucrat::getName() const
{
	return this->_name;
}

unsigned int Bureaucrat::getGrade() const
{
	return this->_grade;
}

const char* Bureaucrat::GradeTooHighException::log() const
{
	return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::log() const
{
	return "Grade is too low";
}

void Bureaucrat::signForm(Bureaucrat& b, Form* f)
{
	try
	{
		f->beSigned(b);
		std::cout << "Bureaucrat " << b._name << " signed " << f->getName() << " form."<< std::endl;
	}
	catch (Form::GradeTooHighException& e)
	{
		std::cout << "Bureaucrat " << b._name << " couldn't sign " << f->getName() << " form. Because " 
			<< "His grade is too high: " << e.log() << std::endl;
	}
	catch (Form::GradeTooLowException& e)
	{
		std::cout << "Bureaucrat " << b._name << " couldn't sign " << f->getName() << " because " 
		<< "his grade is too low: " << e.log() << std::endl;
	}
}

