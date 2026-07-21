#pragma once
#include "Bureaucrat.hpp"
#include <string>

class AForm
{
	private:
		const std::string _name;
		bool _signed;
		const unsigned int _gradeToSign;
		const unsigned int _gradeToExecute;

	public:
		AForm();
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		AForm(const std::string& name, const unsigned int gradeToSign, const unsigned int gradeToExecute);
		virtual ~AForm();

		virtual const std::string& getName() const = 0;
		unsigned int getGradeToSign() const;
		unsigned int getGradeToExecute() const;

		/* To be able to use a pointer to the form instance I use the parameter `self` */
		static bool getSigned(AForm* self);

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

std::ostream& operator<<(std::ostream& o, const AForm& f);
