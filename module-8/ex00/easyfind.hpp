#include <iostream>
class MyException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return "number could not be find in the container!\n"; 
		}
};

template <typename T>
int easyfind(T &c, int n1)
{
	typedef typename T::iterator It;
	for (It it = c.begin(); it != c.end(); ++it)
	{
		if (*it == n1)
			return *it;
	}
	throw MyException();
}
