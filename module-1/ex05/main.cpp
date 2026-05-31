#include <string>
#include <iostream>
class Harl
{
	private:
		void debug();
		void info();
		void warning();
		void error();

	public:
		void complain(std::string level);

		struct table 
		{
			std::string level;
			void (*func) (void);
		};
};

/* table[0] = { "DEBUG",   &Harl::debug   }
table[1] = { "INFO",    &Harl::info    }
table[2] = { "WARNING", &Harl::warning }
table[3] = { "ERROR",   &Harl::error   } */

void Harl::debug()
{
	std::cout << "\033[34m" << "[DEBUG]" << "\033m" ;	
}

/*
void Harl::complain(std::string level)
{
	void (Harl::*ptr)();

	fptr = &this->debug;
}
*/

int main()
{
	return 0;
}
