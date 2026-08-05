#include "AForm.hpp"
#include <string>
class Intern
{
	private:
		Intern(Intern& other);
		Intern& operator=(Intern& other);
	public:
		Intern();
		~Intern();

		AForm* makeForm(std::string formName, std::string formTarget);
};
