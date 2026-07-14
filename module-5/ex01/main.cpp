#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>

int main()
{
	std::cout << "===========Try to create Bureaucrat on the stack=============\n";
	try
	{
		Bureaucrat r = Bureaucrat("Remi", 0);
		std::cout << r.getGrade() << std::endl;
		std::cout << r << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cout << "GradeTooHighException: " << e.log() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cout << "GradeTooLowException: " << e.log() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "===========Try to create Bureaucrat on the heap using `new`=============\n";
	std::cout << "===========Try to create Bureaucrat with a grade that is too low `new`=============\n";

	Bureaucrat* remi; // declare outside the try block to be able to free later (When trying to create more that one Bureaucrat on the heap)
	try
	{
		remi = new Bureaucrat("Remi", 150);
		Bureaucrat* yuchi = new Bureaucrat("Yuchi", 151);
		std::cout << yuchi->getGrade() << std::endl; // this shouldn't run
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cout << "GradeTooHighException: " << e.log() << std::endl;	
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cout << "GradeTooLowException: " << e.log() << std::endl; // <- fall back here
	}
	if (remi)
		delete remi;
	Bureaucrat* b[100];
	for (int i = 0; i < 100; ++i)
		b[i] = NULL;
	Bureaucrat* b_[100];
	for (int i = 0; i < 100; ++i)
		b_[i] = NULL;
	// try to create 100 bureaucrats on the heap
	try
	{
		for (int i = 0; i < 100; ++i)
		{
			b[i] = new Bureaucrat("Bureaucrat", 150);
		}
		for (int i = 0; i < 100; ++i)
		{
			b_[i] = new Bureaucrat("_Bureaucrat", 151);
		}
		for (int i = 0; i < 100; ++i)
		{
			delete b[i];
		}
		for (int i = 0; i < 100; ++i)
		{
			delete b_[i];
		}
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cout << "GradeTooLowException: " << e.log() << std::endl;
	}
	catch (Bureaucrat:: GradeTooHighException& e)
	{
		std::cout << "GradeTooHighException: " << e.log() << std::endl;
	}
	for (int i = 0; i < 100; ++i)
	{
		if (b[i])
		{
			delete b[i];
		}
		if (b_[i])
		{
			delete b_[i];
		}
	}
	return 0;
}
