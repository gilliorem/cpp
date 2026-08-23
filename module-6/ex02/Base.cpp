#include "Base.hpp"
#include <ctime>
#include <iostream>

Base::~Base(){}

Base* generate(void)
{
	Base* basePtr;

	time_t sec = time(NULL);		
	if (sec % 3 == 0)
	{
		basePtr = new A;
	}
	else if (sec % 4 == 0)
	{
		basePtr = new B;
	}
	else 
	{
		basePtr = new C;
	}
	return basePtr;
}

void identify(Base* ptr)
{
	Base* tmp;

	tmp = dynamic_cast<A*>(ptr);
	if (tmp)
	{
		std::cout << "A\n";
	}
	if (!tmp)
	{
		Base* newTmp = dynamic_cast<B*>(ptr);
		if (newTmp)
		{
			std::cout << "B\n";
		}
		else
		{
			newTmp = dynamic_cast<C*>(ptr);
			std::cout << "C\n";
		}
	}
}

void identify(Base& ptr)
{
	try
	{
		ptr = dynamic_cast<A&>(ptr);
		std::cout << "A\n";
	}
	catch(...)
	{
	}
	try
	{
		ptr = dynamic_cast<B&>(ptr);
		std::cout << "B\n";
	}
	catch(...)
	{
	}
	try
	{
		ptr = dynamic_cast<C&>(ptr);
		std::cout << "C\n";
	}
	catch(...)
	{
	}
}


int main()
{
	Base* basePtr = generate();
	identify(basePtr);

	Base* secondBasePtr = generate();
	identify(*secondBasePtr);
	


	return 0;
}
