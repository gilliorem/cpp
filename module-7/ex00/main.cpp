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
/* their main
int main( void ) {
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}
*/
