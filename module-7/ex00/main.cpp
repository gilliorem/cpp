#include "whatever.hpp"
#include <iostream>
#include <string>


int main()
{
	int a = 2, b = 3;
	::swap(a,b);
	std::string s1 = "ni hao";
	std::string s2 = "Hallooooo";
	::swap(s1, s2);
	std::cout << "after swap: a:" << a << ", b:" << b << std::endl;
	std::cout << "after swap: s1:" << s1 << ", s2:" << s2 << std::endl;

	std::cout << "min:" << ::min(a,b) << std::endl;
	std::cout << "max:" << ::max(a,b) << std::endl;
}
