#include "Harl.hpp"

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

void Harl::insignifiant()
{
	std::cout << "complain about insignifiant things\n";
}


void Harl::complain(std::string level)
{
	struct Pair
	{
		std::string level;
		int complainLevel;
	};

	enum complainLevel
	{
		DEBUG,
		INFO,
		WARNING,
		ERROR
	};

	Pair table[] = {
		{"DEBUG", DEBUG},
		{"INFO", INFO},
		{"WARNING", WARNING},
		{"ERROR", ERROR}
	};
	
	int complainCase = -1;

	for (int i = 0; i < 4; i++)
	{
		if (table[i].level == level)
		{
			complainCase = i;
			break ;
		}
	}

	if (complainCase < 0 || complainCase > 3)
		Harl::insignifiant();

	switch (complainCase)
	{
		case 0:
			Harl::debug();
		case 1:
			Harl::info();
		case 2:
			Harl::warning();
		case 3:
			Harl::error();
	}
}
