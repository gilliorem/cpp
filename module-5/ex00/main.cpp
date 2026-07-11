#include <string>
#include <iostream>

class Bureaucrat
{
	private: 
		std::string _name;
		unsigned int _grade;
	
	public:
		const std::string& getName();

		const int getGrade();

		Bureaucrat();
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		Bureaucrat(const std::string& name, const int& grade);

		class Exeception
		{
			std::exception& GradeToHighException()
			{
				throw "Grade to high\n";
			}
			std::exception& GradeToLowException(std::exception& e)
			{
				throw e.what();
			}
		};
};

Bureaucrat::Bureaucrat():_name(""), _grade(1)
{
	std::cout << "A Bureaucrat was created using the default constructor\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
//	this->_name = other._name;
//	this->_grade = other._grade;
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
		
	if (grade > 150)

	std::cout << this->_name << " created using the personalized constructor\n";
}

const std::string& Bureaucrat::getName()
{
	return this->_name;
}

const int Bureaucrat::getGrade()
{
	return this->_grade;
}

int main()
{


	Bureaucrat* yuchi = new Bureaucrat("Yuchi", 150);
	std::cout << "[" << yuchi << "]\n";
	std::cout << yuchi->getName() << std::endl;
	std::cout << yuchi->getGrade() << std::endl;

	Bureaucrat* remi = new Bureaucrat(*yuchi);
	std::cout << remi->getName() << std::endl;

	try
	{
		remi++;
		catch (remi::GradeToHighGradeException)
		{
			
		}
	}

	

}
