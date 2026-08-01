#pragma once
#include "AForm.hpp"

/* _gradeToSign: 145 
 * _gradeToExecute: 137 
 * creates a file <target>_shrubbery in ./ and write ascii trees in it.	
 * */

class ShrubberyCreationForm: public AForm
{
	private:
	const std::string _target;
	
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		const std::string& target() const;
		
		void execute(const Bureaucrat& executor) const;

};

int createAsciiTreeFile(std::string target);
