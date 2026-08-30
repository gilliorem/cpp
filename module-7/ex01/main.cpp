#include "iter.hpp"
#include <iostream>
#include <string>



int main()
{
	int arr[4] = {1,2,3,4};	
	float farr[4] = {1.05f,2.1f,3.234f,4.42f};	
	std::string strarr[5] = {"Hello", "nihao", "Bonjour", "Hola", "Enculé"};
	size_t size = 4;
	iter(arr, size, print);
	iter(arr, size, increment);
	iter(arr, size, print);

	iter(farr, size, print);
	iter(farr, size, increment);
	iter(farr, size, print);

	iter(strarr, size + 1, print);
	iter(strarr, size + 1, increment);
	iter(strarr, size + 1, print);
	return 0;
}
