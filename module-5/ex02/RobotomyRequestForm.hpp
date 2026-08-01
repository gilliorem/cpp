#pragma once
#include "AForm.hpp"

/* _gradeToSign: 72 
 * _gradeToExecute: 45 
 * Makes some drilling noises, then informs that <target> has been robotomized
 successfully 50% of the time. Otherwise, it informs that the robotomy failed.
 * */

class RobotomyRequestForm: public AForm
{
	private:
		const std::string _target;
	
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm();

		const std::string& target() const;
		
		void execute(const Bureaucrat& executor) const;

};

void makeDrillingNoise();
