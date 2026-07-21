#pragma once
#include "AForm.hpp"

/* _gradeToSign: 145 
 * _gradeToExecute: 137 
 * creates a file <target>_shrubbery in ./ and write ascii trees in it.	
 * */

class ShrubberyCreationForm: public AForm
{
	private:
	const std::string _name;
	bool _signed;
	const unsigned int _gradeToSign;
	const unsigned int _gradeToExecute;
	
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		const std::string& getName() const;
		virtual unsigned int getGradeToSign() const;
		virtual unsigned int getGradeToExecute() const;
		
		virtual void beSigned(Bureaucrat& b);

};


