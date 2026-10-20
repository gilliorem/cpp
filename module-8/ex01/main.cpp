#include "Span.hpp"
#include <iostream>
#include <vector>
#include <exception>

int main()
{
	Span sp;
	try
	{
		sp = 1;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		sp.addNumber(10);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		sp.shortestSpan();
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	//std::cout << sp[0] << std::endl;
	try
	{
		for (unsigned long i = 0; i < 3435974; i++)
		{
			sp.addNumber(i);
		}
	}
	catch(std::bad_alloc& ba)
	{
		std::cout << "Exception caught: " << ba.what() << std::endl;
		std::cerr << "Error: program exceding heap allocation limit\n";
	}
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.longestSpan() << std::endl;
	std::cout << sp.shortestSpan() << std::endl;

	Span container(3);

	try
	{
		for (int i = 0; i < 20000; i++)
		{
			container.addNumber(i);
		}
	}
	catch(std::bad_alloc& ba)
	{
		std::cout << "Exception caught: " << ba.what() << std::endl;
		std::cerr << "Error: program exceding heap allocation limit";
	}

	
	std::cout << "longest span:" << container.longestSpan() << std::endl;
	std::cout << "shortest span:" << container.shortestSpan() << std::endl;

	Span span(4);

	for (int i = 0; i < 4; i++)
		span.addNumber(i * 2);
	for (Span::It it = span.begin(); it != span.end(); ++it)
	{
		std::cout << *it << ' ';
	}
	std::cout << '\n';

	int list[] = {10,20,30,40,50};
	span.addNumbers(list, 1, 3);
	for (Span::It it = span.begin(); it != span.end(); ++it)
	{
		std::cout << *it << ' ';
	}

}
