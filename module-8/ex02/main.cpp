#include <iostream>
#include <string>
#include "MutantStack.hpp"

int main()
{

	MutantStack <int>b;
	b.push(1);
	b.push(2);

	std::stack<int>::container_type::iterator it;
	it = b.begin();
	std::cout << *it << std::endl;
	it = b.end() - 1;
	std::cout << *it << std::endl;

	return 0;

	std::stack <int>a;

	a.push(1);

	//std::cout << a[0] << std::endl;

	std::cout << a.top() << std::endl;
	a.pop();
	a.push('b');
	a.push(2);

	try
	{
		std::cout << a.top() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}

