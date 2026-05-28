#pragma once
#include <string>

class Human
{
	public:
		Human(std::string const &name);
		~Human();
	protected:
		std::string const&_name;
};
