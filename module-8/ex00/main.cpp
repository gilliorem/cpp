#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main()
{
	std::vector<int> a;
	a.push_back(1);
	a.push_back(5);
	a.push_back(2);

	std::vector<int>::iterator it;

	try
	{
		it = easyfind(a, 5);
		std::cout << *it;
	}
	catch(std::exception& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;

	std::list<int> b;
	b.push_back(1);
	b.push_back(7);
	b.push_back(3);
	std::list<int>::iterator listIt;

	try
	{
		listIt = easyfind(b, 3);
		std::cout << *listIt << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
