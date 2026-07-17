#pragma once
#include "Bureaucrat.hpp"
#include <string>

class Form
{
	private:
		const std::string _name;
		bool _signed;
		const unsigned int _gradeToSign;
		const unsigned int _gradeToExecute;

	public:
		Form();
		Form(const Form& other);
		Form& operator=(const Form& other);
		Form(const std::string& name, const unsigned int gradeToSign, const unsigned int gradeToExecute);
		~Form();

		const std::string& getName() const;
		unsigned int getGradeToSign() const;
		unsigned int getGradeToExecute() const;

		/* To be able to use a pointer to the form instance I use the parameter `self` */
		static bool getSigned(Form* self);

		void beSigned(Bureaucrat& b) ;

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

std::ostream& operator<<(std::ostream& o, const Form& f);
