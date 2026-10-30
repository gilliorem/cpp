#include "Span.hpp"
#include <iostream>
#include <exception>

int main()
{
	Span a(1);
	Span b(10);
	for (int i = 0; i < 10; i++)
		b.addNumber(i);
	Span c(10);
	
	a.addNumber(12);

	c.addNumbers(b.begin(), b.end());

	try
	{
		a.addNumber(43);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	Span::It it;

	it = a.begin();
	std::cout << *it << std::endl;

	unsigned int sSpan;
	unsigned int lSpan;

	try
	{
		sSpan = b.shortestSpan();
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << sSpan << std::endl;

	try
	{
		lSpan = b.longestSpan();
		std::cout << lSpan << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}
