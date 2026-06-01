#include "Harl.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
		return (std::cout << "Need one argument\n", 0);
	std::string complain = std::string(argv[1]);
	Harl h;
	h.complain(complain);
	return 0;
}
