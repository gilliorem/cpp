#include "Harl.hpp"
#include <string>

void Harl::debug()
{
	std::cout << "\033[36;1m" << "[DEBUG]" << "\033[0m" << std::endl;
}

void Harl::info()
{
	std::cout << "\033[34;1m" << "[INFO]" <<  "\033[0m" << std::endl;
}

void Harl::warning()
{
	std::cout << "\033[33;3m" << "[WARNING]" <<  "\033[0m" << std::endl;
}

void Harl::error()
{
	std::cout << "\033[31;4m" << "[ERROR]" <<  "\033[0m" << std::endl;
}


void Harl::complain(std::string level)
{
	struct Pair
	{
		std::string level;
		void (Harl::*func)(void);
	};

	Pair table[] = {
		{"DEBUG", &Harl::debug},
		{"INFO", &Harl::info},
		{"WARNING", &Harl::warning},
		{"ERROR", &Harl::error}
	};

	for (int i = 0; i < 4; i++)
	{
		if (table[i].level == level)
		{
			(this->*table[i].func)();
			return ;
		}
	}
	std::cout << "Unknown msg type\n";
}
