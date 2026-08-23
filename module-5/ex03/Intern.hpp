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

		AForm* makeForm(const std::string& formName, const std::string& formTarget);
};
