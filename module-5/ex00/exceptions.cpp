#include <iostream>
#include <string>

double f(double d)
{
	return d > 1e7 ? throw std::overflow_error("too big") : d;
}

//int main()
//{
//	try
//	{
//		std::cout << f(1e10) << "\n";
//	}
//	catch (const std::overflow_error &e)
//	{
//		std::cout << e.what() << "\n";
//	}
//
//}

int main()
{
	try
	{
		std::cout << std::string("hello").substr(10) << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << "\n";

		//throw;
	}

}
