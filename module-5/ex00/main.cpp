#include <string>
#include <iostream>
#include <exception>

class Bureaucrat
{
	private: 
		std::string _name;
		unsigned int _grade;
	
	public:

		Bureaucrat();
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		Bureaucrat(const std::string& name, const int& grade);

		Bureaucrat& operator++();
		Bureaucrat operator++(int);
		
		const std::string& getName() const;
		const int getGrade() const;

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const noexcept;
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const noexcept;
		};
};

std::ostream& operator<<(std::ostream &o, const Bureaucrat& b);

std::ostream& operator<<(std::ostream &o, const Bureaucrat& b)
{
	o << b.getName() << ", bureaucrat grade: " << b.getGrade() ;
	return o;
}



const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
	return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
	return "Grade is too low";
}

Bureaucrat::Bureaucrat():_name("Default"), _grade(150)
{
	std::cout << this->_name << " created with default grade:" << this->_grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
	*this = other;
	std::cout << this->_name << " Bureaucrat: [" << this << "] was creating using the copy constructor. Other bureaucrat used as reference: " << other._name << " [" << &other << "]\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this == &other)
		return *this;
	this->_name = other._name;
	this->_grade = other._grade;
	*this = other;

	std::cout << this->_name << " Bureaucrat: [" << this << "] attributes were assigned using the operator overload '='. Other bureaucrat used as reference: " << other._name << " [" << &other << "]\n";

	return *this;
}

Bureaucrat::~Bureaucrat() { std::cout << this->_name << " Bureaucrat destroyed\n"; }

Bureaucrat::Bureaucrat(const std::string& name, const int& grade):_name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();	
	if (grade > 150)
		throw GradeTooLowException();	

	std::cout << this->_name << " created using perso constructor with grade: " << this->_grade << std::endl;
}

const std::string& Bureaucrat::getName() const
{
	return this->_name;
}

const int Bureaucrat::getGrade() const
{
	return this->_grade;
}

int main()
{
	Bureaucrat* yuchi ;
	try
	{
		yuchi= new Bureaucrat("Yuchi", 151);
//		Bureaucrat* b = new Bureaucrat("Baptiste", 151);
//		Bureaucrat* btwo = new Bureaucrat("Brice", 0);


		Bureaucrat *remi = yuchi;
		std::cout << remi->getName() << std::endl;
		std::cout << *yuchi << std::endl;
		delete yuchi;
//		delete b;
//		delete btwo;

		
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cout << "GradeTooHighException: " << e.what() << std::endl;	
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cout << "GradeTooLowException: " << e.what() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	if (yuchi)
		delete yuchi;
	return 0;
}
