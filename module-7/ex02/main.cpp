#include "Array.hpp"
#include "../ex01/iter.hpp"


int main()
{
	int *a = new int();
	std::cout << *a << std::endl;
	delete a;

	Array <int>arr;

	Array <unsigned int>arr2(5);

	iter(arr2.element(), arr2.size(), print);
	
	std::cout << "--\n";

	arr2[3] = 1;

	Array <unsigned int>arr3(arr2);

	try
	{
		std::cout << "Arr 2:" << arr2[3] << std::endl;
		std::cout << "Arr 3:" << arr3[3] << std::endl;
	}
	catch (const Array<unsigned int>::ArrayException& e)
	{
		std::cerr << e.what();
	}
	try
	{
		std::cout << arr2[15] << std::endl;
	}
	catch (const Array<unsigned int>::ArrayException& e)
	{
		std::cerr << e.what();
	}
	return 0;
}
