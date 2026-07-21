#include "Form.hpp"
#include <iostream>
#include <exception>

int main()
{
	Bureaucrat b("Remi", 52);
	Form f("Feedback", 51, 40);

	// Remi should not be able to sign this form.
	// because 
	// Remi sucks.
	b.signForm(b, &f);
	
	return 0;
}
