#pragma once
#include <string>

class Form
{
	private:
		const std::string _name;
		bool _signed;
		unsigned int _gradeToSign;
		unsigned int _gradeToExecute;

	public:
		Form();
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

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

std::ostream& operator<<(std::ostream& o, const Form& f);
