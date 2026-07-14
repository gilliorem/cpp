#pragma once
#include <string>

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
		int getGrade() const;

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* log() const;
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* log() const;
		};
};

std::ostream& operator<<(std::ostream &o, const Bureaucrat& b);
