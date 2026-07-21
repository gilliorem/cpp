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
		ShrubberyCreationForm& operator=(ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		virtual const std::string& getName() const;
	

};


