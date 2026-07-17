#include "Form.hpp"
#include <iostream>
#include <exception>

int main()
{
	Bureaucrat b;
	Form f;

	b.signForm(b, f);
	
	return 0;
}
